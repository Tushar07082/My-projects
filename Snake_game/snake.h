
#include <Windows.h>
#define width 50
#define height 25
class Snake
{
private:
        COORD pos;
        int len;
        int vel;
        char direction;

public:
        Snake(COORD pos, int vel)
        {
                this->pos = pos;
                this->vel = vel;
                this->len = 1;
                this->direction = 'n';
        }
        void change_dir(char dir) { direction = dir; }
        void move_snake()
        {
                switch (direction)
                {
                case 'w':
                        pos.Y -= vel;
                        break;
                case 's':
                        pos.Y += vel;
                        break;
                case 'a':
                        pos.X -= vel;
                        break;
                case 'd':
                        pos.X += vel;
                        break;
                }
        }
        COORD get_pose()
        {
                return pos;
        }
        bool eaten(COORD fpos){
                if(pos.X == fpos.X && pos.Y == fpos.Y){
                        return true;
                }else return false;
        }
        void grow(){
                len++;
        }
        bool collided(){
                if(pos.X < 1 || pos.X >= width-1 || pos.Y < 1 || pos.Y >= height-1){
                        return true;
                }    
                return false;
        }   
};
