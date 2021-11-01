#ifndef SPARSETABLE_INCLUDED_H
#define SPARSETABLE_INCLUDED_H
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;
vector<vector<int>> buildSparseTable(vector<int> arr, int (*compare)(int, int));
void printSparseTable(vector<vector<int>> matrix);
int findMin(vector<vector<int>> sparseTable, int begin, int end, int (*compare)(int, int));
int MIN(int a, int b);
int MAX(int a, int b);
int GCD(int a, int b);
int toInt(char * s);
#endif