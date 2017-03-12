tot = 0

class TinyUrl2:
    def __init__(self):
        self.long_short = {}
        self.short_long = {}
        self.ids = set()
        self.char_dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        self.domain = "http://tiny.url/"
    
    # @param long_url a long url
    # @param a short key
    # @return a short url starts with http://tiny.url/
    def createCustom(self, long_url, short_key):
        # Write your code here
        global tot
        le = len(short_key)
        tmp = 0
        for ch in short_key[-1:-7:-1]:
            tmp *= 62
            if '0' <= ch <= '9':
                tmp += ord(ch) - 48 + 52
            elif 'A' <= ch <= 'Z':
                tmp += ord(ch) - 65 + 26
            elif 'a' <= ch <= 'z':
                tmp += ord(ch) - 97
    
        if short_key in self.short_long:
            if long_url in self.long_short:
                if self.short_long[short_key] != long_url or self.long_short[long_url] != short_key:
                    return "error"
            else:
                if le != 6 or tmp in self.ids:
                    return "error"
                else:
                    # before: pre_url->short_key
                    # after: pre_url->tiny, long_url->short_key
                    # TODO: how to notify the change of pre_url->tiny
                    pre_url = self.short_long[short_key]
                    while tot in self.ids:
                        tot += 1
                    t = tot
                    tiny = ""
                    for i in xrange(6):
                        tiny += str(self.char_dict[t % 62])
                        t /= 62
                    self.long_short[pre_url] = tiny
                    self.short_long[tiny] = pre_url
                    tot += 1
                    
                    self.long_short[long_url] = short_key
                    self.short_long[short_key] = long_url
                    self.ids.add(tmp)
else:
    if long_url in self.long_short:
        return "error"
            self.long_short[long_url] = short_key
            self.short_long[short_key] = long_url
            if le == 6:
                self.ids.add(tmp)
        return self.domain + short_key
    
    # @param {string} long_url a long url
    # @return {string} a short url starts with http://tiny.url/
    def longToShort(self, long_url):
        # Write your code here
        global tot
        if long_url not in self.long_short:
            while tot in self.ids:
                tot += 1
            tmp = tot
            tiny = ""
            for i in xrange(6):
                tiny += str(self.char_dict[tmp % 62])
                tmp /= 62
            self.long_short[long_url] = tiny
            self.short_long[tiny] = long_url
            tot += 1
        return self.domain + self.long_short[long_url]
    
    # @param {string} short_url a short url starts with http://tiny.url/
    # @return {string} a long url
    def shortToLong(self, short_url):
        # Write your code here
        global tot
        le = len(short_url)
        while le:
            if short_url[le - 1] == '/':
                break
            le -= 1
        if short_url[le:] in self.short_long:
            return self.short_long[short_url[le:]]
        else:
            return ""
