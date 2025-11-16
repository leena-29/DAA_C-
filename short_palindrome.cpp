#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int shortPalindrome(string s) {
    long long single[26] = {0};
    long long pairs[26][26] = {0};
    long long triples[26] = {0};
    long long ans = 0;

    for(char ch : s){
        int x = ch - 'a';
        ans = (ans + triples[x]) % MOD;
        for(int j = 0; j < 26; j++){
            triples[j] = (triples[j] + pairs[j][x]) % MOD;
        }
        for(int j = 0; j < 26; j++){
            pairs[j][x] = (pairs[j][x] + single[j]) % MOD;
        }
        single[x]++;
    }
    return ans % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    cout << shortPalindrome(s);
    return 0;
}
