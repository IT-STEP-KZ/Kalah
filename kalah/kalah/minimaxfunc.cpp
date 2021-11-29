#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

void equal(int(&mas1)[10][10], int mas2[10][10]) {
	
		for (int i = 0; i < 10; i++) {
			for (int j=0; j < 10; j++) {
				mas1[i][j] = mas2[i][j];
			}
		}	
}

int nextt(int map[10][10], int firstSize, int secondSize, int turn, int iter, int(winCheck)(int(*map)[10]), int(doturn)(int(&map)[10][10], int , int ,int)) {

	srand(time(NULL));
	int rating[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			rating[i][j] = 0;
		}
	}

	for (int i = 0; i < firstSize; i++) {
		for (int j = 0; j < secondSize; j++) {
			int backit[10][10];
			equal(backit, map);
			rating[i][j] += doturn(backit, turn, i, j);
			rating[i][j] += winCheck(map);
			if (iter > 0) {
				rating[i][j]-= abs(nextt(map, firstSize, secondSize, turn *= -1, iter - 1, winCheck, doturn))/10;
			}
			
		}
	}

	

	if (iter == 1) {
		int best = 0;
		int bestCdX = 1;
		int bestCdY = 1;

		for (int i = 0; i < firstSize; i++) {
			for (int j = 0; j < secondSize; j++) {
				if (rating[i][j] > best) {
					best = rating[i][j];
					bestCdX = j + 1;
					bestCdY = i + 1;

				}
			}
		}
		return bestCdX * 10 + bestCdY;
	}

	if (iter == 0) {
		int best = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (rating[i][j] >= best) {
					if (rand() % 2 == 0) {
						best = rating[i][j];
					}
				}
			}
		}

		return best;
	}
}