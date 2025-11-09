#include <stdio.h>

#define N 10  // maximum number of vertices

void dfs_visit(int A[][N], int p[], int d[], int f[], char c[], int i, int n)
{
    static int time = 0;  // shared time counter
    c[i] = 'g';           // 'g' means gray (vertex discovered)
    d[i] = ++time;        // discovery time

    for (int j = 0; j < n; j++)
    {
        if (A[i][j] == 1 && c[j] == 'w')  // if there is an edge and vertex is unvisited
        {
            p[j] = i;                     // parent of j is i
            dfs_visit(A, p, d, f, c, j, n);
        }
    }

    c[i] = 'b';           // 'b' means black (finished)
    f[i] = ++time;        // finishing time
}

void dfs(int A[][N], int p[], int d[], int f[], int n)
{
    char c[N];

    for (int i = 0; i < n; i++)
    {
        c[i] = 'w';   // 'w' means white (unvisited)
        p[i] = -1;    // no parent initially
    }

    for (int i = 0; i < n; i++)
    {
        if (c[i] == 'w')
            dfs_visit(A, p, d, f, c, i, n);
    }

    // printing the results
    printf("\nVertex\tParent\tDiscovery\tFinish\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t\t%d\n", i, p[i], d[i], f[i]);
    }
}

int main()
{
    int n;
    int A[N][N], p[N], d[N], f[N];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    dfs(A, p, d, f, n);

    return 0;
}