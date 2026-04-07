class Robot {
private:
    int width, height;
    int x, y, d = 0;
    vector<string> dir = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        this->width = width, this->height = height;
        x = y = 0;
    }

    void step(int num) {
        num %= 2*(width + height - 2);
        if(num == 0){
            if(x == 0 && y == 0 && d == 0)
                d = 3;
            else if(x == width - 1 && y == 0 && d == 1)
                d = 0;
            else if(x == width - 1 && y == height - 1 && d == 2)
                d = 1;
            else if(x == 0 && y == height - 1 && d == 3)
                d = 2;
        }        
        while (num) {
            switch (d) {
            case 0:
                if (x + num <= width - 1) {
                    x += num;
                    num = 0;
                } else {
                    ++d;
                    num -= (width - 1 - x), x = width - 1;
                }
                break;
            case 1:
                if (y + num <= height - 1)
                    y += num, num = 0;
                else
                    ++d, num -= (height - 1 - y), y = height - 1;
                break;
            case 2:
                if (x - num >= 0)
                    x -= num, num = 0;
                else
                    ++d, num -= x, x = 0;
                break;
            default:
                if (y - num >= 0)
                    y -= num, num = 0;
                else
                    d = 0, num -= y, y = 0;
                break;
            }
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() { return dir[d]; }
};