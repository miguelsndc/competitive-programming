#include <bits/stdc++.h>
using namespace std;

#define fori(n) for (int i = 0; i < n; i++)

const int maxn = 1e6 + 5;

int trie[maxn][26], word_end[maxn], z = 1;

void add(string &s) {
    int cur = 0;
    fori(s.size()) {
        if (trie[cur][s[i] - 'a'] == -1) {
            memset(trie[z], -1, sizeof trie[z]);
            trie[cur][s[i] - 'a'] = z++;
        }
        cur = trie[cur][s[i] - 'a'];
    }
    word_end[cur]++;
}

int query(string &s){
	int cur = 0;
	fori(s.size()){
		if(trie[cur][s[i] - 'a'] == -1) return 0;
		cur = trie[cur][s[i] - 'a'];
	}
	return word_end[cur];
}

void init(){
	memset(trie[0], -1, sizeof trie[0]);
    memset(word_end, 0, sizeof word_end);
	z = 1;
}