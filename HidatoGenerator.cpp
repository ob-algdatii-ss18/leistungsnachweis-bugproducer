#include "HidatoGenerator.h"
#include <vector>

using namespace std;

std::vector<std::vector<int>> HidatoGenerator::generateField() {
    int counter = 1;
    playGround = std::vector<std::vector<int>>(4,vector<int>(4));

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            playGround[i][j]=counter++;
        }
    }
    return playGround;
}
