#include <bits/stdc++.h>
#include "snake.h"
#include <ctime>
#include "Food.h"
#include <unistd.h>
#include <conio.h>
#define width 50
#define height 25
using namespace std;
int x=10,y=10;
Snake snake({width/2,height/2},1);
Food food;
void board(){
        COORD snakepos = snake.get_pose();
        COORD foodpos = food.get_pos();
        for(int i=0;i<height;i++){
                cout<<"\t\t*";
                for(int j=0;j<width-2;j++){
                        if(i==0 || i== height -1){
                                cout<<"*";
                        }else if(i==snakepos.Y && j+1 ==snakepos.X){
                                cout<<"0";
                        }
                        else if(i== foodpos.Y && j+1 == foodpos.X){
                                cout<<"f";
                        }
                        else cout<<" ";
                        
                }
                cout<<"*\n";
        }
}
int main(){
        system("CLS");
        srand(time(NULL));
        food.gen_food();
        bool game_over = false;
        while(!game_over){
                board();
                if(kbhit()){
                        snake.change_dir(getch());
                }
                
                if(snake.eaten(food.get_pos())){
                        food.gen_food();
                        snake.grow();
                }
                if(snake.collided())game_over = true;
                snake.move_snake();
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        }
        // cout<<"Hello world\rasas";
        
}