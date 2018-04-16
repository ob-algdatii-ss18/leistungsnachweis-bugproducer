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


    for (unsigned int i = 0; i < getNeighboursCount().size(); i++) {
        cout << getNeighboursCount().at(i) << "\n";
    }
}

void PlayGround::setStartPoint() {

    srand((int) time(0));


    if (isRandom == -1) {
        currentPosition = (rand() % (fieldSize * fieldSize));
    } else {
        currentPosition = isRandom;
    }

    playGround.at(currentPosition / fieldSize).at(currentPosition % fieldSize) = 1;
}

vector<int> PlayGround::getNeighboursCount() {

    vector<int> neighbours;

    playGround.at(currentPosition / fieldSize).at(currentPosition % fieldSize);

    // keine Nachbarn darüber, erste Zeile
    if (currentPosition < fieldSize) {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            right(neighbours);
            top(neighbours);
            topRight(neighbours);
        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            left(neighbours);
            top(neighbours);
            topLeft(neighbours);

        } else {
            right(neighbours);
            left(neighbours);
            top(neighbours);
            topRight(neighbours);
            topLeft(neighbours);
        }
    }
        // keine Nachbarn darunter, letzte Zeile
    else if (currentPosition >= ((fieldSize - 1) * fieldSize)) {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            right(neighbours);
            bottom(neighbours);
            bottomRight(neighbours);

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            left(neighbours);
            bottom(neighbours);
            bottomLeft(neighbours);
        } else {
            right(neighbours);
            left(neighbours);
            bottom(neighbours);
            bottomRight(neighbours);
            bottomLeft(neighbours);
        }
    } else {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            right(neighbours);
            bottom(neighbours);
            top(neighbours);
            bottomRight(neighbours);
            topRight(neighbours);

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            left(neighbours);
            bottom(neighbours);
            top(neighbours);
            bottomLeft(neighbours);
            topLeft(neighbours);

        } else {
            topLeft(neighbours);
            top(neighbours);
            topRight(neighbours);
            left(neighbours);
            right(neighbours);
            bottomLeft(neighbours);
            bottom(neighbours);
            bottomRight(neighbours);
        }
    }

    return neighbours;
}

void PlayGround::bottomLeft(vector<int> &neighbours) const {
    if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize - 1);
    }
}

void PlayGround::bottomRight(vector<int> &neighbours) const {
    if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize + 1);
    }
}

void PlayGround::bottom(vector<int> &neighbours) const {
    if (playGround.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
        neighbours.push_back(currentPosition - fieldSize);
    }
}

void PlayGround::topLeft(vector<int> &neighbours) const {
    if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition + fieldSize - 1);
    }
}

void PlayGround::left(vector<int> &neighbours) const {
    if (playGround.at(currentPosition / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition - 1);
    }
}

void PlayGround::topRight(vector<int> &neighbours) const {
    if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) ==
        0) {
        neighbours.push_back(currentPosition + fieldSize + 1);
    }
}

void PlayGround::top(vector<int> &neighbours) const {
    if (playGround.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
        neighbours.push_back(currentPosition + fieldSize);
    }
}

void PlayGround::right(vector<int> &neighbours) const {
    if (playGround.at(currentPosition / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
        neighbours.push_back(currentPosition + 1);
    }
}

std::vector<std::vector<int>> PlayGround::getPlayGround() {
    return playGround;
}


