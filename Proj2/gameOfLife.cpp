#include<vector>
#include <iostream>
using namespace std;

using VEC = vector<int>;
using MATRIX = vector<VEC>;
//make a matrix
static MATRIX makeMat() {
    int row, col = 0;
    cout << "how big do your want your matrix to be? \n";
    cout << "your row is: ";
    cin >> row;
    cout << "your coloumn is: ";
    cin >> col;
    MATRIX currentMat(row+2, VEC(col+2, 0));
    cout << endl;
    return currentMat;
}
//printing my matrix
static void printMat(MATRIX currentMat) {
    for (auto y = 2; y < currentMat[0].size(); y++) {
        for (auto x = 2; x < currentMat[y].size(); x++) {
            cout << currentMat[y][x];
        }
        cout << endl;
    }
    cout << endl;
}
//place cells
static void placeCells(MATRIX &currentMat) {
    cout << "where do you want to place your cells: ";
    int col, row, cell = 0;
    cin >> cell;
    for (auto i = 0; i < cell; i++) {
        cin >> row;
        cin >> col;
        currentMat[row+2][col+2] = 1;
    }
    cout << endl;
}
//rules
static void rules(MATRIX& copyMat, MATRIX& currentMat) {
 
    for (auto y = 2; y < currentMat[0].size(); y++) {
        cout << "im y\n";
        int i = 0;
        for (auto x = 2; x < currentMat[y].size(); x++) {
            cout << "im x \n";
            if (currentMat[y - 1][x] == 1)      //checks up
                i += 1;

            if (currentMat[y + 1][x] == 1)      //checks down
                i += 1;

            if (currentMat[y][x - 1] == 1)        // checks left
                i += 1;

            if (currentMat[y][x + 1] == 1)        //checks right
                i += 1;

            if (currentMat[y - 1][x - 1] == 1)    //checks left upper corner
                i += 1;

            if (currentMat[y - 1][x + 1] == 1)  //checks right upper corner
                i += 1;

            if (currentMat[y + 1][x - 1] == 1)  //checks left lower corner
                i += 1;

            if (currentMat[y + 1][x + 1] == 1)  //checks right lower corner
                i += 1;

            if (currentMat[y][x] == 1) {
                if (i < 2) {
                    copyMat[y][x] = 0;
                }
                else if ((i == 2) || (i == 3)) {
                    copyMat[y][x] = 1;
                }
                else {
                    copyMat[y][x] = 0;
                }
            }
            else if (currentMat[y][x] == 0) {
                if (i == 3) {
                    copyMat[y][x] = 1;
                }
                else {
                    copyMat[y][x] = 0;
                }
            }
        }

    }
    currentMat = copyMat;
}

int main()
{
    MATRIX currentMat = makeMat();
    printMat(currentMat);
    placeCells(currentMat);
    printMat(currentMat);

    MATRIX copyMat = currentMat;
    printMat(copyMat);
    rules(copyMat, currentMat);
    printMat(currentMat);


}


