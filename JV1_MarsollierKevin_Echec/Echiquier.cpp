#ifndef ECHEQUIER_CPP
#define ECHEQUIER_CPP

#include <iostream>
#include "Echiquier.h"
#include "Piece.h"

using namespace std;
Echiquier::Echiquier()
{
  for(int i=0; i<64; i++)
    m_cases[i] = NULL;
}

Piece*
Echiquier::getPiece( int x, int y )
{
  if ((x>=1) && (x<=8) && (y>=1) && (y<=8))
    return m_cases[(x-1)+8*(y-1)];
  return NULL;
}

bool
Echiquier::placer( Piece* p )
{
  if(p==NULL) return false;
  int position = (p->x()-1)+8*(p->y()-1);
  if((p->x()>=1) && (p->x()<=8) && (p->y()>=1) && (p->y()<=8) && m_cases[position]==NULL)
  {
    m_cases[position]=p;
    return true;
  }
  return false;
}

bool
Echiquier::deplacer( Piece* p, int x, int y )
{
    int xDepart = p->x();
    int yDepart = p->y();

    enleverPiece(xDepart, yDepart);
    p->move(x,y);
    placer(p);
    return true;


  return false;
}



Piece*
Echiquier::enleverPiece( int x, int y )
{
  if((x>=1) && (x<=8) && (y>=1) && (y<=8) && getPiece(x,y)!= NULL)
  {
    Piece* tmp = m_cases[(x-1)+8*(y-1)];
    m_cases[(x-1)+8*(y-1)] = NULL;
    return tmp;
  }
  return NULL;
}

void
Echiquier::affiche()
{
  cout << endl << "  12345678" << endl;
  for ( int y = 1; y <= 8; ++y )
    {
      cout << y << " ";
      for ( int x = 1; x <= 8; ++x )
	{
	  char c;
	  Piece* p = getPiece( x, y );
	  if ( p == 0 )
	    c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
	  else
	    c = p->codePiece(); 
	  cout << c;
	}
      cout << " " << y << endl;
    }
  cout << "  12345678" << endl;
}

#endif