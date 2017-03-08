#class HtmlHelper:
#    @classmethod
#    def parseUrls(cls, url)
#       # Get all urls from a webpage of given url.


from Queue import Queue
from threading import Thread
from urlparse import urlparse

queue = Queue()
results = {}


class CrawlerThread(Thread):
    global queue, results
    
    @classmethod
    def run(self):
        while True:
            url = queue.get()
            if url not in results and urlparse(url).hostname.endswith("wikipedia.org"):
                urls = HtmlHelper.parseUrls(url)
                results[url] = True
                for u in urls:ß
                    queue.put(u)
            queue.task_done()


class Solution:
    # @param {string} url a url of root page
    # @return {string[]} all urls
    def crawler(self, url):
    # Write your code here
        global queue, results
        
        n_thread = 10
        thread_pools = []
        for i in range(n_thread):
            thread_pools.append(CrawlerThread())
            thread_pools[i].setDaemon(True)
            thread_pools[i].start()
        
        queue.put(url)
        queue.join()
        
        ans = []
        for key, value in results.items():
            ans.append(key)
        return ans
