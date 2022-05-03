#ifndef JOUEUR_H
#define JOUEUR_H
#include "Piece.h"
#include "Echiquier.h"

class Joueur 
{
 protected:
  Piece m_pieces[16]; //A changer
 public:
  Joueur();
  Joueur(bool white);
  ~Joueur();
  void affiche();
  virtual bool isWhite()=0;
  void placerPieces(Echiquier &e);
};


class JoueurBlanc : public Joueur
{
  public:
   JoueurBlanc();
   bool isWhite();
};


class JoueurNoir : public Joueur
{
  public:
   JoueurNoir();
   bool isWhite();
};
#endif