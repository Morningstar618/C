/*

#############################
######### Example ###########
#############################

        [1 1 1 1 1]
        [1 2 2 2 2]
        [1 2 3 3 3]
        [1 2 3 4 4]
        [1 2 3 4 5]

CONDITION:
    M[i, j] = M[j, i]
    A[1, 3] = A[3, 1] = 1

We can utilize Lower Triangle Matrix to store data, as the rest of the data can be recovered by
reversing the Matrix indices.

        [1 0 0 0 0]
        [1 2 0 0 0]
        [1 2 3 0 0]     M[2, 4] = M[4, 2] = 2
        [1 2 3 4 0]
        [1 2 3 4 5]

*/