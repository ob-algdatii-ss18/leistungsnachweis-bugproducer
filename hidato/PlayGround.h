//
// Created by joe on 10.04.18.
//

#ifndef LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
#define LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H

#include <vector>

class PlayGround {
public:
    PlayGround(unsigned int, int);

    void generateField();

    unsigned int getSize();

    std::vector<std::vector<int>> getPlayGround();

private:
    std::vector<std::vector<int>> playGround;

    void setStartPoint();

    unsigned int fieldSize;
    int currentPosition;
    int isRandom;

    std::vector<int> getNeighboursCount();

    void right(std::vector<int> &neighbours) const;

    void top(std::vector<int> &neighbours) const;

    void topRight(std::vector<int> &neighbours) const;

    void left(std::vector<int> &neighbours) const;

    void topLeft(std::vector<int> &neighbours) const;

    void bottom(std::vector<int> &neighbours) const;

    void bottomRight(std::vector<int> &neighbours) const;

    void bottomLeft(std::vector<int> &neighbours) const;
};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
