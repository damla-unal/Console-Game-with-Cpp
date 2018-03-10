#include "dusman.h"

Dusman::Dusman()
{
    setX(79);
    setY(rand()%14+1);
    ciz();
}

Dusman::~Dusman()
{
    sil();
}
void Dusman::ciz()
{
    cout<<termcolor::dark;
    cout<<termcolor::yellow;
    termcolor::gotoxy(getX(),getY());cout<<"<<";
    termcolor::gotoxy(getX(),getY()+1);cout<<"<<";

}
void Dusman::sil()
{
    cout<<termcolor::yellow;
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY());cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";

}
