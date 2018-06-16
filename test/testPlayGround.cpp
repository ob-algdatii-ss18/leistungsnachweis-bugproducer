#include "testPlayGround.h"

using namespace std;
static const int FIELDSIZE = 4;


TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopLeftPositionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {1, 4, 5};
    auto *gen = new PlayGround(4, 0);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(0, false,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {2, 6, 7};
    auto *gen = new PlayGround(4, 3);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(3, false,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnBottomLeftPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {8, 9, 13};
    auto *gen = new PlayGround(4, 12);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(12, false,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnBottomRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {10, 11, 14};
    auto *gen = new PlayGround(4, 15);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(15, false,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnTopMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 2, 4, 5, 6};
    auto *gen = new PlayGround(4, 1);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(1, false,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnBottomMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {8, 9, 10, 12, 14};
    auto *gen = new PlayGround(4, 13);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(13, false,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnMiddleRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {2, 3, 6, 10, 11};
    auto *gen = new PlayGround(4, 7);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(7, false,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnEightNeigboursOnMiddleMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 1, 2, 4, 6, 8, 9, 10};
    auto *gen = new PlayGround(4, 5);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(5, false,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnMiddleLeftPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 1, 5, 8, 9};
    auto *gen = new PlayGround(4, 4);
    gen->generatePlayground();
    vector<int> haveNeighbours = gen->calcNeighbours(4, false,gen->getPlayGroundSolved());
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
            filledPlayground[i][j] = i * FIELDSIZE + j + 1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(0, true,gen->getPlayGroundSolved());
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
            filledPlayground[i][j] = i * FIELDSIZE + j + 1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(13, true,gen->getPlayGroundSolved());
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
            filledPlayground[i][j] = i * FIELDSIZE + j + 1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(7, true,gen->getPlayGroundSolved());
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
            filledPlayground[i][j] = i * FIELDSIZE + j + 1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(5, true,gen->getPlayGroundSolved());
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
            filledPlayground[i][j] = i * FIELDSIZE + j + 1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(4, true,gen->getPlayGroundSolved());
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
            filledPlayground[i][j] = i * FIELDSIZE + j + 1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(3, true,gen->getPlayGroundSolved());
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
            filledPlayground[i][j] = i * FIELDSIZE + j + 1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(12, true,gen->getPlayGroundSolved());
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
            filledPlayground[i][j] = i * FIELDSIZE + j + 1;
        }
    }

    gen->setPlayGroundSolved(filledPlayground);
    vector<int> haveNeighbours = gen->calcNeighbours(15, true,gen->getPlayGroundSolved());
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}


TEST(PlayGroundTest, shouldGenerateValidFilledPlayGround) {
    auto *gen = new PlayGround(4, -1);
    gen->generatePlayground();
    gen->fillPlayGround();
    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));
    vector<int> adresses;
    filledPlayground = gen->getPlayGroundSolved();
    adresses = gen->getNumberAddresses();

    for (int i = 0; i < adresses.size() - 1; i++) {
        vector<int> neighbours = gen->calcNeighbours(adresses[i], true,gen->getPlayGroundSolved());
        bool hasCorrectNeighbour = false;
        for (int j = 0; j < neighbours.size(); j++) {
            int address = neighbours[j];
            if (filledPlayground[address / FIELDSIZE][address % FIELDSIZE] == i + 2) {
                hasCorrectNeighbour = true;
            }
        }
        ASSERT_TRUE(hasCorrectNeighbour);
    }
}

TEST(PlayGroundTest, shouldGenerateValidUnsolvedPlayGround) {
    auto *gen = new PlayGround(4, 0);
    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    filledPlayground[0][0] = 1;
    filledPlayground[0][1] = 2;
    filledPlayground[0][2] = 3;
    filledPlayground[0][3] = 4;
    filledPlayground[1][3] = 5;
    filledPlayground[1][2] = 6;
    filledPlayground[1][1] = 7;
    filledPlayground[1][0] = 8;
    filledPlayground[2][0] = 9;
    filledPlayground[2][1] = 10;
    filledPlayground[2][2] = 11;
    filledPlayground[2][3] = 12;
    filledPlayground[3][3] = 13;
    filledPlayground[3][2] = 14;
    filledPlayground[3][1] = 15;
    filledPlayground[3][0] = 0;

    vector<vector<int>> filledPlaygroundDummy = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    filledPlaygroundDummy[0][0] = 1;
    filledPlaygroundDummy[0][1] = 0;
    filledPlaygroundDummy[0][2] = 0;
    filledPlaygroundDummy[0][3] = 0;
    filledPlaygroundDummy[1][3] = 0;
    filledPlaygroundDummy[1][2] = 0;
    filledPlaygroundDummy[1][1] = 7;
    filledPlaygroundDummy[1][0] = 0;
    filledPlaygroundDummy[2][0] = 0;
    filledPlaygroundDummy[2][1] = 0;
    filledPlaygroundDummy[2][2] = 0;
    filledPlaygroundDummy[2][3] = 0;
    filledPlaygroundDummy[3][3] = 13;
    filledPlaygroundDummy[3][2] = 0;
    filledPlaygroundDummy[3][1] = 15;
    filledPlaygroundDummy[3][0] = -1;

    vector<int> numberAddresses {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13};

    gen->setPlayGroundSolved(filledPlayground);
    gen->setNumberAddresses(numberAddresses);
    gen->generateUnsolvedPlayground();

    vector<vector<int>> unsolvedPlayground = gen->getPlayGroundUnsolved();

    ASSERT_EQ(unsolvedPlayground, filledPlaygroundDummy);
}


TEST(PlayGroundTest, shouldCheckValidSolution) {
    auto *gen = new PlayGround(4, 0);
    vector<vector<int>> filledPlayground = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));
    vector<vector<int>> filledPlayground1 = vector<vector<int>>(FIELDSIZE, vector<int>(FIELDSIZE));

    filledPlayground[0][0] = 1;
    filledPlayground[0][1] = 2;
    filledPlayground[0][2] = 3;
    filledPlayground[0][3] = 4;
    filledPlayground[1][3] = 5;
    filledPlayground[1][2] = 6;
    filledPlayground[1][1] = 7;
    filledPlayground[1][0] = 8;
    filledPlayground[2][0] = 9;
    filledPlayground[2][1] = 10;
    filledPlayground[2][2] = 11;
    filledPlayground[2][3] = 12;
    filledPlayground[3][3] = 13;
    filledPlayground[3][2] = 14;
    filledPlayground[3][1] = 15;
    filledPlayground[3][0] = 0;

    filledPlayground1[0][0] = 1;
    filledPlayground1[0][1] = 2;
    filledPlayground1[0][2] = 3;
    filledPlayground1[0][3] = 4;
    filledPlayground1[1][3] = 5;
    filledPlayground1[1][2] = 6;
    filledPlayground1[1][1] = 7;
    filledPlayground1[1][0] = 8;
    filledPlayground1[2][0] = 9;
    filledPlayground1[2][1] = 10;
    filledPlayground1[2][2] = 11;
    filledPlayground1[2][3] = 12;
    filledPlayground1[3][3] = 13;
    filledPlayground1[3][2] = 14;
    filledPlayground1[3][1] = 15;
    filledPlayground1[3][0] = 0;



    vector<int> numberAddresses {0,1,2,3,7,6,5,4,8,9,10,11,15,14,13};

    gen->setPlayGroundSolved(filledPlayground);

    gen->setDensityCounter(15);


    gen->setPlayGroundPlayerSolution(filledPlayground1);

    vector<vector<int>> unsolvedPlayground = gen->getPlayGroundUnsolved();

    ASSERT_TRUE(gen->checkSolution());
}
