/**
* Program Name: grid.h
* Discussion: Grid display function declerations
* Written By: Daniel Tanurhan, Edwin Gutheru, Luca Mason
* Date: 2020/12/15
*/
#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include "block.h"

#ifndef GRID_H
#define GRID_H

void drawGrid(void);
void clearGrid(void);

void setUpBlocks(void);

void printEndScreen(void);

void drawHorizontal(int X, int Y);
void drawVertical(int X, int Y);
void drawSquare(int X, int Y, int size);

void putSquareOnGrid(int untranslatedX, int untranslatedY, int size);
void putHorizontalOnGrid(int untranslatedX, int untranslatedY);
void putVerticalOnGrid(int untranslatedX, int untranslatedY);

void drawVerticalLines(void);
void drawHorizontalLines(void);
void drawBorders(void);

int getX(int xToConvert);
int getY(int yToConvert);

void drag(int x, int y);

void removeGridSquare(int X, int Y);
int isSquare(TBlockListPtr blockToAnalyze);

int isHorizontal(TBlockListPtr blockToAnalyze);
int isVertical(TBlockListPtr blockToAnalyze);

void redrawVerticalGridLines(int newX, int positionOnY);
void redrawHorizontalGridLines(int positionOnX, int newY);

#endif