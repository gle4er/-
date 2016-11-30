class tPoint 
{
    protected:
        int x, y, vecx, vecy;
        uint8_t color[4];
    public:
        tPoint();
        tPoint(int w, int h);
        ~tPoint();
        void movePoint(int SCREEN_WIDTH, int SCREEN_HEIGHT); 
        void move(); 
        int getx() const; 
        int gety() const; 
        int getvecx() const;
        int getvecy() const;
        uint8_t *getColor();
        void setx(int tmp); 
        void sety(int tmp);
        void setvecx(int tmp);
        void setvecx(int tmp, int tmp2);
        void setvecy(int tmp);
        void setvecy(int tmp, int tmp2);
        void setColor(uint64_t tmp);
};
