#include <stdio.h>
#define INF 10000000

int c[100][100];
int s[100][100];


//c[i][j]: Ai 부터 Aj까지 곱하기 위한 최소 곱셈 수
void result_print(int n) {
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
			printf("    c|");
		else
			printf("%5d|",i);
	}
	printf("\n");

	for (int i = 1; i <= n; i++)
	{
		printf("%5d|", i);
		for (int k = 1; k <= n; k++)
		{
			printf("%5d|", c[i][k]);
		}
		printf("\n");
	}
	printf("\n");
}


//최소 곱셈 연산을 만들어내는 조합 출력
void result_conbination(int i, int j) {


	if (i == j)
		printf("A%d", i);
	else {
		printf("(");
		result_conbination(i, s[i][j]);
		result_conbination(s[i][j] + 1, j);
		printf(")");
	}


}

//최소 곱을 만드는 조합을 찾는 과정
int minimum_element_multiplication(int d[], int n) {
	for (int i = 1; i <= n; i++) {
		c[i][i] = 0;
		//printf("c[%d][%d] : %d\n", i, i, c[i][i]);
	}
	printf("\n");

	int j, temp;
	for (int L = 2; L <= n; L++)
	{
		for (int i = 1; i <= (n - L +1); i++)
		{
			j = i + L - 1;
			c[i][j] = INF;

			for (int k = i; k <= j-1; k++)
			{
				temp = c[i][k] + c[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (temp < c[i][j]) {
					c[i][j] = temp;
					s[i][j] = k;
					printf("c[%d][%d] : %d\n", i, j, c[i][j]);
				}
				
			}
		}
	}

	printf("\n");
	result_print(n);

	printf("최소 연산 횟수 조합 : ");
	result_conbination(1, n);

	printf("\n\n");
	return c[1][n];
}

int main() {
	int d[] = { 10,20,5,15,30 }; 
	int n = sizeof(d) / sizeof(d[0]) - 1; // 연산할 매트리스 수

	int min = minimum_element_multiplication(d,n);


	printf("min : %d\n", min);


	return 0;
}

//참고자료
//수업 ppt 수도코드