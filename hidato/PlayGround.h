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

    int runCounter;

    const std::vector<std::vector<int>> &getPlayGroundSolved() const;



    std::vector<int> calcNeighbours(int, bool);

    const std::vector<int> &getNeighbours() const;
    void fillPlayGround();
    void printPlayGrounds();
    void generateUnsolvedPlayground();
    void setPlayGroundSolved(const std::vector<std::vector<int>> &playGroundSolved);

private:

    std::vector<std::vector<int>> playGroundSolved;
    std::vector<std::vector<int>> playGroundUnsolved;


    void setStartPoint();

    std::vector<int> neighbours;
    std::vector<int> numberAddresses;
public:
    const std::vector<int> &getNumberAddresses() const;

    void setNumberAddresses(const std::vector<int> &numberAddresses);

    const std::vector<std::vector<int>> &getPlayGroundUnsolved() const;

private:

    unsigned int fieldSize;
    int currentPosition;
    int isRandom;
    int fieldCounter;

    bool checkForSameNeighbours(int, int);

private:

    void hasRightNeighbour(std::vector<int> &neighbours, bool, int ) const;

    void hasBottomNeighbour(std::vector<int> &neighbours, bool, int) const;

    void hasBottomRightNeighbour(std::vector<int> &neighbours, bool, int) const;

    void hasLeftNeighbour(std::vector<int> &neighbours, bool, int) const;

    void hasBottomLeftNeighbour(std::vector<int> &neighbours, bool, int) const;

    void hasTopNeighbour(std::vector<int> &neighbours, bool, int) const;

    void hasTopRightNeighbour(std::vector<int> &neighbours, bool, int) const;

    void hasTopLeftNeighbour(std::vector<int> &neighbours, bool, int) const;

};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
