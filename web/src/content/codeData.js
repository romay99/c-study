/**
 * C 학습 프로젝트의 소스 코드 (브라우저 표시용)
 * 원본: 프로젝트 루트의 src/, include/
 */

// 프로젝트 루트의 C 파일을 fetch로 불러옴
const BASE = '/code';

export const codePaths = {
  '01_basics': {
    header: `${BASE}/include/basics.h`,
    source: `${BASE}/01_basics/basics.c`,
  },
  '02_pointers': {
    header: `${BASE}/include/pointers.h`,
    source: `${BASE}/02_pointers/pointers.c`,
  },
  '03_struct': {
    header: `${BASE}/include/struct.h`,
    source: `${BASE}/03_struct/struct.c`,
  },
  '04_memory': {
    header: `${BASE}/include/memory.h`,
    source: `${BASE}/04_memory/memory.c`,
  },
};

/** 실행 가능한 C 예제 (main 포함, Piston API로 실행) */
export const runnableExamples = {
  basics_variables: `#include <stdio.h>
int main() {
    int count = 10;
    long big_num = 1000000L;
    float price = 19.99f;
    char letter = 'A';
    
    printf("int: %d, long: %ld\\n", count, big_num);
    printf("float: %.2f, char: %c (ASCII: %d)\\n", price, letter, letter);
    printf("sizeof(int)=%zu, sizeof(double)=%zu\\n", sizeof(int), sizeof(double));
    return 0;
}`,
  basics_operators: `#include <stdio.h>
int main() {
    int a = 10, b = 3;
    printf("a + b = %d\\n", a + b);
    printf("a / b = %d (정수 나눗셈)\\n", a / b);
    printf("a %% b = %d (나머지)\\n", a % b);
    return 0;
}`,
  basics_control: `#include <stdio.h>
int main() {
    int score = 85;
    if (score >= 90) printf("등급: A\\n");
    else if (score >= 80) printf("등급: B\\n");
    else printf("등급: C 이하\\n");
    
    for (int i = 0; i < 5; i++) printf("%d ", i);
    printf("\\n");
    return 0;
}`,
  basics_array: `#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\\n");
    return 0;
}`,
  basics_string: `#include <stdio.h>
#include <string.h>
int main() {
    char s[] = "Hello, C!";
    printf("%s (길이: %zu)\\n", s, strlen(s));
    return 0;
}`,
  pointer_basic: `#include <stdio.h>
int main() {
    int num = 42;
    int *ptr = &num;
    printf("num=%d, *ptr=%d\\n", num, *ptr);
    *ptr = 100;
    printf("수정 후 num=%d\\n", num);
    return 0;
}`,
  pointer_swap: `#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int x = 5, y = 10;
    printf("swap 전: x=%d y=%d\\n", x, y);
    swap(&x, &y);
    printf("swap 후: x=%d y=%d\\n", x, y);
    return 0;
}`,
  struct_basic: `#include <stdio.h>
#include <string.h>
typedef struct { char name[20]; int age; } Person;
int main() {
    Person p;
    strcpy(p.name, "홍길동");
    p.age = 25;
    printf("%s, %d세\\n", p.name, p.age);
    return 0;
}`,
  memory_malloc: `#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) arr[i] = i * 10;
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\\n");
    free(arr);
    return 0;
}`,
};
