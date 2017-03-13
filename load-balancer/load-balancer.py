class LoadBalancer:

    def __init__(self):
        # Initialize your data structure here.
        self.servers = []
        self.len = 0
        self.index = {} # too slow without dict

    # @param {int} server_id add a new server to the cluster
    # @return nothing
    def add(self, server_id):
        # Write your code here
        if server_id not in self.index:
            self.servers.append(server_id)
            self.index[server_id] = self.len
            self.len += 1

    # @param {int} server_id remove a bad server from the cluster
    # @return nothing
    def remove(self, server_id):
        # Write your code here
        if server_id in self.index:
            id = self.index[server_id]
            self.servers[id] = self.servers[-1]
            self.index[self.servers[-1]] = id
            del self.index[server_id]
            self.servers.pop()
            self.len -= 1

    # @return {int} pick a server in the cluster randomly with equal probability
    def pick(self):
        # Write your code here
        import random
        return self.servers[random.randint(0, self.len - 1)]

