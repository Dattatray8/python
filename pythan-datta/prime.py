n = int(input("Enter how many prime numbers are required :"))
for num in range(2,n+1):
    is_prime = True
    for i in range(2,num):
        if  num%i==0:
            is_prime = False
            break
    if is_prime==True:
        print(num,end=" ")
