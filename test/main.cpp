#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


//#include <iostream>
//#include "../hidato/PlayGround.h"
//using namespace std;
//
//int main() {
//
//    vector<vector<int>> result;
//    auto *gen = new PlayGround();
//    result = gen->generateField(5);
//
//
//    for(int i=0; i<5; i++){
//        for(int j=0; j<5; j++){
//            cout << result[i][j]<< "  ";
//        }
//            cout << endl;
//    }
//
//
//    return 0;
//}