#include <iostream>
#include <vector>
#include <string>
#include "Cube.h"

class CubeAlgorithm
{
public:
    static const int max_iteration = 1e6;

    // Метод для последовательного сборки кубика
    static bool solve(Cube& cube)
    {
        srand(std::time(NULL));
        cube.clearAnswers();
        if (cross(cube))
        {
            whiteEdge(cube);
            secondEdges(cube);
            yellowCross(cube);
            yellowEdge(cube);
            finishSolve(cube);
            while (cube.getCube()[0].edge[0][1] != cube.getCube()[0].edge[1][1]){
                cube.U();
            }
            return isSolved(0, cube) &&
            isSolved(1, cube) &&
            isSolved(2, cube) &&
            isSolved(3, cube) &&
            isSolved(4,cube) &&
            isSolved(5, cube);
        }
    }

    // Метод для проверки, что грань кубика собрана
    static bool isSolved(int number_verge, Cube& cube)
    {
        for (auto i : cube.getCube()[number_verge].edge)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i[j] != cube.getCube()[number_verge].edge[1][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    // Метод для последнего этапа сборки кубика
    static void finishSolve(Cube& cube)
    {
        for (int x = 0; x < max_iteration; x++)
        {
            for (int k = 0; k < 4; k++)
            {
                int num1 = rand() % 2;
                if (num1 == 1)
                {
                    cube.rp();
                    cube.lp();
                    for (int i = 0; i < 5; i++)
                        cube.rp();
                    for (int i = 0; i < 5; i++)
                        cube.lp();
                    int number;
                    for (int i = 0; i < 4; i++)
                    {
                        number = 0;
                        for (int j = 0; j < 4; j++)
                        {
                            if (cube.getCube()[0].edge[0][0] == cube.getCube()[0].edge[0][1] &&
                                cube.getCube()[0].edge[0][2] == cube.getCube()[0].edge[0][1])
                            {
                                number++;
                            }
                            cube.horizontalRotate();
                        }
                        if (number == 4)
                            return;
                    }
                    cube.rp();
                    cube.lp();
                    for (int i = 0; i < 5; i++)
                        cube.rp();
                    for (int i = 0; i < 5; i++)
                        cube.lp();
                    for (int i = 0; i < 4; i++)
                    {
                        number = 0;
                        for (int j = 0; j < 4; j++)
                        {
                            if (cube.getCube()[0].edge[0][0] == cube.getCube()[0].edge[0][1] &&
                                cube.getCube()[0].edge[0][2] == cube.getCube()[0].edge[0][1])
                            {
                                number++;
                            }
                            cube.horizontalRotate();
                        }
                        if (number == 4)
                            return;
                    }
                }
                cube.horizontalRotate();
            }
        }
    }

    // Метод для сборки желтой грани
    static void yellowEdge(Cube& cube)
    {
        for (int x = 0; x < max_iteration; x++)
        {
            for (int k = 0; k < 4; k++)
            {
                int num1 = rand() % 2;
                if (num1 == 0)
                {
                    cube.rp();
                    cube.rp();
                    cube.rp();
                    cube.horizontalRotate();
                    cube.lp();
                    cube.lp();
                    cube.lp();
                    cube.horizontalRotateL();
                    int num2 = rand() % 5;
                    for (int i = 0; i < num2; i++)
                    {
                        cube.U();
                    }
                    for (int i = 0; i < 4; i++)
                    {
                        while (cube.getCube()[4].edge[2][0] != 'Y')
                        {
                            cube.L();
                            cube.D();
                            cube.L_();
                            cube.D_();
                        }
                        cube.U();
                    }
                    for (int i = 0; i < 4; i++)
                    {
                        int number = 0;
                        for (int j = 0; j < 4; j++)
                        {
                            if (cube.getCube()[0].edge[0][0] == cube.getCube()[0].edge[1][1] &&
                                cube.getCube()[0].edge[0][2] == cube.getCube()[0].edge[1][1])
                            {
                                number++;
                            }
                            cube.horizontalRotate();
                        }
                        if (number == 4)
                        {
                            return;
                        }
                        cube.U();
                    }

                }
                cube.horizontalRotate();
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {

                    }
                }
            }


        }
    }

    // Метод для сборки желтого креста
    static void yellowCross(Cube& cube)
    {
        for (int x = 0; x < max_iteration; x++)
        {
            for (int k = 0; k < 4; k++)
            {
                cube.F();
                int num1 = rand() % 3;
                for (int i = 0; i < num1; i++)
                {
                    cube.rp();
                }
                cube.F_();
                cube.horizontalRotate();
            }
            if (cube.getCube()[4].edge[0][1] == 'Y' && cube.getCube()[4].edge[1][0] == 'Y' && cube.getCube()[4].edge[2][1] == 'Y' &&
                cube.getCube()[4].edge[1][2] == 'Y')
            {
                break;
            }
        }
    }

    // Метод для сборки второго слоя
    static void secondEdges(Cube& cube)
    {
        for (int x = 0; x < max_iteration; x++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (cube.getCube()[0].edge[1][1] == cube.getCube()[0].edge[0][1])
                {
                    if (cube.getCube()[4].edge[2][1] == cube.getCube()[1].edge[1][1])
                    {
                        cube.U();
                        cube.rp();
                        cube.horizontalRotate();
                        cube.lp();
                        cube.horizontalRotateL();
                    }
                    if (cube.getCube()[4].edge[2][1] == cube.getCube()[3].edge[1][1])
                    {
                        cube.U_();
                        cube.lp();
                        cube.horizontalRotateL();
                        cube.rp();
                        cube.horizontalRotate();
                    }
                }
                int num1 = rand() % 2, num2 = rand() % 2, num3 = rand() % 4;
                if (num1 == 0)
                {
                    cube.U();
                    cube.rp();
                    cube.horizontalRotate();
                    cube.lp();
                    cube.horizontalRotateL();
                }
                if (num2 == 0)
                {
                    cube.U_();
                    cube.lp();
                    cube.horizontalRotateL();
                    cube.rp();
                    cube.horizontalRotate();
                }
                for (int i = 0; i < num3; i++)
                {
                    cube.U();
                }
                cube.horizontalRotate();

            }
            bool check = true;
            for (int k = 0; k < 4; k++)
            {
                if (cube.getCube()[k].edge[1][0] != cube.getCube()[k].edge[1][1] || cube.getCube()[k].edge[1][2] != cube.getCube()[k].edge[1][1])
                {
                    check = false;
                }
            }
            if (check)
                break;
        }

    }

    // Метод для сборки белой грани
    static void whiteEdge(Cube& cube)
    {

        for (int x = 0; x < max_iteration; x++)
        {
            for (int k = 0; k < 4; k++)
            {

                int num1 = rand() % 7, num2 = rand() % 7, num3 = rand() % 4;
                for (int i = 0; i < num1; i++)
                {
                    cube.rp();
                }
                for (int i = 0; i < num2; i++)
                {
                    cube.lp();
                }
                for (int i = 0; i < num3; i++)
                {
                    cube.U();
                }
                cube.horizontalRotate();
            }

            if (isSolved(5, cube))
            {
                bool check = true;
                for (int k = 0; k < 4; k++)
                {
                    if (cube.getCube()[0].edge[2][1] != cube.getCube()[0].edge[2][0] || cube.getCube()[0].edge[2][1] != cube.getCube()[0].edge[2][2])
                    {
                        check = false;
                        break;
                    }
                    cube.horizontalRotate();
                }
                if (check)
                {
                    return;
                }
            }
        }
    }

    // Метод для сборки креста
    static bool cross(Cube& cube)
    {
        bool check = false;
        for (int x = 0; x < max_iteration; x++)
        {
            if (cube.getCube()[4].edge[0][1] == 'W' && cube.getCube()[4].edge[1][0] == 'W' && cube.getCube()[4].edge[2][1] == 'W' &&
                cube.getCube()[4].edge[1][2] == 'W')
            {
                check = true;
                break;
            }
            for (int k = 0; k < 4; k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (cube.getCube()[0].edge[i][j] == 'W')
                        {
                            if (i == 0 && j == 1)
                            {
                                cube.F();
                                while (cube.getCube()[4].edge[1][2] == 'W')
                                {
                                    cube.U();
                                }
                                cube.R();
                            }
                            if (i == 1 && j == 0)
                            {
                                while (cube.getCube()[4].edge[1][0] == 'W')
                                {
                                    cube.U();
                                }
                                cube.L_();
                            }
                            if (i == 1 && j == 2)
                            {
                                while (cube.getCube()[4].edge[1][2] == 'W')
                                {
                                    cube.U();
                                }
                                cube.R();
                            }
                            if (i == 2 && j == 1)
                            {
                                cube.F();
                                while (cube.getCube()[4].edge[1][0] == 'W')
                                {
                                    cube.U();
                                }
                                cube.L_();
                            }
                        }
                    }
                }
                cube.horizontalRotate();
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (cube.getCube()[5].edge[i][j] == 'W')
                    {
                        int k1 = i, k2 = j;
                        if (i == 0 && j == 1)
                        {
                            k1 = 2;
                            k2 = 1;
                        }
                        if (i == 2 && j == 1)
                        {
                            k1 = 0;
                            k2 = 1;
                        }
                        while (cube.getCube()[4].edge[k1][k2] == 'W')
                            cube.U();
                        if (i == 0 && j == 1)
                        {
                            cube.F2();
                        }
                        if (i == 1 && j == 0)
                        {
                            cube.L2();
                        }
                        if (i == 1 && j == 2)
                        {
                            cube.R2();
                        }
                        if (i == 2 && j == 1)
                        {
                            cube.B2();

                        }

                    }
                }
            }
        }
        if (check)
        {
            for (int k = 0; k < 4; k++)
            {
                while (cube.getCube()[0].edge[1][1] != cube.getCube()[0].edge[0][1])
                {
                    cube.U();
                }
                cube.F2();
                cube.horizontalRotate();
            }
            return true;
        }
        return false;
    }

    // Проверка на корректность кубика и возможность его собрать
    static bool isCorrect(Cube& cube)
    {
        if (CubeAlgorithm::solve(cube))
            return true;
        else
            return false;
    }

};
