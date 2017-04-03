/**
 * Definition of Trip:
 * class Trip {
 * public:
 *     int id; // trip's id, primary key
 *     int driver_id, rider_id; // foreign key
 *     double lat, lng; // pick up location
 *     Trip(int rider, double lat, double lng);
 * }
 * Definition of Helper
 * class Helper {
 * public:
 *     static get_distance(double lat1, double lng1,
 *                         double lat2, double lng2) {
 *         // return distance between (lat1, lng1) and (lat2, lng2)
 *     }
 * };
 */
class Location {
public:
    double lat, lng;
    Location(double _lat, double _lng): lat(_lat), lng(_lng) {}
};

class MiniUber {
public:
    MiniUber() {
        // initialize your data structure here.
        locations.clear();
        trips.clear();
    }
    
    // @param driver_id an integer
    // @param lat, lng driver's location
    // return matched trip information if there have matched rider or NULL
    Trip* report(int driver_id, double lat, double lng) {
        // Write your code here
        if (trips.find(driver_id) != trips.end()) {
            return trips[driver_id];
        }
        if (locations.find(driver_id) != locations.end()) {
            locations[driver_id]->lat = lat;
            locations[driver_id]->lng = lng;
        } else {
            locations[driver_id] = new Location(lat, lng);
        }
        return NULL;
    }
    
    // @param rider_id an integer
    // @param lat, lng rider's location
    // return a trip
    Trip* request(int rider_id, double lat, double lng) {
        // Write your code here
        double dist = -1, t_dist;
        int driver_id = -1;
        for (map<int, Location*>::iterator it = locations.begin(); it != locations.end(); ++it) {
            t_dist = Helper::get_distance(it->second->lat, it->second->lng, lat, lng);
            if (dist < 0 || dist > t_dist) {
                dist = t_dist;
                driver_id = it->first;
            }
        }
        Trip* trip = new Trip(rider_id, lat, lng);
        trip->driver_id = driver_id;
        if (driver_id != -1) {
            locations.erase(locations.find(driver_id));
            trips[driver_id] = trip;
        }
        return trip;
    }
    
private:
    map<int, Location*> locations;
    map<int, Trip*> trips;
};
