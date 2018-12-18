

def LPS(x):
    dp=[ [0]*(len(x)+1) for _ in xrange(len(x)+1) ]
    for i in xrange(len(x)+1):
        dp[i][i]=1




s="degefe"
print LPS(s)