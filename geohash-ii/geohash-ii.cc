class GeoHash {
    public:
    /**
     * @param geohash a base32 string
     * @return latitude and longitude a location coordinate pair
     */
    vector<double> decode(string& geohash) {
        // Write your code here
        int n = geohash.length();
        for (int i = 0; i < n; ++i) {
            get_bin(geohash[i], i * 5);
        }
        int c_la, c_lo;
        c_la = n * 5 / 2;
        c_lo = n * 5 - c_la;
        
        for (int i = 0; i < c_la; ++i) {
            b_lo[i] = b[i << 1];
            b_la[i] = b[i << 1 | 1];
        }
        if (c_lo > c_la) {
            b_lo[c_la] = b[c_la << 1];
        }
        double la, lo;
        lo = get_db(b_lo, -180, 180, c_lo);
        la = get_db(b_la, -90, 90, c_la);
        return vector<double>{la, lo};
    }
    
    void get_bin(char c, int offset) {
        for (int i = 0; i < 32; ++i) {
            if (base32[i] == c) {
                for (int j = offset + 4; j >= offset; --j) {
                    b[j] = i & 1;
                    i >>= 1;
                }
                return;
            }
        }
    }
    
    double get_db(int *b, double l, double r, int n) {
        double m;
        for (int i = 0; i < n; ++i) {
            m = (l + r) / 2;
            if (b[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        return (l + r) / 2; // imprecise
    }
    
    private:
    string base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
    int b[60];
    int b_la[30], b_lo[30];
};
