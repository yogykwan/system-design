'''
Definition of Tweet:
class Tweet:
    @classmethod
    def create(cls, user_id, tweet_text):
         # This will create a new tweet object,
         # and auto fill id
'''


class MiniTwitter:

    def __init__(self):
        # initialize your data structure here.
        self.follows = dict()
        self.tweets = []

    # @param {int} user_id
    # @param {str} tweet
    # @return {Tweet} a tweet
    def postTweet(self, user_id, tweet_text):
        # Write your code here
        tweet = Tweet.create(user_id, tweet_text)
        self.tweets.append(tweet)
        return tweet

    # @param {int} user_id
    # return {Tweet[]} 10 new feeds recently
    # and sort by timeline
    def getNewsFeed(self, user_id):
        # Write your code here
        if user_id not in self.follows:
            return self.getTimeline(user_id)
        max_length = 10
        ans = []
        for t in self.tweets[::-1]:
            if t.user_id == user_id or t.user_id in self.follows[user_id]:
                ans.append(t)
                max_length -= 1
                if max_length == 0:
                    break
        return ans

    # @param {int} user_id
    # return {Tweet[]} 10 new posts recently
    # and sort by timeline
    def getTimeline(self, user_id):
        # Write your code here
        max_length = 10
        ans = []
        for t in self.tweets[::-1]:
            if t.user_id == user_id:
                ans.append(t)
                max_length -= 1
                if max_length == 0:
                    break
        return ans

    # @param {int} from user_id
    # @param {int} to_user_id
    # from user_id follows to_user_id
    def follow(self, from_user_id, to_user_id):
        # Write your code here
        if from_user_id not in self.follows:
            self.follows[from_user_id] = set()
        self.follows[from_user_id].add(to_user_id)

    # @param {int} from user_id
    # @param {int} to_user_id
    # from user_id unfollows to_user_id
    def unfollow(self, from_user_id, to_user_id):
        # Write your code here
        if from_user_id in self.follows and to_user_id in self.follows[from_user_id]:
            self.follows[from_user_id].remove(to_user_id)

