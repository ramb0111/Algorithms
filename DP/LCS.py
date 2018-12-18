# LCS:
import time

def LCS(a, b):
    if len(a) == 0 or len(b) == 0:
        return 0

    if a[-1] == b[-1]:
        return 1 + LCS(a[:-1], b[:-1])
    else:
        return max(LCS(a, b[:-1]), LCS(a[:-1], b))

# MEMOIZATION
cache = {}
def LCSDP(a,b):
    if cache.has_key((a,b)):
        return cache[(a,b)]
    else:
        if len(a) == 0 or len(b) == 0:
            cache[(a, b)] = 0
        elif a[-1] == b[-1]:
            cache[(a, b)] = 1 + LCSDP(a[:-1], b[:-1])
        else:
            cache[(a, b)] = max(LCSDP(a, b[:-1]), LCSDP(a[:-1], b))
        return cache[(a, b)]


# TABLOID

def LCST(a,b):
    dp = [[0]*(len(b)+1) for _ in xrange(len(a)+1)]
    for i in xrange(0,len(a)):
        for j in xrange(0,len(b)):
            if a[i]==b[j]:
                dp[i+1][j+1]=dp[i][j] + 1
            else:
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])


    i,j,ans=len(a),len(b),""
    while i>=1 and j>=1:
        if dp[i][j]==dp[i-1][j-1]+1:
            ans = a[i-1]+ans
            i-=1
            j-=1
        elif dp[i][j]==dp[i-1][j]:
            i-=1
        else:
            j-=1
    print ans


a = "aaxxxbacdeafaag"
b = "axbxxcyydfewfsg"

start_time = time.time()
# print LCS(a, b)
print("--- %s seconds ---" % (time.time() - start_time))


start_time = time.time()
print LCSDP(a, b)
print("--- %s seconds ---" % (time.time() - start_time))

start_time = time.time()
print LCST(a, b)
print("--- %s seconds ---" % (time.time() - start_time))