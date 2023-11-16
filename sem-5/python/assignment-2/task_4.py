def get_cuboid_permutations(x: int, y: int, z: int, n: int):
    return [
        [i, j, k]
        for i in range(x + 1)
        for j in range(y + 1)
        for k in range(z + 1)
        if i + j + k != n
    ]


if __name__ == "__main__":
    x, y, z, n = map(int, input("Podaj x, y, z, n (oddzielone spacją): ").split())
    print(get_cuboid_permutations(x, y, z, n))
