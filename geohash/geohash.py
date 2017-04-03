class GeoHash:
    # @param {double} latitude, longitude a location coordinate pair
    # @param {int} precision an integer between 1 to 12
    # @return {string} a base32 string
    def encode(self, latitude, longitude, precision):
        # Write your code here
        base32 = "0123456789bcdefghjkmnpqrstuvwxyz"
        c_lo = (precision * 5 + 1) / 2
        c_la = precision * 5 / 2;
        b = []
        bo = self.get_b(longitude, -180, 180, c_lo)
        ba = self.get_b(latitude, -90, 90, c_la)
        for i in xrange(c_la):
            b.append(bo[i])
            b.append(ba[i])
        if c_lo > c_la:
            b.append(bo[-1])
        ans = ""
        for i in xrange(precision):
            id = self.get_id(5 * i, 5 * i + 4, b)
            ans += base32[id]
        return ans
    
    def get_b(self, x, l, r, n):
        b = []
        for i in xrange(n):
            m = (l + r) * 0.5
            if x <= m:
                r = m
                b.append(0)
            else:
                l = m
                b.append(1)
        return b
    
    def get_id(self, l, r, b):
        ans = 0
        for i in range(l, r + 1):
            ans = ans * 2 + b[i]
        return ans
