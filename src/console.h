#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <iostream>
#include <stdio.h>
#include <ncurses.h>

using namespace std;

class Console
{
public:
  Console();
  Console(int _width, int _height);

  int width = 50;
  int height = 30;
  
  void printChar(int x, int y, char character);
  void printCharColor(int x, int y, char character, unsigned char forecolor);
  void printCharOffset(int x, int y, int offsetX, int offsetY, char character);
  void printCharColorOffset(int x, int y, int offsetX, int offsetY, char character, unsigned char color);
  void printString(int x, int y, string message);

  void update();
  void clear();
  void stop();

  char getChar();
  string getString();

 private:
  void init();
};

#endif
