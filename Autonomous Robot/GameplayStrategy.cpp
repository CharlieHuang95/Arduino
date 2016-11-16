#include <stdio.h>

int printBoard(int [6][7]);
int updateBoard(char, int, int [6][7]);
int connectFourCheck(int, int [6][7]);
int updateScore(int *, int *, int, int, int, int);
int calculateBestMove(int [6][7]);
int removeFromBoard(int, int [6][7]);

int main(){
	int connectBoard[6][7] = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};	
	int pointsNextMove[7] = {0,0,0,0,0,0,0};
	int pointsNextTwoMove[7][7] = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
	int column;
	char colour;
	int blackColumns;
	int blackRows;
	int blackDiagonals;
	int totalBlackConnects = 0;
	int totalBlackBalls = 0;
	int totalBlackPoints = 0;
	int whiteColumns;
	int whiteRows;
	int whiteDiagonals;
	int totalWhiteConnects = 0;
	int totalWhiteBalls = 0;
	int totalWhitePoints = 0;
	
	while(1){
		fprintf(stdout, "What column? And black (b) or white (w)?");
		fscanf(stdin, " %d", &column);
		fscanf(stdin, " %c", &colour);
		
		if(colour == 'b'){totalBlackBalls ++;}
		if(colour == 'w'){totalWhiteBalls ++;}
		if(colour == 'r'){removeFromBoard(column - 1, connectBoard); goto Skip;}
		
		updateBoard(colour, column - 1, connectBoard);
		
		Skip:
		printBoard(connectBoard);
		totalBlackConnects = connectFourCheck(1, connectBoard);
		totalWhiteConnects = connectFourCheck(2, connectBoard);
		updateScore(&totalWhitePoints, &totalBlackPoints, totalWhiteBalls, totalBlackBalls, totalWhiteConnects, totalBlackConnects);
		fprintf(stdout, "Total Black Connect 4s: %d. Points = %d\n", totalBlackConnects, totalBlackPoints);
		fprintf(stdout, "Total White Connect 4s: %d. Points = %d\n", totalWhiteConnects, totalWhitePoints);
		calculateBestMove(connectBoard);
	}
	return 0;
}

int calculateBestMove(int connectBoard[6][7]){
	int arrayPoints[7];
	int arrayPoints2[7];
	int arrayPoints3[7];
	int connectBoardTemporary[6][7];
	int totalBlackConnects;
	int totalWhiteConnects;
	int totalWhiteBalls;
	int totalBlackBalls;
	int totalWhitePoints;
	int totalBlackPoints;
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			connectBoardTemporary[i][j] = connectBoard[i][j]; //An exact copy is created
		}
	}
	int temporaryPointsWhite;
	int temporaryPointsBlack;
	for(int i = 0; i < 7; i++){ 
		updateBoard('b', i, connectBoardTemporary); // Update the temporary board with the possible combinations
		totalBlackConnects = connectFourCheck(1, connectBoardTemporary);
		totalWhiteConnects = connectFourCheck(2, connectBoardTemporary);
		updateScore(&totalWhitePoints, &totalBlackPoints, 0, 0, totalWhiteConnects, totalBlackConnects); 
		fprintf(stdout, "%d-",totalBlackPoints);
		arrayPoints[i] = totalBlackPoints;
		removeFromBoard(i, connectBoardTemporary);
		//printBoard(connectBoardTemporary);
	}
	fprintf(stdout, "\n");
	for(int i = 0; i < 7; i++){ 
		updateBoard('w', i, connectBoardTemporary); // Update the temporary board with the possible combinations
		totalBlackConnects = connectFourCheck(1, connectBoardTemporary);
		totalWhiteConnects = connectFourCheck(2, connectBoardTemporary);
		updateScore(&totalWhitePoints, &totalBlackPoints, 0, 0, totalWhiteConnects, totalBlackConnects); 
		fprintf(stdout, "%d-",totalWhitePoints);
		arrayPoints[i] = totalWhitePoints;
		removeFromBoard(i, connectBoardTemporary);
		//printBoard(connectBoardTemporary);
	}
	
	int bestScore = 0;
	int bestColumn = 0;
	for(int i = 0; i < 7; i++){
		if(bestScore<arrayPoints[i]){
			bestColumn = i;
			bestScore = arrayPoints[i];
		}
	}
	fprintf(stdout,"\nThe best column is %d!\n", bestColumn + 1);
	return bestColumn + 1;
}

int updateScore(int * totalWhitePoints, int * totalBlackPoints, int totalWhiteBalls, int totalBlackBalls, int totalWhiteConnects, int totalBlackConnects){
	int white;
	int black;
	white = totalWhiteConnects*4 + totalWhiteBalls - totalBlackConnects*2;
	black = totalBlackConnects*4 + totalBlackBalls - totalWhiteConnects*2;
	if(white < 0){white = 0;}
	if(black < 0){black = 0;}
	*totalWhitePoints = white;
	*totalBlackPoints = black;	
}

int connectFourCheck(int check, int connectBoard[6][7]){
	int count = 0;
	int totalConnects = 0;
	//Check the columns
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			if(connectBoard[j][i] == check){
				count ++;
			}
			else
				count = 0;
			if(count == 4){
				totalConnects ++;
			}
		}
		count = 0;
	}
	//Check the rows
	count = 0;
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			if(connectBoard[i][j] == check){
				count ++;
				if(count == 4){
					totalConnects ++;
				}
			}
			else
				count = 0;
		}
		count = 0;
	}
	//Check the diagonal (/)
	count = 0;
	for(int i = -2; i < 7; i++){
		for(int j = 0; j < 7; j++){
			if(i+j < 0 | i+j > 7){continue; count = 0;}
			if(connectBoard[j][i+j] == check){
				count ++;
			}
			else
				count = 0;
			if(count == 4){
				//fprintf(stdout, "Connect4(/)! %d&%d", j,i+j);
				totalConnects ++;
			}
		}
		count = 0;
	}
	//Check the diagonal (\)
	count = 0;
	for(int i = -3; i < 7; i++){
		for(int j = 0; j < 7; j++){
			if(i+j < 0 | i+j > 7){continue; count = 0;}
			if(connectBoard[6-j][i+j] == check){
				count ++;
			}
			else
				count = 0;
			if(count == 4){
				//fprintf(stdout, "Connect4(>)! %d&%d", 6-j,i+j);
				totalConnects ++;
			}
		}
		count = 0;
	}
	return totalConnects;
}

int removeFromBoard(int column, int connectBoard[6][7]){
	for(int i = 6; i > -1; i--){
		if(connectBoard[i][column] == 1 | connectBoard[i][column] == 2){
			connectBoard[i][column] = 0;
			break;
		}
	}
}

int updateBoard(char colour, int column, int connectBoard[6][7]){
	for(int i = 0; i < 6; i++){
		if(connectBoard[i][column] == 0){
			if(colour == 'b'){
				connectBoard[i][column] = 1;
			}
			else if(colour == 'w'){
				connectBoard[i][column] = 2;
			}
			
			break;
		}
	}
	return 0;
}

int printBoard(int connectBoard[6][7]){
	for(int i = 5; i > -1; i--){
		for(int j = 0; j < 7; j++){
			fprintf(stdout, "|");
			if(connectBoard[i][j] == 0){
				fprintf(stdout, " ");
				continue;
			}
			else if(connectBoard[i][j] == 1){
				fprintf(stdout, "O");
			}
			else if(connectBoard[i][j] == 2){
				fprintf(stdout, "X");
			}
		}
		fprintf(stdout, "|\n_______________\n");
	}
	return 0;
}
