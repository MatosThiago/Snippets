#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, int>> fat(long long N) {
    
    vector<long long> Aux(N, 1);

    for(long long i = 2; i < N; i++) {
        if(Aux[i] == 1) {
            for(long long j = i; j < N; j += i) {
                Aux[j] = i;
            }
        }
    }

    vector<pair<long long, int>> V;

    while(N > 1) {
        if(lower_bound(V.begin(), V.end(), N) == V.end()) {
            V.push_back(Aux[N]);
        } else {
            V[lower_bound(V.begin(), V.end(), N) - V.begin()] = Aux[N];
        }
        N /= Aux[N];
    }

    for(pair<long long, int> i:M) {
        V.emplace_back(i);
    }

    return V;
}

int main() {

    long long N;
    scanf("%lld", &N);
    vector<pair<long long, int>> Fat = fat(N);

    for(auto i:Fat) {
        printf("%lld ^ %d\n", i.first, i.second);
    }

    return 0;
}