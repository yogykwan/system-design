class TinyUrl:
    def __init__(self):
        self.long_short = {}
        self.short_long = {}
        self.char_dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        self.tot = 0

    # @param {string} url a long url
    # @return {string} a short url starts with http://tiny.url/
    def longToShort(self, url):
        # Write your code here
        if url not in self.long_short:
            tiny = ""
            tmp = self.tot
            for i in xrange(6):
                tiny += str(self.char_dict[tmp % 62])
                tmp /= 62
            self.tot += 1
            self.long_short[url] = tiny
            self.short_long[tiny] = url
        return "http://tiny.url/" + self.long_short[url]

    # @param {string} url a short url starts with http://tiny.url/
    # @return {string} a long url
    def shortToLong(self, url):
        # Write your code here
        if url[-6:] in self.short_long:
            return self.short_long[url[-6:]]
        else:
            return None

