def rotate(matrix):
    """
    :type matrix: List[List[int]]
    :rtype: None Do not return anything, modify matrix in-place instead.
    """
    dim = len(matrix)
    for row in range(dim):
        for col in range(row):
            temp = matrix[row][col]
            matrix[row][col] = matrix[col][row]
            matrix[col][row] = temp
    for row in range(dim):
        for col in range(int(dim/2)):
            temp = matrix[row][col]
            matrix[row][col] = matrix[row][dim-col-1]
            matrix[row][dim-col-1] = temp


matrix = [
    [5, 1, 9, 11],
    [2, 4, 8, 10],
    [13, 3, 6, 7],
    [15, 14, 12, 16]
]
rotate(matrix)
