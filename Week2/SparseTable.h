#ifndef SPARSETABLE_INCLUDED_H
#define SPARSETABLE_INCLUDED_H
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;
vector<vector<int>> buildSparseTable(vector<int> arr);
void printSparseTable(vector<vector<int>> matrix);
int findMin(vector<vector<int>> sparseTable, int begin, int end);

#endif