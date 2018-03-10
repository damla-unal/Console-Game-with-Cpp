#include <iostream>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include<vector>
#include"varlik.h"
#include"engel.h"
#include"ogrenci.h"
#include"ates.h"
#include"dusman.h"

using namespace std;
void ekran()
{
    for (int i=1;i<81;i++)
        for(int j=1;j<19;j++)
    {
        cout<<termcolor::white;
        cout<<termcolor::on_blue;
        termcolor::gotoxy(i,j);
        cout<<" ";
    }

    for (int i=1;i<81;i++)
        for(int j=19;j<25;j++)
    {
        cout<<termcolor::white;
        cout<<termcolor::on_green;
        termcolor::gotoxy(i,j);
        cout<<char(176);
    }
}
int puan=0;
int main()
{
    srand(time(NULL));
    ekran();
    Engel *hoca =NULL;
    Ogrenci *Tarkan = new Ogrenci;

    unsigned long int frame=0;
    int engelZamani = rand()%10+1;
    int tus;
    int hainZamani=rand()%50+10;
    vector<Dusman *>Hainler;
    vector<Dusman *>::iterator kostok;
    vector<Ates *>Atesler;
    vector<Ates *>::iterator mermi;
    while(tus!=27)//esc ye basmadýðým sürece
    {
        if(kbhit())
        {
            tus=getch();
            if(tus=='A' || tus=='a')
            {
                Tarkan->hareketEt(-1,0);
            }
            else if(tus=='D' || tus=='d')
            {
                if (Tarkan->getX()<41)
                    Tarkan->hareketEt(1,0);
            }
            else if(tus=='S' || tus=='s')
            {
                Tarkan->setOtur(!Tarkan->getOtur());

            }
            else if(tus=='W' || tus=='w')
            {
                if(Tarkan->getZipla()==false)
                {
                    Tarkan->setZipla(true);
                    Tarkan->setYuksel(true);
                }


            }
            else if (tus==32)
            {
                Ates *disu=new Ates(Tarkan->getX()+3,Tarkan->getY()+1);
                Atesler.push_back(disu);//vector e eleman ekleme

            }
        }

        //bize düşman lazım

        if(frame%hainZamani==0)
        {
            Dusman *ahtapot;
            ahtapot = new Dusman;
            Hainler.push_back(ahtapot);
        }
        //engel yoksa ve zamaný geldiyse enfel oluþtur.
        if(hoca==NULL && frame%engelZamani==0)
        {
            hoca=new Engel;
        }
        //engel ilerlet

        if(hoca !=NULL)//engel varsa har1eket et
        {
            hoca->hareketEt(-1,0);
            if(hoca->getX()<2)//sola gelen engeli sil
            {
                delete hoca;
                hoca = NULL;
                engelZamani = rand()%20+5;
                puan +=20;

            }
        }


        //zıpla
        if(Tarkan->getZipla()==true)
        {
            if(Tarkan->getYuksel())
            {
              Tarkan->hareketEt(0,-1);
              if(Tarkan->getY()<3)
              {
                  Tarkan->setYuksel(false);
              }
            }else
            {//alçalıoyrsa
                Tarkan->hareketEt(0,1);
                if(Tarkan->getY()>14)
              {
                  Tarkan->setZipla(false);
              }
            }
        }
        //dusmanları ilerlet
        for(kostok=Hainler.begin();kostok!=Hainler.end();kostok++)
        {
            (*kostok)->hareketEt(-1,0);
        }
        //atesşleri ilerlet
        for(mermi=Atesler.begin();mermi<Atesler.end();mermi++)
        {
            (*mermi)->hareketEt(1,0);
        }
        //çarpışma testi
        //düşman vs Ates
        kostok=Hainler.begin();
        while(kostok!=Hainler.end())
        {
            bool carpti=false;
            mermi=Atesler.begin();
            while(mermi!=Atesler.end())
            {

                if((*mermi)->getX()>=(*kostok)->getX() &&
                   (*mermi)->getY()>=(*kostok)->getY() &&
                   (*mermi)->getY()>=(*kostok)->getY()+2)
                {
                    //çarptı
                    delete *mermi;
                    Atesler.erase(mermi);
                    delete *kostok;
                    Hainler.erase(kostok);
                    carpti=true;
                    puan+=10;
                    break;
                }
                else

                    mermi++;
            }
            if(!carpti)
                kostok++;



        }
        //düşman kontrol
        kostok=Hainler.begin();
        while(kostok!=Hainler.end())
        {
            if((*kostok)->getX()<2)
            {
                delete *kostok;
                Hainler.erase(kostok);

            }
            else
                kostok++;
        }
        // mermi kontrol
        mermi=Atesler.begin();
        while(mermi!=Atesler.end())
        {
            if((*mermi)->getX()>79)
            {
                delete *mermi;
                Atesler.erase(mermi);//vektorden kalan işaretçiye
            }
            else
            {
                mermi++;

            }
        }
        //engele çarpan mermi kontrol
        if(hoca!=NULL)
        {
            mermi=Atesler.begin();
          while(mermi!=Atesler.end())
        {
            if((*mermi)->getX()>=hoca->getX()&& (*mermi)->getY()>=hoca->getY())
            {
                delete *mermi;
                Atesler.erase(mermi);//vektorden kalan işaretçiye
            }
            else
            {
                mermi++;

            }
        }
        }
        //ölelim mi
            //engele çartıysa öl
        if(hoca!=NULL && Tarkan->getX()+3>=hoca->getX()&&
           Tarkan->getX()<=hoca->getX()+3&&
           Tarkan->getY()+4>=hoca->getY()
           )
        {
            cout<<"GAME OVER !!";
            break;
        }
        //düşmana çartıysan öl
        kostok=Hainler.begin();
        while(kostok!=Hainler.end())
        {
            if(Tarkan->getX()+3>=(*kostok)->getX()&&
               Tarkan->getX()<=(*kostok)->getX()+2&&
               Tarkan->getY()+4>=(*kostok)->getY()&&
               Tarkan->getY()<=(*kostok)->getY()+2)
            {
                return 0;
            }
            else
            {
                kostok++;
            }
        }

        Sleep(50);
        frame++;
        termcolor::white;

        termcolor::on_grey;
        termcolor::gotoxy(1,25);
        //if(hoca==NULL)
            cout<<"Frame:"<<frame;
        termcolor::gotoxy(1,1);
        cout<<"PUAN:"<<puan;


    }
    return 0;
}
