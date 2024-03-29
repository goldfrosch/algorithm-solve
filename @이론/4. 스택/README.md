# 스택

## 스택이란?

### 정의

한쪽 끝에서만 원소를 넣거나 뺄 수 있는 자료구조를 의미함. 쉽게 일상에서 보기 좋은 구조라고 하면 프링글스 통을 생각하면 편함
프링글스 통 처럼 구조적으로 먼저 들어간 원소가 더 나중에 나오게 되는데 이런 구조를 선입후출(First In Last Out)구조라고 부르기도 한다.
큐나 덱도 스텍처럼 특정 위치에서만 원소를 넣거나 뺄 수 있는 제한이 걸려있어 이 3개를 Restrict Structure라고 부른다.

### 성질

1. 원소의 추가 및 제거가 O(1)이다.
2. 제일 상단의 원소 확인이 O(1)이다.
3. 제일 상단이 아닌 나머지 원소들의 확인, 변경이 불가능하다.

스택이라는 자료 구조는 상단만 보고, 사용하기 위한 구조로 되어있어 쌓아만 두고 최상단만 바라보게 하는 것이기에 다른 원소 위치를 확인할 이유도, 필요도 없는 자료구조라고 할 수 있다.
