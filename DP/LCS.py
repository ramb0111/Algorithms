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




a = "abcefghijklmn"
b = "abxdfxxxxxxxxxxin"

start_time = time.time()
print LCS(a, b)
print("--- %s seconds ---" % (time.time() - start_time))


start_time = time.time()
print LCSDP(a, b)
print("--- %s seconds ---" % (time.time() - start_time))