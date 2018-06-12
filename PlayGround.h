//
// Created by joe on 10.04.18.
//

#ifndef LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
#define LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H

#include <vector>

/**
 * Class for the playground.
 */
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
     * Set a solved playground.
     * @param playGroundSolved solved playground
    */
    void setPlayGroundSolved(const std::vector<std::vector<int>> &playGroundSolved);

    /**
     * Calculates the neighbours for a field.
     * @param position current position of a field
     * @param isPlaygroundFilled
     * @param playgroundSolved solved playground
     * @return neighbours of a field
     */
    std::vector<int> calcNeighbours(int position, bool isPlaygroundFilled, std::vector<std::vector<int>> playgroundSolved);

    /**
     * Get the addresses of the number.
     * @return vector with addresses
     */
    const std::vector<int> &getNumberAddresses() const;

    /**
     *  Set the addresses for the numbers.
     * @param numberAddresses vector with addresses
     */
    void setNumberAddresses(const std::vector<int> &numberAddresses);

    /**
     * Get neighbours.
     * @return neighbours in a vector
    */
    const std::vector<int> &getNeighbours() const;

    /**
     * Generates a playground.
     */
    void generatePlayground();

    /**
     * Fills the playground with random numbers.
    */
    void fillPlayGround();

    /**
     * Generates an unsolved playground from the solved playground.
    */
    void generateUnsolvedPlayground();

    /**
     * Get the unsolved playground.
     * @return unsolved playground
     */
    const std::vector<std::vector<int>> &getPlayGroundUnsolved() const;

    void printPlayGrounds();

private:

    std::vector<std::vector<int>> playGroundSolved;
    std::vector<std::vector<int>> playGroundUnsolved;
    std::vector<int> neighbours;
    std::vector<int> numberAddresses;

    unsigned int fieldSize;
    int currentPosition;
    int isRandom;
    int fieldCounter;

    /**
     * Sets the start point in the playground.
     */
    void setStartPoint();

    /**
     * Checks if the field has a right neighbour.
     * @param neighbours vector with the neighbours
     */
    void hasRightNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    /**
     * Checks if the field has a bottom neighbour.
     * @param neighbours vector with the neighbours
    */
    void hasBottomNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    /**
     * Checks if the field has a right bottom neighbour.
     * @param neighbours vector with the neighbours
     */
    void hasBottomRightNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    /**
     * Checks if the field has a left neighbour.
     * @param neighbours vector with the neighbours
     */
    void hasLeftNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    /**
     * Checks if the field has a left bottom neighbour.
     * @param neighbours vector with the neighbours
     */
    void hasBottomLeftNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    /**
     * Checks if the field has a top neighbour.
     * @param neighbours vector with the neighbours
     */
    void hasTopNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    /**
     * Checks if the field has a top right neighbour.
     * @param neighbours vector with the neighbours
     */
    void hasTopRightNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

    /**
     * Checks if the field has a top left neighbour.
     * @param neighbours vector with the neighbours
     */
    void hasTopLeftNeighbour(std::vector<int> &neighbours, bool, int, std::vector<std::vector<int>>) const;

};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
