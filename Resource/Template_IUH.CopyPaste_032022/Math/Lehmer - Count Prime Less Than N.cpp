#define long long long
const int N = 100005;
const int M = 1000000007;
bool np[N];
int p[N], pp = 0;

void eratos() {
    np[0] = np[1] = true;
    for (int i = 2; i * i < N; i++)
        if (!np[i])
            for (int j = i * i; j < N; j += i) np[j] = true;
    for (int i = 2; i < N; i++)
        if (!np[i]) p[++pp] = i;
}

long power(long a, long k) {
    long P = 1;
    while (k) {
        if (k & 1) P = P * a;
        k /= 2;
        a = a * a;
    }
    return P;
}

long power(long a, long k, long M) {
    long P = 1;
    for (a = a % M; k; k /= 2) {
        if (k & 1) P = P * a % M;
        a = a * a % M;
    }
    return P;
}

long root(long n, long k) {
    long x = pow(n, 1.0 / k);
    while (power(x, k) % M == power(x, k, M) && power(x, k) < n) x++;
    while (power(x, k) % M != power(x, k, M) || power(x, k) > n) x--;
    return x;
}

map<long, long> Phi[N];

long phi(long x, int a) {
    if (Phi[a].count(x)) return Phi[a][x];
    if (a == 1) return (x + 1) / 2;
    long Result = phi(x, a - 1) - phi(x / p[a], a - 1);
    return Phi[a][x] = Result;
}

long pi(long x) {
    if (x < N)
        return upper_bound(p + 1, p + pp + 1, x) - (p + 1);
    long a = pi(root(x, 4));
    long b = pi(root(x, 2));
    long c = pi(root(x, 3));
    long Sum = phi(x, a) + (b + a - 2) * (b - a + 1) / 2;
    for (int i = a + 1; i <= b; i++)
        Sum -= pi(x / p[i]);
    for (int i = a + 1; i <= c; i++) {
        long bi = pi(root(x / p[i], 2));
        for (int j = i; j <= bi; j++)
            Sum -= pi(x / p[i] / p[j]) - (j - 1);
    }
    return Sum;
}

