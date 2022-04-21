typedef long long ll;

class Triplet
{
public:
    ll x, y, gcd;
};

Triplet extendedEuclidAlgo(ll a, ll b)
{
    if (b == 0)
    {
        Triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    Triplet small = extendedEuclidAlgo(b, a % b);
    Triplet ans;
    ans.gcd = small.gcd;
    ans.x = small.y;
    ans.y = small.x - ((a / b) * small.y);
    return ans;
}

ll MMI(ll a, ll b)
{
    ll ans = extendedEuclidAlgo(a, b).x;
    return (ans % b + b) % b;
}

//this calculates the value of a-1 % b