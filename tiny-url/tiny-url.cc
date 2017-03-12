class TinyUrl {
public:
    /**
     * @param url a long url
     * @return a short url starts with http://tiny.url/
     */
    string longToShort(string& url) {
        // Write your code here
        if (long_short.find(url) == long_short.end()) {
            string tiny = "000000";
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
        string sub = url.substr(url.length() - 6);
        if (short_long.find(sub) != short_long.end())
            return short_long[sub];
        else
            return NULL;
    }
    
private:
    const string domain = "http://tiny.url/";
    static int tot;
    const string dic = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    map<string, string> long_short;
    map<string, string> short_long;
};

int TinyUrl::tot = 0;

