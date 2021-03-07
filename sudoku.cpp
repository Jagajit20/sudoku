#include <bits/stdc++.h>
using namespace std;
void showMatrix(vector<vector<int>> matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size(); j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>> matrix, int row, int col, int value) {
    for(int j = 0; j < matrix.size(); j++) {
        if(matrix[row][j] == value)                 // checking in rows
            return false;
    }
    for(int j = 0; j < matrix.size(); j++) {
        if(matrix[j][col] == value)                 // checking in columns
            return false;
    }
    int square = sqrt(matrix.size());               // for finding the square we are working with
    row = row - (row % square);
    col = col - (col % square);
    for(int i = row; i < row + square; i++) {
        for(int j = col; j < col + square; j++) {
            if(matrix[i][j] == value)
                return false;
        }
    }
    return true;
}
bool backtrack(vector<vector<int>> &matrix) {
    int row = -1, col = -1;
    bool isZero = false;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size(); j++) {
            if(matrix[i][j] == 0) {
                row = i;
                col = j;
                isZero = true;
                break;
            }
        }
        if(isZero == true)
            break;
    }    
    if(isZero == false)
        return true;
    for(int i = 1; i <= matrix.size(); i++) {
        if(isSafe(matrix, row, col, i)) {
            matrix[row][col] = i;
            if(backtrack(matrix) == true)
                return true;
            else
                matrix[row][col] = 0;
        }
    }
    return false;
}
int main() {
    int N;
    cout<<"Enter the dimensions of the matrix: ";
    cin>>N;
    vector<vector<int>> matrix(N, vector<int> (N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin>>matrix[i][j];
        }
    }
    cout<<endl;
    cout<<"Answer or given sudoku is: "<<endl;
    backtrack(matrix);
    showMatrix(matrix);
    return 0;
} 