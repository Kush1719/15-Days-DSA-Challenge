void multiply(int F[2][2], int M[2][2], const int &mod) {
    int x = ((F[0][0] * 1LL * M[0][0]) % mod + (F[0][1] * 1LL * M[1][0]) % mod) % mod;
    int y = ((F[0][0] * 1LL * M[0][1]) % mod + (F[0][1] * 1LL * M[1][1]) % mod) % mod;
    int z = ((F[1][0] * 1LL * M[0][0]) % mod + (F[1][1] * 1LL * M[1][0]) % mod) % mod;
    int w = ((F[1][0] * 1LL * M[0][1]) % mod + (F[1][1] * 1LL * M[1][1]) % mod) % mod;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void power(int F[2][2], int nStairs, const int& mod) {
    if (nStairs <= 1) {
        return;
    }
    int M[2][2] = {{1, 1}, {1, 0}};
    power(F, nStairs / 2, mod);
    multiply(F, F, mod);
    if (nStairs % 2 == 1) {
        multiply(F, M, mod);
    }
}
int fib(int nStairs, const int& mod) {
    int F[2][2] = {{1, 1}, {1, 0}};
    if (nStairs == 0) {
        return 0;
    }
    power(F, nStairs - 1, mod);
    return F[0][0];
}
int countDistinctWays(int nStairs) {
    const int mod = 1000000007;
    return fib(nStairs + 1, mod);
}