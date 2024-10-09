#include<vector>
#include <iostream>
using namespace std;

using VEC = vector<int>;
using MATRIX = vector<VEC>;
//make a matrix
static MATRIX makeMat(int &row, int &col) {
    cout << "how big do your want your matrix to be? \n";
    cout << "your row is: ";
    cin >> row;
    cout << "your coloumn is: ";
    cin >> col;
    MATRIX m(row, VEC(col, 0));
    cout << endl;
    return m;
}
//printing my matrix
static void printMat(MATRIX curr) {

    for (auto y = 0; y < curr[0].size(); y++) {
        for (auto x = 0; x < curr[y].size(); x++) {
            cout << curr[y][x];
        }
        cout << endl;
    }
    cout << endl;
}
//place cells
static void placeCells(MATRIX &curr) {
    cout << "where do you want to place your cells: ";
    int col, row, cell = 0;
    cin >> cell;
    for (auto i = 0; i < cell; i++) {
        cin >> row;
        cin >> col;
        curr[row][col] = 1;
    }
    cout << endl;
}
//rules
static void rules(MATRIX &curr, int &row, int &col) {
    for (auto y = 0; y < curr[0].size(); y++) {
        for (auto x = 0; x < curr[y].size(); x++) {
            
        } 
    } 
}


int main()
{
    int row, col = 0;
    MATRIX currentMat = makeMat(row, col);
    printMat(currentMat);
    placeCells(currentMat);
    printMat(currentMat);

}


