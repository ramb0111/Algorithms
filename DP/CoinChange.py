import time
# st = set([])
# def CC(ls, sm, s ):
#     if sm==0:
#         x = s.split(',')[:-1]
#         x.sort()
#         ss = ','.join(x)
#         st.add(ss)
#         return True
#     for ele in ls:
#         if sm>=ele:
#             CC(ls, sm - ele, s+str(ele) + ",")
#     return False

def CC(ls, sm, lss ):
    if sm==0:
        return True
    for ele in ls:
        if sm>=ele:
            lss.append(ele)
            CC(ls, sm - ele, lss)
            return True
    return False

# MEMOIZATION
cache = {}
def CCDP(ls, sm, lss):
    if not cache.has_key((sm,len(ls))):
        if sm == 0:
            cache[sm, len(ls)]= True
            return cache[sm, len(ls)]

        for ele in ls:
            if sm >= ele:
                if CCDP(ls, sm - ele, lss):
                    lss.append(ele)
                    cache[sm, len(ls)] = True
                    return cache[sm, len(ls)]
        cache[sm, len(ls)]= False
        return cache[sm, len(ls)]
    return cache[sm,len(ls)]


ls = [5,3,2,1] # Take coins in descending order to get minimum coins
sm = 14
lss = []

start_time = time.time()
print CC(ls,sm, lss), lss
print("--- %s seconds ---" % (time.time() - start_time))

lss = []

start_time = time.time()
print CCDP(ls,sm, lss), lss
print("--- %s seconds ---" % (time.time() - start_time))