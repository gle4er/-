class tPoint 
{
    private:
        int x, y;
        uint8_t color[4];
    public:
        int getx() const; 
        int gety() const; 
        uint8_t *getColor();
        void setx(int tmp); 
        void sety(int tmp);
        void setColor(uint64_t tmp);
};
