//
// Created by mark on 16.04.2018.
//

#include "testPlayGround.h"

using namespace std;

TEST(PlayGroundTest, Test_Generate) {
    auto *gen = new PlayGround(4, -1);
    gen->generateField();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << gen->getPlayGround()[i][j] << "  ";
        }
        cout << endl;
    }

}