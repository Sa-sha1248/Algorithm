#include <stdio.h>
int sorted[100];

void merge(int list[], int left, int mid, int right) {

	int i = left;
	int j = mid + 1;
	int k = left;
	int l;

	//분할 된 list 합치기
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	//남은 레코드 일괄 복사
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	//sort된 리스트를 list로 복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];


}

void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; //리스트 반으로 나누기
		merge_sort(list, left, mid);//나눈 부분의 왼쪽 리스트 정렬
		merge_sort(list, mid + 1, right);//나눈 부분의 오른쪽 리스트 정렬
		merge(list, left, mid, right); // 나눈 리스트 합병
	}
}


int main() {
	int list[8] = { 37, 10, 22, 30, 35, 13, 25, 24 };

	merge_sort(list, 0, 7);

	for (int i = 0; i < 8; i++)
	{
		printf("%d | ", list[i]);
	}

}

//참고자료
//C 언어로 쉽게 풀어쓴 자료구조