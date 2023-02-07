/**
* Program Name: block.c
* Discussion: Block structure function Definitions
* Written By: Daniel Tanurhan, Edwin Gutheru, Luca Mason
* Date: 2020/12/15
*/

#include "block.h"

TGridSquarePtr createSquareLocation(int xForLocation, int yForLocation, int size) {
	TGridSquarePtr locationToReturn = (TGridSquarePtr)malloc(sizeof(TGridSquare));
	locationToReturn->nextGridSquare = NULL;
	locationToReturn->xCoord = NULL;
	locationToReturn->yCoord = NULL;

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			appendLocationList(locationToReturn, x + xForLocation, y + yForLocation);
		}
	}

	return locationToReturn;
}

TGridSquarePtr createHorizontalPosition(int xForLocation, int yForLocation) {
	TGridSquarePtr locationToReturn = (TGridSquarePtr)malloc(sizeof(TGridSquare));
	locationToReturn->nextGridSquare = NULL;
	locationToReturn->xCoord = NULL;
	locationToReturn->yCoord = NULL;

	for (int x = 0; x < 2; x++) {
		appendLocationList(locationToReturn, xForLocation + x, yForLocation);
	}

	return locationToReturn;
}

TGridSquarePtr createVerticalPosition(int xForLocation, int yForLocation) {
	TGridSquarePtr locationToReturn = (TGridSquarePtr)malloc(sizeof(TGridSquare));
	locationToReturn->nextGridSquare = NULL;
	locationToReturn->xCoord = NULL;
	locationToReturn->yCoord = NULL;

	for (int y = 0; y < 2; y++) {
		appendLocationList(locationToReturn, xForLocation, yForLocation + y);
	}

	return locationToReturn;
}

void appendLocationList(TGridSquarePtr LocationList, int x, int y) {
	TGridSquarePtr locationNodeToCycle = LocationList;

	if (LocationList->xCoord) {
		while (locationNodeToCycle->nextGridSquare) {
			locationNodeToCycle = locationNodeToCycle->nextGridSquare;
		}
		locationNodeToCycle->nextGridSquare = (TGridSquarePtr)malloc(sizeof(TGridSquare));
		locationNodeToCycle->nextGridSquare->nextGridSquare = NULL;
		locationNodeToCycle->nextGridSquare->xCoord = x;
		locationNodeToCycle->nextGridSquare->yCoord = y;
	}
	else {
		locationNodeToCycle->xCoord = x;
		locationNodeToCycle->yCoord = y;
	}

}

void appendBlockList(TBlockListPtr listToAppend, TGridSquarePtr locationToAddToList, int keyValue) {
	TBlockListPtr nodeToCycle = listToAppend;

	if (nodeToCycle->gridLocation) {
		while (nodeToCycle->nextBlock) {
			nodeToCycle = nodeToCycle->nextBlock;
		}

		nodeToCycle->nextBlock = (TBlockListPtr)malloc(sizeof(TBlockList));
		nodeToCycle->nextBlock->gridLocation = locationToAddToList;
		nodeToCycle->nextBlock->isKey = keyValue;
		nodeToCycle->nextBlock->nextBlock = NULL;
	}
	else {
		nodeToCycle->gridLocation = locationToAddToList;
		nodeToCycle->isKey = keyValue;
		nodeToCycle->nextBlock = NULL;
	}

}

TBlockListPtr getBlockAtLocation(TBlockListPtr blockListToSearch, int xToLookFor, int yToLookFor) {
	TBlockListPtr nodeToCycle = blockListToSearch;
	TBlockListPtr blockAtLocation = NULL;

	while (nodeToCycle) {
		if (checkForLocation(nodeToCycle->gridLocation, xToLookFor, yToLookFor)) {
			blockAtLocation = nodeToCycle;
			nodeToCycle = NULL;
		}
		else {
			nodeToCycle = nodeToCycle->nextBlock;
		}
	}

	return blockAtLocation;
}

int checkForLocation(TGridSquarePtr locationListToSearch, int xToFind, int yToFind) {
	TGridSquarePtr gridSquareToCycle = locationListToSearch;
	int ifLocationisFound = 0;

	while (gridSquareToCycle) {

		if (gridSquareToCycle->xCoord == xToFind && gridSquareToCycle->yCoord == yToFind) {
			ifLocationisFound = 1;
			gridSquareToCycle = NULL;
		}
		else {
			gridSquareToCycle = gridSquareToCycle->nextGridSquare;
		}
	}

	return ifLocationisFound;
}

void deleteBlockList(TBlockListPtr blockListToDelete) {
	TBlockListPtr blockToDelete = blockListToDelete;
	TBlockListPtr nextBlockToDelete = NULL;

	while (blockToDelete) {
		nextBlockToDelete = blockToDelete->nextBlock;

		deleteGridLocation(blockToDelete->gridLocation);
		blockToDelete->gridLocation = NULL;
		blockToDelete->isKey = NULL;
		free(blockToDelete);
		blockToDelete = nextBlockToDelete;
	}

	blockToDelete = NULL;
	nextBlockToDelete = NULL;
}

void deleteGridLocation(TGridSquarePtr locationToDelete) {
	TGridSquarePtr currentLocation = locationToDelete;
	TGridSquarePtr nextLocation = NULL;

	while (currentLocation) {
		nextLocation = currentLocation->nextGridSquare;

		free(currentLocation);
		currentLocation = nextLocation;
	}

	currentLocation = NULL;
	nextLocation = NULL;
}