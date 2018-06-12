//
// Created by joe on 10.04.18.
//

#ifndef LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
#define LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H

#include <vector>

class PlayGround {
public:
    /**
     * Constructor for init the playground.
     * @param fieldSize
     * @param isRandom
     */
    PlayGround(unsigned int fieldSize, int isRandom);

    int runCounter;

    /**
     * Get the solved playground.
     * @return solved playground
     */
    const std::vector<std::vector<int>> &getPlayGroundSolved() const;

    /**
     * Calculates the neighbours for a field.
     * @param position current position of a field
     * @param isPlaygroundFilled
     * @return neighbours of a field
     */
    std::vector<int> calcNeighbours(int, bool, std::vector<std::vector<int>>);

    /**
     * Get neighbours.
     * @return neighbours in a vector
     */
    const std::vector<int> &getNumberAddresses() const;

    const std::vector<int> &getNeighbours() const;


    void generateField();

    /**
    * Fills the playground with random numbers.
    */
    void fillPlayGround();

    void printPlayGrounds();

    /**
     * Generates an unsolved playground from the solved playground.
     */
    void generateUnsolvedPlayground();

    /**
     * Set a solved playground.
     * @param playGroundSolved solved playground
     */
    void setPlayGroundSolved(const std::vector<std::vector<int>> &playGroundSolved);

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

    void hasRightNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    void hasBottomNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    void hasBottomRightNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    void hasLeftNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    void hasBottomLeftNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    void hasTopNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    void hasTopRightNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    void hasTopLeftNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
