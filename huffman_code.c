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

	//�� ���ں� �󵵸� ������ ��� ���� �� �迭�� �߰�
	for (i = 0; i < n; i++)
	{
		nodes[i] = create_node(chars[i], frequency[i]);
		size++;
	}

	printf("��� ���� ��\n");
	nodes_print(nodes, size);
	

	//��� �迭 ����
	insertion_sort(nodes, size);

	printf("��� ���� ��\n");
	nodes_print(nodes, size);

	printf("\nHuffmanCoding ���� ����\n");
	while (size > 1) {
		//�󵵰� ���� ���� ��� �ΰ��� ���ļ� �ϳ��� Ʈ���� ����
		left = nodes[0];
		right = nodes[1];
		top = create_node('$', left->frequency + right->frequency);
		top->left = left;
		top->right = right;

		//Ʈ���� root�� nodes[0]�� �ְ�,
		//nodes[1]�� ���� ũ�� �ٲ㼭 ���� �� �迭 ���� �ڷ� ���� �Ѵ�.
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

	//���� ��尡 �������ִ� huffman code �״�� ��������,
	//���� ��尡 ��������� �������� ������������ ���� 0 Ȥ�� 1 �߰�
	if (a != 2) {
		for (int i = 0; i < node->count; i++)
			root->huff[i] = node->huff[i];
		root->count = node->count;
		root->huff[root->count] = a;
		root->count++;
	}
	
	//�ش� ��尡 �ܸ������ ���
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
		//0 �߰��ϱ�
	}

	if (root->right != NULL) {
		print_tree(root->right,root, 1);
		//1 �߰��ϱ�
	}
}

int main() {
	char chars[] = { 'A', 'T', 'G', 'C' };
	int frequency[] = { 450, 90, 120, 270 };
	int n = sizeof(chars) / sizeof(chars[0]); // �Էµ� ������ �� (����� ��)

	TreeNode* root = HuffmanCoding(chars, frequency, n);

	printf("\nHuffmanCoding ���� ���\n");
	print_tree(root,root, 2);
}