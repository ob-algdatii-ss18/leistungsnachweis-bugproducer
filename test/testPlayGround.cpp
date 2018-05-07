//
// Created by mark on 16.04.2018.
//

#include "testPlayGround.h"

using namespace std;

static const int FIELDSIZE =4;


TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopLeftPositionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {1, 4, 5};
    auto *gen = new PlayGround(4, 0);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {2, 6, 7};
    auto *gen = new PlayGround(4, 3);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(3, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnBottomLeftPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {8, 9, 13};
    auto *gen = new PlayGround(4, 12);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(12, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnBottomRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {10, 11, 14};
    auto *gen = new PlayGround(4, 15);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(15, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnTopMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 2, 4, 5, 6};
    auto *gen = new PlayGround(4, 1);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(1, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnBottomMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {8, 9, 10, 12, 14};
    auto *gen = new PlayGround(4, 13);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(13, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnMiddleRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {2, 3, 6, 10, 11};
    auto *gen = new PlayGround(4, 7);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(7, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnEightNeigboursOnMiddleMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 1, 2, 4, 6, 8, 9, 10};
    auto *gen = new PlayGround(4, 5);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(5, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnMiddleLeftPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 1, 5, 8, 9};
    auto *gen = new PlayGround(4, 4);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(4, false);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopLeftPositionWithFilledPlayground) {
    vector<int> expectedNeighbours = {1, 4, 5};
    auto *gen = new PlayGround(4, 0);
    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    for (int i = 0; i < FIELDSIZE; i++) {
        for (int j = 0; j < FIELDSIZE; j++) {
            filledPlayground[i][j] = i*FIELDSIZE+j+1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(0,true);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnBottomMiddlePostionWithFilledPlayGround) {
    vector<int> expectedNeighbours = {8, 9, 10, 12, 14};
    auto *gen = new PlayGround(4, 13);

    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    for (int i = 0; i < FIELDSIZE; i++) {
        for (int j = 0; j < FIELDSIZE; j++) {
            filledPlayground[i][j] = i*FIELDSIZE+j+1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(13, true);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnMiddleRightPostionWithFilledyPlayGround) {
    vector<int> expectedNeighbours = {2, 3, 6, 10, 11};
    auto *gen = new PlayGround(4, 7);

    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    for (int i = 0; i < FIELDSIZE; i++) {
        for (int j = 0; j < FIELDSIZE; j++) {
            filledPlayground[i][j] = i*FIELDSIZE+j+1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(7, true);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnEightNeigboursOnMiddleMiddlePostionWithFilledPlayGround) {
    vector<int> expectedNeighbours = {0, 1, 2, 4, 6, 8, 9, 10};
    auto *gen = new PlayGround(4, 5);

    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    for (int i = 0; i < FIELDSIZE; i++) {
        for (int j = 0; j < FIELDSIZE; j++) {
            filledPlayground[i][j] = i*FIELDSIZE+j+1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(5, true);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnMiddleLeftPostionWithFilledPlayGround) {
    vector<int> expectedNeighbours = {0, 1, 5, 8, 9};
    auto *gen = new PlayGround(4, 4);

    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    for (int i = 0; i < FIELDSIZE; i++) {
        for (int j = 0; j < FIELDSIZE; j++) {
            filledPlayground[i][j] = i*FIELDSIZE+j+1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(4, true);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopRightPostionWithFilledPlayGround) {
    vector<int> expectedNeighbours = {2, 6, 7};
    auto *gen = new PlayGround(4, 3);
    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    for (int i = 0; i < FIELDSIZE; i++) {
        for (int j = 0; j < FIELDSIZE; j++) {
            filledPlayground[i][j] = i*FIELDSIZE+j+1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(3, true);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnBottomLeftPostionWithFilledPlayGround) {
    vector<int> expectedNeighbours = {8, 9, 13};
    auto *gen = new PlayGround(4, 12);

    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    for (int i = 0; i < FIELDSIZE; i++) {
        for (int j = 0; j < FIELDSIZE; j++) {
            filledPlayground[i][j] = i*FIELDSIZE+j+1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(12, true);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnBottomRightPostionWithFilledPlayGround) {
    vector<int> expectedNeighbours = {10, 11, 14};
    auto *gen = new PlayGround(4, 15);
    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    for (int i = 0; i < FIELDSIZE; i++) {
        for (int j = 0; j < FIELDSIZE; j++) {
            filledPlayground[i][j] = i*FIELDSIZE+j+1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(15, true);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}


TEST(PlayGroundTest, shouldGenerateValidFilledPlayGround) {
    auto *gen = new PlayGround(4, -1);
    gen->generateField();
    gen->fillPlayGround();
    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));
    vector<int> adresses;
    filledPlayground = gen->getPlayGroundSolved();
    adresses = gen->getNumberAddresses();

    for(int i =0; i<adresses.size()-1; i++){
        vector<int> neighbours = gen->calcNeighbours(adresses[i],true);
        bool hasCorrectNeighbour = false;
        for(int j = 0; j < neighbours.size();j++){
            int address = neighbours[j];
            if(filledPlayground[address/FIELDSIZE][address%FIELDSIZE] == i+2){
                hasCorrectNeighbour = true;

            }

        }
        ASSERT_TRUE(hasCorrectNeighbour);
    }



}


//TEST(PlayGroundTest, test) {
//
//    for(int i = 0; i < 100; i++) {
//        cout << "\n" << endl;
//        auto *gen = new PlayGround(10, -1);
//        gen->generateField();
//        gen->fillPlayGround();
//        gen->printPlayGrounds();
//
//
//   }
//
//}
