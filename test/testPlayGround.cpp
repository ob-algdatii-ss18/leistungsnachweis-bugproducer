//
// Created by mark on 16.04.2018.
//

#include "testPlayGround.h"

using namespace std;

TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopRightPositionWithEmptyPlayGround) {
    vector<int> expectedNeigbours = {1,4,5};
    auto *gen = new PlayGround(4, 0);
    gen->generateField();
    vector<int> haveNeighbours = gen->getNeighbours();
    ASSERT_EQ(expectedNeigbours.size(),haveNeighbours.size());
    for(int i = 0; i<expectedNeigbours.size();i++){
        ASSERT_EQ(expectedNeigbours[i],haveNeighbours[i]);
    }

}


TEST(PlayGroundTest, shouldReturnThreeNeigboursOnTopLeftPosstionWithEmptyPlayGround) {
    vector<int> expectedNeigbours = {2,6,7};
    auto *gen = new PlayGround(4, 3);
    gen->generateField();
    vector<int> haveNeighbours = gen->getNeighbours();
    ASSERT_EQ(expectedNeigbours.size(),haveNeighbours.size());
    for(int i = 0; i<expectedNeigbours.size();i++){
        ASSERT_EQ(expectedNeigbours[i],haveNeighbours[i]);
    }

}