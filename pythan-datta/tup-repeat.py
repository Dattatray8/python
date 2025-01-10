t=(1,2,4,1,4,2,5)
t1=()
print("tuple:",t)
print("Repeated items:",end=" ")
for i in t:
    if i in t1:
        print(i,end=" ")
    else :
        t1+=(i,)
        
