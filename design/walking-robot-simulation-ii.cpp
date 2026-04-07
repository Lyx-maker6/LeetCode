class Robot {
private:
    int width;
    int height;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int dir;
    string dirs[4] = {"East", "North", "West", "South"};

    int x,y;

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->x = 0;
        this->y = 0;
        this->dir = 0;
    }
    
    void step(int num) {
        for(int i = 0;i < num;i++)
        {
            //先往前走
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            //判断是否撞墙，如果撞墙就进循环
            if(nx < 0 || nx >= width || ny < 0 || ny >= height)
            {
                //转向
                dir = (dir + 1) % 4;

                nx = x + dx[dir];
                ny = y + dy[dir];
            } 
            x = nx;
            y = ny;
        }

    }
    
    vector<int> getPos() {
       return {x,y}; 
        
    }
    
    string getDir() {
        return dirs[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */