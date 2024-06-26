# 정렬

개발 중 흔히 .sort()를 이용해 정렬을 하곤 하지만 알고리즘 문제를 푸는 경우에는 단순히 .sort()를 쓰는 것 만이 아니라 여러 종류의 정렬을 직접 구현하면서 사용하게 된다. 실제 [위키피디아 문서](https://ko.wikipedia.org/wiki/%EC%A0%95%EB%A0%AC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)를 확인해보면 수많은 정렬 알고리즘이 있지만 실제 알고리즘 문제에서 활용하는 것은 대표적으로 몇 종류가 있다.

## 기초 정렬

### 버블 정렬 (Bubble Sort)

인접한 두 원소를 보면서 앞의 원소가 뒤의 원소보다 큰 경우에 자리를 바꾸는 작업을 반복하는 정렬 방식이다.

```
int n = 5;
int arr[n] = {-2, 2, 4, 6, 13}

for (int i = 0; i < n; i++) {
    // 비교할 대상은 j와 j+1이기에 -1을 빼고, i가 증가할 수록 뒷자리들의 정렬은 끝났으니 i를 또 빼서 2중 반복문을 처리한다.
    for (int j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }
}
```

버블 정렬의 경우 기본적인 알고리즘이지만 그냥 이런게 있다 정도로 알고 있으면 되고 시간 복잡도는 O(N^2)기에 그렇게 효율적인 방법은 아니다.

### 합병 정렬 (Merge Sort)

합병 정렬은 재귀적으로 수열을 나눠 정렬한 뒤 합치는 정렬법이다. 재귀를 사용함에도 시간 복잡도는 O(NlogN)이다.

합병 정렬을 하기 위해서는 길이가 N, M인 두 정렬된 리스트를 합쳐서 N + M 정렬된 리스트를 만드는 방법부터 알아야한다.

가장 간단하게 처리한다면, [...N, ...M] (JS 기준)으로 해서 합치는 것이지만 이 경우의 시간 복잡도는 O((N + M)^2)로 더욱 복잡한 시간복잡도를 가지게 된다.

이미 두 리스트가 정렬되어있다면 일렬로 넣고 다시 정렬하는 방식이 아닌 이미 정렬된 기준으로 각 앞자리씩을 비교해 새로운 정렬을 만드는 것이 효율적이다.

```
int n[5] = {-9, 1, 6, 8, 12};
int m[4] = {-7, 7, 13, 15};
```

위의 두개의 정렬된 배열을 하나로 합치는 과정을 겪는다고 가정하면 우선 맨 앞의 -9와 -7을 비교하고, 더 작은 수를 새로운 배열에 넣고 기존 배열에서 제거하는 것을 이어가면 된다.

```
/**
 1. (-9 < -7)
 int n[5] = {1, 6, 8, 12};
 int m[4] = {-7, 7, 13, 15};

*/ int k[9] = {-9};

/**
 2. (-7 < 1)
 int n[5] = {1, 6, 8, 12};
 int m[4] = {7, 13, 15};

 int k[9] = {-9, -7};
*/
.
.
.
```

이 공식을 반복하게 된다면 굳이 새로 정렬할 필요 없이 빠르게 정렬이 가능해진다.

하지만 여기까지만 보면 재귀는 존재하지 않지만 실제로 재귀를 활용하는 경우는 위의 문제 중 두개의 정렬된 배열이 정렬되지 않은 경우를 의미한다.

merge sort는 이진 트리 처럼 절반씩 쪼개서 검증한다고 생각하면 편하다.

```
1. [1, -1, 3, 5, -4, 8, 2, -9];

2. [1, -1, 3, 5], [-4, 8, 2, -9];

3. [1, -1], [3, 5], [-4, 8], [2, -9];

4. [-1, 1], [3, 5], [-4, 8], [-9, 2];

5. [-1, 1, 3, 5], [-9, -4, 2, 8];

6. [-9, -4, -1, 1, 2, 3, 5, 8];
```

이런식으로 최소한으로 쪼개서 2개씩 나눠지고 나면 정렬 후 합쳐서 merge sort를 반복하는 방식을 반복해 정렬의 최종 값을 보여주는 방식이 된다.

이 경우는 두개 씩 쪼개서 정렬을 하니 생각보다 많이 걸린다고 생각할 수 있지만 실제로 쪼개는 부분은 큰 연산을 하는 것은 아니다.

분리는 실제로 시간 복잡도에 영향을 주지는 않으니 정렬되기 전까지 보게된다면 1 ~ 3번까지 후 4번 결과가 나올 때 까지 각 줄 별로 1(둘로 쪼개기), 2(를 또 둘로 쪼개기), 4(를 정렬하기)... 2^k번 호출되게 된다. 즉 2N - 1만큼 발생하기 때문에 O(N)만큼 발생하게 된다. 분할 자체의 시간 복잡도는 O(N)이라고 할 수 있다.

그리고 각 분할된 것을 합치는 과정은 위 처럼 O(NlogN)이 되는데 4 ~ 6번까지 보면 4번에서 5번의 결과가 나오려면 N/4 만큼 쪼개진 배열이 4번 동작을 해야하기에 N/4 \* 4가 되어 단순히 N번만큼 동작한다. 그리고 분할하는 과정에서 점점 줄어들기 때문에 최종적으로는 O(NlogN)만큼 시간 복잡도가 소요되고 O(N) < O(NlogN)이기에 머지 소트는 실제로는 O(NlogN)만큼의 시간이 소요된다고 할 수 있다.

### 빠른 정렬 (Quick Sort)

이름 그대로 거의 모든 정렬 알고리즘 보다 빨라서 붙은 이름이고, 대부분의 라이브러리들의 정렬이 이 quick sort 방식을 사용한다. 다만 코딩 테스트에서 STL을 못쓰고 직접 정렬 로직을 구현해야 한다면 사용하지 않는 것이 권장된다. (merge sort or heap sort 사용 권장)

Quick Sort 또한 재귀적으로 구현되는 정렬 동작이다. 이 정렬은 매 단계마다 pivot이라고 이름 붙은 원소 하나를 제자리로 보내는 작업을 반복하는 방식을 택하는데 그 pivot의 경우는 위치를 마음대로 잡고 사용해도 무방하나 편의상 맨 앞의 원소를 pivot으로 잡고 정렬하고 밑의 예시를 정렬한다.

```
// AS-IS
["6", -8, 1, 12, 8, 3, 7, -7]

// TO-BE
[3, -8, 1, -7, "6", 8, 7, 2]

// Code
int N;
int arr[] = {6, -8, 1, 12, 8, 3, 7, -7};

std::cin >> N;

for (int i = 0; i < 8; i++) {
        if (i != N) {
            if (arr[i] < arr[N]) {
                tempN++;
            }
        }
    }

    auto tempI = arr[N];
    arr[N] = arr[tempN];
    arr[tempN] = tempI;

    for (int i : arr) std::cout << i << " ";
```

위의 예시는 반복문 하나만써서 6보다 작으면 1칸씩 뒤로 밀 수 있도록 int 값을 저장하고 반복문이 끝날 때 자리만 스왑시켜주면 되는 간단한 로직이다.

퀵 소트의 장점 중 하나는 추가적인 공간을 필요로 하지 않는다라는 것이다. 그 배열 안에서만 자리 바꿈으로 동작이 처리가 되기 때문에 cache hit rate가 높아 속도가 빨라진다는 장점도 따라오게 되는 것이다. 그래서 추가적인 공간을 사용하지 않고 pivot을 제자리로 보내는 방법을 인지하는 것이 중요한데, 이렇게 추가적인 공간을 활용하지 않는 정렬을 In-Place sort라고도 부르기도 한다.

#### 예제

물론 위의 예제의 경우도 별도의 공간을 활용하지 않았다. 내부에서 스와핑하는 형태로 처리했기 때문에 문제가 없지만, 더 빠르게 해결하기 위한 Quick Sort 의 예제를 더 알아보자

추가적인 공간을 활용하지 않는 방법 중 하나는 원소의 위치를 잘 바꿔주면 되는 것이다. 배열의 양 쪽 끝에 포인터를 2개 두고 적절하게 스와핑하는 방식을 사용해 quick sort 구현이 가능하다.

L, R이라는 포인터를 2개 두고 L은 pivot(배열의 0번째 값으로 지정)보다 큰 값이 나올 때 까지 오른쪽으로 이동하고 R은 그 반대로 이동시켜 본다.

```
// 가장 왼쪽의 6은 12보다 작으니 12까지 오른쪽으로 이동
L - L - L - L
[6, -8, 1, 12, 8, 3, 7, -7]
                         R
// 가장 오른쪽의 -7은 7보다 작으니 계속 대기
```

위의 상황에서는 L의 12가 -7보다 앞에 있는 것이 말이 안되니 2개의 위치를 스왑해준다.

```
            L - L
[6, -8, 1, -7, 8, 3, 7, 12]
                  R - R -R
```

또 각각 이동하다보면 둘이 만나는 구간에서 L의 8과 R의 3이 서로의 위치가 말이 안되니 서로의 위치를 바꿔준다.

```
[6, -8, 1, -7, 3, 8, 7, 12]
```

다시 L을 옮기다 보면 8에서 멈추고 r은 옮겨지지 않고 바로 멈춰 또 두개의 위치를 바꿀 것이다. 이런 방식을 반복해서 정렬해주다보면 pivot과 R을 스왑하면서 알고리즘이 종료된다.
물론 완벽하게 정렬이 되진 않지만 모든 순간의 L의 왼쪽에는 pivot보다 작거나 같은 원소들만 있고, R의 오른쪽에는 pivot보다는 긑 원소들만 있는 것이 핵심이다.

##### 코드

```
int arr[] = {6, -8, 1, 12, 8, 3, 7, -7};
int pivot = arr[0];

int L = 1, R = 7;

while (true) {
    while(L <= R && arr[L] <= pivot) L++;
    while(L <= R && arr[R] > pivot) R--;
    if (L > R) break;
    swap(arr[L], arr[R]);
}

swap(arr[0], arr[R]);

for (const auto i: arr) std::cout << i << " ";

```

위 코드는 2중 while문이라고는 하지만 결국은 배열 크기만큼 계속 반복되고, 동시에 L과 R은 계속 가까워 지기 때문에 시간 복잡도는 O(N)만큼 소요된다.

#### 본제

위의 예제는 한번만 실행한 quick sort로 모든 것을 정렬하지 않았다. 이제 여기서 재귀를 껴 넣어서 quick sort를 완성시키면 된다.

```
int arr[] = {6, -8, 1, 12, 8, 3, 7, -7};

void quickSort(int start, int end) {
    if (end <= start + 1) return;
    int pivot = arr[start];
    auto L = start + 1;
    auto R = end - 1;
    while (true) {
        while(L <= R && arr[L] <= pivot) L++;
        while(L <= R && arr[R] > pivot) R--;
        if (L > R) break;
        swap(arr[L], arr[R]);
    }
    swap(arr[start], arr[R]);
    quickSort(start, R);
    quickSort(R + 1, end);
}

int main() {
    quickSort(0, 8);

    for (const auto i: arr) std::cout << i << " ";

    return 0;
}

```

예제의 코드에서 재귀 형태로 돌려버린 코드가 된다. 재귀를 통해 start와 오른쪽 포인터, 오른쪽 포인터의 다음과 끝 자리 식으로 두 갈래로 나뉘어 계속해서 검증하는 과정을 거쳐 해결해준다.

오른쪽 포인터의 경우 위의 함수를 통해서 점점 앞으로 가 본래의 위치를 찾은 상태에서 재귀가 호출되기 때문에 중간 중간 쪼개고, 위치를 찾은 것들에 대해 계속해서 잘게 쪼개면서 재귀를 통해 위치를 정렬해준다. 첫번째 줄은 무조건 N 만큼의 검증이 필요하기에 시간 복잡도는 O(N)이지만, 2번째 부터는 중간씩 쪼개고 이미 찾아진 pivot은 제거해줘야 하기 때문에 N - 1만큼의 검증을 해줘야한다. 이렇게 잘게 쪼개면 쪼갤수록 O(N)만큼이 계속 필요하다고 느낄 수 있으나 merge sort처럼 pivot이 중앙을 계속해서 지켜주게 된다면 생각보다 많은 pivot이 제자리를 찾아 계산해야 할 pivot의 수가 줄어들어 O(NlogN)만큼의 실행으로도 해결이 가능하다.

물론 pivot이 계속 중앙을 차지하지 않고 끝을 차지하는 최악의 경우는 O(N)이 N만큼의 작업 공수가 들어 O(N^2)까지 시간복잡도가 늘어날 수 있다.

merge sort가 quick sort보다 느린 것은 맞지만 어차피 O(NlogN)의 시간복잡도로 해결이 되니 굳이 위험 부담이 있는 quick sort보다는 merge sort를 쓰는 것이 차라리 나을 수도 있다.

### Counting Sort

가장 쉽게 수열을 정리하는 알고리즘으로 공간 복잡도를 최대한 활용해서 수열을 정렬하는 알고리즘이다.

```
int a[] = {1,5,4,2,3,1,4,3};
int temp[100];

for (int i : a) temp[i]++;

for (int i = 0; i < 100; i++) {
    if (temp[i] != 0) {
        while(temp[i]--) {
            std::cout << i << " ";
        }
    }
}

return 0;

```

매우 간단하게 temp[int] 배열안에 특정 숫자가 몇개가 있는지 저장하고 배열 반복문으로 특정 숫자를 갯수만큼 그대로 호출하면 되는 방식이다. 다만 이 알고리즘은 정말 쉽고 편하지만 만능은 아니다. 각 수의 횟수를 저장하기에 10억이 넘는 숫자를 정렬한다고 하면 그만큼의 배열이 필요해 굉장하게 큰 배열 공간이 필요해진다. 그렇기 때문에 어느정도 한정된 숫자에서만 활용이 가능하며 int의 max까지 가능은 하나 가장 효율적인것은 수의 범위가 대략 10,000,000 아래일 때 사용 가능하다. (음수일 때도 사용이 어렵다. - 어거지로 사용은 가능하지만)

### Radix Sort

자릿수를 이용해 정렬을 수행하는 알고리즘으로 카운팅 소트를 응용한 알고리즘이기도 하다.

#### 예제

10개의 숫자를 정렬한다고 가정한다

```
// 숫자 앞의 0은 편의상 넣은 것이고 실제로는 들어가지 않는 값이다
[012, 421, 046, 674, 103, 502, 007, 100, 021, 545];

```

1. 마지막 자리 기준으로 공간 배열 안에 넣기

   | 배열 숫자 | 값 목록  |
   | --------- | -------- |
   | 0         | 100      |
   | 1         | 421, 021 |
   | 2         | 012, 502 |
   | 3         | 103      |
   | 4         | 674      |
   | 5         | 545      |
   | 6         | 046      |
   | 7         | 007      |
   | 8         |          |
   | 9         |          |

2. 1번의 배열을 다시 10의 자릿 수 기준으로 재정렬하기
   | 배열 숫자 | 값 목록 |
   | --------- | -------- |
   | 0 | 100, 502, 103, 007 |
   | 1 | 012 |
   | 2 | 421, 021 |
   | 3 | |
   | 4 | 545, 046 |
   | 5 | |
   | 6 | |
   | 7 | 674 |
   | 8 | |
   | 9 | |

3. 2번의 상태에서 100의 자릿 수를 기준으로 재정렬
   | 배열 숫자 | 값 목록 |
   | --------- | -------- |
   | 0 | 007, 012, 021, 046 |
   | 1 | 100, 103 |
   | 2 | |
   | 3 | |
   | 4 | 421 |
   | 5 | 502, 545 |
   | 6 | 674 |
   | 7 | |
   | 8 | |
   | 9 | |

계속해서 아래 자릿수부터 차례차례 정렬해 나가면 결국은 정렬이 완료되는 것이 목표다.

## STL Sort

코딩 테스트의 경우 이런 정렬을 직접 구현하는 것은 위의 4개 중에 무엇도 쓸 것이 아닌 STL에서 제공해주는 기본 sort를 써주는 것이 가장 좋다. (직접 짜고 있는 경우 자체가 호구인 경우가...)

```
int a[5] = {1, 4, 5, 2, 7};
sort(a, a + 5);

vector<int> b = {1, 4, 5, 2, 7};
sort(b.begin(), b.end());
```

위 처럼 C++에서 제공해주는 기본 sort문을 쓰는 것이 가장 효율적이다.

STL:sort의 경우 특징 중 하나는 3번째 인자에는 정렬 기준을 넣는 것도 가능한데, boolean 값으로 return을 해줘야하고 우선 순위가 높은 경우에 true, 아닐 때 false를 반환하는 식으로 해결하면 된다.
