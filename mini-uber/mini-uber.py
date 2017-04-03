'''
    Definition of Trip:
    class Trip:
    self.id; # trip's id, primary key
    self.driver_id, self.rider_id; # foreign key
    self.lat, self.lng; # pick up location
    def __init__(self, rider_id, lat, lng):
    
    Definition of Helper
    class Helper:
    @classmethod
    def get_distance(cls, lat1, lng1, lat2, lng2):
    # return calculate the distance between (lat1, lng1) and (lat2, lng2)
    '''
from Trip import Trip, Helper


class MiniUber:
    
    def __init__(self):
        # initialize your data structure here.
        self.locs = {}
        self.trips = {}
    
    # @param {int} driver_id an integer
    # @param {double} lat, lng driver's location
    # return {trip} matched trip information if there have matched rider or null
    def report(self, driver_id, lat, lng):
        # Write your code here
        if driver_id in self.trips:
            return self.trips[driver_id]
        self.locs[driver_id] = (lat, lng)
        return None
    
    
    # @param rider_id an integer
    # @param lat, lng rider's location
    # return a trip
    def request(self, rider_id, lat, lng):
        # Write your code here
        dist = -1
        driver = -1
        for key, value in self.locs.items():
            td = Helper.get_distance(value[0], value[1], lat, lng)
            if dist == -1 or td < dist:
                dist = td
                driver = key
        
        trip = Trip(rider_id, lat, lng)
        trip.driver_id = driver
        if dist != -1:
            del self.locs[driver]
            self.trips[driver] = trip
        return trip
