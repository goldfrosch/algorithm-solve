#include <iostream>
#include <map>

using namespace std;

struct Node {
    char Left = '.';
    char Right = '.';
};

map <char, Node> Tree;

void PreOrder(char Node) {
    if (Node == '.') {
        return;
    }

    printf("%c", Node);
    PreOrder(Tree[Node].Left);
    PreOrder(Tree[Node].Right);
}

void InOrder(char Node) {
    if (Node == '.') {
        return;
    }

    InOrder(Tree[Node].Left);
    printf("%c", Node);
    InOrder(Tree[Node].Right);
}

void PostOrder(char Node) {
    if (Node == '.') {
        return;
    }

    PostOrder(Tree[Node].Left);
    PostOrder(Tree[Node].Right);
    printf("%c", Node);
}

int main() {
    // https://www.acmicpc.net/problem/1991
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        char Parent, Left, Right;

        std::cin >> Parent >> Left >> Right;

        Tree[Parent].Left = Left;
        Tree[Parent].Right = Right;
    }

    PreOrder('A');
    printf("\n");
    InOrder('A');
    printf("\n");
    PostOrder('A');

    return 0;
}