/**
* Program Name: grid.c
* Discussion: Grid display function definitions
* Written By: Daniel Tanurhan, Edwin Gutheru, Luca Mason
* Date: 2020/12/15
*/

#include "grid.h"

TBlockListPtr theBlockList = NULL;
int lastXForDrag;
int lastYForDrag;

void drag(int x, int y) {

	int currentX = getX(x);
	int currentY = getY(y);
	TBlockListPtr blockToPossiblyDrag = getBlockAtLocation(theBlockList, lastXForDrag, lastYForDrag);

	if (!getBlockAtLocation(theBlockList, currentX, currentY)) {
		if (blockToPossiblyDrag) {
			if (blockToPossiblyDrag->isKey) {
				if (currentX == lastXForDrag + 1) {

					if (!getBlockAtLocation(theBlockList, currentX, blockToPossiblyDrag->gridLocation->yCoord) &&
						!getBlockAtLocation(theBlockList, currentX, blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord)) {

						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->yCoord);
						putSquareOnGrid(currentX - 1, blockToPossiblyDrag->gridLocation->yCoord, 2);

						blockToPossiblyDrag->gridLocation->xCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->xCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->xCoord++;

						if (currentY > blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->yCoord) {
							redrawHorizontalGridLines(lastXForDrag - 1, currentY - 1);
							redrawVerticalGridLines(lastXForDrag - 1, currentY);
							redrawVerticalGridLines(lastXForDrag - 1, currentY - 1);
						}
						else {
							redrawHorizontalGridLines(lastXForDrag - 1, currentY);
							redrawVerticalGridLines(lastXForDrag - 1, currentY + 1);
							redrawVerticalGridLines(lastXForDrag - 1, currentY);
						}
					}
				}
				else if (currentX == lastXForDrag - 1) {

					if (currentX && !getBlockAtLocation(theBlockList, currentX, blockToPossiblyDrag->gridLocation->yCoord) &&
						!getBlockAtLocation(theBlockList, currentX, blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord)) {

						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->xCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->xCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->xCoord--;

						if (currentY > blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->yCoord) {
							redrawHorizontalGridLines(lastXForDrag + 1, currentY - 1);
							redrawVerticalGridLines(lastXForDrag, currentY);
							redrawVerticalGridLines(lastXForDrag, currentY - 1);
						}
						else {
							redrawHorizontalGridLines(lastXForDrag + 1, currentY);
							redrawVerticalGridLines(lastXForDrag, currentY + 1);
							redrawVerticalGridLines(lastXForDrag, currentY);
						}
						putSquareOnGrid(currentX, blockToPossiblyDrag->gridLocation->yCoord, 2);
					}
				}
				else if (currentY == lastYForDrag + 1) {
					if (!getBlockAtLocation(theBlockList, blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord, currentY) &&
						!getBlockAtLocation(theBlockList, blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->xCoord, currentY)) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->yCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->yCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->yCoord++;

						putSquareOnGrid(blockToPossiblyDrag->gridLocation->xCoord, blockToPossiblyDrag->gridLocation->yCoord, 2);

						if (currentX > blockToPossiblyDrag->gridLocation->xCoord) {

							redrawHorizontalGridLines(lastXForDrag, currentY - 2);
							redrawHorizontalGridLines(lastXForDrag - 1, currentY - 2);
							redrawVerticalGridLines(lastXForDrag - 1, currentY - 2);
						}
						else {
							redrawHorizontalGridLines(lastXForDrag + 1, currentY - 2);
							redrawHorizontalGridLines(lastXForDrag, currentY - 2);
							redrawVerticalGridLines(lastXForDrag, currentY - 2);
						}
					}
				}
				else if (currentY && currentY == lastYForDrag - 1) {
					if (!getBlockAtLocation(theBlockList, blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord, currentY) && 
						!getBlockAtLocation(theBlockList, blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->xCoord, currentY)) {

						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->yCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->yCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->nextGridSquare->yCoord--;

						putSquareOnGrid(blockToPossiblyDrag->gridLocation->xCoord, blockToPossiblyDrag->gridLocation->yCoord, 2);
						if (currentX > blockToPossiblyDrag->gridLocation->xCoord) {

							redrawHorizontalGridLines(lastXForDrag, currentY + 1);
							redrawHorizontalGridLines(lastXForDrag - 1, currentY + 1);
							redrawVerticalGridLines(lastXForDrag - 1, currentY + 2);
						}
						else {
							redrawHorizontalGridLines(lastXForDrag, currentY + 1);
							redrawHorizontalGridLines(lastXForDrag + 1, currentY + 1);
							redrawVerticalGridLines(lastXForDrag, currentY + 2);
						}
					}
				}

			}
			else if (isSquare(blockToPossiblyDrag)) {

				if (currentX && currentY &&
					(((currentX == lastXForDrag + 1 || currentX == lastXForDrag - 1) &&
						currentY == lastYForDrag) ||
						((currentY == lastYForDrag + 1 || currentY == lastYForDrag - 1) &&
							currentX == lastXForDrag))) {
					removeGridSquare(lastXForDrag, lastYForDrag);
					putSquareOnGrid(currentX, currentY, 1);

					blockToPossiblyDrag->gridLocation->xCoord = currentX;
					blockToPossiblyDrag->gridLocation->yCoord = currentY;
				}
			}
			else if (isHorizontal(blockToPossiblyDrag)) {

				if (currentY == lastYForDrag) {
					if (currentX == lastXForDrag + 1) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->xCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord++;

						putHorizontalOnGrid(blockToPossiblyDrag->gridLocation->xCoord, currentY);

						redrawVerticalGridLines(lastXForDrag - 1, currentY);
					}
					else if (currentX && currentX == lastXForDrag - 1) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->xCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord--;

						putHorizontalOnGrid(blockToPossiblyDrag->gridLocation->xCoord, currentY);
						redrawVerticalGridLines(lastXForDrag, currentY);
					}
				}
				else if (currentX == lastXForDrag) {
					if (currentY == lastYForDrag + 1) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->yCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord++;

						putHorizontalOnGrid(blockToPossiblyDrag->gridLocation->xCoord, currentY);

						(currentX > blockToPossiblyDrag->gridLocation->xCoord) ?
							redrawVerticalGridLines(lastXForDrag - 1, currentY - 1) :
							redrawVerticalGridLines(lastXForDrag, currentY - 1);
					}
					else if (currentY && currentY == lastYForDrag - 1) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->yCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord--;

						putHorizontalOnGrid(blockToPossiblyDrag->gridLocation->xCoord, currentY);

						(currentX > blockToPossiblyDrag->gridLocation->xCoord) ?
							redrawVerticalGridLines(lastXForDrag - 1, currentY + 1) :
							redrawVerticalGridLines(lastXForDrag, currentY + 1);
					}
				}
			}
			else if (isVertical(blockToPossiblyDrag)) {
				if (currentX == lastXForDrag) {
					if (currentY && currentY == lastYForDrag - 1) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->yCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord--;
						putVerticalOnGrid(currentX, blockToPossiblyDrag->gridLocation->yCoord);

						redrawHorizontalGridLines(currentX, lastYForDrag);
					}
					else if (currentY == lastYForDrag + 1) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->yCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord++;
						putVerticalOnGrid(currentX, blockToPossiblyDrag->gridLocation->yCoord);
						redrawHorizontalGridLines(currentX, lastYForDrag - 1);
					}

				}
				else if (currentY == lastYForDrag) {
					if (currentX && currentX == lastXForDrag - 1) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->xCoord--;
						blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord--;
						putVerticalOnGrid(currentX, blockToPossiblyDrag->gridLocation->yCoord);

						(currentY > blockToPossiblyDrag->gridLocation->yCoord) ?
							redrawHorizontalGridLines(currentX + 1, lastYForDrag - 1) :
							redrawHorizontalGridLines(currentX + 1, lastYForDrag);
					}
					else if (currentX == lastXForDrag + 1) {
						removeGridSquare(blockToPossiblyDrag->gridLocation->xCoord,
							blockToPossiblyDrag->gridLocation->yCoord);
						removeGridSquare(blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord,
							blockToPossiblyDrag->gridLocation->nextGridSquare->yCoord);

						blockToPossiblyDrag->gridLocation->xCoord++;
						blockToPossiblyDrag->gridLocation->nextGridSquare->xCoord++;
						putVerticalOnGrid(currentX, blockToPossiblyDrag->gridLocation->yCoord);

						(currentY > blockToPossiblyDrag->gridLocation->yCoord) ?
							redrawHorizontalGridLines(currentX - 1, lastYForDrag - 1) :
							redrawHorizontalGridLines(currentX - 1, lastYForDrag);
					}
				}
			}
		}
	}

	if (blockToPossiblyDrag && blockToPossiblyDrag->isKey &&
		blockToPossiblyDrag->gridLocation->xCoord == 2 &&
		blockToPossiblyDrag->gridLocation->nextGridSquare->nextGridSquare->xCoord == 3 &&
		(x > 293 && x < 709) && (y > 930 && y < 999)) {

		printEndScreen();

		deleteBlockList(theBlockList);

		theBlockList = NULL;
		lastXForDrag = NULL;
		lastYForDrag = NULL;
	}

	if (getX(x) && getY(y)) {
		lastXForDrag = getX(x);
		lastYForDrag = getY(y);
	}
}

void redrawVerticalGridLines(int newX, int positionOnY) {
	glColor3f(0.8, 0.60, 0.2);

	int bottomOfYAxis = 40 + ((positionOnY - 1) * 5) + (positionOnY * 80);
	int topOfYAxis = bottomOfYAxis - 85;
	int leftXPoint = 40 + ((newX - 1) * 4) + (newX * 102);
	int rightXPoint = leftXPoint + 4;

	glBegin(GL_QUADS);
	glVertex2f(leftXPoint, bottomOfYAxis + 5);
	glVertex2f(leftXPoint, topOfYAxis);
	glVertex2f(rightXPoint, topOfYAxis);
	glVertex2f(rightXPoint, bottomOfYAxis + 5);
	glEnd();


	glFlush();
}

void redrawHorizontalGridLines(int positionOnX, int newY) {

	glColor3f(0.8, 0.60, 0.2);

	int bottomOfYAxis = 40 + ((newY - 1) * 5) + (newY * 80);
	int topOfYAxis = bottomOfYAxis + 5;
	int rightXPoint = 40 + ((positionOnX - 1) * 4) + (positionOnX * 102);
	int leftXPoint = rightXPoint - 102;

	glBegin(GL_QUADS);
	glVertex2f(leftXPoint, bottomOfYAxis);
	glVertex2f(leftXPoint, topOfYAxis);
	glVertex2f(rightXPoint, topOfYAxis);
	glVertex2f(rightXPoint, bottomOfYAxis);
	glEnd();


	glFlush();
}

void drawGrid(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glVertex2f(500, 0);
	glEnd();

	drawBorders();
	drawVerticalLines();
	drawHorizontalLines();

	setUpBlocks();

	glFlush();

	glutMotionFunc(drag);
}

void drawBorders(void) {

	glColor3f(0.8, 0.60, 0.2);

	glBegin(GL_QUADS);
	glVertex2f(460, 0);
	glVertex2f(500, 0);
	glVertex2f(500, 500);
	glVertex2f(460, 500);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(40, 0);
	glVertex2f(40, 500);
	glVertex2f(0, 500);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(40, 0);
	glVertex2f(40, 500);
	glVertex2f(0, 500);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0, 460);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glVertex2f(500, 460);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(0, 40);
	glVertex2f(146, 40);
	glVertex2f(146, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(354, 0);
	glVertex2f(354, 40);
	glVertex2f(500, 40);
	glVertex2f(500, 0);
	glEnd();
}

void drawVerticalLines(void) {

	glColor3f(0.8, 0.60, 0.2);

	glBegin(GL_QUADS);
	glVertex2f(142, 460);
	glVertex2f(146, 460);
	glVertex2f(146, 40);
	glVertex2f(142, 40);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(248, 460);
	glVertex2f(252, 460);
	glVertex2f(252, 40);
	glVertex2f(248, 40);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(354, 460);
	glVertex2f(358, 460);
	glVertex2f(358, 40);
	glVertex2f(354, 40);
	glEnd();
}

void drawHorizontalLines(void) {

	glColor3f(0.8, 0.60, 0.2);

	glBegin(GL_QUADS);
	glVertex2f(40, 35);
	glVertex2f(40, 40);
	glVertex2f(460, 40);
	glVertex2f(460, 35);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(40, 120);
	glVertex2f(40, 125);
	glVertex2f(460, 125);
	glVertex2f(460, 120);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(40, 205);
	glVertex2f(40, 210);
	glVertex2f(460, 210);
	glVertex2f(460, 205);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(40, 290);
	glVertex2f(40, 295);
	glVertex2f(460, 295);
	glVertex2f(460, 290);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(40, 375);
	glVertex2f(40, 380);
	glVertex2f(460, 380);
	glVertex2f(460, 375);
	glEnd();

}

void drawHorizontal(int X, int Y) {

	putHorizontalOnGrid(X, Y);

	appendBlockList(theBlockList, createHorizontalPosition(X, Y), 0);

}

void putHorizontalOnGrid(int untranslatedX, int untranslatedY) {

	int xCorner1 = 40 + ((untranslatedX - 1) * 106);
	int yCorner1 = 40 + ((untranslatedY - 1) * 85);
	int xCorner2 = xCorner1 + 208;
	int yCorner2 = yCorner1 + 80;

	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(xCorner1, yCorner1);
	glVertex2f(xCorner1, yCorner2);
	glVertex2f(xCorner2, yCorner2);
	glVertex2f(xCorner2, yCorner1);
	glEnd();

	glFlush();
}

void putVerticalOnGrid(int untranslatedX, int untranslatedY) {

	glColor3f(0.0, 1.0, 0.0);

	int xCorner1 = 40 + ((untranslatedX - 1) * 106);
	int yCorner1 = 40 + ((untranslatedY - 1) * 85);
	int xCorner2 = xCorner1 + 102;
	int yCorner2 = yCorner1 + 165;

	glBegin(GL_QUADS);
	glVertex2f(xCorner1, yCorner1);
	glVertex2f(xCorner1, yCorner2);
	glVertex2f(xCorner2, yCorner2);
	glVertex2f(xCorner2, yCorner1);
	glEnd();

	glFlush();
}

void drawVertical(int X, int Y) {

	putVerticalOnGrid(X, Y);

	appendBlockList(theBlockList, createVerticalPosition(X, Y), 0);
}

void drawSquare(int X, int Y, int size) {
	int keyvalue = size - 1;

	putSquareOnGrid(X, Y, size);

	appendBlockList(theBlockList, createSquareLocation(X, Y, size), keyvalue);
}

void putSquareOnGrid(int untranslatedX, int untranslatedY, int size) {

	glColor3f(0.0, 0.0, 1.0);

	int xCorner1 = 40 + ((untranslatedX - 1) * 106);
	int yCorner1 = 40 + ((untranslatedY - 1) * 85);

	int xCorner2 = xCorner1 + (size * 102) + ((size - 1) * 4);

	int yCorner2 = yCorner1 + (size * 80) + ((size - 1) * 5);

	glBegin(GL_QUADS);
	glVertex2f(xCorner1, yCorner1);
	glVertex2f(xCorner1, yCorner2);
	glVertex2f(xCorner2, yCorner2);
	glVertex2f(xCorner2, yCorner1);
	glEnd();

	glFlush();
}

void removeGridSquare(int X, int Y) {

	glColor3f(1.0, 1.0, 1.0);

	int xCorner1 = 40 + ((X - 1) * 106);
	int yCorner1 = 40 + ((Y - 1) * 85);

	int xCorner2 = xCorner1 + 102;

	int yCorner2 = yCorner1 + 80;

	glBegin(GL_QUADS);
	glVertex2f(xCorner1, yCorner1);
	glVertex2f(xCorner1, yCorner2);
	glVertex2f(xCorner2, yCorner2);
	glVertex2f(xCorner2, yCorner1);
	glEnd();

	glFlush();
}

void setUpBlocks(void) {

	theBlockList = (TBlockListPtr)malloc(sizeof(TBlockList));
	theBlockList->gridLocation = NULL;
	theBlockList->nextBlock = NULL;

	drawSquare(1, 1, 1);
	drawSquare(4, 1, 1);
	drawSquare(2, 2, 1);
	drawSquare(3, 2, 1);
	drawHorizontal(2, 3);
	drawVertical(1, 2);
	drawVertical(4, 2);
	drawVertical(1, 4);
	drawVertical(4, 4);
	drawSquare(2, 4, 2);
}

int getX(int xToConvert) {

	int xToReturn;

	(xToConvert > 80 && xToConvert < 284) ?
		(xToReturn = 1) : (xToConvert > 293 && xToConvert < 496) ?
		(xToReturn = 2) : (xToConvert > 505 && xToConvert < 708) ?
		(xToReturn = 3) : (xToConvert > 717 && xToConvert < 921) ?
		(xToReturn = 4) : (xToReturn = 0);

	return xToReturn;
}

int getY(int yToConvert) {

	int yToReturn;

	(yToConvert > 760 && yToConvert < 918) ?
		(yToReturn = 1) : (yToConvert > 589 && yToConvert < 756) ?
		(yToReturn = 2) : (yToConvert > 419 && yToConvert < 577) ?
		(yToReturn = 3) : (yToConvert > 248 && yToConvert < 407) ?
		(yToReturn = 4) : (yToConvert > 78 && yToConvert < 236) ?
		(yToReturn = 5) : (yToReturn = 0);

	return yToReturn;
}

int isSquare(TBlockListPtr blockToAnalyze) {
	int isSquare = 0;

	if (!blockToAnalyze->gridLocation->nextGridSquare) {
		isSquare = 1;
	}

	return isSquare;
}

int isHorizontal(TBlockListPtr blockToAnalyze) {
	int isHorizontal = 0;

	if (blockToAnalyze->gridLocation->yCoord == blockToAnalyze->gridLocation->nextGridSquare->yCoord) {
		isHorizontal = 1;
	}

	return isHorizontal;
}

int isVertical(TBlockListPtr blockToAnalyze) {
	int isVertical = 0;

	if (blockToAnalyze->gridLocation->xCoord == blockToAnalyze->gridLocation->nextGridSquare->xCoord) {
		isVertical = 1;
	}

	return isVertical;
}

void clearGrid() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glVertex2f(500, 0);
	glEnd();

	glFlush();
}

void printEndScreen(void) {

	clearGrid();

	glColor3f(0.8, 0.60, 0.2);

	glBegin(GL_QUADS);
	glVertex2f(40, 50);
	glVertex2f(40, 125);
	glVertex2f(55, 125);
	glVertex2f(55, 50);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(48, 110);
	glVertex2f(77, 130);
	glVertex2f(70, 145);
	glVertex2f(40, 125);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(48, 110);
	glVertex2f(18, 130);
	glVertex2f(25, 145);
	glVertex2f(55, 125);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(77, 50);
	glVertex2f(107, 50);
	glVertex2f(102, 65);
	glVertex2f(82, 65);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(107, 50);
	glVertex2f(102, 65);
	glVertex2f(107, 80);
	glVertex2f(122, 80);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(107, 110);
	glVertex2f(102, 95);
	glVertex2f(107, 80);
	glVertex2f(122, 80);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(62, 80);
	glVertex2f(77, 80);
	glVertex2f(82, 65);
	glVertex2f(77, 50);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(62, 80);
	glVertex2f(77, 80);
	glVertex2f(82, 95);
	glVertex2f(77, 110);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(77, 110);
	glVertex2f(107, 110);
	glVertex2f(102, 95);
	glVertex2f(82, 95);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(169, 115);
	glVertex2f(169, 45);
	glVertex2f(181, 50);
	glVertex2f(181, 115);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(139, 45);
	glVertex2f(139, 57);
	glVertex2f(169, 57);
	glVertex2f(169, 45);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(127, 115);
	glVertex2f(127, 50);
	glVertex2f(139, 45);
	glVertex2f(139, 115);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(217, 115);
	glVertex2f(227, 115);
	glVertex2f(252, 45);
	glVertex2f(242, 45);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex2f(252, 45);
	glVertex2f(242, 45);
	glVertex2f(267, 115);
	glVertex2f(277, 115);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(267, 115);
	glVertex2f(277, 115);
	glVertex2f(302, 45);
	glVertex2f(292, 45);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(292, 45);
	glVertex2f(302, 45);
	glVertex2f(327, 115);
	glVertex2f(317, 115);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(292, 45);
	glVertex2f(302, 45);
	glVertex2f(327, 115);
	glVertex2f(317, 115);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(332, 45);
	glVertex2f(332, 115);
	glVertex2f(342, 115);
	glVertex2f(342, 45);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(332, 122);
	glVertex2f(332, 132);
	glVertex2f(342, 132);
	glVertex2f(342, 122);

	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(349, 45);
	glVertex2f(349, 125);
	glVertex2f(359, 125);
	glVertex2f(359, 45);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(359, 105);
	glVertex2f(359, 115);
	glVertex2f(394, 115);
	glVertex2f(394, 105);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(394, 45);
	glVertex2f(394, 115);
	glVertex2f(404, 110);
	glVertex2f(404, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(411, 60);
	glVertex2f(411, 125);
	glVertex2f(421, 125);
	glVertex2f(421, 60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(411, 45);
	glVertex2f(411, 55);
	glVertex2f(421, 55);
	glVertex2f(421, 45);
	glEnd();

	glFlush();
}