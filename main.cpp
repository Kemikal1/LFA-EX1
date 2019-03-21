#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


ifstream f("in.txt");
int nrq=4;//nr de stari
int nrt=8;//nr de tranzitii
int nrf=1;//nr de stari finale

int fi[100];// indica daca starea este sau nu finala  0=nu,1=da;

char q[100][100][100];
//primul parametru, starea de unde pleaca tranzitia
//al doilea parametru ,starea unde unde ajunge tranzitia
//valoarea casutei,pasul tranzitiei.


//mai intai citim tranzitiile dupa care citim starile finale
void citire()
{
    int s,p;
    int k,m;
    int o;
    for (k=0,m=0;k<8;k++)
    {
        f>>s;
        f>>p;
       while (q[s][p][m])
        m++;
        f>>q[s][p][m];
    }
    while(nrf)
    {
        f>>o;
        nrf--;
        fi[o]=1;
    }
}
void afis()
{
    int i,j,k;
    for(i=1;i<=nrq;i++)
        {for(j=1;j<=nrq;j++)
          if(q[i][j][0]==0)cout<<0<<" ";
          else cout<<q[i][j][0]<<" ";
      cout<<endl;}
}
int main()
{
    char *cuv=new char[1000];
    char aux;
    int stare=1,i=0,j=0,n,m;
    //stare=starea curenta.
    citire();
    afis();
    cout<<"cuvantul:";
    cin>>cuv;
    /*cuv[0]='a';
    cuv[1]='a';
    cuv[2]='a';
    cuv[3]='a';*/
    n=strlen(cuv)-1;

    while(n-i>n/2)
    {
        aux=cuv[i];
        cuv[i]=cuv[n-i];
        cuv[n-i]=aux;
        i++;
    }
    i=0;

    while (n-i>-1 && j<=nrq+1)
    {

        for(j=1;j<=nrq&&j!=-1;j++)
        {

        for(m=0;q[stare][j][m]&&m!=-1;m++)
         if (q[stare][j][m]==cuv[n-i])
           {

            cuv[n-i]=NULL;
            stare=j;
            j=-1;
            m=-1;
            i++;
           }
           }


    }


    cout<<endl<<cuv<<endl;
    if(fi[stare])
        cout<<"apartine";
    else
        cout<<"nu apartine";





    return 0;
}
