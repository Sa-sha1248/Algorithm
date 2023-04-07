#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

//====================== union-find ���� ============================
void set_init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}
//=========================================================

struct Edge {
	int start, end, weight;
};

typedef struct GraphType {
	int n;
	int nvertex;
	struct Edge edges[2 * MAX_VERTICES];
}GraphType;

//�׷��� �ʱ�ȭ
void graph_init(GraphType* g)
{
	g->n = g->nvertex = 0;
	for (int i = 0; i < 2*MAX_VERTICES; i++)
	{
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

//���� �߰� - ������ �̸��� �ҹ��� ����� �޾�����, 'a'��ŭ ���ָ� 0,1,2... ������ ���� ������ �ȴ�.
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start-'a';
	g->edges[g->n].end = end-'a';
	g->edges[g->n].weight = w;
	g->n++;
}

//qsort�� ���Ǵ� �Լ�, �ش� �Լ��� ���� ������ ����ġ�� ���Ͽ��� ������������ ���ĵȴ�.
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return(x->weight - y->weight);
}

typedef struct kruskal_mst {
	int edge_accepted;
	struct Edge T[MAX_VERTICES];
}kruskal_mst;

void print_mst(kruskal_mst mst)
{
	printf("����Ʈ�� T = { ");
	for (int i = 0; i < mst.edge_accepted; i++)
	{
		printf("(%c, %c) ", mst.T[i].start+'a', mst.T[i].end+'a');
	}
	printf("}\n");
}

void kruskal(GraphType* g)
{
	kruskal_mst mst;
	mst.edge_accepted = 0;
	int uset, vset;
	struct Edge e;

	set_init(g->nvertex);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("ũ�罺Į �ּ� ���� Ʈ�� �˰���\n");
	printf("�׷����� ������ ��: %d -> MST ������ ��:%d\n", g->nvertex, g->nvertex-1);
	int i = 0;
	while (mst.edge_accepted < (g->nvertex - 1))
	{
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset) {
			printf("\n���� (%c-%c) ����ġ:%d\n", e.start + 'a', e.end + 'a', e.weight);
			mst.T[mst.edge_accepted].start = e.start;
			mst.T[mst.edge_accepted].end = e.end;
			mst.edge_accepted++;

			set_union(uset, vset);
			print_mst(mst);
		}
		i++;
	}

}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	g->nvertex = 6;
	insert_edge(g, 'a', 'b', 8);
	insert_edge(g, 'a', 'd', 2);
	insert_edge(g, 'a', 'e', 4);
	insert_edge(g, 'b', 'c', 1);
	insert_edge(g, 'b', 'f', 2);
	insert_edge(g, 'b', 'd', 4);
	insert_edge(g, 'c', 'f', 1);
	insert_edge(g, 'd', 'f', 7);
	insert_edge(g, 'd', 'e', 3);
	insert_edge(g, 'e', 'f', 9);

	kruskal(g);
}