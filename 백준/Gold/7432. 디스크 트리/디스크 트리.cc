#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct trie
{
    map<string, trie*> childs;
    map<string, trie*>::iterator it;

    void insert(queue<string> q)
    {
        if (q.empty())
        {
            return;
        }
        string directoryName = q.front();
        q.pop();
        it = childs.find(directoryName);
        if (it == childs.end())
        {
            trie* newDirectory = new trie();
            childs.insert({ directoryName, newDirectory });
            newDirectory->insert(q);
        }
        else
        {
            it->second->insert(q);
        }
    }

    void dfs(int depth)
    {
        for (it = childs.begin(); it != childs.end(); it++)
        {
            for (int i = 0; i < depth; i++)
            {
                cout << " ";
            }
            cout << it->first << "\n";
            it->second->dfs(depth + 1);
        }
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    string str, token;
    trie* root = new trie();
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        istringstream ss(str);
        queue<string> fullDirectory;
        while (getline(ss, token, '\\'))
        {
            fullDirectory.push(token);
        }
        root->insert(fullDirectory);
    }
    root->dfs(0);
    return 0;
}