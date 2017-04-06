import bisect

class RateLimiter:
    
    def __init__(self):
        # do some intialize if necessary
        self.logs = dict()
    
    # @param {int} timestamp the current timestamp
    # @param {string} event the string to distinct different event
    # @param {string} rate the format is [integer]/[s/m/h/d]
    # @param {boolean} increment whether we should increase the counter
    # @return {boolean} true or false to indicate the event is limited or not
    def is_ratelimited(self, timestamp, event, rate, increment):
        # Write your code here
        limit, type = rate.split('/')
        limit = int(limit)
        if type == 's': base = 1
        elif type == 'm': base = 60
        elif type == 'h': base = 3600
        elif type == 'd': base = 86400
        
        if event not in self.logs:
            self.logs[event] = []
    
        id = bisect.bisect_right(self.logs[event], timestamp - base)
        
        cnt = len(self.logs[event]) - id
        if increment and cnt < limit:
            self.logs[event].append(timestamp)
return cnt >= limit
