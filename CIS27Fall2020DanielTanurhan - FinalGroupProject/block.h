/**
* Program Name: block.h
* Discussion: Block structure function Decleration
* Written By: Daniel Tanurhan, Edwin Gutheru, Luca Mason
* Date: 2020/12/15
*/
#include <stdlib.h>
#include <stdio.h>

#ifndef BLOCK_H
#define BLOCK_H

struct gridSquare {
	int xCoord;
	int yCoord;
	struct gridSquare* nextGridSquare;
};

typedef struct gridSquare TGridSquare;
typedef struct gridSquare* TGridSquarePtr;

struct blockList {
	TGridSquarePtr gridLocation;
	int isKey;
	struct blockList* nextBlock;
};

typedef struct blockList TBlockList;
typedef struct blockList* TBlockListPtr;
TGridSquarePtr createSquareLocation(int xForLocation, int yForLocation, int size);
TGridSquarePtr createHorizontalPosition(int xForLocation, int yForLocation);
TGridSquarePtr createVerticalPosition(int xForLocation, int yForLocation);
void appendLocationList(TGridSquarePtr LocationList, int x, int y);
void appendBlockList(TBlockListPtr listToAppend, TGridSquarePtr locationToAddToList, int keyValue);
TBlockListPtr getBlockAtLocation(TBlockListPtr blockListToSearch, int xToLookFor, int yToLookFor);
int checkForLocation(TGridSquarePtr locationListToSearch, int xToFind, int yToFind);
void deleteBlockList(TBlockListPtr blockListToDelete);
void deleteGridLocation(TGridSquarePtr locationToDelete);
#endif