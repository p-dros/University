import tkinter as tk

def read_input(file_path):
    with open(file_path, 'r') as file:
        size = int(file.readline().strip())
        grid = [list(map(int, file.readline().split())) for _ in range(size)]
    return size, grid

def find_largest_empty_rectangle(size, grid):
    max_area = 0
    max_coords = (0, 0, 0, 0)  # (start_row, start_col, width, height)

    for i in range(size):
        for j in range(size):
            if grid[i][j] == 0:
                height = 1
                while i + height < size and grid[i + height][j] == 0:
                    width = 1
                    while j + width < size and all(grid[i + k][j:j + width + 1] == [0] * (width + 1) for k in range(1, height + 1)):
                        width += 1
                    area = width * height
                    if area > max_area:
                        max_area = area
                        max_coords = (i, j, width, height)
                    height += 1

    return max_area, max_coords

def draw_grid_with_rectangle(size, grid, rectangle_coords):
    root = tk.Tk()
    canvas = tk.Canvas(root, width=size * 20, height=size * 20)
    canvas.pack()

    for i in range(size):
        for j in range(size):
            color = "black" if grid[i][j] == 1 else "white"
            canvas.create_rectangle(j * 20, i * 20, (j + 1) * 20, (i + 1) * 20, fill=color)

    if rectangle_coords:
        i, j, width, height = rectangle_coords
        for k in range(i+1, i + height+1):
            for l in range(j, j + width):
                canvas.create_rectangle(l * 20, k * 20, (l + 1) * 20, (k + 1) * 20, outline="blue", width=2)

    root.mainloop()

if __name__ == "__main__":
    file_path = "zadanie5_input.txt"
    size, grid = read_input(file_path)
    max_rectangle_area, max_rectangle_coords = find_largest_empty_rectangle(size, grid)
    print(f"Największy prostokąt ma pole powierzchni: {max_rectangle_area}")

    draw_grid_with_rectangle(size, grid, max_rectangle_coords)
