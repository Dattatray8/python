set1={1,2,3,4,5}
set2={4,5,6,7,8}
print("intersection of sets:",set1&set2)
print("union of sets:",set1|set2)
print("Elements of set1 who are not in set2:",set1.difference(set2))
print("Elements of set2 who are not in set1:",set2.difference(set1))
print("length of ",set1,"is",len(set1),"length of ",set2,"is",len(set2))
print("symetric differnce",set1.symmetric_difference(set2))
print("shallow copy of set",set1,"is",set1.copy())
