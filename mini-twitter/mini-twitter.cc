/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
class MiniTwitter {
private:
    map<int, set<int> > follows_;
    vector<Tweet> tweets_;

public:
    MiniTwitter() {
        // initialize your data structure here.
        follows_.clear();
        tweets_.clear();
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        Tweet new_tweet = Tweet::create(user_id, tweet_text);
        tweets_.push_back(new_tweet);
        return new_tweet;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        if (follows_.find(user_id) == follows_.end()) {
            return getTimeline(user_id);
        }
        vector<Tweet> ans;
        int max_length = 10;
        for (vector<Tweet>::reverse_iterator it = tweets_.rbegin(); it != tweets_.rend(); ++it) {
            if (it->user_id == user_id ||
            follows_[user_id].find(it->user_id) != follows_[user_id].end()) {
                ans.push_back(*it);
                if (--max_length == 0) break;
            }
        }
        return ans;
    }

    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        // Write your code here
        vector<Tweet> ans;
        int max_length = 10;
        for (vector<Tweet>::reverse_iterator it = tweets_.rbegin(); it != tweets_.rend(); ++it) {
            if (it->user_id == user_id) {
                ans.push_back(*it);
                if (--max_length == 0) break;
            }
        }
        return ans;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows_ to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        if (follows_.find(from_user_id) == follows_.end()) {
            follows_[from_user_id] = set<int>();
        }
        follows_[from_user_id].insert(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows_ to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        if (follows_.find(from_user_id) != follows_.end()) {
            follows_[from_user_id].erase(to_user_id);
        }
    }
};

