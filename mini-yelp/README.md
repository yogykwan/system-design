# Description

Design a simple yelp system. Support the following features:

1. Add a restaurant with name and location.
2. Remove a restaurant with id.
3. Search the nearby restaurants by given location.

A location is represented by latitude and longitude, both in double. A Location class is given in code.

Nearby is defined by distance smaller than k Km .

Restaurant class is already provided and you can directly call Restaurant.create() to create a new object. Also, a Helper class is provided to calculate the distance between two location, use Helper.get_distance(location1, location2).

A GeoHash class is provided to convert a location to a string. Try GeoHash.encode(location) to convert location to a geohash string and GeoHash.decode(string) to convert a string to location.

# Input

```
addRestaurant("Lint Cafe", 10.4999999, 11.599999)
addRestaurant("Code Cafe", 10.4999999, 11.512109)
neighbors(10.5, 11.6, 6.7)
removeRestaurant(1)
neighbors(10.5, 11.6, 6.7)
```

# Output

```
1
2
["Lint Cafe"]
[]
```
