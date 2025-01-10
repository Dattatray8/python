val = [1,21,323,1,3,1]
val2 = [2,3,1,21,33]
if len(val) != len(set(val)) :
    print("In the list :",val,"values are duplicating")
else :
    print("In the list :",val,"values are all unique")

if len(val2) != len(set(val2)) :
    print("In the list :",val2,"values are duplicating")
else :
    print("In the list :",val2,"values are all unique")
