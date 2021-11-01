
#include"SparseTable.h"
#include<algorithm>
int toInt(char * s){
    int i = 0, num = 0;
    if (s[0] == '-'){
        i ++;
    }
    while (s[i] != '\0'){
        num = num * 10 + (s[i] - '0');
        i++;
    }
    if (s[0] == '-'){
        return -num;
    }
    return num;
}
int MIN(int a,int b){
    return min(a, b);
}

int MAX(int a, int b){
    return max(a, b);
}

int GCD(int a, int b){
    if (b == 0){
        return a;
    }
    
    if (a % b == 0){
        return b;
    }

    return GCD(b, abs(a - b));
}

vector<vector<int>> buildSparseTable(vector<int> arr, int (*compare)(int, int)){
    vector<vector<int>> sparseTable;
    sparseTable.resize(arr.size(), vector<int>(arr.size()));

    for (int i = 0; i < arr.size(); i++){
        sparseTable[i][0] = arr[i];
    }

    for (int j = 1; (1 << j) <= arr.size(); j ++){
        for (int i = 0; i < arr.size() - (1 << j) + 1; i++ ){
            sparseTable[i][j] = compare(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
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

int findMin(vector<vector<int>> sparseTable, int begin, int end, int (*compare)(int, int)){
    int j = (int) log2(end - begin + 1);

    return compare(sparseTable[begin][j], sparseTable[end - (1 << j) + 1][j]);
}

