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


int parrition(int arr[], int left, int right) {
	int pivot, temp, low, high;

	low = left;//�迭�� ���� ���� ��ġ�� pivot�� ���ֱ� ������
	//�� ��ġ���� do-while���� ����Ǿ ������ ����.
	high = right + 1; // �迭���� ���� ������ ��ġ�� ����Ű�� right�� �״�� �ְ� �Ǹ�
	//do-while�� �����ϴ� �������� ���� ������ �ִ� ���� ���� �� ���� �ǹǷ�,
	//1�� ���ؼ� �����ϵ��� �Ѵ�.
	pivot = arr[left]; //�迭���� ���� ���ʿ� �����ϴ� ���� pivot���� ��´�.

	count++;//parrition�Լ��� ȣ��Ǵ� Ƚ��

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
	printf("\n");
	return high;
}

void quick_sort(int arr[], int left, int right) {
	if (left < right)
	{
		//parrition�Լ��� ����ǰ� ���� return�Ǵ� ���� pivot���� ���� ���̴�.
		int q = parrition(arr, left, right);
		//parrition�Լ��� ���� ���� pivot�� ��ġ�� �߽����� ��, ��� ������ ��ȯȣ���Ѵ�.
		quick_sort(arr, left, q - 1);
		quick_sort(arr, q + 1, right);
	}
}

int main() {
	int arr[12] = { 6, 3, 11, 9,  12, 2, 8, 15, 18, 10, 7, 14 };
	print_arr(arr);

	quick_sort(arr, 0, 11);


}

//�����ڷ�
//C���� ���� Ǯ� �ڷᱸ��