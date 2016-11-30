class tLine : public tPoint
{
    protected:
        int x1, y1;
    public:
        tLine();
        ~tLine();
        int getx1() const;
        int gety1() const;
        void setx1(int tmp);
        void sety1(int tmp);
        void move();
};
