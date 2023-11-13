#include "game.h"
void Game::fill(){
    for(unsigned int i{0}; i < game_matrix.size(); i++){
        for(unsigned int j{0}; j < game_matrix[i].size(); j++){
            if(game_matrix[i][j] == 'T' || game_matrix[i][j] == 'G'){
                continue;
            }else{
                game_matrix[i][j] = 'X';
            }
        }
    }
}
void Game::fill_t_and_g(){
    short int count{0};
    while(count < P_row){    
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0, 9);
        int row{dist(rd)};
        int col{dist(rd)};
        if(count == 0){
            game_matrix[col][row] = 'T';
            T_position[0] = col;
            T_position[1] = row;
        }else{
            game_matrix[col][row] = 'G';
            G_position[0] = col;
            G_position[1] = row;
        }
        ++count;
    }
}
void Game::display(){
    for(unsigned int i{0}; i < game_matrix.size(); i++){
        for(unsigned int j{0}; j < game_matrix[i].size(); j++){
            std::cout << game_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void Game::add_P(){
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 9);
        for(unsigned int i{0}; i < Game_row ; i++){
            int row{dist(rd)};
            int col{dist(rd)};
            if(game_matrix[col][row] == 'T' || game_matrix[col][row] == 'G'){
                continue;
            }else{
                game_matrix[col][row] = 'P';
                P_position[0][i] = col;
                P_position[1][i] = row;
            }
            
        }
}
void Game::move(){
    std::cout << std::endl ;
	std::cout << "where to move with G ( w, a, s, d, quit the game with q ) : ";
	char in{};
	std::cin >> in;
    game_matrix[G_position[0]][G_position[1]] = 'X';
	switch (in)
	{
	case 'w':
        if(G_position[0] == 0){break;}
		G_position[0] -= 1;
		game_matrix[G_position[0]][G_position[1]] = 'G';
		break;
	case 'a':
        if(G_position[1] == 0){break;}
		G_position[1] -= 1;
		game_matrix[G_position[0]][G_position[1]] = 'G';
		break;
	case 's':
        if(G_position[0] == 9){break;}
		G_position[0] += 1;
		game_matrix[G_position[0]][G_position[1]] = 'G';
		break;
	case 'd':
        if(G_position[1] == 9){break;}
		G_position[1] += 1;
		game_matrix[G_position[0]][G_position[1]] = 'G';
		break;
	case 'q':
		exit(0);
		break;
	}
}
bool Game::check(){
    if(game_matrix[G_position[0]][G_position[1]] == game_matrix [T_position[0]][T_position[1]]){
		//std::cout << "You have won" << std::endl;
        status = true;
		return false;
	}
	for(unsigned int i{}; i < P_position[0].size(); i++){
		if( (G_position[0] == P_position[0][i]) && (G_position[1] == P_position[1][i]) ){
			//std::cout << "You have lost" << std::endl;
			status = false;
            return false;
		}
	}
	int x_index_0{0}, y_index_0{0}, x_index_1{9}, y_index_1{9};
	if(G_position[0] < y_index_0){//rows check
		G_position[0] += 1;
	}else if(G_position[0] > y_index_1){
		G_position[0] -= 1;
	}else if(G_position[1] < x_index_0){//columns
		G_position[1] += 1;
	}else if(G_position[1] > x_index_1){
		G_position[1] -= 1;
	}
	game_matrix[G_position[0]][G_position[1]] = 'G';
	return true;
}
void Game::start(){
    fill_t_and_g();
    bool truth = true;
    while(truth != false){
    system("clear");
    fill();
    add_P();
    display();
    move();
    truth = check();
    }
    system("clear");
    if(status==true){
        std::cout << "You have won" << std::endl;
    }else{
        std::cout << "You have lost" << std::endl;
    }
}