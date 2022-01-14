#include <vector>
#include <Windows.h>
#define width 50
#define height 25
using namespace std;
class Snake
{
private:
        COORD pos;
        int len;
        int vel;
        char direction;
        vector <COORD> body;

public:
        Snake(COORD pos, int vel)
        {
                this->pos = pos;
                this->vel = vel;
                this->len = 1;
                body.push_back(pos);
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
                body.push_back(pos);
                if(body.size()>len)body.erase(body.begin());
        }
        COORD get_pose()
        {
                return pos;
        }
        vector <COORD> get_body(){
                return body;
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
                for(int i=0;i<len-1;i++){
                        if(pos.X == body[i].X && pos.Y == body[i].Y){
                                return true;
                        }
                }

                return false;
        }   
};
