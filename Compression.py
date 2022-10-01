# List Compression 
ls = [i for i in range(100) if i%2==0]
print(ls)

#Dictonary Compression 
dict1 = {i:f"item {i}" for i in range(1, 10001) if i%100==0}
dict1 = {i:f"Item {i}" for i in range(5)}

# Swap key and values
dict2 = {value:key for key,value in dict1.items()}
print(dict1,"\n", dict2)


#Sets Compression
persons = {person for person in ["Yogesh", "Mukesh","Yogesh",
                               "Mukesh","Yogesh", "Mukesh"]}
print(persons)

#Generator Compression
evens = (i for i in range(100) if i%2==0)

for item in evens:
    print(item)
