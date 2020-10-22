#include <stdio.h>
#include <stdlib.h>

#define N 50 // number of fish
#define M 20 // number of tanks

typedef struct fish {
	
	int length;
	float weight;
	
} FISH;

typedef struct tank {

	FISH fishes[N];
	double stats[N];

} TANK;

typedef struct tank2 {

	FISH * fishes;
	int nfishes;

} TANK2;

void init_tanks(TANK[M]);

void init_tanks(TANK tanks[M]) {
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			tanks[i].fishes[j].length = i + j;
			tanks[i].fishes[j].weight = (i + j) * 3.2;	
		}
	}
}

void init_tanks2(TANK2 *);

void init_tanks2(TANK2 * tanks) {
	for (int i = 0; i < M; ++i){
		/*for (int j = 0; j < N; ++j){
			(*(tanks + i)).fishes[j].length = i + j;
			(*(tanks + i)).fishes[j].weight = (i + j) * 3.2;	
		}*/
		for (int j = 0; j < N; ++j){
			(tanks + i)->fishes[j].length = i + j;
			(tanks + i)->fishes[j].weight = (i + j) * 3.2;	
		}
	}
}

int main(){

	TANK tanks[M]; // number of bytes: 20 * 50(4(int) + 4(float) + 8(double)) = 16000 bytes (16 kilobytes)
	init_tanks(tanks);

	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			tanks[i].stats[j] = tanks[i].fishes[j].weight * tanks[i].fishes[j].length;
		}
	}

	int m = 30;
	int n = 45;
	TANK2 * newtanks = (TANK2 *)malloc(m * sizeof(TANK2));
	for (int i = 0; i < m; ++i){
		FISH * f;
		(newtanks + i)->nfishes = n;
		(newtanks + i)->fishes = f =(FISH *)malloc(n * sizeof(FISH));
		for (int j = 0; j < n; ++j){
			(f + j)->length = i;
			(f + j)->weight = (i+j) * 3.2;
		}
	}
	for (int i = 0; i < m; ++i){
		free((newtanks + i)->fishes);
	}
	free(newtanks);
}