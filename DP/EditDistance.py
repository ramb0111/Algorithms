# EDIT DISTANCE
import time

def f(a,b):
    if len(a)==0 or len(b)==0:
        return 0
    elif a[-1]==b[-1]:
        return f(a[:-1],b[:-1])
    else:
        return min(1 + f(a[:-1],b[:-1]), # CHANGE COST
                   1 + f(a[:-1],b),   # ADD COST
                   1 + f(a,b[:-1]))   # DELETE COST


# MEMOIZATION
cache = {}
def fDP(a,b):
    if cache.has_key((a,b)):
        return cache[(a,b)]
    else:
        if len(a)==0 or len(b)==0:
            cache[(a, b)]=0
        elif a[-1]==b[-1]:
            cache[(a, b)]= fDP(a[:-1],b[:-1])
        else:
            cache[(a, b)] =\
                min(1 + fDP(a[:-1],b[:-1]),
                   1 + fDP(a[:-1],b),
                   1 + fDP(a,b[:-1]))
        return cache[(a,b)]


a = "geeekdjsk"
b = "gesekwskk"

start_time = time.time()
print f(a, b)
print("--- %s seconds ---" % (time.time() - start_time))

start_time = time.time()
print fDP(a, b)
print("--- %s seconds ---" % (time.time() - start_time))
