def search(arr, X):
 
    for i in range(0, len(arr)):
        if (arr[i] == x):
            print("Element found at the index:",i)
            return
    print("Element not found")
    return

arr = [2, 3, 4, 10, 40]
x = 10
search(arr, N, x)
 
