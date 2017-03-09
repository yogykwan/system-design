class Node:
    def __init__(self, ip, ts):
        self.ip = ip
        self.ts = ts
        self.next = None


class HeartBeat:
    def __init__(self):
        # initialize your data structure here
        self.ip_pa = dict()
        self.head = Node("", 0)
        self.tail = None
        self.rtt = 0

    # @param {str[]} slaves_ip_list a list of slaves'ip addresses
    # @param {int} k an integer
    # @return nothing
    def initialize(self, slaves_ip_list, k):
        # Write your code here
        self.rtt = k + k
        pa = self.head
        cur = None
        for ip in slaves_ip_list:
            cur = Node(ip, 0)
            pa.next = cur
            self.ip_pa[ip] = pa
            pa = pa.next
        self.tail = cur

    # @param {int} timestamp current timestamp in seconds
    # @param {str} slave_ip the ip address of the slave server
    # @return nothing
    def ping(self, timestamp, slave_ip):
        # Write your code here
        if slave_ip in self.ip_pa:
            pa = self.ip_pa[slave_ip]
            cur = pa.next
            cur.ts = timestamp
            if cur == self.tail:
                return
            pa.next = cur.next
            self.ip_pa[cur.next.ip] = pa
            self.tail.next = cur
            self.ip_pa[slave_ip] = self.tail
            self.tail = cur
            self.tail.next = None

    # @param {int} timestamp current timestamp in seconds
    # @return {str[]} a list of slaves'ip addresses that died
    def getDiedSlaves(self, timestamp):
        # Write your code here
        ans = []
        pa = self.head.next
        while pa:
            if pa.ts + self.rtt > timestamp:
                break
            ans.append(pa.ip)
            pa = pa.next
        return ans

