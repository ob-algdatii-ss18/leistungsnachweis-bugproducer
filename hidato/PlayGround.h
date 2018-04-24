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
    std::vector<int> calcNeighbours();

    const std::vector<int> &getNeighbours() const;
    void fillPlayGround();
    void printPlayGround();
    void generateUnsolvedPlayground();

private:
    std::vector<std::vector<int>> playGroundSolved;
    std::vector<std::vector<int>> playGroundUnsolved;


    void setStartPoint();

    std::vector<int> neighbours;


    unsigned int fieldSize;
    int currentPosition;
    int isRandom;
    int fieldCounter;



    void hasRightNeighbour(std::vector<int> &neighbours) const;

    void hasBottomNeighbour(std::vector<int> &neighbours) const;

    void hasBottomRightNeighbour(std::vector<int> &neighbours) const;

    void hasLeftNeighbour(std::vector<int> &neighbours) const;

    void hasBottomLeftNeighbour(std::vector<int> &neighbours) const;

    void hasTopNeighbour(std::vector<int> &neighbours) const;

    void hasTopRightNeighbour(std::vector<int> &neighbours) const;

    void hasTopLeftNeighbour(std::vector<int> &neighbours) const;

    bool checkDensity();
};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
