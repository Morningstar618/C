/*

#############################
######### Example ###########
#############################

        [1 2 3 4 5]
        [6 1 2 3 4]
        [7 6 1 2 3]
        [8 7 6 1 2]
        [9 8 7 6 1]

In this type of Matrix, all the elements in a diagonal are equal.

CONDITION:
    M[i][j] == M[i-1][j-1]

STORAGE:
    We only need to store the first row and the first column from a Toeplitz matrix
    as the rest of the elements can be determined from them as they lay on a diagonal.

    Therefore, total elements = 2n - 1

    The elements will be stored in two parts in an array. First is, the upper triangle matrix [i <= j],
    Second is, lower triangular matrix [i > j].

INDEX:
    Case 1: Upper Triangular Matrix [i <= j]    Index = j - i
    Case 2: Lower Triangular Matrix [i > j]     Index = n + i - j - 1


*/