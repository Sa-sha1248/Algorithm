#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

//====================== union-find 과정 ============================
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

//그래프 초기화
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

//간선 추가 - 정점의 이름을 소문자 영어로 받았으니, 'a'만큼 빼주면 0,1,2... 과같은 값을 가지게 된다.
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start-'a';
	g->edges[g->n].end = end-'a';
	g->edges[g->n].weight = w;
	g->n++;
}

//qsort에 사용되는 함수, 해당 함수를 통해 간선의 가중치를 비교하여서 오름차순으로 정렬된다.
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
	printf("신장트리 T = { ");
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

	printf("크루스칼 최소 신장 트리 알고리즘\n");
	printf("그래프의 정점의 수: %d -> MST 간선의 수:%d\n", g->nvertex, g->nvertex-1);
	int i = 0;
	while (mst.edge_accepted < (g->nvertex - 1))
	{
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset) {
			printf("\n간선 (%c-%c) 가중치:%d\n", e.start + 'a', e.end + 'a', e.weight);
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