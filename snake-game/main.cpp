#include <iostream>
#include <conio.h>

bool gameOver;
const int WIDTH{20};
const int HEIGHT{20};
int x, y;
int fruitX, fruitY;
int score;

enum eDirection{STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setUp();
void draw();
void input();
void logic();
int main(){

    setUp();
    while(!gameOver){
        draw();
        input();
        logic();
        // sleep(10);
    }


    return 0;
}

void setUp(){
    gameOver =false;
    dir = STOP;
    x = WIDTH/2;
    y = HEIGHT/2;
    fruitX = std::rand() % WIDTH;
    fruitY = std::rand() % HEIGHT;
    score = 0;
}

void draw(){
    system("cls");  //Clear screen
    for(int i{0}; i < WIDTH+2; i++)
        std::cout << "#";
    std::cout << std::endl;

    for(int i{0}; i < HEIGHT; i++){
        for(int j{0}; j < WIDTH; j++){
            if(j == 0)
                std::cout << "#";
                
            if (i == x && j == y)
                std::cout << "o";
            else if(i == fruitX && j == fruitY)
                std::cout << "f";
            else
                std::cout << " ";

            if(j == WIDTH -1)
                std::cout << "#";
        }
        std::cout << std::endl;

    }

    for(int i{0}; i < WIDTH+2; i++)
        std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score : " << score << std::endl;    
}

void input(){
    if(_kbhit()){
        switch (_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            gameOver = true;
            break;
        default:
            break;
        }

    }

}

void logic(){
    switch (dir){
    case LEFT:
        y--;
        break;
    case RIGHT:
        y++;
        break;
    case UP:
        x--;
        break;
    case DOWN:
        x++;
        break;
    
    default:
        break;
    }

    if(x > WIDTH+2 || x < 0 || y >= HEIGHT || y < 0)
        gameOver = true;
    
    if (x == fruitX && y == fruitY){
        score += 10;
        fruitX = std::rand() % WIDTH;
        fruitY = std::rand() % HEIGHT;
    }

}