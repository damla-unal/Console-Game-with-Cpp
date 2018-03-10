#include "ates.h"

Ates::Ates(int x, int y):Varlik(x,y)
{
    ciz();
}

Ates::~Ates()
{
    sil();
}
void Ates::ciz()
{
    cout<<termcolor::yellow;
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY());cout<<"*";

}
void Ates::sil()
{
    //cout<<termcolor::yellow;
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY());cout<<" ";

}
