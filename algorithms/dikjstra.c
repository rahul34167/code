#include<stdio.h>
#include<stdlib.h>
#define V 9
#include<limits.h>
#define bool int
int findmin(int spt[] , int wgtspt[]);

int findmin(int spt[] , int wgtspt[])
{
	
	int min = INT_MAX;
	int min_ind;
	int i;
	for(i=0;i<V;i++)
	{
		if(spt[i] == 0 && wgtspt[i] < min)
	{
		min = wgtspt[i] ;
		min_ind = i;
	}
	}
	
	return min_ind;
}

void printspt(int graph[V][V] , int arr[V] ,int wgtspt[V])
{
	int i;
	for(i=0;i<V;i++)
	{
		printf("%d \t %d \n", i , wgtspt[i]);
	}
	
	for(i=0;i<V;i++)
	printf("%d - %d \n", arr[i] , i);  //prints the graph i.e parent and correspondindg vertex
}

void dijkstra(int graph[V][V] , int source)
{
bool spt[V];
int wgtspt[V];   //matrix to store the min path value found yet
int parent[V];
int i;

for(i=0;i<V;i++)
{
	spt[i] = 0;
	wgtspt[i] = INT_MAX;	
}

wgtspt[source] = 0;
parent[source] = source;

int count;
for(count=0;count<V-1;count++)
{
	int u = findmin(spt,wgtspt);
	
	spt[u] = 1;
	int v;
	for(v=0;v<V;v++)
	{
		if(spt[v] == 0 && graph[u][v]  && wgtspt[u] != INT_MAX && wgtspt[u] + graph[u][v]  < wgtspt[v])
		{
		wgtspt[v] = wgtspt[u] + graph[u][v];
		parent[v] = u;
	}
}
}

printspt(graph,parent,wgtspt);
	
}



int main()
{
	
	int graph[V] [V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
	dijkstra(graph,0);
	return 0;
}
