/*

#############################
######### Example ###########
#############################

        [1 1 0 0 0]
        [1 2 2 0 0]
        [0 2 3 3 0]
        [0 0 3 4 4]
        [0 0 0 4 5]

CONDITION:
    M[i, j] != 0 if |i - j| <= 1
    M[i, j] == 0 if |i - j| > 1


NUMBER OF NON-ZERO ELEMENTS = 3n - 2


STORAGE IN MEMORY: Can be stored diagonal by diagonal. Like for example starting from Lower, then Main, then Upper Diagonal.
        {a21, a32, a43, a54, a11, a22, a33, a44, a55, a12, a23, a34, a45}


INDEX: (M[i][j])
    Case 1  if i - j = 1    `index = i - 1`
    Case 2  if i - j = 0    `index = (n - 1) + (i - 1)`
    Case 3  if i - j = -1   `index = (2n - 1) + (i - 1)`



#################################
###### SQUARE BAND MATRIX #######
#################################

Similar to TriDiagonal Matrix with the only difference being that there are more than one
lower and upper diagonals alongside the main diagonal.

*/