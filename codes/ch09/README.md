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

두 번째 구현:  
이전에는 부피가 0보다 작아지는 경우 다음 부분문제를 해결하지 않았지만 음의 무한을 도입하여 부피의 크기를 검사하지 않고 다음 부분문제를 호출한다. 따라서 함수의 부피 v가 0보다 작은 경우에 음의 무한을 반환하도록 종료조건을 추가했다. 해당 종료조건 v < 0은 정상적으로 packing이 완성된 경우의 종료조건 i == N보다 선행되어야만 한다.  
실제 최적화가 이루어지는 해를 재구성하는 함수 reconstruct는 각 부분문제에서 최적화가 이루어지는 선택이 기록된 choice배열을 사용하지 않도록 구현을 변경했다. 이 문제의 경우 각 부분문제에서 선택 가능한 경우의 수가 2가지뿐이므로 다음에 해결해야할 두 부분문제의 정답을 비교하는 것만으로도 현재 부분문제에서 최적화가 이뤄지는 선택을 추적할 수 있다.  
음의 무한을 도입하여 구현이 더 간결해지기는 했지만, 짧은 시간내에 부분문제의 정의로부터 직관적으로 구현하기는 상대적으로 어려운 느낌. 이런식으로 구현하는 경우 종료조건 2가지가 존재하는데 각 종료조건을 검사하는 순서가 결과에 영향을 미치므로 논리적으로 더 정교한 검토가 필요하다.
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