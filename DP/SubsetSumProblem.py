import time
# Subset Sum Problem

def SSP(ls, sm, lss):
    if len(ls)==0:
        if sm==0:
            return True
        else:
            return False
    else:
        if sm >=ls[-1]:
            ok = SSP(ls[:-1],sm-ls[-1], lss)
            if ok:
                lss.append(ls[-1])
            return ok or SSP(ls[:-1],sm, lss)
        else:
            return SSP(ls[:-1],sm, lss)


cache = {}
def SSPDP(ls,sm,lss):
    if not cache.has_key((sm,len(ls))):
        if len(ls) == 0:
            if sm == 0:
                cache[(sm,len(ls))]= True
            else:
                cache[(sm, len(ls))]= False
        else:
            if sm >= ls[-1]:
                ok = SSPDP(ls[:-1], sm - ls[-1], lss)
                if ok:
                    lss.append(ls[-1])
                cache[(sm, len(ls))] = ok or SSPDP(ls[:-1], sm, lss)
            else:
                cache[(sm, len(ls))] = SSPDP(ls[:-1], sm, lss)
    return cache[(sm, len(ls))]





ls=[3, 34, 4, 12, 5, 2]
sm =  9
lss = []

start_time = time.time()
print SSP(ls,sm,lss), lss
print("--- %s seconds ---" % (time.time() - start_time))

lss = []
start_time = time.time()
print SSPDP(ls,sm,lss), lss
print("--- %s seconds ---" % (time.time() - start_time))