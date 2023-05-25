#include <stdio.h>

typedef struct item {
	int value;
	int weight;
}item;

//결과 도출을 위해 사용 될 배열
int K[100][100];

//가방에 들어갈 물건들의 가치와 무게
//index 1부터 사용하기 위해 의미없는 값을 0번째에 추가
item items[] = { {0,0}, {10,5}, {40,4}, {30,6}, {50,3} };

void initKnap(int C) {

	for (int i = 0; i <= 4; i++)
	{
		K[0][i] = 0;
	}

	for (int i = 0; i <= C; i++)
	{
		K[i][0] = 0;
	}

}

int Zero_One_Knapsack(int C) {

	initKnap(C);

	for (int i = 1; i <= 4; i++)
	{
		for (int w = 1; w <= C; w++)
		{
			if (items[i].weight > w) {
				K[i][w] = K[i - 1][w];
			}else {
				if (K[i - 1][w] > K[i - 1][w - (items[i].weight)] + items[i].value) {
					K[i][w] = K[i - 1][w];
				}
				else {
					K[i][w] = K[i - 1][w - (items[i].weight)] + items[i].value;
				}
			}
				
		}
	}

	return K[4][10];

}

void print_Zero_One_Knapsack(int C, int result) {
	printf("\n------------------------------------------------------------------------------\n");


	printf("|      가방 용량     || ");
	for (int w = 0; w <= C; w++)
	{
		printf("%2d | ", w);
	}
	printf("\n|--------------------||------------------------------------------------------|\n");

	printf("| 물건 | 가치 | 무게 || ");
	for (int w = 0; w <= C; w++)
	{
		printf("%2d | ", K[0][w]);
	}

	printf("\n|--------------------||------------------------------------------------------|\n");

	
	for (int i = 1; i <= 4; i++)
	{
		printf("| %4d | %4d | %4d || ", i, items[i].value, items[i].weight);
		for (int w = 0; w <= C; w++)
		{
			printf("%2d | ", K[i][w]);
		}
		printf("\n");
	}
	printf("------------------------------------------------------------------------------\n");

	printf("\nresult: %d\n", result);


	printf("최적해를 만들어내는 조합: ");
}

int main() {
	int C = 10; // 가방이 수용할 수 있는 최대 무게

	int result = Zero_One_Knapsack(C);
	print_Zero_One_Knapsack(C, result);


}