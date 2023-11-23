#pragma once

#include <windows.h>
#include <conio.h>
#include "funcionesGlobales.h"

void cargarCadena(char *word, int tam)
{
  int i = 0;
  fflush(stdin);
  for (i = 0; i < tam; i++)
  {
    word[i] = cin.get();
    if (word[i] == '\n')
      break;
  }
  word[i] = '\0';
  fflush(stdin);
}

int contarCadena(char *word, int tam)
{
  int counter = 0;
  for (int i = 0; i < tam; i++)
  {
    if (word[i] == '\0')
    {
      break;
    }
    counter++;
  }
  return counter;
}

void divisorDoble()
{
  cout << "=======================================" << endl;
}
void divisorSimple()
{
  cout << "---------------------------------------" << endl;
}

void divisorSimpleLargo()
{
  cout << "------------------------------------------------------------------" << endl;
}

void textColor(int colorText = 15, int colorBackground = 0)
{
  int color = colorText + colorBackground * 16;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(short x, short y)
{ /// UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
  COORD a;
  a.X = x;
  a.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void dibujarRecuadro(int base, int altura, int posX, int posY)
{
  // Dibuja la esquina superior izquierda
  gotoxy(posX, posY);
  cout << '+';

  // Dibuja la esquina superior derecha
  gotoxy(posX + base - 1, posY);
  cout << '+';

  // Dibuja la esquina inferior izquierda
  gotoxy(posX, posY + altura - 1);
  cout << '+';

  // Dibuja la esquina inferior derecha
  gotoxy(posX + base - 1, posY + altura - 1);
  cout << '+';

  // Dibuja los bordes superior e inferior
  for (int i = 1; i < base - 1; i++)
  {
    gotoxy(posX + i, posY);
    cout << '-'; // arriva
    gotoxy(posX + i, posY + altura - 1);
    cout << '-'; // abajo
  }
  // Dibuja los lados del recuadro
  for (int i = 1; i < altura - 1; i++)
  {
    gotoxy(posX, posY + i);
    cout << '|'; // izquierdo
    gotoxy(posX + base - 1, posY + i);
    cout << '|'; // derecho
  }
}
