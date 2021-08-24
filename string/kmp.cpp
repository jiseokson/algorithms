#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

vi getPartialMatch(const string &n) {
    vi partialMatch(n.length(), 0);
    int begin = 1, matched = 0;
    while (begin + matched < n.length()) {
        if (n[begin + matched] == n[matched]) {
            ++matched;
            partialMatch[begin + matched - 1] = matched;
        } else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - partialMatch[matched - 1];
                matched = partialMatch[matched - 1];
            }
        }
    }
    return partialMatch;
}

vi search(const string &h, const string &n) {
    vi partialMatch = getPartialMatch(n);
    vi res;

    int begin = 0, matched = 0;
    while (begin + n.length() <= h.length()) {
        if (matched < n.length() && h[begin + matched] == n[matched])
            ++matched;
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - partialMatch[matched - 1];
                matched = partialMatch[matched - 1];
            }
        }
        if (matched == n.size())
            res.push_back(begin);
    }

    return res;
}

vi getPi(const string &p) {
    vi pi(p.length(), 0);
    int j = 0;
    for (int i = 1; i < p.length(); ++i) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

vi kmp(const string &s, const string &p) {
    // i: s의 인덱스
    // j: p의 인덱스, s와 p가 이전까지 일치한 문자수

    vi pi = getPi(p);
    vi res;
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
        while (j > 0 && s[i] != p[j]) // 불일치가 발생했을때 최대한 멀리 점프
            j = pi[j - 1];
        if (s[i] == p[j]) {
            ++j;
            if (j == p.length()) {
                res.push_back(i - p.length() + 1);
                j = pi[j - 1];
            }
        }
        // else if (j > 0)  // 한번만 점프,,
        //     j = pi[j - 1];
    }
    return res;
}


int main(void) {
    string h, n;
    cin >> h >> n;
    for (int &begin: kmp(h, n))
        cout << begin << ' ';
    return 0;
}