# implementation of counting sort in python

def counting_sort(arr):
    min_val = min(arr)
    max_val = max(arr)
    count = [0] * (max_val - min_val + 1)
    for elem in arr:
	    count[elem - min_val] += 1

    for i in range(1, len(count)):
        count[i] += count[i - 1]

    sortd = [0] * len(arr)
    for elem in arr[::-1]:
        count[elem - min_val] -= 1
        sortd[count[elem - min_val]] = elem
    return sortd
