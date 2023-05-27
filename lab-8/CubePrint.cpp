#include <iostream>
#include "Cube.h"

class CubePrint {
public:
    static void print(Cube& cube) {
        for (int i = 0; i < 6; i++)
        {
            std::cout << i + 1 << ' ' << "edge:" << '\n';
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    std::cout << cube.getCube()[i].edge[j][k] << ' ';
                }
                std::cout << '\n';
            }
        }
    }
};