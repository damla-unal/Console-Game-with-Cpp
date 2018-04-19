#ifndef VARLIK_H
#define VARLIK_H
#include<iostream>
#include"termcolor.hpp"

using namespace std;

class Varlik
{
    public:
        Varlik();
        Varlik(int x,int y);
        virtual void ciz();
        virtual void sil(); //ezmeye yarar. atamdaki deðil çocuðumdaki fonk çaðýrsýn.
        void hareketEt(int dx,int dy);
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
        virtual ~Varlik(); // genelde dtor lar virtual alýr.

    protected:
        int mX;
        int mY;

    private:
};

#endif // VARLIK_H
