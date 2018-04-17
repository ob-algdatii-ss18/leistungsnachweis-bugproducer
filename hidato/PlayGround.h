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
    std::vector<int> getNeighbours();

private:
    std::vector<std::vector<int>> playGround;

    void setStartPoint();

    unsigned int fieldSize;
    int currentPosition;
    int isRandom;



    void hasRightNeighbour(std::vector<int> &neighbours) const;

    void hasBottomNeighbour(std::vector<int> &neighbours) const;

    void hasBottomRightNeighbour(std::vector<int> &neighbours) const;

    void hasLeftNeighbour(std::vector<int> &neighbours) const;

    void hasBottomLeftNeighbour(std::vector<int> &neighbours) const;

    void hasTopNeighbour(std::vector<int> &neighbours) const;

    void hasTopRightNeighbour(std::vector<int> &neighbours) const;

    void hasTopLeftNeighbour(std::vector<int> &neighbours) const;
};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
