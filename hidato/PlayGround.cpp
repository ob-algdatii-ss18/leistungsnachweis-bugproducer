#include "PlayGround.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(1, 99); // guaranteed unbiased


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
    calcNeighbours(currentPosition, false);
}

vector<int> PlayGround::calcNeighbours(int position,bool isPlayGroundFilled ) {

    neighbours.clear();


    playGroundSolved.at(position / fieldSize).at(position % fieldSize);

    // keine Nachbarn darüber, erste Zeile
    if (position < fieldSize) {
        // erste spalte
        if (position % fieldSize == 0) {
            hasRightNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled,position);
        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled,position);

        } else {
            hasLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasRightNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled,position);
        }
    }
        // keine Nachbarn darunter, letzte Zeile
    else if (position >= ((fieldSize - 1) * fieldSize)) {
        // erste spalte
        if (position % fieldSize == 0) {
            hasTopNeighbour(neighbours, isPlayGroundFilled,position);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled,position);
            hasRightNeighbour(neighbours, isPlayGroundFilled,position);

        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasTopNeighbour(neighbours, isPlayGroundFilled,position);
            hasLeftNeighbour(neighbours, isPlayGroundFilled,position);
        } else {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasTopNeighbour(neighbours, isPlayGroundFilled,position);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled,position);
            hasLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasRightNeighbour(neighbours, isPlayGroundFilled,position);
        }
    } else {
        // erste spalte
        if (position % fieldSize == 0) {
            hasTopNeighbour(neighbours, isPlayGroundFilled,position);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled,position);
            hasRightNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled,position);

        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasTopNeighbour(neighbours, isPlayGroundFilled,position);
            hasLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled,position);

        } else {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasTopNeighbour(neighbours, isPlayGroundFilled,position);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled,position);
            hasLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasRightNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled,position);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled,position);
        }
    }

    return neighbours;
}

const vector<int> &PlayGround::getNeighbours() const {
    return neighbours;
}

void PlayGround::hasTopLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled,int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize - 1);
        }
    } else {
        neighbours.push_back(position - fieldSize - 1);
    }
}

void PlayGround::hasTopRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled,int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at((position + 1) % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize + 1);
        }
    } else {
        neighbours.push_back(position - fieldSize + 1);
    }
}

void PlayGround::hasTopNeighbour(vector<int> &neighbours, bool isPlayGroundFilled,int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at(position % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize);
        }
    } else {
        neighbours.push_back(position - fieldSize);
    }
}

void PlayGround::hasBottomLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled,int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position + fieldSize - 1);
        }
    } else {
        neighbours.push_back(position + fieldSize - 1);
    }
}

void PlayGround::hasLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled,int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at(position / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position - 1);
        }
    } else {
        neighbours.push_back(position - 1);
    }
}

void PlayGround::hasBottomRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled,int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at((position + 1) % fieldSize) ==
            0) {
            neighbours.push_back(position + fieldSize + 1);
        }
    } else {
        neighbours.push_back(position + fieldSize + 1);
    }
}

void PlayGround::hasBottomNeighbour(vector<int> &neighbours, bool isPlayGroundFilled,int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at(position % fieldSize) == 0) {
            neighbours.push_back(position + fieldSize);
        }
    } else {
        neighbours.push_back(position + fieldSize);
    }
}

void PlayGround::hasRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled,int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at(position / fieldSize).at((position + 1) % fieldSize) == 0) {
            neighbours.push_back(position + 1);
        }
    } else {
        neighbours.push_back(position + 1);
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
            calcNeighbours(currentPosition, false);
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

    generateUnsolvedPlayground();
}

void PlayGround::printPlayGrounds() {
    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            cout << playGroundSolved[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "\n\n\n" << endl;

    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            cout << playGroundUnsolved[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "\n\n\n" << endl;

    for (int i = 0; i < numberAddresses.size(); i++) {
        cout << numberAddresses[i] << " ";

    }
    cout << endl << "Anzahl der Durchlaeufe: " << runCounter;


}

void PlayGround::generateUnsolvedPlayground() {

    playGroundUnsolved = vector<vector<int>>(fieldSize, vector<int>(fieldSize));
    int saveLastPosition = currentPosition;
    int deleteMarker = 9;

    playGroundUnsolved[numberAddresses[0] / fieldSize][numberAddresses[0] % fieldSize] = 1;
    playGroundUnsolved[numberAddresses[numberAddresses.size() - 1] / fieldSize][numberAddresses[numberAddresses.size() - 1] % fieldSize] = numberAddresses.size();

    for (int i = 1; i * deleteMarker < numberAddresses.size() - 1; i++) {
        int tempMarker = i * deleteMarker;
        int tempPos = numberAddresses[tempMarker];
        int temp = playGroundSolved[tempPos / fieldSize][tempPos % fieldSize];
        playGroundUnsolved[tempPos / fieldSize][tempPos % fieldSize] = temp;

    }
//
//    for (int i = 0; i < fieldSize; i++) {
//        for (int j = 0; j < fieldSize; j++) {
//            cout << playGroundSolved[i][j] << "  ";
//        }
//        cout << endl;
//    }
//    cout << "\n\n\n" << endl;

    for (int i = 0; i < numberAddresses.size() - 2; i++) {
        if (checkForSameNeighbours(numberAddresses[i], numberAddresses[i + 2])) {
            if (playGroundUnsolved[numberAddresses[i + 2] / fieldSize][numberAddresses[i + 2] % fieldSize] == 0) {
                int temp = playGroundSolved[numberAddresses[i + 2] / fieldSize][numberAddresses[i + 2] % fieldSize];
                playGroundUnsolved[numberAddresses[i + 2] / fieldSize][numberAddresses[i + 2] % fieldSize] = temp;

            } else {
                int temp = playGroundSolved[numberAddresses[i + 1] / fieldSize][numberAddresses[i + 1] % fieldSize];
                playGroundUnsolved[numberAddresses[i + 1] / fieldSize][numberAddresses[i + 1] % fieldSize] = temp;
            }
            i++;
        }

//        for (int i = 0; i < fieldSize; i++) {
//            for (int j = 0; j < fieldSize; j++) {
//                cout << playGroundUnsolved[i][j] << "  ";
//            }
//            cout << endl;
//        }
//
//        cout << "\n\n\n" << endl;
    }

    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if (playGroundSolved[i][j] == 0) {
                playGroundUnsolved[i][j] = -1;
            }
        }
    }

    printPlayGrounds();

}

bool PlayGround::checkForSameNeighbours(int addr1, int addr2) {

    vector<int> one = calcNeighbours(addr1,true);

    for (int elem : one) {
        if (elem == addr2)
            return true;
    }
    return false;

}

void PlayGround::setPlayGroundSolved(const vector<vector<int>> &playGroundSolved) {
    PlayGround::playGroundSolved = playGroundSolved;
}

void PlayGround::setCurrentPosition(int currentPosition) {
    PlayGround::currentPosition = currentPosition;
}



