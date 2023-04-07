#include <stdio.h>

int count = 0;

void print_arr(int arr[]) {

	if (count == 0)
		printf("정렬 전 ");
	else
		printf("%d번째 정렬", count);
	for (int i = 0; i < 12; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int parrition(int arr[], int left, int right) {
	int pivot, temp, low, high;

	low = left;//배열의 가장 왼쪽 위치에 pivot이 들어가있기 때문에
	//그 위치에서 do-while문이 실행되어도 문제가 없다.
	high = right + 1; // 배열에서 가장 오른쪽 위치를 가리키는 right를 그대로 넣게 되면
	//do-while을 진행하는 과정에서 가장 우측에 있는 값을 비교할 수 없게 되므로,
	//1을 더해서 진행하도록 한다.
	pivot = arr[left]; //배열에서 가장 왼쪽에 존재하는 값을 pivot으로 잡는다.

	count++;//parrition함수가 호출되는 횟수

	do
	{
		//pivot 값보다 큰 값이 나올때까지 리스트의 가장 왼쪽부터 오른쪽으로 한칸씩 옮기며 비교
		do low++;
		while (arr[low] < pivot);

		//pivot 값보다 작은 값이 나올때까지 리스트의 가장 오른쪽부터 왼쪽으로 한칸씩 옮기며 비교
		do high--;
		while (arr[high] > pivot);

		//첫번째 do-while문을 통해 나온 low가 두번쨰 do-while문을 통해 나온 high보다 작다면,
		//둘의 위치를 바꿔준다.
		//만약 그렇지 않다면 반복문을 종료한다.
		if (low < high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			print_arr(arr);
		}

	} while (low < high);

	//위의 do-while문이 실행되면서
	//첫번째 do-while문을 통해 나온 low가 두번쨰 do-while문을 통해 나온 high보다 작지 않다면,
	//해당 배열에서 low가 위치하는 값과 가장 왼쪽에 존재하는 pivot의 값을 바꾸면,
	//pivot값이 들어있는 위치를 기준으로 왼쪽에 pivot보다 작은 값이,
	//오른쪽에 pivot보다 큰값이 존재하게 된다.
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
		//parrition함수가 진행되고 나서 return되는 값은 pivot으로 사용된 값이다.
		int q = parrition(arr, left, right);
		//parrition함수를 통해 나온 pivot의 위치를 중심으로 좌, 우로 나눠서 순환호출한다.
		quick_sort(arr, left, q - 1);
		quick_sort(arr, q + 1, right);
	}
}

int main() {
	int arr[12] = { 6, 3, 11, 9,  12, 2, 8, 15, 18, 10, 7, 14 };
	print_arr(arr);

	quick_sort(arr, 0, 11);


}

//참고자료
//C언어로 쉽게 풀어쓴 자료구조