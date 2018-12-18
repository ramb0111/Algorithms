ls = [-2,-3,4,-1,-2,1,3,-5,1]

ans,tmp = 0, 0
for ele in ls:
    tmp += ele
    if tmp<0:
        tmp=0
    ans = max(ans,tmp)
print ans