#include "PlayGround.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

PlayGround::PlayGround(unsigned int fieldSize, int isRandom) {
    this->fieldSize = fieldSize;
    this->isRandom = isRandom;

}

unsigned int PlayGround::getSize() {
    return 0;
}

void PlayGround::generateField() {

    playGround = vector<vector<int>>(fieldSize, vector<int>(fieldSize));

    for (unsigned int i = 0; i < fieldSize; i++) {

        vector<int> d = playGround.at(i);
        fill(d.begin(), d.end(), 0);
    }

    setStartPoint();
    calcNeighbours();

/*
    for (unsigned int i = 0; i < getNeighbours().size(); i++) {
        cout << calcNeighbours().at(i) << "\n";
    }*/
}

void PlayGround::setStartPoint() {

    fieldCounter = 1;

    srand((unsigned int) time(0));


    if (isRandom == -1) {
        currentPosition = (rand() % (fieldSize * fieldSize));
    } else {
        currentPosition = isRandom;
    }

    playGround.at(currentPosition / fieldSize).at(currentPosition % fieldSize) = fieldCounter++;
}

vector<int> PlayGround::calcNeighbours() {

    neighbours.clear();


    playGround.at(currentPosition / fieldSize).at(currentPosition % fieldSize);

    // keine Nachbarn darüber, erste Zeile
    if (currentPosition < fieldSize) {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            hasRightNeighbour(neighbours);
            hasBottomNeighbour(neighbours);
            hasBottomRightNeighbour(neighbours);
        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            hasLeftNeighbour(neighbours);
            hasBottomLeftNeighbour(neighbours);
            hasBottomNeighbour(neighbours);

        } else {
            hasLeftNeighbour(neighbours);
            hasRightNeighbour(neighbours);
            hasBottomLeftNeighbour(neighbours);
            hasBottomNeighbour(neighbours);
            hasBottomRightNeighbour(neighbours);
        }
    }
        // keine Nachbarn darunter, letzte Zeile
    else if (currentPosition >= ((fieldSize - 1) * fieldSize)) {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            hasTopNeighbour(neighbours);
            hasTopRightNeighbour(neighbours);
            hasRightNeighbour(neighbours);

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours);
            hasTopNeighbour(neighbours);
            hasLeftNeighbour(neighbours);
        } else {
            hasTopLeftNeighbour(neighbours);
            hasTopNeighbour(neighbours);
            hasTopRightNeighbour(neighbours);
            hasLeftNeighbour(neighbours);
            hasRightNeighbour(neighbours);
        }
    } else {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            hasTopNeighbour(neighbours);
            hasTopRightNeighbour(neighbours);
            hasRightNeighbour(neighbours);
            hasBottomNeighbour(neighbours);
            hasBottomRightNeighbour(neighbours);

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours);
            hasTopNeighbour(neighbours);
            hasLeftNeighbour(neighbours);
            hasBottomLeftNeighbour(neighbours);
            hasBottomNeighbour(neighbours);

        } else {
            hasTopLeftNeighbour(neighbours);
            hasTopNeighbour(neighbours);
            hasTopRightNeighbour(neighbours);
            hasLeftNeighbour(neighbours);
            hasRightNeighbour(neighbours);
            hasBottomLeftNeighbour(neighbours);
            hasBottomNeighbour(neighbours);
            hasBottomRightNeighbour(neighbours);
        }
    }

    return neighbours;
}

const vector<int> &PlayGround::getNeighbours() const {
    return neighbours;
}

void PlayGround::hasTopLeftNeighbour(vector<int> &neighbours) const {
    if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize - 1);
    }
}

void PlayGround::hasTopRightNeighbour(vector<int> &neighbours) const {
    if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize + 1);
    }
}

void PlayGround::hasTopNeighbour(vector<int> &neighbours) const {
    if (playGround.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize);
    }
}

void PlayGround::hasBottomLeftNeighbour(vector<int> &neighbours) const {
    if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition + fieldSize - 1);
    }
}

void PlayGround::hasLeftNeighbour(vector<int> &neighbours) const {
    if (playGround.at(currentPosition / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - 1);
    }
}

void PlayGround::hasBottomRightNeighbour(vector<int> &neighbours) const {
    if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) ==
        0) {
        neighbours.push_back(currentPosition + fieldSize + 1);
    }
}

void PlayGround::hasBottomNeighbour(vector<int> &neighbours) const {
    if (playGround.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
        neighbours.push_back(currentPosition + fieldSize);
    }
}

void PlayGround::hasRightNeighbour(vector<int> &neighbours) const {
    if (playGround.at(currentPosition / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition + 1);
    }
}

std::vector<std::vector<int>> PlayGround::getPlayGround() {
    return playGround;
}

void PlayGround::fillPlayGround() {
    int nextPosition;

    while (getNeighbours().size() != 0) {
        nextPosition = (rand() % (getNeighbours().size()));
        nextPosition = getNeighbours()[nextPosition];
        if (playGround[nextPosition / fieldSize][nextPosition % fieldSize] == 0) {
            playGround[nextPosition / fieldSize][nextPosition % fieldSize] = fieldCounter++;
            currentPosition = nextPosition;
            calcNeighbours();
        }

    }
    if(!checkDensity()){
        for(int i=0; i < fieldSize; i++ ){
            for(int j=0; j < fieldSize; j++ ){
               playGround[i][j]=0;
            }

        }

        setStartPoint();
        fillPlayGround();
    }

}

void PlayGround::printPlayGround() {
    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            cout << playGround[i][j] << "  ";
        }
        cout << endl;
    }


}

bool PlayGround::checkDensity() {
    float densityCounter=0;
    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if(playGround[i][j]!=0){
                densityCounter++;
            }
        }
    }
    return densityCounter / (float)(fieldSize * fieldSize) >= 0.9f;

}


