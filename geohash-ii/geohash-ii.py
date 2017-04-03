class GeoHash:
    # @param {string} geohash a base32 string
    # @return {double[]} latitude and longitude a location coordinate pair
    def decode(self, geohash):
        # Write your code here
        base32 = "0123456789bcdefghjkmnpqrstuvwxyz"
        n = len(geohash)
        b = []
        for i in xrange(n):
            c = geohash[i]
            for j in xrange(32):
                if c == base32[j]:
                    tb = []
                    for k in xrange(5):
                        tb.append(j & 1)
                        j >>= 1
                    for tbit in tb[::-1]:
                        b.append(tbit)
                    break
        m = len(b)
        lo = self.get_db(b[::2], -180, 180, m - m / 2)
        la = self.get_db(b[1::2], -90, 90, m / 2)
        return [la, lo]
    
    def get_db(self, b, l, r, n):
        for i in xrange(n):
            m = (l + r) * 0.5
            if b[i] == 0:
                r = m
            else:
                l = m
        return (l + r) * 0.5
