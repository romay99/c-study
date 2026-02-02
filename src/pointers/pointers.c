/**
 * @file pointers.c
 * @brief C 언어 포인터 학습 구현
 * 
 * [Java vs C]
 * Java: 참조(reference) - 객체를 가리키지만 주소 연산 불가
 * C: 포인터(pointer) - 메모리 주소 자체를 다룸, *와 & 연산자 사용
 * 
 * 포인터는 C의 핵심이자 Java 개발자가 가장 헷갈리는 부분입니다!
 */

#include <stdio.h>
#include <stdlib.h>
#include "pointers.h"

/* 함수 포인터 예제용 도우미 함수 */
static int add(int a, int b) { return a + b; }
static int subtract(int a, int b) { return a - b; }

/* =============================================================================
 * 1. 포인터 기본
 * =============================================================================
 * & : 주소 연산자 (변수의 메모리 주소)
 * * : 역참조 연산자 (포인터가 가리키는 값)
 */
void learn_pointer_basics(void) {
    printf("\n========== 1. 포인터 기본 ==========\n");
    
    int num = 42;
    int *ptr;   /* ptr은 "int를 가리키는 포인터" */
    
    ptr = &num; /* ptr에 num의 주소 저장 */
    
    printf("변수 num의 값: %d\n", num);
    printf("변수 num의 주소: %p\n", (void*)&num);  /* %p: 포인터 출력 */
    printf("포인터 ptr이 가리키는 주소: %p\n", (void*)ptr);
    printf("ptr이 가리키는 값 (*ptr): %d\n", *ptr);  /* 역참조 */
    
    /* 포인터를 통해 값 수정 */
    *ptr = 100;
    printf("\n*ptr = 100 실행 후\n");
    printf("num의 값: %d (포인터를 통해 변경됨!)\n", num);
    
    /* NULL 포인터: 아무것도 가리키지 않음 (Java의 null과 유사) */
    int *null_ptr = NULL;
    if (null_ptr == NULL) {
        printf("null_ptr은 아무것도 가리키지 않습니다.\n");
    }
}

/* =============================================================================
 * 2. 포인터와 배열
 * =============================================================================
 * C에서 배열 이름은 "첫 번째 요소의 주소"로 변환됩니다!
 * arr == &arr[0]
 * *(arr + i) == arr[i]  (포인터 산술)
 */
void learn_pointer_and_array(void) {
    printf("\n========== 2. 포인터와 배열 ==========\n");
    
    int arr[] = {10, 20, 30, 40, 50};
    
    printf("arr (배열이름): %p = 첫 요소의 주소\n", (void*)arr);
    printf("&arr[0]: %p (동일!)\n", (void*)&arr[0]);
    
    /* 포인터로 배열 순회 */
    int *p = arr;
    printf("\n포인터로 배열 접근: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));  /* p[i]와 동일 */
    }
    printf("\n");
    
    /* p++로 다음 요소로 이동 (포인터 산술) */
    p = arr;
    printf("포인터 증가(p++)로 순회: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *p);
        p++;  /* int 크기(4바이트)만큼 주소 증가 */
    }
    printf("\n");
}

/* =============================================================================
 * 3. 포인터를 함수 인자로 (Call by Reference)
 * =============================================================================
 * Java는 항상 "값에 의한 전달"이지만, 객체 참조는 복사됩니다.
 * C에서 함수가 변수를 수정하려면 포인터로 주소를 전달해야 합니다!
 */
static void swap_wrong(int a, int b) {
    /* 이건 동작 안 함 - 복사본만 바뀜 */
    int temp = a;
    a = b;
    b = temp;
}

static void swap_correct(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void learn_pointer_as_argument(void) {
    printf("\n========== 3. 포인터를 인자로 (Call by Reference) ==========\n");
    
    int x = 5, y = 10;
    printf("swap 전: x=%d, y=%d\n", x, y);
    
    swap_wrong(x, y);
    printf("swap_wrong 후: x=%d, y=%d (변화 없음!)\n", x, y);
    
    swap_correct(&x, &y);  /* 주소 전달! */
    printf("swap_correct 후: x=%d, y=%d (제대로 swap됨!)\n", x, y);
}

/* =============================================================================
 * 4. 이중 포인터 (int **)
 * =============================================================================
 * 포인터를 가리키는 포인터
 * 용도: 포인터를 수정하는 함수에 전달할 때
 * (Java에는 이 개념이 없음 - 참조의 참조 없음)
 */
static void allocate_int(int **ptr) {
    *ptr = (int*)malloc(sizeof(int));  /* 동적 할당 */
    **ptr = 999;  /* 이중 역참조로 값 설정 */
}

void learn_double_pointer(void) {
    printf("\n========== 4. 이중 포인터 ==========\n");
    
    int *p = NULL;
    allocate_int(&p);  /* p의 주소 전달 - 함수 내에서 p를 변경할 수 있음 */
    
    printf("동적 할당된 값: %d\n", *p);
    
    free(p);  /* 반드시 해제! */
}

/* =============================================================================
 * 5. 함수 포인터
 * =============================================================================
 * Java의 람다, 메서드 참조, Strategy 패턴과 유사
 * 함수도 메모리에 있으므로 그 주소를 저장할 수 있음
 */
void learn_function_pointer(void) {
    printf("\n========== 5. 함수 포인터 ==========\n");
    
    /* 함수 포인터 타입: 반환형 (*이름)(매개변수들) */
    int (*operation)(int, int);
    
    operation = add;
    printf("add(10, 5) = %d\n", operation(10, 5));
    
    operation = subtract;
    printf("subtract(10, 5) = %d\n", operation(10, 5));
    
    /* 함수 포인터 배열 (전략 패턴) */
    int (*ops[])(int, int) = {add, subtract};
    printf("ops[0](20, 8) = %d\n", ops[0](20, 8));
    printf("ops[1](20, 8) = %d\n", ops[1](20, 8));
}
