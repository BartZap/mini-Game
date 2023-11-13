#ifndef GAME_H
#define GAME_H
#include <iostream> 
#include <random>
#include <stdlib.h>
#include <vector>
class Game{
public:
    Game():game_matrix(Game_row,std::vector<char>(Game_col)),P_position(P_row,std::vector<int>(Game_col)),
            T_position(P_row), G_position(P_row)
    {}
    ~Game() = default;
    void fill();
    void fill_t_and_g();
    void display();
    void add_P();
    void move();
    bool check();
    void start();
private:
    const int Game_row{10};
    const int Game_col{10};
    const int P_row{2};
    bool status = false;
    std::vector<std::vector<char>> game_matrix;
    std::vector<std::vector<int>> P_position;
    std::vector<int> T_position;
    std::vector<int> G_position;
};
#endif