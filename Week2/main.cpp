#include"SparseTable.h"
#include<fstream>

struct SparseTable{
    string compare;
    string name;
    vector<vector<int>> data;
};

int main(int argc, char** argv){
    vector<SparseTable> tbs;

    // Read table from database
    fstream f("Database", ios::in);
    
    int n_tbs;
    f>>n_tbs;
    tbs.resize(n_tbs);

    for (int i = 0; i < n_tbs; i++){
        f>>tbs[i].name;
        f>>tbs[i].compare;
        int m, n;

        f>>m>>n;

        tbs[i].data.resize(m, vector<int>(n));
        
        for (int j = 0; j < m; j++){
            for (int k = 0; k < n; k++){
                f>>tbs[i].data[j][k];
            }
        }
    }

    string name = argv[2];
    string req = argv[1];
    
    // solve problem
    if (req == "query"){
        
        int i = 0, l = toInt(argv[3]), r = toInt(argv[4]);

        while (i < n_tbs) {
            if (tbs[i].name == name){
                
                break;
            }
            i++;
        }
        
        if (tbs[i].compare == "MIN"){
            cout<<findMin(tbs[i].data, l, r, MIN)<<endl;
        }
        else if (tbs[i].compare == "MAX"){
            cout<<findMin(tbs[i].data, l, r, MAX)<<endl;
        }
        else{
            cout<<findMin(tbs[i].data, l, r, GCD)<<endl;
        }

    }
    else{
        
        vector<int> nums;
        for (int i = 4; i < argc; i++){
            nums.push_back(toInt(argv[i]));
        }

        SparseTable sp_tb;

        sp_tb.name = argv[2];
        sp_tb.compare = argv[3];

        if (sp_tb.compare == "MIN"){
            sp_tb.data = buildSparseTable(nums, MIN);
        }
        else if (sp_tb.compare == "MAX"){
            sp_tb.data = buildSparseTable(nums, MAX);
        }
        else{
            sp_tb.data = buildSparseTable(nums, GCD);
        }
        
        bool flag = 0;
        for (int i = 0; i < n_tbs; i++){
            if (tbs[i].name == sp_tb.name){
                flag = 1;
                tbs[i] = sp_tb;
                break;
            }
        }
        
        if (flag == 0){
            tbs.push_back(sp_tb);
        }

        cout<<sp_tb.name<<" "<<sp_tb.compare<<endl;
        printSparseTable(sp_tb.data);
        cout<<endl;
    }
    f.close();

    // Write table to database
    fstream f2("Database", ios::out);

    f2<<tbs.size()<<endl;

    for (int i = 0; i < tbs.size(); i++){
        f2<<tbs[i].name<<" "<<tbs[i].compare<<endl;
        f2<<tbs[i].data.size()<<" "<<tbs[i].data[0].size()<<endl;

        for (int j = 0; j < tbs[i].data.size(); j++){
            for (int k = 0; k < tbs[i].data[j].size(); k++){
                f2<<tbs[i].data[j][k]<<" ";
            }
            f2<<endl;
        }

    }
    f2.close();

    // main make B GCD 12 14 16 8 4 6 10 20 100 -25 200 1000
    // main query B 3 4
    // main make C MAX 1 8 2 5 9 9 10 15 -7 6 700 -255 15 23 999
    // main query B 7 11
    // main query C 4 9
    // main query C 1 7
}
