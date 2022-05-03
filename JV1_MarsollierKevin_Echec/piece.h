#ifndef PIECE_H
#define PIECE_H

class Echiquier;

class Piece
{
protected:
  int m_x;
  int m_y;
  bool m_white;

public:
  Piece();
  virtual ~Piece();
  Piece(const Piece & autre);
  Piece & operator=(const Piece & autre);
  Piece( int x, int y, bool white );
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x();
  int y();
  bool isWhite();
  bool isBlack();
  void affiche();
  virtual bool mouvementValide(Echiquier &e, int x, int y);
  virtual char codePiece(); 
};


class Roi : public Piece
{
  public:
   Roi(bool white);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Fou : virtual public Piece
{
  public:
   Fou(bool white, bool left);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Tour : virtual public Piece
{
  public:
   Tour(bool white, bool left);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Reine : public Fou, public Tour
{
  public:
   Reine(bool white);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Cavalier : virtual public Piece
{
  public:
   Cavalier(bool white, bool left);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};

class Pion :  virtual public Piece
{
  public:
   Pion(int x, bool white);
   bool mouvementValide(Echiquier &e, int x, int y);
   char codePiece();
};
#endif