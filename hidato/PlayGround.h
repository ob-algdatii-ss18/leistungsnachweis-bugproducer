//
// Created by joe on 10.04.18.
//

#ifndef LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
#define LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H

#include <vector>

class PlayGround {
public:
    PlayGround(unsigned int, int);

    int runCounter;
    const std::vector<std::vector<int>> &getPlayGroundSolved() const;
    const std::vector<int> &getNumberAddresses() const;
    const std::vector<int> &getNeighbours() const;

    void generateField();
    void fillPlayGround();
    void printPlayGrounds();
    void generateUnsolvedPlayground();
    void setPlayGroundSolved(const std::vector<std::vector<int>> &playGroundSolved);
    std::vector<int> calcNeighbours(int, bool,std::vector<std::vector<int>>);
    void setNumberAddresses(const std::vector<int> &numberAddresses);
    const std::vector<std::vector<int>> &getPlayGroundUnsolved() const;

private:

    std::vector<std::vector<int>> playGroundSolved;
    std::vector<std::vector<int>> playGroundUnsolved;
    std::vector<int> neighbours;
    std::vector<int> numberAddresses;

    unsigned int fieldSize;
    int currentPosition;
    int isRandom;
    int fieldCounter;

    void setStartPoint();
    bool checkForSameNeighbours(int, int,std::vector<std::vector<int>>);
    bool checkForInLine(int);
    void hasRightNeighbour(std::vector<int> &neighbours, bool, int ,std::vector<std::vector<int>>) const;
    void hasBottomNeighbour(std::vector<int> &neighbours, bool, int,std::vector<std::vector<int>>) const;
    void hasBottomRightNeighbour(std::vector<int> &neighbours, bool, int,std::vector<std::vector<int>>) const;
    void hasLeftNeighbour(std::vector<int> &neighbours, bool, int,std::vector<std::vector<int>>) const;
    void hasBottomLeftNeighbour(std::vector<int> &neighbours, bool, int,std::vector<std::vector<int>>) const;
    void hasTopNeighbour(std::vector<int> &neighbours, bool, int,std::vector<std::vector<int>>) const;
    void hasTopRightNeighbour(std::vector<int> &neighbours, bool, int,std::vector<std::vector<int>>) const;
    void hasTopLeftNeighbour(std::vector<int> &neighbours, bool, int,std::vector<std::vector<int>>) const;

};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
