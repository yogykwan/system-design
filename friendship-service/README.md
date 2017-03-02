# Description

Support follow & unfollow, getFollowers, getFollowings.

# Input
```
follow(1, 3)
getFollowers(1)
getFollowings(3)
follow(2, 3)
getFollowings(3)
unfollow(1, 3)
getFollowings(3)
```

# Output
```
[3]
[1]
[1,2]
[2]
```
