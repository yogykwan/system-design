class TinyUrl {
public:
    /**
     * @param url a long url
     * @return a short url starts with http://tiny.url/
     */
    string longToShort(string& url) {
        // Write your code here
        if (long_short.find(url) == long_short.end()) {
            short_long.push_back(url);
            string tiny = "000000";
            int tmp = tot;
            for (int i = 0; i < 6; ++i) {
                tiny[i] = dic[tmp % 62];
                tmp /= 62;
            }
            long_short[url] = tiny;
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
        int tmp = 0;
        int len = url.length();
        for (int i = len - 1; i >= len - 6; --i) {
            tmp *= 62;
            if (url[i] <= '9') {
                tmp += url[i] - '0' + 52;
            } else if (url[i] <= 'Z') {
                tmp += url[i] - 'A' + 26;
            } else if (url[i] <= 'z') {
                tmp += url[i] - 'a';
            }
        }
        return short_long[tmp];
    }

private:
    const string domain = "http://tiny.url/";
    static int tot;
    const char dic[62] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    map<string, string> long_short;
    vector<string> short_long;
};

int TinyUrl::tot = 0;

