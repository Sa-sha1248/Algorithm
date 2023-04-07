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
	//pivot 랜덤으로 선택하기
	r = ran(left, right);
	pivot = arr[r];
	printf("pivot: %d\n", pivot);
	print_arr(arr);

	//pivot값을 가장 왼쪽에 있는 값과 바꾸기(pivot과 리스트 안에 있는 값을 비교하기 위함)
	temp = arr[left];
	arr[left] = arr[r];
	arr[r] = temp;


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

	//pivot을 기준으로 왼쪽에 있는 리스트 칸의 크기
	int S = high - left;


	if (k <= S) {
		//만약 pivot아래에 있는 칸의 크기가 구하고자 하는 k보다 크다면, pivot을 기준으로 왼쪽의 데이터를 가지고
		//selection함수를 재호출한다.
		printf("small group size: %d, 왼쪽 그룹 재호출\n\n", S);
		return selection(arr, left, high - 1, k);
	}
	else if (k == S + 1) {
		//만약 pivot아래에 있는 칸의 크기 + 1이 구하고자 하는 k와 같다면 선택된 pivot값이 구하고자 하는 값이 된다.
		return arr[high];
	}
	else {
		//위의 경우 둘다에 해당하지 않는다면, 구하고자 하는 k번째의 값이 pivot을 기준으로 오른쪽에 있다는 뜻이므로
		//pivot을 기준으로 오른쪽에 있는 데이터를 가지고 selection 함수를 재호출한다.
		printf("small group size: %d, 오른쪽 그룹 재호출\n\n", S);
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

	printf("%d번째 작은 수: %d\n", k, selected);

	return 0;
}
