#include "PlayGround.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(1,99); // guaranteed unbiased


PlayGround::PlayGround(unsigned int fieldSize, int isRandom) {
    this->fieldSize = fieldSize;
    this->isRandom = isRandom;
    this->runCounter = 1;

}

unsigned int PlayGround::getSize() {
    return 0;
}

void PlayGround::generateField() {

    playGroundSolved = vector<vector<int>>(fieldSize, vector<int>(fieldSize));

    for (unsigned int i = 0; i < fieldSize; i++) {

        vector<int> d = playGroundSolved.at(i);
        fill(d.begin(), d.end(), 0);
    }

    setStartPoint();


/*
    for (unsigned int i = 0; i < getNeighbours().size(); i++) {
        cout << calcNeighbours().at(i) << "\n";
    }*/
}

void PlayGround::setStartPoint() {

    fieldCounter = 1;
    numberAddresses = vector<int>();


    srand((unsigned int) time(0));


    if (isRandom == -1) {
        currentPosition = (rand() % (fieldSize * fieldSize));
    } else {
        currentPosition = isRandom;
    }

    playGroundSolved.at(currentPosition / fieldSize).at(currentPosition % fieldSize) = fieldCounter++;
    numberAddresses.push_back(currentPosition);
    calcNeighbours();
}

vector<int> PlayGround::calcNeighbours() {

    neighbours.clear();


    playGroundSolved.at(currentPosition / fieldSize).at(currentPosition % fieldSize);

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
    if (playGroundSolved.at((currentPosition - fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize - 1);
    }
}

void PlayGround::hasTopRightNeighbour(vector<int> &neighbours) const {
    if (playGroundSolved.at((currentPosition - fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize + 1);
    }
}

void PlayGround::hasTopNeighbour(vector<int> &neighbours) const {
    if (playGroundSolved.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize);
    }
}

void PlayGround::hasBottomLeftNeighbour(vector<int> &neighbours) const {
    if (playGroundSolved.at((currentPosition + fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition + fieldSize - 1);
    }
}

void PlayGround::hasLeftNeighbour(vector<int> &neighbours) const {
    if (playGroundSolved.at(currentPosition / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - 1);
    }
}

void PlayGround::hasBottomRightNeighbour(vector<int> &neighbours) const {
    if (playGroundSolved.at((currentPosition + fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) ==
        0) {
        neighbours.push_back(currentPosition + fieldSize + 1);
    }
}

void PlayGround::hasBottomNeighbour(vector<int> &neighbours) const {
    if (playGroundSolved.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
        neighbours.push_back(currentPosition + fieldSize);
    }
}

void PlayGround::hasRightNeighbour(vector<int> &neighbours) const {
    if (playGroundSolved.at(currentPosition / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition + 1);
    }
}

std::vector<std::vector<int>> PlayGround::getPlayGround() {
    return playGroundSolved;
}

void PlayGround::fillPlayGround() {
    int nextPosition = 0;
    float densityCounter = 0;

    while (getNeighbours().size() != 0) {
        auto random_integer = uni(rng);
        nextPosition = random_integer % getNeighbours().size();
        nextPosition = getNeighbours()[nextPosition];
        if (playGroundSolved[nextPosition / fieldSize][nextPosition % fieldSize] == 0) {
            playGroundSolved[nextPosition / fieldSize][nextPosition % fieldSize] = fieldCounter++;
            currentPosition = nextPosition;
            numberAddresses.push_back(currentPosition);
            calcNeighbours();
            densityCounter++;
        }

    }
    if (densityCounter / (float) (fieldSize * fieldSize) < 0.9f) {
        for (int i = 0; i < fieldSize; i++) {
            for (int j = 0; j < fieldSize; j++) {
                playGroundSolved[i][j] = 0;
            }
        }
       runCounter++;
        setStartPoint();
        fillPlayGround();
    }

}

void PlayGround::printPlayGround() {
    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            cout << playGroundSolved[i][j] << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < numberAddresses.size(); i++) {

        cout << numberAddresses[i] << " ";


    }
    cout << endl <<"Anzahl der Durchlaeufe: " <<runCounter;


}

void PlayGround::generateUnsolvedPlayground() {

    playGroundUnsolved = vector<vector<int>>(fieldSize, vector<int>(fieldSize));
    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            //remove numbers
            if(playGroundSolved[i][j] != 1 || playGroundSolved[i][j] != currentPosition){

            }



        }
        cout << endl;
    }

}



