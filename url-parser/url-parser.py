class HtmlParser:
    # @param {string} content source code
    # @return {string[]} a list of links
    def parseUrls(self, content):
        # Write your code here
        import re
        pattern = r'href\s*=\s*"?\'?([^\s"\'>]*)'
        url_re = re.compile(pattern)
        urls = re.findall(pattern, content, re.IGNORECASE)
        links = [link for link in urls if len(link) and not link.startswith('#')]
        return links
