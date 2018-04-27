//
// Created by mark on 16.04.2018.
//

#include "testPlayGround.h"

using namespace std;

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopLeftPositionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {1, 4, 5};
    auto *gen = new PlayGround(4, 0);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {2, 6, 7};
    auto *gen = new PlayGround(4, 3);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnBottomLeftPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {8, 9, 13};
    auto *gen = new PlayGround(4, 12);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnBottomRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {10, 11, 14};
    auto *gen = new PlayGround(4, 15);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}


TEST(PlayGroundTest, shouldReturnFiveNeigboursOnTopMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 2, 4, 5, 6};
    auto *gen = new PlayGround(4, 1);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnBottomMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {8, 9, 10, 12, 14};
    auto *gen = new PlayGround(4, 13);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnMiddleRightPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {2, 3, 6, 10, 11};
    auto *gen = new PlayGround(4, 7);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnEightNeigboursOnMiddleMiddlePostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 1, 2, 4, 6, 8, 9, 10};
    auto *gen = new PlayGround(4, 5);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}

TEST(PlayGroundTest, shouldReturnFiveNeigboursOnMiddleLeftPostionWithEmptyPlayGround) {
    vector<int> expectedNeighbours = {0, 1, 5, 8, 9};
    auto *gen = new PlayGround(4, 4);
    gen->generateField();
    vector<int> haveNeighbours = gen->calcNeighbours(0);
    ASSERT_EQ(expectedNeighbours.size(), haveNeighbours.size());
    for (int i = 0; i < expectedNeighbours.size(); i++) {
        ASSERT_EQ(expectedNeighbours[i], haveNeighbours[i]);
    }
}
//
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
