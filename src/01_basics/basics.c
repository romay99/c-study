/**
 * @file basics.c
 * @brief [1단계] C 언어 기본 문법 구현
 *
 * Java Spring 개발자를 위한 C 기본 문법 학습
 * 각 섹션마다 Java와의 비교 주석을 포함했습니다.
 *
 * ========== #include 설명 (Java만 알면 참고) ==========
 * #include "파일" → 그 파일 내용을 여기에 붙여 넣는 것. Java의 import 와 비슷한 역할.
 *
 * #include <stdio.h>
 *   - 표준 라이브러리. printf, scanf 등 사용하려면 필요. (Java의 System.out 같은 것)
 * #include <stdlib.h>
 *   - 표준 라이브러리. malloc, free 등에 필요.
 * #include <string.h>
 *   - 문자열 함수들. strcpy, strlen, strcmp 등 (C에는 String 클래스가 없어서 이걸 씀)
 * #include "basics.h"
 *   - 우리가 만든 헤더. "이 파일(basics.c)에서 쓰는 함수들이 뭔지" 선언이 들어 있음.
 *     실제 구현은 이 .c 파일 안에 아래에 나옵니다.
 */
#include <stdio.h>   /* printf, scanf 등 - Java의 System.out과 유사 */
#include <stdlib.h>  /* 표준 라이브러리 */
#include <string.h>  /* 문자열 함수들 */
#include "basics.h"

/* =============================================================================
 * 1. 변수와 데이터 타입
 * =============================================================================
 * Java: int, long, double, boolean, String, etc.
 * C: int, long, float, double, char, _Bool (C99), 포인터 타입들
 * C에는 boolean이 없었음 (C99에서 _Bool 추가, stdbool.h로 true/false 사용 가능)
 */
void learn_variables_and_types(void) {
    printf("\n========== 1. 변수와 데이터 타입 ==========\n");
    
    /* 기본 정수 타입 */
    int count = 10;           /* Java의 int와 동일, 보통 4바이트 */
    long big_num = 1000000L;  /* L 접미사로 long 리터럴 */
    short small = 100;        /* 2바이트, Java의 short */
    
    /* 부호 없는 타입 (Java에는 없음 - 주의!) */
    unsigned int positive_only = 100;  /* 음수 없이 0~양수만 */
    
    /* 실수 타입 */
    float price = 19.99f;     /* f 접미사로 float 리터럴 (안쓰면 double로 인식) */
    double precise = 3.14159265358979;
    
    /* 문자 - C에서 char는 1바이트 정수이자 문자 */
    char letter = 'A';        /* 싱글 쿼트 = 문자 하나 */
    
    /* C에는 String이 없음! char 배열 또는 포인터 사용 */
    
    printf("int: %d, long: %ld, short: %d\n", count, big_num, small);
    printf("float: %.2f, double: %.6f\n", price, precise);
    printf("char: %c (ASCII: %d)\n", letter, letter);
    
    /* sizeof 연산자: 타입/변수의 바이트 크기 (Java에는 없음) */
    printf("\n[sizeof - 메모리 크기 확인]\n");
    printf("int: %zu bytes, long: %zu bytes\n", sizeof(int), sizeof(long));
    printf("double: %zu bytes, char: %zu byte\n", sizeof(double), sizeof(char));
}

/* =============================================================================
 * 2. 연산자
 * =============================================================================
 */
void learn_operators(void) {
    printf("\n========== 2. 연산자 ==========\n");
    
    int a = 10, b = 3;
    
    /* 산술 연산자 - Java와 동일 */
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d (정수 나눗셈!)\n", a / b);  /* 3, 소수 버림 */
    printf("a %% b = %d (나머지)\n", a % b);       /* %%는 % 출력 */
    
    /* 증감 연산자 */
    int x = 5;
    printf("x++ 후위: %d (출력 후 증가)\n", x++);  /* 5 출력, x는 6 */
    printf("현재 x: %d\n", x);
    printf("++x 전위: %d (증가 후 출력)\n", ++x);  /* 7 출력 */
    
    /* 논리 연산자: && || ! (Java와 동일) */
    /* 비교 연산자: == != < > <= >= (Java와 동일) */
}

/* =============================================================================
 * 3. 제어문
 * =============================================================================
 */
void learn_control_flow(void) {
    printf("\n========== 3. 제어문 ==========\n");
    
    /* if-else - Java와 동일, 단 괄호 필수 */
    int score = 85;
    if (score >= 90) {
        printf("등급: A\n");
    } else if (score >= 80) {
        printf("등급: B\n");
    } else {
        printf("등급: C 이하\n");
    }
    
    /* switch - Java와 유사, break 없으면 fall-through! */
    int choice = 2;
    switch (choice) {
        case 1:
            printf("case 1 선택\n");
            break;  /* break 빼먹으면 다음 case도 실행됨 (주의!) */
        case 2:
            printf("case 2 선택\n");
            break;
        default:
            printf("기본값\n");
    }
    
    /* for 반복문 */
    printf("\nfor 루프: ");
    for (int i = 0; i < 5; i++) {  /* C99부터 for 안에서 변수 선언 가능 */
        printf("%d ", i);
    }
    printf("\n");
    
    /* while 반복문 */
    int j = 0;
    printf("while 루프: ");
    while (j < 3) {
        printf("%d ", j);
        j++;
    }
    printf("\n");
    
    /* do-while: 최소 1회 실행 */
    int k = 0;
    do {
        printf("do-while: %d (최소 1번 실행)\n", k);
        k++;
    } while (k < 1);
}

/* =============================================================================
 * 4. 배열
 * =============================================================================
 * Java: int[] arr = new int[5];  - 동적 크기 가능
 * C: int arr[5];  - 선언 시 크기 고정, 변경 불가
 * C: 배열에 .length 없음! 크기를 별도 변수로 관리해야 함
 */
void learn_arrays(void) {
    printf("\n========== 4. 배열 ==========\n");
    
    /* 정수 배열 선언 및 초기화 */
    int numbers[5] = {10, 20, 30, 40, 50};
    
    /* 부분 초기화: 나머지는 0 */
    int partial[5] = {1, 2, 3};  /* {1, 2, 3, 0, 0} */
    
    /* 크기 생략 가능 (초기화 시) */
    int auto_size[] = {1, 2, 3, 4, 5};  /* 자동으로 크기 5 */
    
    printf("배열 요소: ");
    int len = sizeof(numbers) / sizeof(numbers[0]);  /* 배열 길이 구하는 방법 */
    for (int i = 0; i < len; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    /* 2차원 배열 */
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("2차원 배열[1][2]: %d\n", matrix[1][2]);
}

/* =============================================================================
 * 5. 문자열
 * =============================================================================
 * Java: String s = "hello";  - 객체, 불변
 * C: char s[] = "hello";  - char 배열, null 문자('\0')로 종료
 * C 문자열은 "문자 배열 + 끝에 \\0" 형태입니다.
 */
void learn_strings(void) {
    printf("\n========== 5. 문자열 ==========\n");
    
    /* 방법 1: char 배열 (수정 가능) */
    char greeting[] = "Hello, C!";  /* 자동으로 '\0' 추가됨 */
    printf("문자열: %s\n", greeting);
    
    /* 방법 2: 포인터 (읽기 전용 메모리 가리킴) */
    const char *msg = "Read-only string";
    printf("상수 문자열: %s\n", msg);
    
    /* 문자열 길이 - strlen (null 제외) */
    printf("'Hello, C!' 길이: %zu\n", strlen(greeting));
    
    /* 문자열 복사 - strcpy (Java의 String.copyValueOf 같은 역할) */
    char dest[20];
    strcpy(dest, "Copied");
    printf("복사된 문자열: %s\n", dest);
    
    /* 문자열 연결 - strcat */
    strcat(dest, " string");
    printf("연결 후: %s\n", dest);
    
    /* 문자열 비교 - strcmp (같으면 0, 다르면 양수/음수) */
    if (strcmp(greeting, "Hello, C!") == 0) {
        printf("문자열이 일치합니다.\n");
    }
}
