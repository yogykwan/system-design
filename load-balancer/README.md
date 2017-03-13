# Description

Implement a load balancer for web servers. It provide the following functionality:

1. Add a new server to the cluster => add(server_id).
2. Remove a bad server from the cluster => remove(server_id).
3. Pick a server in the cluster randomly with equal probability => pick().

# Input

```
add(1)
add(2)
add(3)
pick()
pick()
pick()
pick()
remove(1)
pick()
pick()
pick()
```

# Output

```
Your code pass chi-square test, we think you pick a server randomly with equal probability.
```
