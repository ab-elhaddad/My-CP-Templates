struct edge
{
    int to;
    int cost;
    int time;

    edge(int t, int c, int ti)
    {
        to = t;
        cost = c;
        time = ti;
    }
};

struct CompareMyStruct
{
    bool operator()(const edge *a, const edge *b)
    {
        return a->cost > b->cost;
    }
};

set<edge, vector<edge>, CompareMyStruct> st;