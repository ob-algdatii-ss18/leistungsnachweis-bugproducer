//
// Created by mark on 16.04.2018.
//

#include "testHidatoGenerator.h"

using namespace std;

TEST(HidatoGeneratorTest, Test_Generate){
vector<vector<int>> result;
    auto *gen = new HidatoGenerator();
    result = gen->generateField(5);


    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << result[i][j]<< "  ";
        }
            cout << endl;
    }
}