#include <stdio.h>

//물건의 가치와 무게를 구조체로 선언
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

	//물건이 선택되기 전인 경우의 가치를 0으로 초기화 시킨다.
	for (int i = 0; i <= 4; i++)
	{
		K[0][i] = 0;
	}

	//가방 용량이 0인 경우의 가치를 0으로 초기화 시킨다.
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
			//i번째 물건의 무게가 용량 w보다 크다면, 넣을 수 없기때문에, 물건 i가 선택되기 전인 i-1번째에 선택된 가치와 똑같다.
			if (items[i].weight > w) {
				K[i][w] = K[i - 1][w];
			}
			else {
				//i번째 물건의 무게가 용량 w와 같거나 그보다 작다면,
				//물건 i가 선택되기 전인 i-1번째에 선택된 가치와
				//i-1번째에서 i번째의 물건을 넣을 수 있을 만큼의 용량을 확보한 후 물건 i를 넣었을때의 가치를 비교하여서
				//더 큰 값을 K[i][w]의 값으로 갱신한다.
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

//최적해를 만드는 조합을 찾는 함수
void search_comb(int result, int C) {
	int i = 4;
	int w = C;

	while (i > 0 && w > 0) { //가장 마지막에 만들어진 값에서 시작, 용량이 0 혹은 음수가 되거나 물건이 아무것도 선택되지 않게 되면 정지
		//용량이 w일때, 물건 i가 선택된 경우와, 물건 i가 선택된 전인 i-1인 경우가 같다면, 물건 i는 선택되지 않은 것이다.
		//반대로 두 경우에 입력된 가치가 다르다면, 물건 i는 선택되었다.
		if (K[i][w] != K[i - 1][w]) { 
			printf("%d번 ", i); //선택된 물건인 i를 출력하고,
			w -= items[i].weight;//총 용량 C에서 물건 i의 무게만큼을 뺀다.
		}
		i--;//가장 마지막에 선택된 물건부터 첫번째로 선택된 물건까지 거꾸로 간다.
	}
}

//결과 출력
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

	search_comb(result, C);

	printf("\n");


}

int main() {
	int C = 10; // 가방이 수용할 수 있는 최대 무게

	int result = Zero_One_Knapsack(C);
	print_Zero_One_Knapsack(C, result);


}