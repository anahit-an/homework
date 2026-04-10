#include <iostream>
using namespace std;
void Rotate (int matrix[][100], int size){
    for (int i=0;i<size/2;i++){
        for (int j=i;j<size - 1-i;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[size - 1-j][i];
            matrix[size - 1-j][i]=matrix[size - 1-i][size - 1-j];
            matrix[size - 1-i][size - 1-j]=matrix[j][size - 1-i];
            matrix[j][size - 1 -i]=temp;
        }
    }
}
int main() {
    int size=3;
    int matrix[100][100]={
        {1,2,3}, 
        {4,5,6},
        {7,8,9}
    };
    Rotate(matrix,size);
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
