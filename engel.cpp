#include "engel.h"

Engel::Engel():Varlik(78,16)
{
    ciz();
}

Engel::~Engel()
{
    sil();
}
void Engel::ciz()
{
    cout<<termcolor::yellow;
    cout<<termcolor::on_grey;
    termcolor::gotoxy(getX(),getY());cout<<"###";
    termcolor::gotoxy(getX(),getY()+1);cout<<"###";
    termcolor::gotoxy(getX(),getY()+2);cout<<"###";
}
void Engel::sil()
{
    cout<<termcolor::yellow;
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY());cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+2);cout<<"   ";
}
