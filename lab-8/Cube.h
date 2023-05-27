#ifndef CUBE_H
#define CUBE_H

#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<cstdlib>
#include<vector>
#include "Edge.h"

class Cube {
public:
    Cube(std::ifstream &FILE) {
        char colors[9];
        int k;
        for (int i = 0; i < 6; i++) {
            k = 0;
            for (int j = 0; j < 3; j++) {
                for (int q = 0; q < 3; q++) {
                    FILE >> colors[k];
                    k++;
                }

            }
            int edge_number = colors_number[colors[4]];
            k = 0;
            for (auto & j : cube[edge_number].edge) {
                for (char & q : j) {
                    q = colors[k];
                    k++;
                }
            }

        }
    }

    Cube() {
        for (auto & it : colors_number) {
            int edge_number = it.second;
            char edge_color = it.first;
            for (auto & i : cube[edge_number].edge) {
                for (char & j : i) {
                    j = edge_color;
                }
            }
        }
    }

    Cube(const Cube &other) {
        for (int k = 0; k < 6; k++) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    cube[k].edge[i][j] = other.cube[k].edge[i][j];
                }
            }
        }
    }

    ~Cube() = default;

    // Методы по вращению граней
    void R() {
        int edges[] = {0, 4, 2, 5};
        int row[] = {0, 1, 2, 0, 1, 2, 2, 1, 0, 0, 1, 2};
        int column[] = {2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2};
        rotate(edges, row, column, 1, 1);
        answers.push_back('R');
    }

    void R_() {
        int edges[] = {5, 2, 4, 0};
        int row[] = {2, 1, 0, 0, 1, 2, 2, 1, 0, 2, 1, 0};
        int column[] = {2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2};
        rotate(edges, row, column, 1, 0);
        answers.push_back('R');
        answers.push_back('_');
    }

    void R2() {
        this->R();
        this->R();
        answers.push_back('R');
        answers.push_back('2');
    }

    void L() {
        int edges[] = {5, 2, 4, 0};
        int row[] = {0, 1, 2, 2, 1, 0, 0, 1, 2, 0, 1, 2};
        int column[] = {0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0};
        rotate(edges, row, column, 3, 1);
        answers.push_back('L');
    }

    void L_() {
        int edges[] = {0, 4, 2, 5};
        int row[] = {2, 1, 0, 2, 1, 0, 0, 1, 2, 2, 1, 0};
        int column[] = {0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0};
        rotate(edges, row, column, 3, 0);
        answers.push_back('L');
        answers.push_back('_');
    }

    void L2() {
        this->L();
        this->L();
        answers.push_back('L');
        answers.push_back('2');
    }

    void F() {
        int edges[] = {1, 5, 3, 4};
        int row[] = {0, 1, 2, 0, 0, 0, 2, 1, 0, 2, 2, 2};
        int column[] = {0, 0, 0, 2, 1, 0, 2, 2, 2, 0, 1, 2};
        rotate(edges, row, column, 0, 1);
        answers.push_back('F');
    }

    void F_() {
        int edges[] = {4, 3, 5, 1};
        int row[] = {2, 2, 2, 0, 1, 2, 0, 0, 0, 2, 1, 0};
        int column[] = {2, 1, 0, 2, 2, 2, 0, 1, 2, 0, 0, 0};
        rotate(edges, row, column, 0, 0);
        answers.push_back('F');
        answers.push_back('_');
    }

    void F2() {
        this->F();
        this->F();
        answers.push_back('F');
        answers.push_back('2');
    }

    void B() {
        int edges[] = {1, 4, 3, 5};
        int row[] = {0, 1, 2, 0, 0, 0, 2, 1, 0, 2, 2, 2};
        int column[] = {2, 2, 2, 0, 1, 2, 0, 0, 0, 2, 1, 0};
        rotate(edges, row, column, 2, 1);
        answers.push_back('B');
    }

    void B_() {
        int edges[] = {5, 3, 4, 1};
        int row[] = {2, 2, 2, 0, 1, 2, 0, 0, 0, 2, 1, 0};
        int column[] = {0, 1, 2, 0, 0, 0, 2, 1, 0, 2, 2, 2};
        rotate(edges, row, column, 2, 0);
        answers.push_back('B');
        answers.push_back('_');
    }

    void B2() {
        this->B();
        this->B();
        answers.push_back('B');
        answers.push_back('2');
    }

    void U() {
        int edges[] = {3, 2, 1, 0};
        int row[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int column[] = {2, 1, 0, 2, 1, 0, 2, 1, 0, 2, 1, 0};
        rotate(edges, row, column, 4, 1);
        answers.push_back('U');
    }

    void U_() {
        int edges[] = {0, 1, 2, 3};
        int row[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int column[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
        rotate(edges, row, column, 4, 0);
        answers.push_back('U');
        answers.push_back('_');
    }

    void U2() {
        this->U();
        this->U();
        answers.push_back('U');
        answers.push_back('2');
    }

    void D() {
        int edges[] = {0, 1, 2, 3};
        int row[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        int column[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
        rotate(edges, row, column, 5, 1);
        answers.push_back('D');
    }

    void D_() {
        int edges[] = {3, 2, 1, 0};
        int row[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        int column[] = {2, 1, 0, 2, 1, 0, 2, 1, 0, 2, 1, 0};
        rotate(edges, row, column, 5, 0);
        answers.push_back('D');
        answers.push_back('_');
    }

    void D2() {
        this->D();
        this->D();
        answers.push_back('D');
        answers.push_back('2');
    }

    void rp() {
        this->R();
        this->U();
        this->R_();
        this->U_();
    }

    void rp_() {
        this->R_();
        this->U_();
        this->R();
        this->U();
    }

    void lp() {
        this->L_();
        this->U_();
        this->L();
        this->U();
    }

    void lp_() {
        this->L();
        this->U();
        this->L_();
        this->U_();
    }

    // Вывод результата в файл
    void answers_output() {
        std::ofstream FILE;
        FILE.open("/Users/DNK/Desktop/cpp-labs/output.txt");
        for (auto it = answers.begin(); it != answers.end(); it++) {
            FILE << *it;
        }
    }

    // геттер для куба
    const Edge *getCube() const {
        return cube;
    }

    // удаление записанных ответов
    void clearAnswers() {
        answers.clear();
    }

    void horizontalRotate() {
        int edges[] = {3, 2, 1, 0};
        char save[3];
        for (int i = 0; i < 3; i++) {
            save[i] = cube[0].edge[1][i];
        }
        for (int edge : edges) {
            for (int i = 0; i < 3; i++) {
                char saved = cube[edge].edge[1][i];
                cube[edge].edge[1][i] = save[i];
                save[i] = saved;
            }
        }
        answers.push_back('M');
        answers.push_back('_');
        this->D_();
        this->U();
    }

    void horizontalRotateL() {
        int edges[] = {0, 1, 2, 3};
        char save[3];
        for (int i = 0; i < 3; i++) {
            save[i] = cube[3].edge[1][i];
        }
        for (int edge : edges) {
            for (int i = 0; i < 3; i++) {
                char saved = cube[edge].edge[1][i];
                cube[edge].edge[1][i] = save[i];
                save[i] = saved;
            }
        }
        answers.push_back('M');
        this->D();
        this->U_();
    }

    // генерит рандомный кубик
    void generateRandomCube() {
        srand(std::time(NULL));
        int n = rand() % 100;
        for (int i = 0; i < n; i++) {
            random_rotate();
        }
    }

private:
    Edge cube[6];
    std::map<char, int> colors_number = {{'R', 0},
                                         {'G', 1},
                                         {'O', 2},
                                         {'B', 3},
                                         {'Y', 4},
                                         {'W', 5}};
    std::vector<char> answers;

    // Метод для вращения кубика по заданным параметрам
    void rotate(int edges[], int row[], int column[], int roll_edge, bool direction) {
        int current, k = 0;
        char save[3] = {cube[edges[3]].edge[row[9]][column[9]], cube[edges[3]].edge[row[10]][column[10]],
                        cube[edges[3]].edge[row[11]][column[11]]};
        for (int i = 0; i < 4; i++) {
            current = edges[i];
            for (char & j : save) {
                int pos1 = row[k];
                int pos2 = column[k];
                k++;
                char s;
                s = cube[current].edge[pos1][pos2];
                cube[current].edge[pos1][pos2] = j;
                j = s;
            }
        }
        char updated[3][3];
        if (direction) {
            updated[0][2] = cube[roll_edge].edge[0][0];
            updated[1][2] = cube[roll_edge].edge[0][1];
            updated[2][2] = cube[roll_edge].edge[0][2];
            updated[2][1] = cube[roll_edge].edge[1][2];
            updated[2][0] = cube[roll_edge].edge[2][2];
            updated[1][0] = cube[roll_edge].edge[2][1];
            updated[0][0] = cube[roll_edge].edge[2][0];
            updated[0][1] = cube[roll_edge].edge[1][0];
        } else {
            updated[0][0] = cube[roll_edge].edge[0][2];
            updated[1][0] = cube[roll_edge].edge[0][1];
            updated[2][0] = cube[roll_edge].edge[0][0];
            updated[2][1] = cube[roll_edge].edge[1][0];
            updated[2][2] = cube[roll_edge].edge[2][0];
            updated[1][2] = cube[roll_edge].edge[2][1];
            updated[0][2] = cube[roll_edge].edge[2][2];
            updated[0][1] = cube[roll_edge].edge[1][2];
        }
        updated[1][1] = cube[roll_edge].edge[1][1];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cube[roll_edge].edge[i][j] = updated[i][j];
            }
        }

    }

    // Рандомно определеяет операцию для вращения
    void random_rotate() {
        int value = rand() % 18;
        switch (value) {
            case 0:
                this->R();
                break;
            case 1:
                this->R_();
                break;
            case 2:
                this->R2();
            case 3:
                this->U();
                break;
            case 4:
                this->U_();
                break;
            case 5:
                this->U2();
                break;
            case 6:
                this->L();
                break;
            case 7:
                this->L_();
                break;
            case 8:
                this->L2();
                break;
            case 9:
                this->D();
                break;
            case 10:
                this->D_();
                break;
            case 11:
                this->D2();
                break;
            case 12:
                this->F();
                break;
            case 13:
                this->F_();
                break;
            case 14:
                this->F2();
                break;
            case 15:
                this->B();
                break;
            case 16:
                this->B_();
                break;
            case 17:
                this->B2();
                break;
        }
    }
};

#endif