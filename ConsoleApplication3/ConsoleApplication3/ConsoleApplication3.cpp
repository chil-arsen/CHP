// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>


using namespace std;

// Define moves for the knight
const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Check if a position is valid on the board
bool isValid(int x, int y, int N, vector<vector<int>>& board) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

// Warnsdorff's rule to find the next move
int findNextMove(int x, int y, int N, vector<vector<int>>& board) {
    int minDegIdx = -1, minDeg = INT_MAX;

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, N, board)) {
            int deg = 0;
            for (int j = 0; j < 8; ++j) {
                int nextX = newX + dx[j];
                int nextY = newY + dy[j];
                if (isValid(nextX, nextY, N, board))
                    deg++;
            }

            if (deg < minDeg) {
                minDeg = deg;
                minDegIdx = i;
            }
        }
    }

    return minDegIdx;
}

// Knight's tour using Warnsdorff's algorithm
bool knightTour(int x, int y, int moveCount, int N, vector<vector<int>>& board) {
    if (moveCount == N * N)
        return true;

    int nextX, nextY;

    int nextMove = findNextMove(x, y, N, board);
    if (nextMove == -1)
        return false;

    nextX = x + dx[nextMove];
    nextY = y + dy[nextMove];

    board[nextX][nextY] = moveCount;

    if (knightTour(nextX, nextY, moveCount + 1, N, board))
        return true;

    board[nextX][nextY] = -1;

    return false;
}

// Function to solve Knight's tour problem
void solveKnightTour(int N) {
    // Initialize the chessboard
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Start from position (0, 0)
    int startX = 0, startY = 0;
    board[startX][startY] = 0; // Knight starts at move 0

    if (knightTour(startX, startY, 1, N, board)) {
        // Print the solution
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution exists!" << endl;
    }
}

int main() {
    int N;
    cout << "Enter the size of the board: ";
    cin >> N;

    solveKnightTour(N);

    return 0;
}
