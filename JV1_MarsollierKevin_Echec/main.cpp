#include <iostream>
#include "Piece.cpp"
#include "Joueur.cpp"
#include "Echiquier.cpp"
#include "Partie.cpp"


using namespace std;


bool compare(Piece &pa, Piece &pb)
{
  return ( (pa.x()== pb.x()) && (pa.y() == pb.y()) );
}


int main( int argc, char** argv )
{
    Partie p;
    p.jouerPartie();

}