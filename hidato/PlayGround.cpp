#include "PlayGround.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>
#include <map>

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

    playGroundSolved = vector < vector < int >> (fieldSize, vector<int>(fieldSize));

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
    densityCounter = 0;

    while (!getNeighbours().empty()) {
        int random_integer = uni(engine);
        nextPosition = random_integer % (int) getNeighbours().size();
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
    playGroundUnsolved = vector<vector<int>>(fieldSize, vector<int>(fieldSize));
    int deleteMarker = 10-fieldSize;

    playGroundUnsolved[numberAddresses[0] / fieldSize][numberAddresses[0] % fieldSize] = 1;
    playGroundUnsolved[numberAddresses[numberAddresses.size() - 1] / fieldSize][
            numberAddresses[numberAddresses.size() - 1] % fieldSize] = numberAddresses.size();

    for (int i = 1; i * deleteMarker < numberAddresses.size() - 1; i++) {
        int tempMarker = i * deleteMarker;
        int tempPos = numberAddresses[tempMarker];
        int temp = playGroundSolved[tempPos / fieldSize][tempPos % fieldSize];
        playGroundUnsolved[tempPos / fieldSize][tempPos % fieldSize] = temp;
    }

    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if (playGroundSolved[i][j] == 0) {
                playGroundUnsolved[i][j] = -1;
            }
        }
    }

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


void PlayGround::setPlayGroundSolved(const vector <vector<int>> &playGroundSolved) {
    PlayGround::playGroundSolved = playGroundSolved;
}

const vector <vector<int>> &PlayGround::getPlayGroundSolved() const {
    return playGroundSolved;
}

const vector<int> &PlayGround::getNumberAddresses() const {
    return numberAddresses;
}

void PlayGround::setNumberAddresses(const vector<int> &numberAddresses) {
    PlayGround::numberAddresses = numberAddresses;
}

const vector <vector<int>> &PlayGround::getPlayGroundUnsolved() const {
    return playGroundUnsolved;
}

bool PlayGround::checkSolution() {

    map<int, int> numAddr;

    for (int i = 0; i < fieldSize; i++) {
        for (int j = 0; j < fieldSize; j++) {
            if(playGroundPlayerSolution[i][j] != 0){
                numAddr[playGroundPlayerSolution[i][j]] = i * fieldSize + j; //Zahlenwert/Adresse
            }
        }
    }

    for (int i = 1; i < densityCounter-1; i++) {
        if (!checkForSameNeighbours(numAddr.find(i)->second,numAddr.find(i+1)->second,playGroundPlayerSolution)){
            return false;
        }
    }
    return true;
}

bool PlayGround::checkForSameNeighbours(int addr1, int addr2, vector<std::vector<int>> pg) {

    vector<int> one = calcNeighbours(addr1, true, pg);

    for (int elem : one) {
        if (elem == addr2)
            return true;
    }
    return false;

}



void PlayGround::setDensityCounter(float densityCounter) {
    PlayGround::densityCounter = densityCounter;
}

void PlayGround::setPlayGroundPlayerSolution(const vector<vector<int>> &playGroundPlayerSolution) {
    PlayGround::playGroundPlayerSolution = playGroundPlayerSolution;
}











