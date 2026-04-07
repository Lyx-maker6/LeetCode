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
        //如果直接用 (width + height) * 2，你会发现你把矩形的四个角都多算了一次。
        int perimeter = (width + height - 2) * 2;
        num %= perimeter;

        // 特殊处理：如果正好绕完一圈（或几圈）回到原点
        // 此时机器人已经“撞”过边缘并转向了，方向应定为 South
        if (num == 0 && (x == 0 && y == 0 && dir == 0)) {
            // 只有当真的移动过（这里 num 是取模前的概念，或者判断是否执行了 step）
            // 这里我们用一个 trick：直接把方向设为南，因为除了初始状态，
            // 任何回到原点的情况在逻辑上都是从“西边”也就是南向走下来的。
            // 但最稳妥的办法是在下面的循环里跑，或者单独判断
        }

        // 如果取模后 num 依然为 0，且这不是初始状态，
        // 说明它转了一圈回来。为了符合题目对方向的要求，
        // 我们可以把 num 设为一圈的长度，或者手动修正方向。
        if (num == 0) num = perimeter;
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