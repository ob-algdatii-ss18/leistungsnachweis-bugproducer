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

    playGroundSolved = vector<vector<int>>(fieldSize, vector<int>(fieldSize));

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
    calcNeighbours(currentPosition, false);
}

vector<int> PlayGround::calcNeighbours(int position, bool isPlayGroundFilled) {

    neighbours.clear();


    playGroundSolved.at(position / fieldSize).at(position % fieldSize);

    // keine Nachbarn darüber, erste Zeile
    if (position < fieldSize) {
        // erste spalte
        if (position % fieldSize == 0) {
            hasRightNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled, position);
        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position);

        } else {
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled, position);
        }
    }
        // keine Nachbarn darunter, letzte Zeile
    else if (position >= ((fieldSize - 1) * fieldSize)) {
        // erste spalte
        if (position % fieldSize == 0) {
            hasTopNeighbour(neighbours, isPlayGroundFilled, position);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled, position);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position);

        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasTopNeighbour(neighbours, isPlayGroundFilled, position);
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position);
        } else {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasTopNeighbour(neighbours, isPlayGroundFilled, position);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled, position);
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position);
        }
    } else {
        // erste spalte
        if (position % fieldSize == 0) {
            hasTopNeighbour(neighbours, isPlayGroundFilled, position);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled, position);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled, position);

        }
            // letzte Spalte
        else if (position % fieldSize == fieldSize - 1) {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasTopNeighbour(neighbours, isPlayGroundFilled, position);
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position);

        } else {
            hasTopLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasTopNeighbour(neighbours, isPlayGroundFilled, position);
            hasTopRightNeighbour(neighbours, isPlayGroundFilled, position);
            hasLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasRightNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomLeftNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomNeighbour(neighbours, isPlayGroundFilled, position);
            hasBottomRightNeighbour(neighbours, isPlayGroundFilled, position);
        }
    }

    return neighbours;
}

const vector<int> &PlayGround::getNeighbours() const {
    return neighbours;
}

void PlayGround::hasTopLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize - 1);
        }
    } else {
        neighbours.push_back(position - fieldSize - 1);
    }
}

void PlayGround::hasTopRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at((position + 1) % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize + 1);
        }
    } else {
        neighbours.push_back(position - fieldSize + 1);
    }
}

void PlayGround::hasTopNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position - fieldSize) / fieldSize).at(position % fieldSize) == 0) {
            neighbours.push_back(position - fieldSize);
        }
    } else {
        neighbours.push_back(position - fieldSize);
    }
}

void PlayGround::hasBottomLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position + fieldSize - 1);
        }
    } else {
        neighbours.push_back(position + fieldSize - 1);
    }
}

void PlayGround::hasLeftNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at(position / fieldSize).at((position - 1) % fieldSize) == 0) {
            neighbours.push_back(position - 1);
        }
    } else {
        neighbours.push_back(position - 1);
    }
}

void PlayGround::hasBottomRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at((position + 1) % fieldSize) ==
            0) {
            neighbours.push_back(position + fieldSize + 1);
        }
    } else {
        neighbours.push_back(position + fieldSize + 1);
    }
}

void PlayGround::hasBottomNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position) const {
    if (!isPlayGroundFilled) {
        if (playGroundSolved.at((position + fieldSize) / fieldSize).at(position % fieldSize) == 0) {
            neighbours.push_back(position + fieldSize);
        }
    } else {
        neighbours.push_back(position + fieldSize);
    }
}

void PlayGround::hasRightNeighbour(vector<int> &neighbours, bool isPlayGroundFilled, int position) const {
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

    for (int numberAddresse : numberAddresses) {
        cout << numberAddresse << " ";

    }
    cout << endl << "Anzahl der Durchlaeufe: " << runCounter << endl;
    cout << endl << "Empty Fields: " << emptyCounter << endl;
    cout << endl << "------------------------------------------------------ " << endl;


}

void PlayGround::generateUnsolvedPlayground() {
    emptyCounter = 0;
    vector<int> unsolvedAddresses;


    playGroundUnsolved = vector<vector<int>>(fieldSize, vector<int>(fieldSize));


   // playGroundUnsolved[numberAddresses[0] / fieldSize][numberAddresses[0] % fieldSize] = 1;
    playGroundUnsolved[numberAddresses[numberAddresses.size() - 1] / fieldSize][
            numberAddresses[numberAddresses.size() - 1] % fieldSize] = numberAddresses.size();

    for(int i =0; i<=numberAddresses.size()-2; i += 2){
        int tmp = playGroundSolved[numberAddresses[i]/fieldSize][numberAddresses[i]%fieldSize];
        playGroundUnsolved[numberAddresses[i]/fieldSize][numberAddresses[i]%fieldSize]=tmp;
        unsolvedAddresses.push_back(numberAddresses[i]);
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

bool PlayGround::checkForSameNeighbours(int addr1, int addr2) {

    vector<int> one = calcNeighbours(addr1, true);

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





