from collections import defaultdict
from typing import List, Tuple, Dict

BEST = float('inf')
dir = {
    'U': (-1, 0),
    'D': (1, 0),
    'L': (0, -1),
    'R': (0, 1)
}

outposts = {}


def print_grids(grid_fl: bool, cov_grid_fl: bool, grid: List[List[str]], cov_grid: List[List[int]]):
    if grid_fl:
        print('Grid:')
        for row in grid:
            print(' '.join(row))
    if cov_grid_fl:
        print('Cov Grid:')
        for row in cov_grid:
            print(' '.join(map(str, row)))
    print()


def in_range(x: int, y: int, max_x: int, max_y: int) -> bool:
    return 0 <= x < max_x and 0 <= y < max_y


def valid(x: int, y: int, grid: List[List[str]], cov_grid: List[List[int]]) -> bool:
    return (
        in_range(x, y, len(grid), len(grid[0])) and
        cov_grid[x][y] == 0 and
        grid[x][y] == '.'
    )

def remove_turret(x: int, y: int, grid: List[List[str]], cov_grid: List[List[int]]):
    cov_grid[x][y] -= 1
    grid[x][y] = '.'
    for direction, (dx, dy) in dir.items():
        nx, ny = x + dx, y + dy
        while in_range(nx, ny, len(grid), len(grid[0])) and grid[nx][ny] != '#' and not ('0' <= grid[nx][ny] <= '4'):
            cov_grid[nx][ny] -= 1
            nx += dx
            ny += dy

def place_turret(x: int, y: int, grid: List[List[str]], cov_grid: List[List[int]]) -> int:
    if grid[x][y] in 'x#I' or ('0' <= grid[x][y] <= '4'):
        return 0

    new_covered = 0
    cov_grid[x][y] += 1
    if cov_grid[x][y] == 1:
        new_covered += 1

    grid[x][y] = 'x'

    for direction, (dx, dy) in dir.items():
        nx, ny = x + dx, y + dy
        while in_range(nx, ny, len(grid), len(grid[0])) and grid[nx][ny] != '#' and not ('0' <= grid[nx][ny] <= '4'):
            cov_grid[nx][ny] += 1
            if cov_grid[nx][ny] == 1:
                new_covered += 1
            nx += dx
            ny += dy

    for (o_x, o_y), required in outposts.items():
        t_count, empty_count = 0, 0
        for dx, dy in dir.values():
            nx, ny = o_x + dx, o_y + dy
            if in_range(nx, ny, len(grid), len(grid[0])):
                if grid[nx][ny] == 'x':
                    t_count += 1
                elif grid[nx][ny] == '.' and cov_grid[nx][ny] == 0:
                    empty_count += 1

        if t_count > required or (t_count + empty_count < required):
            remove_turret(x, y, grid, cov_grid)
            return 0

    return new_covered


def detect_mandatory_turrets(grid: List[List[str]]) -> List[Tuple[int, int]]:
    mandatory_positions = []
    R, C = len(grid), len(grid[0])
    
    for i in range(R):
        for j in range(C):
            if '0' <= grid[i][j] <= '4':
                required = int(grid[i][j])
                empty_cells = 0
                empty_positions = []

                for dx, dy in dir.values():
                    ni, nj = i + dx, j + dy
                    if in_range(ni, nj, R, C) and grid[ni][nj] == '.':
                        empty_cells += 1
                        empty_positions.append((ni, nj))

                if empty_cells == required:
                    mandatory_positions.extend(empty_positions)
    return mandatory_positions


def validate_leaf(grid: List[List[str]], cov_grid: List[List[int]], uncovered_cells: int) -> bool:
    if uncovered_cells != 0:
        return False

    for (x, y), required in outposts.items():
        if not check_around_outpost(x, y, grid):
            return False

    return True


def rec(cur_grid: List[List[str]], cov_grid: List[List[int]], cur_cell: int, cur_cost: int, uncovered_cells: int):
    global BEST

    if cur_cost >= BEST:
        return

    max_x, max_y = len(cur_grid), len(cur_grid[0])

    if cur_cell == max_x * max_y:
        if validate_leaf(cur_grid, cov_grid, uncovered_cells):
            BEST = cur_cost
        return

    cur_x, cur_y = divmod(cur_cell, max_y)

    if cur_grid[cur_x][cur_y] != '.' or cov_grid[cur_x][cur_y] > 0:
        rec(cur_grid, cov_grid, cur_cell + 1, cur_cost, uncovered_cells)
        return

    if valid(cur_x, cur_y, cur_grid, cov_grid):
        new_covered = place_turret(cur_x, cur_y, cur_grid, cov_grid)

        if new_covered > 0:
            rec(cur_grid, cov_grid, cur_cell + 1, cur_cost + 1, uncovered_cells - new_covered)
            remove_turret(cur_x, cur_y, cur_grid, cov_grid)

    rec(cur_grid, cov_grid, cur_cell + 1, cur_cost, uncovered_cells)


def main():
    global BEST, outposts

    t = int(input())

    for _ in range(t):
        BEST = float('inf')
        R, C = map(int, input().split())
        grid = [list(input().strip()) for _ in range(R)]
        cov_grid = [[0] * C for _ in range(R)]

        uncovered_cells = sum(row.count('.') for row in grid)

        outposts.clear()
        for i in range(R):
            for j in range(C):
                if '0' <= grid[i][j] <= '4':
                    outposts[(i, j)] = int(grid[i][j])

        rec(grid, cov_grid, 0, 0, uncovered_cells)

        if BEST == float('inf'):
            print('noxus will rise!')
        else:
            print(BEST)


if __name__ == '__main__':
    main()