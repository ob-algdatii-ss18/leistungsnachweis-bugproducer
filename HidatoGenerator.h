//
// Created by joe on 10.04.18.
//

#ifndef LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
#define LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H

#include <vector>

class HidatoGenerator {
public:
    std::vector<std::vector<int>> generateField(unsigned int);

private:
    std::vector<std::vector<int>> playGround;
    void setStartPoint();
    unsigned int fieldSize;
    int currentPosition;
    std::vector<int> getNeighboursCount();
};


#endif //LEISTUNGSNACHWEIS_BUGPRODUCER_HIDATOGENERATOR_H
