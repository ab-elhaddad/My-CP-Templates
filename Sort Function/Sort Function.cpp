#include <algorithm>
#include <vector>

struct el {
    int points;
    int penalty;
    bool isRudolf;
};

vector<el> lis;

sort(lis.begin(), lis.end(), [&](el a, el b) -> bool
     {
        if (a.points != b.points) return a.points < b.points;
        if (a.penalty != b.penalty) return a.penalty > b.penalty;
        return b.isRudolf; 
        });
