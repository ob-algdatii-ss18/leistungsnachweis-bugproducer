#include "PlayGround.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;
random_device rd;     // only used once to initialise (seed) engine // NOLINT
mt19937 engine(rd());    // random-number engine used (Mersenne-Twister in this case) // NOLINT
uniform_int_distribution<int> uni(1, 99); // guaranteed unbiased // NOLINT
int emptyCounter = 0;

PlayGround::PlayGround(unsigned int fieldSize, int isRandom) {
    this->fieldSize = fieldSize;
    this->isRandom = isRandom;
    this->runCounter = 1;

}

void PlayGround::generatePlayground() {

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
    auto random_integer = uni(engine);

    if (isRandom == -1) {
        currentPosition = (random_integer % (fieldSize * fieldSize));
    } else {
        currentPosition = isRandom;
    }

    playGroundSolved.at(currentPosition / fieldSize).at(currentPosition % fieldSize) = fieldCounter++;
    numberAddresses.push_back(currentPosition);
    calcNeighbours(currentPosition, false, playGroundSolved);
}

vector<int>
PlayGround::calcNeighbours(int position, bool isPlayGroundFilled, std::vector<std::vector<int>> playGroundSolved) {

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

void PlayGround::hasTopLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position,
                                     std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize - 1);
        }
    } else {
        neighbours.push_back(position - fieldSize - 1);
    }
}

void PlayGround::hasTopRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position,
                                      std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at((position + 1) % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize + 1);
        }
    } else {
        neighbours.push_back(position - fieldSize + 1);
    }
}

void PlayGround::hasTopNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position,
                                 std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at(position % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize);
        }
    } else {
        neighbours.push_back(position - fieldSize);
    }
}

void PlayGround::hasBottomLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position,
                                        std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position + fieldSize - 1);
        }
    } else {
        neighbours.push_back(position + fieldSize - 1);
    }
}

void PlayGround::hasLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position,
                                  std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at(position / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position - 1);
        }
    } else {
        neighbours.push_back(position - 1);
    }
}

void PlayGround::hasBottomRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position,
                                         std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at((position + 1) % fieldSize) ==
            0) {
            neighbours.push_back(position + fieldSize + 1);
        }
    } else {
        neighbours.push_back(position + fieldSize + 1);
    }
}

void PlayGround::hasBottomNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position,
                                    std::vector<std::vector<int>> playGroundSolved) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at(position % fieldSize) == 0) {
            neighbours.push_back(position + fieldSize);
        }
    } else {
        neighbours.push_back(position + fieldSize);
    }
}

void PlayGround::hasRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position,
                                   std::vector<std::vector<int>> playGroundSolved) const {
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
        int random_integer = uni(engine);
        nextPosition = random_integer % (int)getNeighbours().size();
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
    } else {
        generateUnsolvedPlayground();
    }
}


void PlayGround::generateUnsolvedPlayground() {
    emptyCounter = 0;


    playGroundUnsolved = vector<vector<int >>(fieldSize, vector<int>(fieldSize));


    playGroundUnsolved[numberAddresses[0] / fieldSize][numberAddresses[0] % fieldSize] = 1;
    playGroundUnsolved[numberAddresses[numberAddresses.size() - 1] / fieldSize][
            numberAddresses[numberAddresses.size() - 1] % fieldSize] = static_cast<int>(numberAddresses.size());

    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if ((i % 2 == 0) && (j % 2 == 0)) {
                int tmp = playGroundSolved[i][j];
                playGroundUnsolved[i][j] = tmp;
            }
            if ((i % 2 != 0) && (j % 2 != 0)) {
                int tmp = playGroundSolved[i][j];
                playGroundUnsolved[i][j] = tmp;
            }
        }
    }


    for (
            int i = 0;
            i < fieldSize;
            i++) {
        for (
                int j = 0;
                j < fieldSize;
                j++) {
            if (playGroundSolved[i][j] == 0) {
                playGroundUnsolved[i][j] = -1;
            }
        }
    }


    for (
            int i = 0;
            i < fieldSize;
            i++) {
        for (
                int j = 0;
                j < fieldSize;
                j++) {
            if (playGroundUnsolved[i][j] == 0) {
                emptyCounter++;
            }
        }
    }

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







