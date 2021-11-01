#include"SparseTable.h"

void testSparseTable(){
    vector<vector<int>> sparseTable = buildSparseTable({ 7, 2, 3, 0, 5, 10, 3, 12, 18 });
       
    cout<<findMin(sparseTable, 3, 7);
}

int main(){
    testSparseTable();
}
