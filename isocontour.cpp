#include "isocontour.h"
#include <iostream>

using namespace std;

void isocontour(float p, float *coorx, float *coory, float *val,
    float *resx, float *resy, int &k)
{
  // p Valeur de l'isocontour
  // Sommets du carré en cours
  // ATTENTION les sommets sont un a un adjacents
  int i1,i2;

  // Résultats
  //initialisation du résultat
  for (k=0; k<4; k++)
  {
    resx[k]=-1;
    resy[k]=-1;
  }

  //Calcul du resultat pour un élément carré
  k=0;
  for (i1=0; i1<4; i1++)
  {
    i2=(i1+1)%4;
    if (val[i1]<p)
    {
      if (val[i2]>=p)
      {
        //Il y a un point entre i1 et i2
        resx[k] = (coorx[i1]+coorx[i2])/2;
        resy[k] = (coory[i1]+coory[i2])/2;
        k++; // Un résultat a été trouvé
      }
    }else
    {
      if (val[i2]<p)
      {
        //Il y a un point entre i1 et i2
        resx[k] = (coorx[i1]+coorx[i2])/2;
        resy[k] = (coory[i1]+coory[i2])/2;
        k++; // Un résultat a été trouvé
      }
    }
  }
  if (k==4)
  {
    float m = (val[0]+val[1]+val[2]+val[3])/4;
    if ((val[0]-p)*(m-p)<0){
      float tmpx = resx[0];
      float tmpy = resy[0];
      for (int i=0; i<3; i++)
      {
        resx[i]=resx[i+1];
        resy[i]=resy[i+1];
      }
      resx[3]=tmpx;
      resy[3]=tmpy;
    }
  }
  if (k==2) cerr << k <<endl;
//  for (int i=0; i<4; i++)
//    cout << resx[i] << "  " << resy[i] << endl;
}
