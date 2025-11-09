#include <stdio.h>
#define N 10
#define MS 10  // Queue size same as your deque structure

// --- Queue structure (same as your deque code but simplified) ---
typedef struct {
    int arr[MS];
    int front, rear;
} QUEUE;

void init(QUEUE *q) {
    q->front = -1;
    q->rear = -1;
}

int isempty(QUEUE *q) {
    return (q->front == -1);
}

int isfull(QUEUE *q) {
    return ((q->rear + 1) % MS == q->front);
}

void enqueue(QUEUE *q, int item) {
    if (isfull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % MS;
    q->arr[q->rear] = item;
}

int dequeue(QUEUE *q) {
    if (isempty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MS;
    return temp;
}

// --- BFS Implementation ---
void BFS(int A[N][N], int p[N], int d[N], int i, int n) {
    char c[N]; // color array: 'w' = white, 'g' = gray, 'b' = black
    QUEUE q;
    init(&q);

    // Initialize all vertices as unvisited
    for (int j = 0; j < n; j++)
        c[j] = 'w';

    // Initialize starting vertex
    p[i] = -1;
    d[i] = 0;
    c[i] = 'g';
    enqueue(&q, i);

    // BFS loop
    while (!isempty(&q)) {
        int u = dequeue(&q);
        printf("Visited vertex: %d\n", u);

        for (int j = 0; j < n; j++) {
            if (A[u][j] == 1 && c[j] == 'w') {
                p[j] = u;
                d[j] = d[u] + 1;
                c[j] = 'g';
                enqueue(&q, j);
            }
        }
        c[u] = 'b';
    }
}

// --- Main Function ---
int main() {
    int n, i;
    int A[N][N], p[N], d[N];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            scanf("%d", &A[r][c]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &i);

    BFS(A, p, d, i, n);

    printf("\nParent and Distance arrays:\n");
    for (int k = 0; k < n; k++)
        printf("Vertex %d → Parent: %d, Distance: %d\n", k, p[k], d[k]);

    return 0;
}