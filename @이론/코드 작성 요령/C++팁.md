## C++의 팁

알고리즘을 C++로 할 때 알면 좋은 팁이다.

### 구조체

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

#### 구조체란

하나 이상의 변수를 그룹 지어 새로운 자료형을 정의하는 것

헷갈리는 부분:

- Java, JS의 객체와 헷갈려하면 안됨.
  Java, JS의 객체는 참조타입이지만 C++의 구조체는 복합 타입이므로
  구조체를 paramter로 주입해도 메모리 주소가 아닌 값 자체를 복사해서 사용함
