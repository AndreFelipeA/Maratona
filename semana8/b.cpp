#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Estrutura para representar um nó no labirinto
struct Node {
    int row;
    int col;
    string path;
};

// Verifica se uma posição está dentro dos limites do labirinto
bool isValid(int row, int col, int N, int M) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

// Função para resolver o labirinto
void solveMaze(vector<string>& maze, int N, int M) {
    // Vetor para marcar as posições visitadas
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // Movimentos possíveis: cima, baixo, esquerda, direita
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    vector<char> directions = {'U', 'D', 'L', 'R'};

    // Encontra a posição de partida (A) e de chegada (B)
    int startRow, startCol, endRow, endCol;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == 'A') {
                startRow = i;
                startCol = j;
            } else if (maze[i][j] == 'B') {
                endRow = i;
                endCol = j;
            }
        }
    }

    // Fila para a busca em largura
    queue<Node> q;
    q.push({startRow, startCol, ""});
    visited[startRow][startCol] = true;

    // Variáveis para armazenar o menor caminho
    int minPathLength = 0;
    string minPath;

    // Executa a busca em largura
    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        int row = current.row;
        int col = current.col;
        string path = current.path;

        // Verifica se chegou à posição de chegada (B)
        if (row == endRow && col == endCol) {
            minPathLength = path.length();
            minPath = path;
            break;
        }

        // Explora as posições vizinhas
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            // Verifica se a posição vizinha é válida e não foi visitada
            if (isValid(newRow, newCol, N, M) && maze[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                q.push({newRow, newCol, path + directions[i]});
                visited[newRow][newCol] = true;
            }
        }
    }

    // Imprime a solução
    if (minPathLength > 0) {
        cout << "YES" << endl;
        cout << minPathLength << endl;
        cout << minPath << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> maze(N);
    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    solveMaze(maze, N, M);

    return 0;
}