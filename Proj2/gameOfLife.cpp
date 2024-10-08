#include<vector>
#include <iostream>
using namespace std;

using VEC = vector<int>;
using MATRIX = vector<VEC>;
//make a matrix
static MATRIX makeMat() {
    int col, row = 0;
    cout << "how big do your want your matrix to be?";
    cout << "your row is: ";
    cin >> row;
    cout << "your coloumn is: ";
    cin >> col;

    return MATRIX m(row, VEC(col, 0));
}
//place cells
static MATRIX placeCells() {

}
//printing my matrix
static void printMat() {
    makeMat();


}


int main()
{
    printMat();
}


