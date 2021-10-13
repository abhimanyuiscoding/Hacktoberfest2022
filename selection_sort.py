def selection_sort(v):
    n = len(v)
    for i in range(n):
        minidx = i
        j = i + 1
        while j < n and v[j] < v[minidx]:
            minidx = j
            j += 1
        v[i], v[minidx] = v[minidx], v[i]
    return(v)

# Example
a = [1,5,7,4,3,9,8,6,2]
selection_sort(a)