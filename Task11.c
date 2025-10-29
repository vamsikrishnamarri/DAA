#include <stdio.h>
#include <stdlib.h>

#define N 8

int board[N][N];

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return 0;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return 0;
    return 1;
}

int solveNQueens(int col) {
    if (col >= N) return 1;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQueens(col + 1)) return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

// Rat in Maze
#define MAZE_SIZE 4
int maze[MAZE_SIZE][MAZE_SIZE] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};
int sol[MAZE_SIZE][MAZE_SIZE];

int isSafeMaze(int x, int y) {
    return (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && maze[x][y] == 1);
}

int solveMazeUtil(int x, int y) {
    if (x == MAZE_SIZE - 1 && y == MAZE_SIZE - 1) {
        sol[x][y] = 1;
        return 1;
    }
    if (isSafeMaze(x, y)) {
        sol[x][y] = 1;
        if (solveMazeUtil(x + 1, y)) return 1;
        if (solveMazeUtil(x, y + 1)) return 1;
        sol[x][y] = 0;
        return 0;
    }
    return 0;
}

void solveMaze() {
    if (solveMazeUtil(0, 0)) {
        printf("Maze Solution:\n");
        for (int i = 0; i < MAZE_SIZE; i++) {
            for (int j = 0; j < MAZE_SIZE; j++) {
                printf("%d ", sol[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution\n");
    }
}

int main() {
    printf("Test Case 1: Rat in Maze\n");
    solveMaze();

    printf("\nTest Case 2: N-Queens for n=1 to 3\n");
    for (int n = 1; n <= 3; n++) {
        printf("N=%d:\n", n);
        if (solveNQueens(0)) {
            printBoard();
        } else {
            printf("No solution\n");
        }
    }

    return 0;
}
