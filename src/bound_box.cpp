#include <shapes/bound_box.h>

BoundBox::BoundBox()
    : BoundBox(0,0,0,0)
{
}

BoundBox::BoundBox(int zerox, int zeroy, int x, int y)
    : ZeroY(zeroy), ZeroX(zerox)
    , X(x), Y(y)
{}

BoundBox::~BoundBox()
{
}
