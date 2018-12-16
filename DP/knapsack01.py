import time

def f(w,v,W):
    if len(w)==0 or W==0:
        return 0
    else:
        if W >= w[-1]:
            return max( f(w[:-1], v[:-1], W),
                    f(w[:-1], v[:-1], W-w[-1]) + v[-1]
                )
        return f(w[:-1], v[:-1], W)


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


v=[60,100,120,100,100]
w=[10,10,50,40,20]
W = 40

start_time = time.time()
print f(w,v,W)
print("--- %s seconds ---" % (time.time() - start_time))

start_time = time.time()
print fDP(w,v,W)
print("--- %s seconds ---" % (time.time() - start_time))
