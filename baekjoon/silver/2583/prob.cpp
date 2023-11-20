#include <bits/stdc++.h>
using namespace std;

#define SIZE        100
bool coordinates[SIZE][SIZE];
bool visited[SIZE][SIZE];
int M, N;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

typedef struct _point {
    int x;
    int y;
} Point;

void read_next_point(Point* point)
{
    cin >> point->x >> point->y;
}

void draw_rect(Point* points)
{
    Point* left = &points[0];
    Point* right = &points[1];

    for (int y = left->y; y < right->y; y++) {
        for (int x = left->x; x < right->x; x++) {
            coordinates[y][x] = true;
        }
    }
}

int dfs(int y, int x) 
{
    int count = 0;

    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            continue;
        }
        if (visited[ny][nx]) {
            continue;
        }
        if (coordinates[ny][nx]) {
            continue;
        }
        count += dfs(ny, nx);
    }
    return count + 1;
}

int main (void)
{
    int K;
    Point points[2];

	std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N >> K;
    
    int rect_case;
    for (rect_case = 0; rect_case < K; rect_case++) {
        read_next_point(&points[0]);
        read_next_point(&points[1]);
        
        draw_rect(points);
    }

    vector<int> area;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            if (coordinates[i][j]) continue;

            int size = dfs(i, j);
            if (size) {
                area.push_back(size);
            }
        }
    }
    sort(area.begin(), area.end());

    cout << area.size() << '\n';
    for (int size : area) {
        cout << size << ' ';
    }
    cout << '\n';
   
    return 0;
}