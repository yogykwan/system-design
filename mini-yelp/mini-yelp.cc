/**
 * Definition of Location:
 * class Location {
 * public:
 *     double latitude, longitude;
 *     static Location create(double lati, double longi) {
 *         // This will create a new location object
 *     }
 * };
 * Definition of Restaurant
 * class Restaurant {
 * public:
 *     int id;
 *     string name;
 *     Location location;
 *     static Restaurant create(string &name, Location &location) {
 *         // This will create a new restaurant object,
 *         // and auto fill id
 *     }
 * };
 * Definition of Helper
 * class Helper {
 * public:
 *     static get_distance(Location &location1, Location &location2) {
 *         // return distance between location1 and location2.
 *     }
 * };
 * class GeoHash {
 * public:
 *     static string encode(Location &location) {
 *         // return convert location to a GeoHash string
 *     }
 *     static Location decode(string &hashcode) {
 *          // return convert a GeoHash string to location
 *     }
 * };
 */

typedef pair<double, string> pds;


class MiniYelp {
    public:
    MiniYelp() {
        // initialize your data structure here.
        codes.clear();
        rests.clear();
    }
    
    // @param name a string
    // @param location a Location
    // @return an integer, restaurant's id
    int addRestaurant(string name, Location &location) {
        // Write your code here
        Restaurant rest = Restaurant::create(name, location);
        string code = GeoHash::encode(location);
        stringstream ss;
        ss << rest.id;
        string suffix;
        ss >> suffix;
        code += "." + suffix;
        codes[rest.id] = code;
        rests[code] = rest;
        return rest.id;
    }
    
    // @param restaurant_id an integer
    void removeRestaurant(int restaurant_id) {
        // Write your code here
        string code = codes[restaurant_id];
        codes.erase(restaurant_id);
        rests.erase(code);
    }
    
    // @param location a Location
    // @param k an integer, distance smaller than k miles
    // @return a list of restaurant's name and sort by
    // distance from near to far.
    vector<string> neighbors(Location &location, double k) {
        // Write your code here
        string code = GeoHash::encode(location);
        
        int prefix = 12;
        for (int i = 0; i < 12; ++i) {
            if (k > errors[i]) {
                prefix = i;
                break;
            }
        }
        code = code.substr(0, prefix);
        priority_queue<pds, vector<pds>, greater<pds>> pq;
        map<string, Restaurant>::iterator it = rests.lower_bound(code);
        for (; it != rests.end(); ++it) {
            if (it->first.substr(0, prefix) != code) {
                break;
            }
            Restaurant trest = it->second;
            double tdist = Helper::get_distance(location, trest.location);
            if (tdist <= k) {
                pq.push(make_pair(tdist, trest.name));
            }
        }
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    private:
    map<int, string> codes;
    map<string, Restaurant> rests;
    double errors[12] = {2500, 630, 78, 20, 2.4, 0.61, 0.076, 0.01911, 0.00478, 0.0005971, 0.0001492, 0.0000186};
};
