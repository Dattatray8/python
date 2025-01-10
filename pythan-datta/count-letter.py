word=input("Enter a string:")
cnt={}
for i in word:
    if i in cnt:
        cnt[i]+=1
    else:
        cnt[i]=1
print(cnt)
