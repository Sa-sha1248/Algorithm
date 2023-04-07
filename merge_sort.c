#include <stdio.h>
int sorted[100];

void merge(int list[], int left, int mid, int right) {

	int i = left;
	int j = mid + 1;
	int k = left;
	int l;

	//���� �� list ��ġ��
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	//���� ���ڵ� �ϰ� ����
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	//sort�� ����Ʈ�� list�� ����
	for (l = left; l <= right; l++)
		list[l] = sorted[l];


}

void merge_sort(int list[], int left, int right) {
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2; //����Ʈ ������ ������
		merge_sort(list, left, mid);//���� �κ��� ���� ����Ʈ ����
		merge_sort(list, mid + 1, right);//���� �κ��� ������ ����Ʈ ����
		merge(list, left, mid, right); // ���� ����Ʈ �պ�
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

//�����ڷ�
//C ���� ���� Ǯ� �ڷᱸ��