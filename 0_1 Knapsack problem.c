#include <stdio.h>

typedef struct item {
	int value;
	int weight;
}item;

//��� ������ ���� ��� �� �迭
int K[100][100];

//���濡 �� ���ǵ��� ��ġ�� ����
//index 1���� ����ϱ� ���� �ǹ̾��� ���� 0��°�� �߰�
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


	printf("|      ���� �뷮     || ");
	for (int w = 0; w <= C; w++)
	{
		printf("%2d | ", w);
	}
	printf("\n|--------------------||------------------------------------------------------|\n");

	printf("| ���� | ��ġ | ���� || ");
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


	printf("�����ظ� ������ ����: ");
}

int main() {
	int C = 10; // ������ ������ �� �ִ� �ִ� ����

	int result = Zero_One_Knapsack(C);
	print_Zero_One_Knapsack(C, result);


}