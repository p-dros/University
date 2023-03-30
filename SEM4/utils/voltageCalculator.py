R_1 = 2992
R_2 = 1536

while (True):
    print("Type U_we")
    U_we = float(input())
    U_wy = (U_we * R_2) / (R_1 + R_2)
    print("U_wy = ", U_wy)