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
    int runCounter;

    std::vector<std::vector<int>> getPlayGround();
    std::vector<int> calcNeighbours(int);

    const std::vector<int> &getNeighbours() const;
    void fillPlayGround();
    void printPlayGrounds();
    void generateUnsolvedPlayground();

private:

    std::vector<std::vector<int>> playGroundSolved;
    std::vector<std::vector<int>> playGroundUnsolved;


    void setStartPoint();

    std::vector<int> neighbours;
    std::vector<int> numberAddresses;


    unsigned int fieldSize;
    int currentPosition;
    int isRandom;
    int fieldCounter;

    bool checkForSameNeighbours(int, int);



    void hasRightNeighbour(std::vector<int> &neighbours, int) const;

    void hasBottomNeighbour(std::vector<int> &neighbours, int) const;

    void hasBottomRightNeighbour(std::vector<int> &neighbours, int) const;

    void hasLeftNeighbour(std::vector<int> &neighbours, int) const;

    void hasBottomLeftNeighbour(std::vector<int> &neighbours, int) const;

    void hasTopNeighbour(std::vector<int> &neighbours, int) const;

    void hasTopRightNeighbour(std::vector<int> &neighbours, int) const;

    void hasTopLeftNeighbour(std::vector<int> &neighbours, int) const;

    bool checkDensity();
};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
