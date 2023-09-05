#include <map>
#include<string>
#include <queue>

struct node
{
    char c;
    bool isEnd;
    map<char, node *> childs;
    int len;

    node(char ch)
    {
        c = ch;
        isEnd = false;
        len = 0; // Determines the current char is a prefix for how many strings
    }

    void insert(node *&head, int idx, string &s)
    {
        if (idx == s.size())
        {
            head->isEnd = true;
            return;
        }
        if (!head->childs.count(s[idx]))
            head->childs[s[idx]] = new node(s[idx]);
        insert(head->childs[s[idx]], idx + 1, s);
    }

    node *findLast(node *&head, int idx, string &s)
    {
        if (idx == s.size())
            return head;
        if (head->childs.count(s[idx]))
            return findLast(head->childs[s[idx]], idx + 1, s);
        else
            return NULL;
    }

    int BFS(node *&curr)
    {
        if (!curr)
            return -1;
        queue<node *> q;
        q.push(curr);
        int steps = -1;
        while (!q.empty())
        {
            int sz = q.size();
            bool found = false;
            for (int i = 0; i < sz; i++)
            {
                node *front = q.front();
                q.pop();
                if (front->isEnd)
                    found = true;
                for (auto it : front->childs)
                    q.push(it.second);
            }
            steps++;
            if (found)
                return steps;
        }
        return -1;
    }

    int search(node *&head, string &s)
    {
        auto res = findLast(head, 0, s);
        return BFS(res);
    }

    int build(node *&curr)
    {
        int &ans = curr->len;
        int mn = INT32_MAX;
        for (auto &it : curr->childs)
        {
            mn = min(mn, build(it.second));
        }
        if (mn != INT32_MAX)
            ans += mn;
        if (curr->isEnd)
            ans = 0;
        ans++;
        return ans;
    }
};