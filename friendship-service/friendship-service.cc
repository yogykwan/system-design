class FriendshipService {
private:
    map<int, vector<int> > from_to;
    map<int, vector<int> > to_from;

public:
    FriendshipService() {
        // initialize your data structure here.
        from_to.clear();
        to_from.clear();
    }

    // @param user_id an integer
    // return all followers and sort by user_id
    vector<int>  getFollowers(int user_id) {
        // Write your code here
        vector<int> &tmp = from_to[user_id];
        sort(tmp.begin(), tmp.end());
        return tmp;
    }

    // @param user_id an integer
    // return all followings and sort by user_id
    vector<int>  getFollowings(int user_id) {
        // Write your code here
        vector<int> &tmp = to_from[user_id];
        sort(tmp.begin(), tmp.end());
        return tmp;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        vector<int> &from = from_to[from_user_id];
        vector<int> &to = to_from[to_user_id];
        vector<int>::iterator from_it = find(from.begin(),from.end(),to_user_id);
        if(from_it == from.end()) {
            from.push_back(to_user_id);
            to.push_back(from_user_id);
        }
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        vector<int> &from = from_to[from_user_id];
        vector<int> &to = to_from[to_user_id];
        vector<int>::iterator from_it = find(from.begin(),from.end(),to_user_id);
        if(from_it != from.end()) {
            from.erase(from_it);
            vector<int>::iterator to_it = find(to.begin(),to.end(),from_user_id);
            to.erase(to_it);
        }
    }
};
