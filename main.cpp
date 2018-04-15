#include <iostream>
#include "HidatoGenerator.h"
using namespace std;

int main() {

    vector<vector<int>> result;
    auto *gen = new HidatoGenerator();
    result = gen->generateField(4);


    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << result[i][j]<< "  ";
        }
            cout << endl;
    }


    return 0;
}