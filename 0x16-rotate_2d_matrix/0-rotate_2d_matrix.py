def rotate_2d_matrix(matrix):
    size = len(matrix)
    arr = []
    for x in range(0, size):
    	arr.append([i[x] for i in matrix][::-1])
    for x in range(0, size):
       matrix[x] = arr[x]
       