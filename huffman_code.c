#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int symbol;
	int frequency;
	struct TreeNode* left;
	struct TreeNode* right;
	int count;
	int huff[100];
}TreeNode;

TreeNode* create_node(char c, int f) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->symbol = c;
	node->frequency = f;
	node->left = node->right = NULL;
	node->count = 0;
	return node;
}

void insertion_sort(TreeNode** arr, int n) {
	int i, j;
	TreeNode* temp;

	for (i = 1; i < n; i++) {
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j]->frequency > temp->frequency) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void nodes_print(TreeNode* nodes[], int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%c: %d | ", nodes[i]->symbol, nodes[i]->frequency);
	}
	printf("\n");
}

TreeNode* HuffmanCoding(char chars[], int frequency[], int n) {
	TreeNode* nodes[100];
	TreeNode* left, * right, * top;
	TreeNode* T[100];

	int i, j, size = 0;

	//각 문자별 빈도를 포함한 노드 생성 후 배열에 추가
	for (i = 0; i < n; i++)
	{
		nodes[i] = create_node(chars[i], frequency[i]);
		size++;
	}

	printf("노드 생성 후\n");
	nodes_print(nodes, size);
	

	//노드 배열 정렬
	insertion_sort(nodes, size);

	printf("노드 정렬 후\n");
	nodes_print(nodes, size);

	printf("\nHuffmanCoding 실행 과정\n");
	while (size > 1) {
		//빈도가 가장 작은 노드 두개를 합쳐서 하나의 트리로 생성
		left = nodes[0];
		right = nodes[1];
		top = create_node('$', left->frequency + right->frequency);
		top->left = left;
		top->right = right;

		//트리의 root를 nodes[0]에 넣고,
		//nodes[1]의 값을 크게 바꿔서 정렬 후 배열 가장 뒤로 가게 한다.
		nodes[0] = top;
		nodes[1]->frequency = 10000;

		insertion_sort(nodes, size);
		
		size--;

		nodes_print(nodes, size);
	}


	return nodes[0];
}

int isLeaf(TreeNode* node) {
	return !(node->left) && !(node->right);
}


void print_tree(TreeNode* root, TreeNode* node, int a) {

	if (root == NULL) {
		return;
	}

	//상위 노드가 가지고있는 huffman code 그대로 가져오고,
	//현재 노드가 상위노드의 왼쪽인지 오른쪽인지에 따라 0 혹은 1 추가
	if (a != 2) {
		for (int i = 0; i < node->count; i++)
			root->huff[i] = node->huff[i];
		root->count = node->count;
		root->huff[root->count] = a;
		root->count++;
	}
	
	//해당 노드가 단말노드라면 출력
	if (isLeaf(root)) {
		printf("%c ", root->symbol);
		for (int k = 0; k < root->count; k++)
		{
			printf("%d", root->huff[k]);
		}
		printf(" | ");
	}
		

	if (root->left != NULL) {
		print_tree(root->left, root, 0);
		//0 추가하기
	}

	if (root->right != NULL) {
		print_tree(root->right,root, 1);
		//1 추가하기
	}
}

int main() {
	char chars[] = { 'A', 'T', 'G', 'C' };
	int frequency[] = { 450, 90, 120, 270 };
	int n = sizeof(chars) / sizeof(chars[0]); // 입력된 문자의 수 (노드의 수)

	TreeNode* root = HuffmanCoding(chars, frequency, n);

	printf("\nHuffmanCoding 실행 결과\n");
	print_tree(root,root, 2);
}