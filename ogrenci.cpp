#include "ogrenci.h"

Ogrenci::Ogrenci():Varlik(5,15)
{
    setOtur(false);
    ciz();
}

Ogrenci::~Ogrenci()
{
    sil();

}
void Ogrenci::ciz()
{
    cout<<termcolor::white;
    cout<<termcolor::on_blue;
    if(getOtur())
    {
    termcolor::gotoxy(getX(),getY() );cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+2);cout<<"-"<<char(1)<<"-";
    termcolor::gotoxy(getX(),getY()+3);cout<<"< >";
    }
    else
    {
    termcolor::gotoxy(getX(),getY());cout<<" "<<char(1)<<" ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"\\|-";
    termcolor::gotoxy(getX(),getY()+2);cout<<" | ";
    termcolor::gotoxy(getX(),getY()+3);cout<<"/ \\";
    }
}
void Ogrenci::sil()
{
    cout<<termcolor::white;
    cout<<termcolor::on_blue;
    termcolor::gotoxy(getX(),getY()  );cout<<"   ";
    termcolor::gotoxy(getX(),getY()+1);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+2);cout<<"   ";
    termcolor::gotoxy(getX(),getY()+3);cout<<"   ";
}

void Ogrenci::setOtur(bool durum)
{
    mOtur =durum;
    ciz();
}
bool Ogrenci::getOtur()
{
   return mOtur;
}
void Ogrenci::setZipla(bool durum)
{
    mZipla=durum;
}
bool Ogrenci::getZipla()
{
    return mZipla;
}
void Ogrenci::setYuksel(bool durum)

{
    mYuksel=durum;
}
bool Ogrenci::getYuksel()
{
    return mYuksel;
}



