import time
# Longest Palindromic Subsequence

def LPS(a, ans):
    if len(a)<=1:
        return len(a), a
    if a[0]==a[-1]:
        x, xs = LPS(a[1:-1], ans)
        return x + 2, a[0]+xs+a[-1]
    else:
        x,sx = LPS(a[:-1], ans)
        y,sy = LPS(a[1:], ans)
        if x < y:
            return y, sy
        else:
            return x, sx


# MEMOIZATION
cache = {}
def LPSDP(a, ans):
    if not cache.has_key(a):
        if len(a) <= 1:
            cache[a]=len(a), a
        elif a[0] == a[-1]:
            x, xs = LPSDP(a[1:-1], ans)
            cache[a] = x + 2, a[0] + xs + a[-1]
        else:
            x, sx = LPSDP(a[:-1], ans)
            y, sy = LPSDP(a[1:], ans)
            if x < y:
                cache[a] = y, sy
            else:
                cache[a] = x, sx
    return cache[a]


s="akshdbcbshkdhdhsgeywuiw"

start_time = time.time()
print LPS(s, "")
print("--- %s seconds ---" % (time.time() - start_time))

start_time = time.time()
print LPSDP(s, "")
print len(cache), len(s)
print("--- %s seconds ---" % (time.time() - start_time))





