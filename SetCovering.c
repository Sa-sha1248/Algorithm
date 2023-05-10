#include <stdio.h>

#define TRUE 1
#define FALSE 0

//입력: U, F = { S_i }, i = 1, ⋯, n
//출력 : 집합 커버 C
//1. C = ∅
//2. while (U≠∅) do {
//	3. U의 원소들을 가장 많이 포함하고 있는 집합 S_i를 F에서 선택한다.
//		4. U = U - S_i
//		5. S_i를 F에서 제거하고, S_i를 C에 추가한다.
//}
//6. return C

int all_covered(int a[]) {
	for (int i = 0; i < 10; i++)
	{
		if (a[i] == FALSE)
			return 0;
	}
	return 1;
}

int SetCover(int U[], int* S[]) {
	int C[10];
	int select = 0;

	//정점 선택 배열 초기화
	int is_covered[10];
	for (int i = 0; i < 10; i++)
	{
		is_covered[i] = FALSE;
	}

	while (!all_covered(is_covered))
	{
		int best_set = -1;
		int best_count = 0;

		//가장 많은 원소를 포함한 집합 선택	
		for (int i = 0; i < 10; i++)
		{
			int count = 0;
			for (int k = 0; k < 10; k++)
			{
				if (S[i][k] != 0 && !is_covered[S[i][k]-1])
					count++;
			}
			if (count > best_count)
			{
				best_count = count;
				best_set = i;
			}

		}

		//원소가 가장 많은 집합을 C에 추가하고, 
		//집합에 포함되어있던 원소들을 커버 된 것으로 변경
		printf("집합 S%d 추가\n", best_set+1);
		C[select++] = best_set;
		for (int j = 0; j < 10; j++) {
			if (S[best_set][j]!= 0) {
				printf("%d ", S[best_set][j]);
				is_covered[S[best_set][j]-1] = TRUE;
			}
		}
		printf("\n");

		for (int j = 0; j < 10; j++) {
				printf("%d ", is_covered[j]);
		}
		printf("\n\n");

	}

	//결과출력
	printf("결과 C = { ");
	for (int i = 0; i < select; i++)
	{
		printf("S%d ", C[i]+1);
	}
	printf("} 선택");
	
	return select;

}

int main() {
	int U[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int s1[] = {1, 2, 3, 8, 0, 0, 0, 0, 0, 0};
	int s2[] = {1, 2, 3, 4, 8, 0, 0, 0, 0, 0};
	int s3[] = {1, 2, 3, 4, 0, 0, 0, 0, 0, 0};
	int s4[] = {2, 3, 4, 5, 7, 8, 0, 0, 0, 0};
	int s5[] = {4, 5, 6, 7, 0, 0, 0, 0, 0, 0};
	int s6[] = {5, 6, 7, 9, 10, 0, 0, 0, 0, 0};
	int s7[] = {4, 5, 6, 7, 0, 0, 0, 0, 0, 0};
	int s8[] = {1, 2, 4, 8, 0, 0, 0, 0, 0, 0};
	int s9[] = {6, 9, 0, 0, 0, 0, 0, 0, 0, 0};
	int s10[] = {6, 10, 0, 0, 0, 0, 0, 0, 0, 0 };

	int* S[10] = {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10};

	int a = SetCover(U, S);
}