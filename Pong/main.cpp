#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x,int y);



class jugador{
    int x, y;
public:
    jugador(int _x, int _y); //constructor
    void pintar() const;
    void borrar() const;
    void Y(int _y) {y+= _y;}
    int RY(){return y;}
    int RX () {return x;}

};

jugador::jugador(int _x, int _y): x(_x), y(_y){}

void jugador::pintar() const{

    gotoxy(x,y-1); printf("%c",219);
    gotoxy(x,y ); printf("%c",219);
    gotoxy(x,y+1); printf("%c",219);

}

void jugador::borrar() const{

    gotoxy(x,y-1); printf("  ");
    gotoxy(x,y ); printf("  ");
    gotoxy(x,y+1); printf("  ");

}

class pelota{

    int x, y;
    int dx, dy;
public:
    pelota(int _x, int _y, int _dx, int _dy);
    void pintar() const;
    void borrar () const;
    void mover (jugador A, jugador B);
    void asign (int _x, int _y) {x = _x; y = _y;}

};

pelota::pelota(int _x, int _y, int _dx, int _dy): x(_x), y(_y), dx(_dx), dy(_dy) {}

void pelota::pintar() const{

gotoxy(x, y); printf("%c",2);

}

void pelota::borrar() const {

gotoxy(x,y); printf("  ");

}

void pelota::mover(jugador A, jugador B){
    borrar();
    x += dx; y += dy;
    pintar();
        if (x + dx == 3 || x + dx == 76 ){
            borrar();
            dx = - dx;
        }
        if (y + dy == 3 || y + dy == 23){

            dy = -dy;
        }
        if (x + dx == A.RX() && y >= A.RY()-2 && y <= A.RY()+2) {dx = -dx;}
        if (x + dx == B.RX() && y >= B.RY()-2 && y <= B.RY()+2) {dx = -dx;}
}


int main(){

    jugador A(6,15); A.pintar();
    jugador B(74, 15); B.pintar();
    pelota P(38, 14, 1, 1);

    char tecla;
        while(1){

            A.borrar();
            B.borrar();

            if(kbhit()){

                tecla = getch();

                if (tecla == 'q' && A.RY() > 5)
                    A.Y(-1);
                else if (tecla == 'a' && A.RY() < 21)
                    A.Y(1);

                if (tecla == 'o' && B.RY() > 5)
                    B.Y(-1);
                else if (tecla == 'l' && B.RY() < 21)
                    B.Y(1);
                }

                A.pintar(); B.pintar();
                P.mover(A, B);
                Sleep(100);
            }

    return 0;

}

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
  }


