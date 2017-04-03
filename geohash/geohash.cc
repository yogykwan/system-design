class GeoHash {
    public:
    /**
     * @param latitude, longitude a location coordinate pair
     * @param precision an integer between 1 to 12
     * @return a base32 string
     */
    string encode(double latitude, double longitude, int precision) {
        // Write your code here
        int c_lo, c_la;
        c_lo = (5 * precision + 1) / 2;
        c_la = 5 * precision / 2;
        get_bin(longitude, -180, 180, c_lo, 0);
        get_bin(latitude, -90, 90, c_la, 1);
        string ans;
        for (int i = 0; i < precision; ++i) {
            int id = get_id(i * 5, i * 5 + 4);
            ans += base32[id];
        }
        return ans;
    }
    
    void get_bin(double x, double l, double r, int n, int a) {
        double m;
        for (int i = 0; i < n; ++i) {
            m = (l + r) / 2;
            if (x <= m) {
                bin[i * 2 + a] = 0;
                r = m;
            } else {
                bin[i * 2 + a] = 1;
                l = m;
            }
        }
    }
    
    int get_id(int l, int r) {
        int id = 0;
        for (int i = l; i <= r; ++i) {
            id = id * 2 + bin[i];
        }
        return id;
    }
    
    private:
    string base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
    int bin[60];
};
