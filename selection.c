#include <stdio.h>
int count = 0;
void print_arr(int arr[]) {

	if (count == 0)
		printf("���� �� ");
	else
		printf("%d��° ����", count);
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int ran(int left, int right) {
	int num;
	srand(time(NULL));
	num = rand() % (right - left + 1) + left;
	return num;
}

int selection(int arr[], int left, int right, int k) {
	int pivot, temp, low, high, r;
	count++;
	low = left;
	high = right + 1;
	//pivot �������� �����ϱ�
	r = ran(left, right);
	pivot = arr[r];
	printf("pivot: %d\n", pivot);
	print_arr(arr);

	//pivot���� ���� ���ʿ� �ִ� ���� �ٲٱ�(pivot�� ����Ʈ �ȿ� �ִ� ���� ���ϱ� ����)
	temp = arr[left];
	arr[left] = arr[r];
	arr[r] = temp;


	do
	{
		//pivot ������ ū ���� ���ö����� ����Ʈ�� ���� ���ʺ��� ���������� ��ĭ�� �ű�� ��
		do low++;
		while (arr[low] < pivot);

		//pivot ������ ���� ���� ���ö����� ����Ʈ�� ���� �����ʺ��� �������� ��ĭ�� �ű�� ��
		do high--;
		while (arr[high] > pivot);

		//ù��° do-while���� ���� ���� low�� �ι��� do-while���� ���� ���� high���� �۴ٸ�,
		//���� ��ġ�� �ٲ��ش�.
		//���� �׷��� �ʴٸ� �ݺ����� �����Ѵ�.
		if (low < high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			print_arr(arr);
		}

	} while (low < high);

	//���� do-while���� ����Ǹ鼭
	//ù��° do-while���� ���� ���� low�� �ι��� do-while���� ���� ���� high���� ���� �ʴٸ�,
	//�ش� �迭���� low�� ��ġ�ϴ� ���� ���� ���ʿ� �����ϴ� pivot�� ���� �ٲٸ�,
	//pivot���� ����ִ� ��ġ�� �������� ���ʿ� pivot���� ���� ����,
	//�����ʿ� pivot���� ū���� �����ϰ� �ȴ�.
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp;

	print_arr(arr);

	//pivot�� �������� ���ʿ� �ִ� ����Ʈ ĭ�� ũ��
	int S = high - left;


	if (k <= S) {
		//���� pivot�Ʒ��� �ִ� ĭ�� ũ�Ⱑ ���ϰ��� �ϴ� k���� ũ�ٸ�, pivot�� �������� ������ �����͸� ������
		//selection�Լ��� ��ȣ���Ѵ�.
		printf("small group size: %d, ���� �׷� ��ȣ��\n\n", S);
		return selection(arr, left, high - 1, k);
	}
	else if (k == S + 1) {
		//���� pivot�Ʒ��� �ִ� ĭ�� ũ�� + 1�� ���ϰ��� �ϴ� k�� ���ٸ� ���õ� pivot���� ���ϰ��� �ϴ� ���� �ȴ�.
		return arr[high];
	}
	else {
		//���� ��� �Ѵٿ� �ش����� �ʴ´ٸ�, ���ϰ��� �ϴ� k��°�� ���� pivot�� �������� �����ʿ� �ִٴ� ���̹Ƿ�
		//pivot�� �������� �����ʿ� �ִ� �����͸� ������ selection �Լ��� ��ȣ���Ѵ�.
		printf("small group size: %d, ������ �׷� ��ȣ��\n\n", S);
		return selection(arr, high + 1, right, k - S - 1);
	}
}

int main() {
	int arr[] = { 6,3,11,9,12,2,8,15,18,10,7,14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	print_arr(arr);
	printf("\n");
	int selected = selection(arr, 0, n - 1, k);

	printf("%d��° ���� ��: %d\n", k, selected);

	return 0;
}
