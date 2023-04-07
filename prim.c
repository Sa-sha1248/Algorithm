#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

//가중치가 가장 적은 정점 찾기
int get_min_vertex(int n)
{
	int v, i;
	//아직 선택되지 않은 정점 탐색
	for ( i = 0; i < n; i++)
	{
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	//앞의 for문에서 선택된 정점보다 가중치가 더 낮은 정점이 있다면, v값 대체
	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;
	}

	return v;
}

int T[MAX_VERTICES];

void print_tree(int T[], int n) {
	printf("T = { ");
	for (int i = 0; i < n+1; i++)
	{
		printf("%c ", T[i]+'a');
	}
	printf("}\n");
}
void print_distance(GraphType* g) {
	printf("D = { ");
	for (int i = 0; i < g->n; i++)
	{
		printf("%d ", distance[i]);
	}
	printf("}\n");
}

void prim(GraphType* g)
{
	int i, u, v;
	//최초의 정점 랜덤선택
	srand(time(NULL));
	int s = rand() % g->n;

	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("\n정점 %c 추가\n", u+'a');
		T[i] = u;
		//정점이 추가되어서 변하는 가중치들 갱신
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
		print_tree(T, i);
		print_distance(g);
	}

}

int main() {
	GraphType g = { 6,
		{
			{0, 3, INF, 2, 4, INF},
			{3, 0, 1, 4, INF, 2},
			{INF, 1, 0, INF, INF, 1},
			{2, 4, INF,0, 5, 7},
			{4, INF, INF, 5, 0, 9},
			{INF, 2, 1, 7, 9, 0}
		}
	};
	prim(&g);
}