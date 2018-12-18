import time

# RECURSION
def f(w,v,W):
    if len(w)==0 or W==0:
        return 0
    else:
        if W >= w[-1]:
            return max( f(w[:-1], v[:-1], W),
                    f(w[:-1], v[:-1], W-w[-1]) + v[-1]
                )
        return f(w[:-1], v[:-1], W)

#MEMOIZATION
cache = {}
def fDP(w,v,W):
    if cache.has_key((W,len(w))):
        return cache[(W,len(w))]
    else:
        if len(w) == 0 or W == 0:
            cache[(W, len(w))] = 0
        else:
            if W >= w[-1]:
                cache[(W, len(w))] = max(fDP(w[:-1], v[:-1], W),
                           fDP(w[:-1], v[:-1], W - w[-1]) + v[-1]
                           )
            else:
                cache[(W, len(w))] = fDP(w[:-1], v[:-1], W)
        return cache[(W,len(w))]

# TABULATION
def ffDP(w,v,W):
    dp = []
    for _ in xrange(0,W+1):
        dp.append([0]*(len(w)+1))
    for i in xrange(1,W+1):
        for j in xrange(1,len(w)+1):
            if i-w[j-1]>=0:
                dp[i][j] = max(dp[i-w[j-1]][j-1]+v[j-1],dp[i][j-1])
            else:
                dp[i][j] = dp[i][j-1]

    return dp[W][len(w)]




v=[60,100,120,100,100,60,100,120,100,100,60,100,120,100,100,60,100,120,100,100]
w=[1,1,5,4,2,1,1,5,4,2,1,1,5,4,2]
W = 600

# start_time = time.time()
# print f(w,v,W)
# print("--- %s seconds ---" % (time.time() - start_time))

start_time = time.time()
print fDP(w,v,W)
print("--- %s seconds ---" % (time.time() - start_time))

start_time = time.time()
print ffDP(w,v,W)
print("--- %s seconds ---" % (time.time() - start_time))
