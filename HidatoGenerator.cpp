#include "HidatoGenerator.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

vector<vector<int>> HidatoGenerator::generateField(unsigned int fieldSize) {
    this->fieldSize = fieldSize;

    playGround = vector<vector<int>>(fieldSize, vector<int>(fieldSize));

    for (unsigned int i = 0; i < fieldSize; i++) {

        vector<int> d = playGround.at(i);
        fill(d.begin(), d.end(), 0);
    }

    setStartPoint();


    for (unsigned int i = 0; i < getNeighboursCount().size(); i++) {
        cout << getNeighboursCount().at(i) << "\n";
    }


    return playGround;
}

void HidatoGenerator::setStartPoint() {

    srand((int) time(0));

    currentPosition = (rand() % (fieldSize * fieldSize));

    //cout << "currentPosition: " << currentPosition << "\n";

    currentPosition = 3;

    playGround.at(currentPosition / fieldSize).at(currentPosition % fieldSize) = 1;
}

vector<int> HidatoGenerator::getNeighboursCount() {

    vector<int> neighbours;

    playGround.at(currentPosition / fieldSize).at(currentPosition % fieldSize);

    // keine Nachbarn darüber, erste Zeile
    if (currentPosition < fieldSize) {
        // erste spalte
        if (currentPosition % fieldSize == 0) {

            if (playGround.at(currentPosition / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + 1);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) ==
                0) {
                neighbours.push_back(currentPosition + fieldSize + 1);
            }

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {

            if (playGround.at(currentPosition / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - 1);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize - 1);
            }

        } else {
            if (playGround.at(currentPosition / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + 1);
            }
            if (playGround.at(currentPosition / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - 1);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize + 1);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize - 1);
            }
        }
    }
        // keine Nachbarn darunter, letzte Zeile
    else if (currentPosition >= ((fieldSize - 1) * fieldSize)) {
        // erste spalte
        if (currentPosition % fieldSize == 0) {
            if (playGround.at((currentPosition) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + 1);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize + 1);
            }

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {

            if (playGround.at((currentPosition) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - 1);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize);

            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize - 1);
            }
        } else {
            if (playGround.at(currentPosition / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + 1);
            }
            if (playGround.at(currentPosition / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - 1);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize + 1);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) ==
                0) {
                neighbours.push_back(currentPosition - fieldSize - 1);
            }
        }
    } else {
        // erste spalte
        if (currentPosition % fieldSize == 0) {

            if (playGround.at((currentPosition) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + 1);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize + 1);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize + 1);
            }

        }
            // letzte Spalte
        else if (currentPosition % fieldSize == fieldSize - 1) {
            if (playGround.at((currentPosition) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - 1);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize - 1);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize - 1);
            }

        } else {
            if (playGround.at(currentPosition / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + 1);
            }
            if (playGround.at(currentPosition / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - 1);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize + 1);
            }
            if (playGround.at((currentPosition + fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition + fieldSize - 1);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at(currentPosition % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition + 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize + 1);
            }
            if (playGround.at((currentPosition - fieldSize) / fieldSize).at((currentPosition - 1) % fieldSize) == 0) {
                neighbours.push_back(currentPosition - fieldSize - 1);
            }
        }
    }

    return neighbours;
}


