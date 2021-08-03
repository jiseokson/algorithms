#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define FOR(i, n) for (int (i) = 0; (i) < (n); ++(i));
#define VVI(r, c, e) vvi((r), vi((c), (e)))

using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

int h, w, r, c;
vvi board, block;
vector<vii> blocks;

void make_blocks() {
  vii new_block = VII(max(r, c), max(r, c), 0);
  FOR(t, turn) {
    
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int c;
  cin >> c;

  while (c--) {
    cin >> h >> w >> r >> c;
    board = VVI(h, w, 0);
    block = VVI(r, c, 0);

    FOR(i, h) FOR(j, w)
      cin >> board[i][j];
    FOR(i, r) FOR(j, c)
      cin >> block[i][j];

    make_blocks();
  }

  return 0;
}