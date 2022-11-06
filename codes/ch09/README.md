## 01. packing ##
첫 번째 구현
``` C++
int pack(int i, int v)
{
    if (i == N) return 0;
    int &ret = cache[i][v];
    if (ret != -1) return ret;
    ret = pack(i + 1, v);
    choice[i][v] = v;
    if (v - w[i] >= 0) {
        int temp = p[i] + pack(i + 1, v - w[i]);
        if (ret < temp) {
            ret = temp;
            choice[i][v] = v - w[i];
        }
    }
    return ret;
}

void reconstruct(vs &packs, int i, int v)
{
    if (i == N) return;
    if (choice[i][v] != v)
        packs.push_back(stuff[i]);
    reconstruct(packs, i + 1, choice[i][v]);
}
```
<br>

두 번째 구현
``` C++
int pack(int i, int v)
{
    if (v < 0) return neg_inf;
    if (i == N) return 0;
    int &ret = cache[i][v];
    if (ret != -1) return ret;
    return ret = max(pack(i + 1, v), p[i] + pack(i + 1, v - w[i]));
}

void reconstruct(vs &packs, int i, int v)
{
    if (i == N) return;
    if (pack(i, v) == pack(i + 1, v)) {
        reconstruct(packs, i + 1, v);
    } else {
        packs.push_back(stuff[i]);
        reconstruct(packs, i + 1, v - w[i]);
    }
}
```
이전에는 부피가 0보다 작아지는 경우 다음 부분문제를 해결하지 않았지만 음의 무한을 도입하여 부피의 크기를 검사하지 않고 다음 부분문제를 호출한다. 따라서 함수의 부피 v가 0보다 작은 경우에 음의 무한을 반환하도록 종료조건을 추가했다. 해당 종료조건 v < 0은 정상적으로 packing이 완성된 경우의 종료조건 i == N보다 선행되어야만 한다.  
실제 최적화가 이루어지는 해를 재구성하는 함수 reconstruct는 각 부분문제에서 최적화가 이루어지는 선택이 기록된 choice배열을 사용하지 않도록 구현을 변경했다. 이 문제의 경우 각 부분문제에서 선택 가능한 경우의 수가 2가지뿐이므로 다음에 해결해야할 두 부분문제의 정답을 비교하는 것만으로도 현재 부분문제에서 최적화가 이뤄지는 선택을 추적할 수 있다.  
음의 무한을 도입하여 구현이 더 간결해지기는 했지만, 짧은 시간내에 부분문제의 정의로부터 직관적으로 구현하기는 상대적으로 어려운 느낌. 이런식으로 구현하는 경우 종료조건 2가지가 존재하는데 각 종료조건을 검사하는 순서가 결과에 영향을 미치므로 논리적으로 더 정교한 검토가 필요하다.  
보통 비정상적인 종료 조건, 정상적인 종료 조건순으로 검사를 구현한 경우가 많은것 같다.
<br>

## 02. OCR ##
원문 S = [w1, w2, ... wn], 인식한 문장 S' = [w1', w2', ... wn']  
P(원문이 S | 인식한 문장이 S') = P(원문이 S이고 분류기로 S') / P(인식한 문장이 S')  
이때 인식한 문장이 S'일 확률은 고정이므로 P(원문이 S이고 분류기로 S')를 최대화하는 문제로 생각하자.  
P(원문이 S이고 분류기로 S') = P(원문이 w1이고 인식결과가 w1') * ... * P(원문이 wn이고 인식결과가 wn')  
```C++
double max_prob(int prev_wi, int i) // 이전 단어가 prev_wi일때 확률이 최대화되는 i번째 단어 결정
{
    if (i == n) return 1.0;
    double& ret = cache[prev_wi][i];
    if (ret != -1) return ret;

    for (int cur_wi = 1; cur_wi <= wc; ++cur_wi) {
        double temp = T[prev_wi][cur_wi] * M[cur_wi][clf[i]] * max_prob(cur_wi, i + 1);
        if (ret < temp) {
            choice[prev_wi][i] = cur_wi;
            ret = temp;
        }
    }
    return ret;
}
```
<br>

## 순서대로 생성하기, k번째 답 생성하기 ##
'-'을 n개, 'o'를 m개 가지는 모스부호를 사전식 순서대로 모두 생성하는 완전탐색 알고리즘을 구현하자.
```C++
void search(string res, int n, int m)
{
    if (n == 0 && m == 0) {
        cout << res << endl;
        return;
    }
    if (n > 0) search(res + '-', n - 1, m);
    if (m > 0) search(res + 'o', n, m - 1);
```
n또는 m이 0이면 다음 함수를 호출하지 않도록 구현했다. 이를 검사하지 않고 일단 다음 함수를 호출한 뒤, 호출된 즉시 전달받은 인자가 유효하지 않다면 비정상 종료하도록 구현할 수도 있다. (if n == 0 or m == 0 then return)
<br>

위 알고리즘을 변형해 k번째 모스부호를 생성하는 알고리즘을 작성하자.
```C++
int search(string res, int n, int m)
{
    if (n == 0 && m == 0) {
        if (k == 0) {
            cout << res << endl;
            return 1;
        }
        --k;
        return 0;
    }
    if (n > 0 && search(res + '-', n - 1, m)) return 1;
    if (m > 0 && search(res + 'o', n, m - 1)) return 1;
    return 0;
}
```
완성된 결과 중 사전순으로 처음오는 문자열을 0번째 문자열이라 하자. (완성된 결과 중 처음오는 문자열을 1번째라 가정하고 구현해도 좋지만, 몇가지 응용 상황에서 첫 번째 결과를 0번째라 가정하면 더 편리한 경우가 있어 일단은 받아들이자. 책의 구현도 이것을 따르기도 하고.) 모스부호를 하나씩 완성해가며 전역변수 k를 하나씩 줄여나간다. 만약 k == 0 이라면 현재 완성된 결과가 답이 되므로 1을 반환하고 더이상 탐색을 하지 않는다. 0을 반환하면 탐색을 계속 진행한다.
<br>

```C++
// bino: 이항계수

int search(string res, int n, int m)
{
    if (n == 0 && m == 0) {
        if (k == 0) {
            cout << res << endl;
            return 1;
        }
        --k;
        return 0;
    }
    if (bino[n + m][n] <= k) {
        // 현재 위치에서 생성할 수 있는 문자열에 순서를 붙힌다면 0, 1, ... (bino[n + m][n] - 1)
        // 따라서 index k가 이를 벗어난다면 더 이상 탐색하지 않고 넘어간다.
        k -= bino[n + m][n];
        return 0;
    }
    if (m > 0 && search(res + '-', n - 1, m)) return 1;
    if (n > 0 && search(res + 'o', n, m - 1)) return 1;
    return 0;
}
```
이전까지 생성된 문자열의 개수와 현재 위치에서 생성하게 될 문자열의 개수를 더한다 하더라도 k번째 문자열을 만나지 못한다면, 현재위치에서 답을 탐색할 이유가 없다. 따라서 실제로 문자열을 생성하지 않고, k를 현재위치에서 생성할 수 있는 문자열의 개수만큼 빼준 값으로 변경한다. 그리고 0을 반환하면 자신을 호출한 호출부에서 마저 탐색을 진행한다.(또는 그 호출부를 호출한 호출부, 또는 그 호출부를 호출한...)
<br>

```C++
string kth(int n, int m, int k)
{
    if (n == 0) return string(m, '-');
    if (m == 0) return string(n, 'o');
    if (k < bino[n + m - 1][n - 1])
        return "-" + kth(n - 1, m, k);
    return "o" + kth(n, m - 1, k - bino[n + m - 1][n - 1]);
}
```
현재 위치에서 가능한 선택으로부터 파생되는 결과물의 수에 따라 다음 탐색의 방향을 결정할 수도 있다. 현재 위치에서 '-'를 선택한다면 첫 문자로 '-'를 가지는 이후 모든 모스부호의 개수는 bino[n + m - 1][n - 1]개이다. index k가 이 수보다 작다면 정답을 생성하기 위해서는 현재 위치에서 '-'를 선택해야 한다. 만약 index k가 이 수보다 크거나 같다면 정답은 현재 위치에서 'o'를 선택했을때 index (k - bino[n + m - 1][n - 1])에 위치한다.
<br>

다른 문제로 k번째 답을 생성하는 연습을 더 해보자. 다음 문제를 생각해보자.
>a, e, i, o, u로만 구성된 길이 1 ~ 5의 모든 단어를 사전순으로 나열했을 때 k번째 단어를 반환하는 알고리즘을 작성하라.
<br>

사전순으로 모든 단어를 출력하는 완전탐색 알고리즘을 작성하자.
```C++
void search(string res, int len) // len: 더 첨가할 수 있는 문자의 개수
{
    cout << res << endl;
    if (len == 5) return;
    for (char c: {'A', 'E', 'I', 'O', 'U'})
        search(res + c, len - 1);
}

...

main()
{
    search("", 5); // 최대 길이 5, 빈 문자열은 0번째 문자열
}
```
<br>

이것을 변형해 index k번째 답만 출력하는 알고리즘을 작성하자. 이때 빈문자열을 index 0이라 가정했다.
```C++
int search(string res, int len) // len: 더 첨가할 수 있는 문자의 개수
{
    if (k == 0) {
        cout << res << endl;
        return 1;
    }
    --k;
    if (len == 5) return 0;
    for (char c: {'A', 'E', 'I', 'O', 'U'})
        if (search(res + c, len - 1))
            return 1;
    return 0;
}

...

main()
{
    search("", 5); // 문자열의 최대 길이 5, 빈 문자열은 0번째 문자열
}
```
이 구현은 문자열이 완성된 경우에 k가 하나씩만 넘어간다. 효율성을 높이기 위해 문자열을 생성하기 전에 앞으로 생성하게 될 문자열 중 원하는 문자열이 없으면 넘어가도록 구현을 바꿔보자.
<br>

```C++
int search(string res, int len) // len: 더 첨가할 수 있는 문자의 개수
{
    if (k == 0) {
        cout << res << endl;
        return 1;
    }
    --k;
    for (char c: {'A', 'E', 'I', 'O', 'U'}) {
        if (k < cnt[n - 1]) {
            search(res + c, len - 1);
            return 1;
        }
        k -= cnt[len - 1];
    }
}

...

main()
{
    for (i <= max_len) cnt[i] = cnt[i] * 5 + 1;
    // cnt[i] = 5^i + ... 5^0
}
```
cnt[i]: i개의 문자를 더 첨가할 때 생성할 수 있는 문자열의 개수  
현재 위치에서 문자 하나를 첨가할때 이후로 생성될수 있는 문자열의 개수는 cnt[n - 1]이다.
<br>

```C++
string kth(int n, int k)
{
    if (k == 0) return "";
    --k;
    return "AEIOU"[k / cnt[n - 1]] + kth(n - 1, k % cnt[n - 1]);
}
```
<br>

번외로 길이가 5인 문자열을 사전순으로 배열했을 때 k번째 문자열 반환하는 함수.
```C++
string kth2(int n, int k) // 길이 5인 단어들 중 사전식 순서로 k번재 단어
{
    if (n == 0) return "";
    return "AEIOU"[k / power(5, n - 1)] + kth2(n - 1, k % power(5, n - 1));
}
```