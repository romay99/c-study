# C 언어 학습 가이드 – 추천 순서

Java Spring 개발자를 위한 **학습 순서**와 **어떤 파일을 어떻게 볼지** 정리한 가이드입니다.

---

## ⚠️ C를 아예 모르는 경우 (Java만 한 경우)

**`#include`, `#define`, `#ifndef` 같은 게 뭔지 모르겠다**면,  
먼저 **[C_BASICS.md](C_BASICS.md)** 를 읽어 보세요.  
`#include` / `#define` / `#ifndef` / `.h`와 `.c` / `void` 등이 **한글 주석으로** 설명되어 있고, Java와 비교 표도 있습니다.  
그다음에 이 학습 순서대로 진행하면 됩니다.

---

## 학습 순서 한눈에 보기

| 순서 | 모듈 폴더 | 학습 주제 | 예상 시간 |
|:----:|-----------|-----------|----------|
| **1** | `01_basics` | 변수, 연산자, 제어문, 배열, 문자열 | 1~2일 |
| **2** | `02_pointers` | 포인터 (C의 핵심) | 2~3일 |
| **3** | `03_struct` | 구조체 (Java 클래스와 비교) | 1일 |
| **4** | `04_memory` | malloc/free, 동적 메모리 관리 | 1~2일 |

---

## 1단계: 기본 문법 (`01_basics`)

**목표:** C의 기본 문법과 Java와의 차이를 익힌다.

**볼 파일**
- `include/basics.h` – 함수 목록과 주석
- `src/01_basics/basics.c` – 전체 코드 (주석 순서대로 읽기)

**읽는 순서 (basics.c 안에서)**
1. 변수와 데이터 타입 (`learn_variables_and_types`)
2. 연산자 (`learn_operators`)
3. 제어문 (`learn_control_flow`)
4. 배열 (`learn_arrays`)
5. 문자열 (`learn_strings`)

**실습**
- `build.bat` 또는 `make`로 빌드 후 실행 → 메뉴에서 **1번(기본 문법)** 선택

**체크리스트**
- [ ] `int`, `float`, `char`, `sizeof` 이해
- [ ] `for`/`while`, `if`/`switch` 사용 가능
- [ ] 배열 선언·접근, `sizeof`로 길이 구하기
- [ ] `char[]`, `strcpy`, `strcmp`, `strlen` 사용

---

## 2단계: 포인터 (`02_pointers`)

**목표:** 포인터(`*`, `&`)와 주소 개념을 확실히 이해한다.

**볼 파일**
- `include/pointers.h`
- `src/02_pointers/pointers.c`

**읽는 순서 (pointers.c 안에서)**
1. 포인터 기본 (`learn_pointer_basics`) – `&`, `*`, `NULL`
2. 포인터와 배열 (`learn_pointer_and_array`)
3. 포인터를 인자로 (`learn_pointer_as_argument`) – Call by reference
4. 이중 포인터 (`learn_double_pointer`)
5. 함수 포인터 (`learn_function_pointer`)

**실습**
- 실행 후 메뉴 **2번(포인터)** 선택  
- 포인터가 헷갈리면 1번만 다시 보고, 2번을 여러 번 실행해 보기

**체크리스트**
- [ ] `ptr = &변수`, `*ptr`으로 값 읽기/쓰기
- [ ] 배열 이름 = 첫 요소 주소, `*(arr+i)` 와 `arr[i]` 관계
- [ ] 함수에 `&변수` 넘겨서 값 변경하는 패턴 이해
- [ ] `int **` 이중 포인터가 필요한 이유
- [ ] 함수 포인터 선언·호출

---

## 3단계: 구조체 (`03_struct`)

**목표:** struct로 데이터를 묶고, Java 클래스와 비교해서 이해한다.

**볼 파일**
- `include/struct.h` – `Person` 구조체 정의
- `src/03_struct/struct.c`

**읽는 순서 (struct.c 안에서)**
1. 구조체 기본 (`learn_struct_basics`) – 선언, 초기화, `.` 접근
2. 구조체 포인터 (`learn_struct_pointer`) – `->` 연산자
3. 구조체를 함수 인자로 (`learn_struct_as_argument`) – `const Person*`
4. 구조체 배열 (`learn_struct_array`)

**실습**
- 메뉴 **3번(구조체)** 선택

**체크리스트**
- [ ] `typedef struct { ... } 이름;` 으로 타입 정의
- [ ] `구조체.멤버`, `포인터->멤버` 구분
- [ ] 구조체를 함수에 넘길 때 값 vs 포인터 차이

---

## 4단계: 메모리 관리 (`04_memory`)

**목표:** `malloc`/`free`로 동적 메모리를 안전하게 다룬다.

**볼 파일**
- `include/memory.h`
- `src/04_memory/memory.c`

**읽는 순서 (memory.c 안에서)**
1. 동적 할당 (`learn_dynamic_allocation`) – `malloc`, `calloc`, `realloc`
2. 메모리 해제 (`learn_memory_free`) – `free`, NULL 대입
3. 동적 문자열 (`learn_dynamic_string`)
4. 메모리 안전 (`learn_memory_safety`) – 누수, use-after-free 방지

**실습**
- 메뉴 **4번(메모리 관리)** 선택

**체크리스트**
- [ ] `malloc` 후 반드시 `free`, `free` 후 포인터 `NULL` 설정
- [ ] `malloc` 실패 시 `NULL` 체크
- [ ] 문자열 동적 할당 시 `strlen + 1` 크기 할당

---

## 프로젝트 구조 (번호 기준)

```
c-study/
├── LEARNING_GUIDE.md     ← 지금 보고 있는 학습 가이드
├── README.md
├── Makefile
├── build.bat
├── include/
│   ├── basics.h          ← 1단계
│   ├── pointers.h        ← 2단계
│   ├── struct.h          ← 3단계
│   └── memory.h          ← 4단계
└── src/
    ├── main.c            ← 진입점 (메뉴)
    ├── 01_basics/        ← 1단계: 기본 문법
    │   └── basics.c
    ├── 02_pointers/      ← 2단계: 포인터
    │   └── pointers.c
    ├── 03_struct/        ← 3단계: 구조체
    │   └── struct.c
    └── 04_memory/        ← 4단계: 메모리 관리
        └── memory.c
```

---

## 팁

- **한 번에 다 보지 말고** 1단계 → 2단계 → 3단계 → 4단계 순서로 진행하는 것을 권장합니다.
- **포인터(2단계)** 가 가장 중요하고 난이도도 높으니, 여기서 막히면 1단계를 다시 보고 2단계 예제를 여러 번 실행해 보세요.
- 각 `.c` 파일 상단과 섹션마다 **Java와의 차이**가 주석으로 적혀 있으니, Java 경험과 연결해서 읽으면 이해가 빠릅니다.

---

화이팅.
