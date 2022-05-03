#ifndef PARTIE_H
#define PARTIE_H

#include "Piece.h"
#include "Echiquier.h"
#include "Joueur.h"
#include <string>

using namespace std;

class Partie
{
 protected:
    Echiquier e;
    JoueurBlanc jb;
    JoueurNoir jn;
    bool joueurActuel;
    int x;
    int y;


 public:
  Partie();
  ~Partie();
  void jouerPartie();
  void verifCoordonnees();
  int YaEchecAdv();
};


#endif