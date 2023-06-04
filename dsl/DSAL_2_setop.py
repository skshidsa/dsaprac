set_a={1,5,3,7,14,23,77,89}
set_b={2,5,3,8,56,34,89,77,12}

while True:
    print("--------------Menu-------------")
    print("1. Add element")
    print("2. Remove element")
    print("3. Union")
    print("4. Intersection")
    print("5. Search")
    print("6. Length")
    print("7. Difference")
    print("8. Subset")
    print("9. Exit")

    ch=int(input("Enter your choice: "))

    if(ch==1):
        s=input("enter in set to add element: ")
        if s=='a':
            n1=int(input("Enter element to add to set A: "))
            set_a.add(n1)
            print(set_a)
        elif s=='b':
            n2=int(input("Enter element to add to set B: "))
            set_b.add(n2)
            print(set_b)

    elif(ch==2):
        s=input("enter from which set to remove element: ")
        if s=='a':
            n1=int(input("Enter element to remove from set A: "))
            set_a.remove(n1)
            print(set_a)
        elif s=='b':
            n2=int(input("Enter element to remove from set B: "))
            set_b.remove(n2)
            print(set_b)

    elif(ch==3):
        res_set=set_a.union(set_b)
        print("Union of set A and set B is: ",res_set)

    elif(ch==4):
        res_set=set_a.intersection(set_b)
        print("Intersection of  set A and set B is: ",res_set)

    elif(ch==5):
        n=int(input("Enter element to search: "))
        if n in set_a:
            print("Element present in set A!!")
        elif n in set_b:
            print("Element present in set B!!")
        else:
            print("Element not present at all....")

    elif(ch==6):
        print("Length of given set A is: ",len(set_a))
        print("Length of given set B is: ",len(set_b))

    elif(ch==7):
        print("Difference of set A and set B is: ",set_a.difference(set_b))

    elif(ch==8):
        print("Is set A subset of set B:",set_a.issubset(set_b))
        print("Is set B subset of set A:",set_b.issubset(set_a))

    else:
        quit(0)
