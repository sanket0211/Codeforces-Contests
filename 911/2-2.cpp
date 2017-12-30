mn=1
n,a,b=map(int,input().split())
for x in range(1,a-1):
    #count a
    #if b//(n-a) >=
    try:
        #print(x,a//x,b//(n-x))
        mn=max(mn,min(a//x-a%x,b//(n-x)))
    except:
        pass
        
print(mn)