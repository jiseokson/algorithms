#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR((i), 0, (n))

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;

int ans;
int h, w, r, c;
int block_size;
vvi board, block;
vector<vector<ii>> blocks;

void make_blocks() {
  blocks = vector<vector<ii>>(4);

  // 첫블럭 초기화
  REP(i, r) REP(j, c)
    if (block[i][j] == '#')
      blocks[0].push_back({i, j});

  // 회전 적용
  int cc = c;
  FOR(turn, 1, 4) {
    for (ii b: blocks[turn - 1])
      blocks[turn].push_back({cc - b.second - 1, b.first});
    sort(blocks[turn].begin(), blocks[turn].end());
    cc = r + c - cc;
  }

  // 첫번째 위치가 0이 되도록 조정
  REP(turn, 4) {
    while (blocks[turn][0].second != 0)
      for (ii &b: blocks[turn])
        b = {b.first, b.second - 1};
  }
}

bool put(int br, int bc, int turn, int ch) {
  for (ii b: blocks[turn]) {
    int nr = br + b.first;
    int nc = bc + b.second;
    if (!(0 <= nr && nr < h && 0 <= nc && nc < w) || board[nr][nc] == ch)
      return false;
  }

  for (ii b: blocks[turn]) {
    int nr = br + b.first;
    int nc = bc + b.second;
    board[nr][nc] = ch;
  }
  return true;
}

void max_block(int i, int count, int white_space) {
  ans = max(ans, count);
  if (count + white_space / block_size < ans)
    return;

  for (; i < h * w; ++i) {
    int br = i / w;
    int bc = i % w;
    if (board[br][bc] == '#')
      continue;
    REP(turn, 4) {
      if (!put(br, bc, turn, '#'))
        continue;
      max_block(i, count + 1, white_space - block_size);
      put(br, bc, turn, '.');
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    cin >> h >> w >> r >> c;
    board = vvi(h, vi(w));
    block = vvi(r, vi(c));

    int white_space = 0;
    REP(i, h) {
      string row;
      cin >> row;
      REP(j, w) {
        board[i][j] = row[j];
        if (board[i][j] == '.')
          ++white_space;
      }
    }

    block_size = 0;
    REP(i, r) {
      string row;
      cin >> row;
      REP(j, c) {
        block[i][j] = row[j];
        if (block[i][j] == '#')
          ++block_size;
      }
    }
    
    ans = 0;
    make_blocks();
    max_block(0, 0, white_space);

    cout << ans << '\n';
  }

  return 0;
}