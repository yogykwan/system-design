'''
    Definition of Location:
    class Location:
    # @param {double} latitude, longitude
    # @param {Location}
    @classmethod
    def create(cls, latitude, longitude):
    # This will create a new location object
    
    Definition of Restaurant:
    class Restaurant:
    # @param {str} name
    # @param {Location} location
    # @return {Restaurant}
    @classmethod
    def create(cls, name, location):
    # This will create a new restaurant object,
    # and auto fill id
    
    Definition of Helper
    class Helper:
    # @param {Location} location1, location2
    @classmethod
    def get_distance(cls, location1, location2):
    # return calculate the distance between two location
    
    Definition of GeoHash
    class GeoHash:
    # @param {Location} location
    # @return a string
    @classmethom
    def encode(cls, location):
    # return convert location to a geohash string
    
    # @param {str} hashcode
    # @return {Location}
    @classmethod
    def decode(cls, hashcode):
    # return convert a geohash string to location
    '''
from YelpHelper import Location, Restaurant, GeoHash, Helper
import bisect

class MiniYelp:
    
    def __init__(self):
        # initialize your data structure here.
        self.rests = {}
        self.codes = {}
        self.geos = []
    
    
    # @param {str} name
    # @param {Location} location
    # @return {int} restaurant's id
    def add_restaurant(self, name, location):
        # Write your code here
        rest = Restaurant.create(name, location)
        code = "%s.%s" % (GeoHash.encode(location), rest.id)
        self.codes[rest.id] = code
        self.rests[code] = rest
        bisect.insort(self.geos, code)
        return rest.id
    
    
    # @param {int} restaurant_id
    # @return nothing
    def remove_restaurant(self, restaurant_id):
        # Write your code here
        code = self.codes[restaurant_id]
        del self.rests[code]
        del self.codes[restaurant_id]
        self.geos.pop(bisect.bisect_left(self.geos, code))
    
    
    # @param {Location} location
    # @param {double} k, distance smaller than k miles
    # @return {str[]} a list of restaurant's name and sort by
    # distance from near to far.
    def neighbors(self, location, k):
        # Write your code here
        errors = [2500, 630, 78, 20, 2.4, 0.61, 0.076, 0.01911, 0.00478, 0.0005971, 0.0001492, 0.0000186]
        pre = 12
        for i in xrange(12):
            if k > errors[i]:
                pre = i
                break
        code = GeoHash.encode(location)[:pre]
        l = bisect.bisect_left(self.geos, code)
        r = bisect.bisect_right(self.geos, code + '{')
        ans = []
        for i in xrange(l, r):
            code = self.geos[i]
            rest = self.rests[code]
            dist = Helper.get_distance(location, rest.location)
            if dist <= k:
                ans.append((dist, rest.name))
        
        ans = sorted(ans, key=lambda x: x[0])
    return [x[1] for x in ans]
