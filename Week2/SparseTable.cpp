
#include"SparseTable.h"

vector<vector<int>> buildSparseTable(vector<int> arr){
    vector<vector<int>> sparseTable;
    sparseTable.resize(arr.size(), vector<int>(arr.size()));

    for (int i = 0; i < arr.size(); i++){
        sparseTable[i][0] = arr[i];
    }

    for (int j = 1; (1 << j) <= arr.size(); j ++){
        for (int i = 0; i < arr.size() - (1 << j) + 1; i++ ){
            sparseTable[i][j] = min(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
    return sparseTable;
}

void printSparseTable(vector<vector<int>> matrix){
    
    for (int i = 0; i < matrix.size(); i++){
        
        for (int j = 0; j < matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int findMin(vector<vector<int>> sparseTable, int begin, int end){
    int j = (int) log2(end - begin + 1);

    return min(sparseTable[begin][j], sparseTable[begin - (1 << j) + 1][j]);
}

