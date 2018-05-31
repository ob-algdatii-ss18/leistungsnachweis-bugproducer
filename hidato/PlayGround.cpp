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
int emptyCounter = 0;


PlayGround::PlayGround(unsigned int fieldSize, int isRandom) {
    this->fieldSize = fieldSize;
    this->isRandom = isRandom;
    this->runCounter = 1;

}

void PlayGround::generateField() {

    playGroundSolved = vector<vector<int >>(fieldSize, vector<int>(fieldSize));

    for (unsigned int i = 0; i < fieldSize; i++) {

        vector<int> d = playGroundSolved.at(i);
        fill(d.begin(), d.end(), 0);
    }

    setStartPoint();
}

void PlayGround::setStartPoint() {

    fieldCounter = 1;
    numberAddresses = vector<int>();


    srand((unsigned int) time(nullptr));
    auto random_integer = uni(rng);

    if (isRandom == -1) {
        currentPosition = (random_integer % (fieldSize * fieldSize));
    } else {
        currentPosition = isRandom;
    }

    playGroundSolved.at(currentPosition / fieldSize).at(currentPosition % fieldSize) = fieldCounter++;
    numberAddresses.push_back(currentPosition);
    calcNeighbours(currentPosition, false, playGroundSolved);
}

vector<int> PlayGround::calcNeighbours(int position, bool isPlayGroundFilled, std::vector<std::vector<int>> playGroundSolved) {

    neighbours.clear();


    playGroundSolved.at(position / fieldSize).at(position % fieldSize);

    // keine Nachbarn darüber, erste Zeile
    if (position < fieldSize) {
        // erste spalte
        if (position % fieldSize == 0) {
            hasRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);

        } else {
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
        }
    }
        // keine Nachbarn darunter, letzte Zeile
    else if (position >= ((fieldSize - 1) * fieldSize)) {
        // erste spalte
        if (position % fieldSize == 0) {
            hasTopNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);

        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasTopNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
        } else {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasTopNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
        }
    } else {
        // erste spalte
        if (position % fieldSize == 0) {
            hasTopNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);

        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasTopNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);

        } else {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasTopNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled, position, playGroundSolved);
        }
    }

    return neighbours;
}

const vector<int> &PlayGround::getNeighbours() const {
    return neighbours;
}

void PlayGround::hasTopLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position, std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize - 1);
        }
    } else {
        neighbours.push_back(position - fieldSize - 1);
    }
}

void PlayGround::hasTopRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position, std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at((position + 1) % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize + 1);
        }
    } else {
        neighbours.push_back(position - fieldSize + 1);
    }
}

void PlayGround::hasTopNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position, std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at(position % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize);
        }
    } else {
        neighbours.push_back(position - fieldSize);
    }
}

void PlayGround::hasBottomLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position, std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position + fieldSize - 1);
        }
    } else {
        neighbours.push_back(position + fieldSize - 1);
    }
}

void PlayGround::hasLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position, std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at(position / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position - 1);
        }
    } else {
        neighbours.push_back(position - 1);
    }
}

void PlayGround::hasBottomRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position, std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at((position + 1) % fieldSize) ==
            0) {
            neighbours.push_back(position + fieldSize + 1);
        }
    } else {
        neighbours.push_back(position + fieldSize + 1);
    }
}

void PlayGround::hasBottomNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position, std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at(position % fieldSize) == 0) {
            neighbours.push_back(position + fieldSize);
        }
    } else {
        neighbours.push_back(position + fieldSize);
    }
}

void PlayGround::hasRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position, std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at(position / fieldSize).at((position + 1) % fieldSize) == 0) {
            neighbours.push_back(position + 1);
        }
    } else {
        neighbours.push_back(position + 1);
    }
}

void PlayGround::fillPlayGround() {
    int nextPosition = 0;
    float densityCounter = 0;

    while (!getNeighbours().empty()) {
        auto random_integer = uni(rng);
        nextPosition = random_integer % getNeighbours().size();
        nextPosition = getNeighbours()[nextPosition];
        if (playGroundSolved[nextPosition / fieldSize][nextPosition % fieldSize] == 0) {
            playGroundSolved[nextPosition / fieldSize][nextPosition % fieldSize] = fieldCounter++;
            currentPosition = nextPosition;
            numberAddresses.push_back(currentPosition);
            calcNeighbours(currentPosition, false, playGroundSolved);
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

    for (int numberAddresse : numberAddresses) {
        cout << numberAddresse << " ";

    }
    cout << endl << "Anzahl der Durchlaeufe: " << runCounter << endl;
    cout << endl << "Empty Fields: " << emptyCounter << endl;
    cout << endl << "------------------------------------------------------ " << endl;


}

void PlayGround::generateUnsolvedPlayground() {
    emptyCounter = 0;


    playGroundUnsolved = vector<vector<int >>(fieldSize, vector<int>(fieldSize));


    // playGroundUnsolved[numberAddresses[0] / fieldSize][numberAddresses[0] % fieldSize] = 1;
    playGroundUnsolved[numberAddresses[numberAddresses.size() - 1] / fieldSize][
            numberAddresses[numberAddresses.size() - 1] % fieldSize] = numberAddresses.size();

    for (int i = 0; i <= numberAddresses.size() - 2; i += 2) {
        int tmp = playGroundSolved[numberAddresses[i] / fieldSize][numberAddresses[i] % fieldSize];
        playGroundUnsolved[numberAddresses[i] / fieldSize][numberAddresses[i] % fieldSize] = tmp;

    }



    for (int i = 1; i <= numberAddresses.size() - 3; i += 2) {
        vector<int> tmp = calcNeighbours(numberAddresses[i], false, playGroundUnsolved);
        if (checkForSameNeighbours(numberAddresses[i], numberAddresses[i + 2], playGroundUnsolved) && checkForInLine(numberAddresses[i])) {
            playGroundUnsolved[numberAddresses[i] / fieldSize][numberAddresses[i] % fieldSize] = 0;
        }
    }


    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if (playGroundSolved[i][j] == 0) {
                playGroundUnsolved[i][j] = -1;
            }
        }
    }


    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if (playGroundUnsolved[i][j] == 0) {
                emptyCounter++;
            }
        }
    }


}

bool PlayGround::checkForInLine(int addr) {

    vector<int> neighbours = calcNeighbours(addr, false, playGroundUnsolved);

    if (neighbours.size() < 2) {
        return false;
    }

    int countervert = 0;
    int counterhori = 0;

    // vertikal
    for (int i = 0; i < neighbours.size(); i++) {
        if (neighbours[i] == addr - fieldSize || neighbours[i] == addr + fieldSize) {
            countervert++;
        }
    }



    //horizontal

    for (int i = 0; i < neighbours.size(); i++) {
        if (neighbours[i] == addr - 1 || neighbours[i] == addr + 1) {
            counterhori++;
        }
    }


    return (counterhori == 2) || (countervert == 2) && ((counterhori + countervert) < 3);

}


bool PlayGround::checkForSameNeighbours(int addr1, int addr2, vector<std::vector<int>> pg) {

    vector<int> one = calcNeighbours(addr1, true, pg);

    for (int elem : one) {
        if (elem == addr2)
            return true;
    }
    return false;

}

void PlayGround::setPlayGroundSolved(const vector<vector<int>> &playGroundSolved) {
    PlayGround::playGroundSolved = playGroundSolved;
}

const vector<vector<int>> &PlayGround::getPlayGroundSolved() const {
    return playGroundSolved;
}

const vector<int> &PlayGround::getNumberAddresses() const {
    return numberAddresses;
}

void PlayGround::setNumberAddresses(const vector<int> &numberAddresses) {
    PlayGround::numberAddresses = numberAddresses;
}

const vector<vector<int>> &PlayGround::getPlayGroundUnsolved() const {
    return playGroundUnsolved;
}







