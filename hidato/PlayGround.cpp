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
    calcNeighbours(0);
}

vector<int> PlayGround::calcNeighbours(int value) {

    neighbours.clear();


    playGroundSolved.at(currentPosition / fieldSize).at(currentPosition % fieldSize);

    // keine Nachbarn darüber, erste Zeile
    if (currentPosition < fieldSize) {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            hasRightNeighbour(neighbours, value);
            hasBottomNeighbour(neighbours, value);
            hasBottomRightNeighbour(neighbours, value);
        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            hasLeftNeighbour(neighbours, value);
            hasBottomLeftNeighbour(neighbours, value);
            hasBottomNeighbour(neighbours, value);

        } else {
            hasLeftNeighbour(neighbours, value);
            hasRightNeighbour(neighbours, value);
            hasBottomLeftNeighbour(neighbours, value);
            hasBottomNeighbour(neighbours, value);
            hasBottomRightNeighbour(neighbours, value);
        }
    }
        // keine Nachbarn darunter, letzte Zeile
    else if (currentPosition >= ((fieldSize - 1) * fieldSize)) {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            hasTopNeighbour(neighbours, value);
            hasTopRightNeighbour(neighbours, value);
            hasRightNeighbour(neighbours, value);

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours, value);
            hasTopNeighbour(neighbours, value);
            hasLeftNeighbour(neighbours, value);
        } else {
            hasTopLeftNeighbour(neighbours, value);
            hasTopNeighbour(neighbours, value);
            hasTopRightNeighbour(neighbours, value);
            hasLeftNeighbour(neighbours, value);
            hasRightNeighbour(neighbours, value);
        }
    } else {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            hasTopNeighbour(neighbours, value);
            hasTopRightNeighbour(neighbours, value);
            hasRightNeighbour(neighbours, value);
            hasBottomNeighbour(neighbours, value);
            hasBottomRightNeighbour(neighbours, value);

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours, value);
            hasTopNeighbour(neighbours, value);
            hasLeftNeighbour(neighbours, value);
            hasBottomLeftNeighbour(neighbours, value);
            hasBottomNeighbour(neighbours, value);

        } else {
            hasTopLeftNeighbour(neighbours, value);
            hasTopNeighbour(neighbours, value);
            hasTopRightNeighbour(neighbours, value);
            hasLeftNeighbour(neighbours, value);
            hasRightNeighbour(neighbours, value);
            hasBottomLeftNeighbour(neighbours, value);
            hasBottomNeighbour(neighbours, value);
            hasBottomRightNeighbour(neighbours, value);
        }
    }

    return neighbours;
}

const vector<int> &PlayGround::getNeighbours() const {
    return neighbours;
}

void PlayGround::hasTopLeftNeighbour(vector<int> &neighbours, int value) const {
    if (value == 0) {
        if (playGroundSolved.at((currentPosition - fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
            neighbours.push_back(currentPosition - fieldSize - 1);
        }
    } else {
        neighbours.push_back(currentPosition - fieldSize - 1);
    }
}

void PlayGround::hasTopRightNeighbour(vector<int> &neighbours, int value) const {
    if (value == 0) {
        if (playGroundSolved.at((currentPosition - fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
            neighbours.push_back(currentPosition - fieldSize + 1);
        }
    } else {
        neighbours.push_back(currentPosition - fieldSize + 1);
    }
}

void PlayGround::hasTopNeighbour(vector<int> &neighbours, int value) const {
    if (value == 0) {
        if (playGroundSolved.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
            neighbours.push_back(currentPosition - fieldSize);
        }
    } else {
        neighbours.push_back(currentPosition - fieldSize);
    }
}

void PlayGround::hasBottomLeftNeighbour(vector<int> &neighbours, int value) const {
    if (value == 0) {
        if (playGroundSolved.at((currentPosition + fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
            neighbours.push_back(currentPosition + fieldSize - 1);
        }
    } else {
        neighbours.push_back(currentPosition + fieldSize - 1);
    }
}

void PlayGround::hasLeftNeighbour(vector<int> &neighbours, int value) const {
    if (value == 0) {
        if (playGroundSolved.at(currentPosition / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
            neighbours.push_back(currentPosition - 1);
        }
    } else {
        neighbours.push_back(currentPosition - 1);
    }
}

void PlayGround::hasBottomRightNeighbour(vector<int> &neighbours, int value) const {
    if (value == 0) {
        if (playGroundSolved.at((currentPosition + fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) ==
            0) {
            neighbours.push_back(currentPosition + fieldSize + 1);
        }
    } else {
        neighbours.push_back(currentPosition + fieldSize + 1);
    }
}

void PlayGround::hasBottomNeighbour(vector<int> &neighbours, int value) const {
    if (value == 0) {
        if (playGroundSolved.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
            neighbours.push_back(currentPosition + fieldSize);
        }
    } else {
        neighbours.push_back(currentPosition + fieldSize);
    }
}

void PlayGround::hasRightNeighbour(vector<int> &neighbours, int value) const {
    if (value == 0) {
        if (playGroundSolved.at(currentPosition / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
            neighbours.push_back(currentPosition + 1);
        }
    } else {
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
            calcNeighbours(0);
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
    int deleteMarker = 3;

    // test values
    // todo remove
    vector<int> test = checkForSameNeighbours(numberAddresses[0], numberAddresses[1]);

    playGroundUnsolved[numberAddresses[0] / fieldSize][numberAddresses[0] % fieldSize] = 1;
    playGroundUnsolved[numberAddresses[numberAddresses.size() - 1] / fieldSize][
            numberAddresses[numberAddresses.size() - 1] % fieldSize] = numberAddresses.size();
    for (int i = 1; i * deleteMarker < numberAddresses.size() - 1; i++) {
        int tempMarker = i*deleteMarker;
        int tempPos = numberAddresses[tempMarker];
        int temp = playGroundSolved[tempPos/fieldSize][tempPos%fieldSize];
        playGroundUnsolved[tempPos/fieldSize][tempPos%fieldSize] = temp;

    }

    printPlayGrounds();

}

vector<int> PlayGround::checkForSameNeighbours(int addr1, int addr2) {

    currentPosition = addr1;
    vector<int> one = calcNeighbours(1);
    currentPosition = addr2;
    vector<int> two = calcNeighbours(1);
    vector<int> intersection;

    for (int i = 0; i < one.size(); i++) {
        for (int j = 0; j < two.size(); j++) {
            if (one[i] == two[j]) {
                intersection.push_back(one[i]);
            }
        }
    }
    return intersection;
}



