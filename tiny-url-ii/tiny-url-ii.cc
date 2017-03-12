class TinyUrl2 {
public:
    /**
     * @param long_url a long url
     * @param a short key
     * @return a short url starts with http://tiny.url/
     */
    string createCustom(string& long_url, string& short_key) {
        // Write your code here
        int tmp = 0;
        int len = short_key.length();
        if (len == 6) {
            for (int i = len - 1; i >= 0; --i) {
                tmp *= 62;
                if (short_key[i] <= '9') {
                    tmp += short_key[i] - '0' + 52;
                } else if (short_key[i] <= 'Z') {
                    tmp += short_key[i] - 'A' + 26;
                } else if (short_key[i] <= 'z') {
                    tmp += short_key[i] - 'a';
                }
            }
        }
        if (short_long.find(short_key) == short_long.end()) {
            if (long_short.find(long_url) != long_short.end()) {
                return "error";
            }
            long_short[long_url] = short_key;
            short_long[short_key] = long_url;
            if (len == 6) {
                ids.insert(tmp);
            }
        } else {
            if (long_short.find(long_url) == long_short.end()) {
                return "error";
            }
            if (len != 6 || ids.find(tmp) != ids.end()) {
                if (long_short[long_url] != short_key || short_long[short_key] != long_url) {
                    return "error";
                }
            } else {
                string origin_url = short_long[short_key];
                string tiny = "000000";
                while (ids.find(tot) != ids.end()) {
                    ++tot;
                }
                int t = tot;
                for (int i = 0; i < 6; ++i) {
                    tiny[i] = dic[t % 62];
                    t /= 62;
                }
                long_short[origin_url] = tiny;
                short_long[tiny] = origin_url;
                ++tot;
                ids.insert(tmp);
                long_short[long_url] = short_key;
                short_long[short_key] = long_url;
            }
        }
        return domain + short_key;
        
    }
    
    string longToShort(string& url) {
        // Write your code here
        if (long_short.find(url) == long_short.end()) {
            string tiny = "000000";
            while (ids.find(tot) != ids.end()) {
                ++tot;
            }
            int tmp = tot;
            for (int i = 0; i < 6; ++i) {
                tiny[i] = dic[tmp % 62];
                tmp /= 62;
            }
            long_short[url] = tiny;
            short_long[tiny] = url;
            ++tot;
        }
        return domain + long_short[url];
    }
    
    /**
     * @param url a short url starts with http://tiny.url/
     * @return a long url
     */
    string shortToLong(string& url) {
        // Write your code here
        int len = url.length();
        while (--len) {
            if (url[len] == '/') break;
        }
        string sub = url.substr(len + 1);
        if (short_long.find(sub) != short_long.end())
            return short_long[sub];
        else
            return "";
    }
    
private:
    const string domain = "http://tiny.url/";
    static int tot;
    const string dic = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    map<string, string> long_short;
    map<string, string> short_long;
    set<int> ids;
};

int TinyUrl2::tot = 0;
