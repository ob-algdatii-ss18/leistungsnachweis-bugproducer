#include <iostream>
#include "HidatoGenerator.h"
using namespace std;

int main() {

    vector<vector<int>> result;
    auto *gen = new HidatoGenerator();
    result = gen->generateField(5);


    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << result[i][j]<< "  ";
        }
            cout << endl;
    }


    return 0;
}