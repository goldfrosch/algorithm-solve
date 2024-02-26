# C++의 팁

알고리즘을 C++로 할 때 알면 좋은 팁이다.

## 구조체

구조체는 원시타입 처럼 취급되어 함수에서 parameter로 받아 직접 값을 제어하려 하면 동작하지 않는다.

ex.

```
struct point {
    int x,y;
}

void func1(int a) {
    a = 5;
}

void func2(int arr[]) {
    arr[0] = 10;
}

void func3(point a) {
    a.x = 5;
}

int main(void) {
    int test1 = 0;
    int testArray2[3] = {1,2,3};
    point test3 = {0,0}

    func1(test1);
    func2(testArray2);
    func3(test3);

    cout << test1; // 0 출력
    cout << testArray2[0]; // 10 출력
    cout << test3; // 0 출력
}
```

### 구조체란

하나 이상의 변수를 그룹 지어 새로운 자료형을 정의하는 것

헷갈리는 부분:

- Java, JS의 객체와 헷갈려하면 안됨.
  Java, JS의 객체는 참조타입이지만 C++의 구조체는 복합 타입이므로
  구조체를 paramter로 주입해도 메모리 주소가 아닌 값 자체를 복사해서 사용함

## 포인터와 참조자

포인터: 메모리 주소를 저장하는 변수. 해당 주소값을 이용해 변수의 저장 값을 직접 접근이 가능하다.
참조자: 이미 만들어진 변수에 대한 별명을 만들 때 사용함. 해당 별명을 이용해 변수에 직접 접근이 가능함.

```
// 메모리 주소가 아닌 값 자체를 복사해서 가져오기 때문에 parameter 변수에 영향 없음
void swapTest1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 메모리 주소를 가져와 해당 메모리 주소의 값 자체를 변환하기 때문에 parameter 변수에 영향이 있음.
void swapTest2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 변수 자체를 가져와도 참조 타입처럼 이용하기 때문에 parameter 변수에 영향이 있음.
void swapTest3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

```

차이점:

1. 포인터는 NULL을 가질 수 있지만 참조자는 불가능하다.
2. 포인터는 나중에 다른 주소값으로도 변경이 가능하지만 참조자는 한번 선언되면 그 이후에 다른 변수 값으로 변경이 불가능하다. (JS의 let과 const 같은 느낌)
3. 포인터는 간접 참조 연산자인 (\*)를 사용해서 주소 or 값을 가져오게 할 수 있지만 참조자라는 것은 일반 변수처럼 사용되어 추가 연산자를 필요로 하지 않는다

## STL

C++ STandard Library라는 뜻으로 C++에서 제공해서는 표준 라이브러리다. (자바의 java.util과 비슷한 개념)
STL은 크게 컨테이너, 반복자, 알고리즘 3개로 구성된다.

사용을 위해서 네임스페이스를 받아서 사용하고 필요한 것만 includes해온다.

```
#include <vector>
#include <iterator>

using namespace std;
```

### 컨테이너

자료를 저장하는 클래스 집합체

예시

- list/forward_list: 연결 리스트로 검색, 접근은 느리나 위치만 알 때 빠른 접근이 가능함. (forward가 앞에 붙으면 후진 검색은 불가능함)
- set/multiset: 삽입하는 시점에서 부터 정렬해주는 자료구조(자바 Set과는 조금 다른 느낌), multiset의 경우는 key가 중복이여도 문제가 없음
- map/multimap: key:value형태를 가진 객체 자료구조, multimap은 key가 중복이여도 문제가 없음
- unordered*set/unordered_map/unordered_multiset/unordered_multimap: 위의 set, map 자료구조는 트리 구조로 이루어져 있어 자동으로 정렬된다면, unordered*이 붙으면 hash 자료구조로 구현되어있어 정렬되지 않음

- stack: 후입선출 배열 구조
- queue: 선입선출 배열 구조
- priority queue: queue 자료구조에서 높은 우선순위를 가진 요소가 상위로 올라오는 자료 구조
- deque: 맨 앞, 맨 뒤에서 O(1)으로 삽입, 삭제가 가능한 자료구조, 메모리 상에서 변할 때 마다 저장은 안하기에 반복자에서 유효하게 동작을 안할 수 있음.

- vector: 삽입, 삭제, 참조가 O(1)로 돌아가는 배열 구조, 삽입, 삭제가 끝이 아니라면 O(n)이 걸리는 자료 구조다.

#### Vector의 주요 특징

Vector는 함수 인자로 Vector를 참조시키려 하면 해당 값이 복사본으로 이동해 (즉 복합 타입(ex. 구조체)과 동일하게 동작한다.)실제 원본에는 영향을 주지 않는다.

외부 함수를 통해 parameter에 주입되는 vector값을 변경하고 싶으면 참조자 타입으로 해당 값을 받아 사용하면 메모리 주소의 값 자체를 변경하기 때문에 변경되게 된다.

#### pair

두개의 자료형을 묶어서 가지고 다닐 수 있는 자료구조로 make_pair로 값을 넣어줄 수 도 있지만, C++ 11부터는 중괄호로 묶어 쉽게 사용이 가능하다.

ex.

```
pair<int, int> exam1 = {4, 6};
pair<int, int> exam2 = make_pair(10, 12);

cout << exam1.first << " " << exam1.second; // 4 6
```

### 알고리즘

정렬, 삭제, 검색 등 연산 활동 중에 많이 쓰이는 함수를 템플릿 화한 함수들

예시

- sort: 정렬 함수
- find: 검색 함수
- transform: 변경 함수
- for_each: 반복문 함수
- generate: 생성 함수
- binary_search: 이진 탐색 함수

### 반복자

반복자는 컨테이너 원소를 순회하는 방법을 추상화하는 객체를 의미함
대표적으로는 input, output 두 종류로 나뉘어 있다.

```
int main()
{
    vector<int> test = {1,2,3,4,5};

    // 포인터를 사용해서 iterator 메모리 주소 값에서 값을 빼서 사용하는 방식
    for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it) {
        std::cout << *it << " ";
    }

    // C++ 11버전 이상 부터 사용 가능한 간략화된 iterator 사용 법
    // 참조자로 지정했기 때문에 일반 변수처럼 사용하면 됨
    for (const auto &value : test) {
        std::cout << value << " ";
    }

    return 0;
}
```

## 표준 입출력

### 입출력 방식 cin, cout

C에서는 scanf, printf였다면 C++에서는 cin, cout이다.

scanf와 printf의 단점은 C++의 string을 처리할 수 없기 때문에 C++로 알고리즘 or 개발을 한다면 cin, cout을 쓰는게 현명하다고 할 수 있다.

cin과 scanf에는 동일한 이슈가 존재한다. (공백 포함한 문자열 차리가 까다로움)

해결 방법에는 3가지가 존재한다. (3번이 가장 좋은 방안)

1. scanf에서 줄바꿈 나오기 전까지만 입력받는 것을 명시: 코드 외우기 힘듦
2. gets 함수사용: 보안 이슈로 C++ 14이후부터 사라진 메소드
3. getline 사용: 함수 인자의 타입이 C++의 string이여야 한다.

```
string s;
getline(cin, s);
```

### 주의사항

endl 사용하지 말 것. 개행문자 출력 후 출력 버퍼를 비우라는 명령인데 중간 중간 버퍼를 지우는 것이 좋은 방법은 아님. 차라리 \n 개행문자를 사용할 것

## 가장 중요한 팁?

알고리즘과 현업 개발 방식은 다르게 생각해야한다.

알고리즘 문제를 풀이할 때 코드가 더러운 것에 대해 고려하지 말고 최대한 시간, 공간 복잡도를 고려하며 짜는 것이 중요하다.
