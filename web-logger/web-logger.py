class WebLogger:
    
    def __init__(self):
        # initialize your data structure here.
        self.q = []
    
    def pop_q(self, timestamp):
        timestamp -= 299
        while len(self.q) and self.q[0] < timestamp:
            self.q.pop(0)

# @param {int} timestamp an integer
# @return nothing
def hit(self, timestamp):
    # Write your code here
    self.q.append(timestamp)
        self.pop_q(timestamp)
    
    
    # @param {int} timestamp an integer
    # @return {int} an integer
    def get_hit_count_in_last_5_minutes(self, timestamp):
        # Write your code here
        self.pop_q(timestamp)
        return len(self.q)
