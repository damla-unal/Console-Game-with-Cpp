#include "varlik.h"

Varlik::Varlik()
{
    setX(5);
    setY(10);

}

Varlik::~Varlik()
{
    sil();
}

Varlik::Varlik(int x,int y)
{
    setX(x);
    setY(y);

}
void Varlik::ciz()
{
   //�ocuklar�m �izecek in�.
}
void Varlik::sil()
{
    //�ocucklar�m silecek in�.
}
void Varlik::hareketEt(int dx,int dy)
{
    sil();
    setX(getX()+dx); //mX+=dx;
    setY(getY()+dy); //mY+=dy;
    ciz();
}
void Varlik::setX(int x)
{
    mX=x>0 && x<81? x:mX;
    /*
    if(x>0 && x<81)
        mX=x;
    */
}
int  Varlik::getX()
{
    return mX;
}
void Varlik::setY(int y)
{
    mY= y>0 && y<25? y:mY;
}
int  Varlik::getY()
{
    return mY;
}
