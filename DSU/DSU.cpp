#include <vector>
#define ll long long

struct DSU
{
    vector<ll> leader, groupSize;

    DSU(int n)
    {
        leader.resize(n + 5);
        for (int i = 1; i <= n; i++)
            leader[i] = i;

        groupSize.resize(n + 5, 1);
    }

    int FindLeader(int i)
    {
        if (leader[i] == i)
            return i;
        leader[i] = FindLeader(leader[i]);
        return leader[i];
    }

    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        if (leader1 == leader2)
            return;

        if (groupSize[leader1] > groupSize[leader2])
        {
            leader[leader2] = leader1;
            groupSize[leader1] += groupSize[leader2];
        }
        else
        {
            leader[leader1] = leader2;
            groupSize[leader2] += groupSize[leader1];
        }
    }
};