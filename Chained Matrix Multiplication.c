#include <stdio.h>
#define INF 10000000

int c[100][100];
int s[100][100];


//c[i][j]: Ai ���� Aj���� ���ϱ� ���� �ּ� ���� ��
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


//�ּ� ���� ������ ������ ���� ���
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

//�ּ� ���� ����� ������ ã�� ����
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

	printf("�ּ� ���� Ƚ�� ���� : ");
	result_conbination(1, n);

	printf("\n\n");
	return c[1][n];
}

int main() {
	int d[] = { 10,20,5,15,30 }; 
	int n = sizeof(d) / sizeof(d[0]) - 1; // ������ ��Ʈ���� ��

	int min = minimum_element_multiplication(d,n);


	printf("min : %d\n", min);


	return 0;
}

//�����ڷ�
//���� ppt �����ڵ�