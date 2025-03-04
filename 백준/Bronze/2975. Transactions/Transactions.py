while True:
    A, command, B = input().split()
    
    A, B = int(A), int(B)
    if A == 0 and command == "W" and B == 0:
        break
    
    if command == "W":
        if A - B < -200:
            print("Not allowed")
        else:
            print(A - B)
    else:
        print(A + B)