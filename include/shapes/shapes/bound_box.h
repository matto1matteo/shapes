class BoundBox
{
public:
    BoundBox();
    BoundBox(BoundBox &&) = default;
    BoundBox(const BoundBox &) = default;
    BoundBox &operator=(BoundBox &&) = default;
    BoundBox &operator=(const BoundBox &) = default;
    ~BoundBox();

    BoundBox(int zerox, int zeroy, int x, int y);

    int ZeroX;
    int ZeroY;
    int X;
    int Y;

private:
    
};

