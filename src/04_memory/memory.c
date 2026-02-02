/**
 * @file memory.c
 * @brief [4단계] C 언어 메모리 관리 학습 구현
 * 
 * [Java vs C 메모리]
 * Java: new로 할당 -> GC가 자동 회수
 * C: malloc/calloc으로 할당 -> free로 수동 해제 (반드시!)
 * 
 * 메모리 누수, Double free, Use-after-free 등 주의!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"

/* =============================================================================
 * 1. 동적 메모리 할당
 * =============================================================================
 * malloc(size): size 바이트 할당, 초기화 안 됨 (쓰레기값)
 * calloc(count, size): count*size 바이트, 0으로 초기화
 * realloc(ptr, size): 크기 재조정 (확대/축소)
 */
void learn_dynamic_allocation(void) {
    printf("\n========== 1. 동적 메모리 할당 ==========\n");
    
    /* malloc: Java의 new int[10]과 유사 */
    int *arr = (int*)malloc(10 * sizeof(int));  /* 10개 정수 공간 */
    
    if (arr == NULL) {
        printf("메모리 할당 실패!\n");
        return;
    }
    
    /* 사용 */
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
    }
    
    printf("malloc 배열: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);  /* 반드시 해제! */
    arr = NULL; /* 해제 후 NULL로 (dangling pointer 방지) */
    
    /* calloc: 0으로 초기화된 배열 */
    int *zeros = (int*)calloc(5, sizeof(int));
    printf("calloc (0 초기화): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", zeros[i]);
    }
    printf("\n");
    free(zeros);
    
    /* realloc: 크기 변경 */
    int *dynamic = (int*)malloc(3 * sizeof(int));
    dynamic[0] = 1; dynamic[1] = 2; dynamic[2] = 3;
    
    int *resized = (int*)realloc(dynamic, 5 * sizeof(int));
    if (resized != NULL) {
        dynamic = resized;  /* realloc은 새 포인터 반환할 수 있음 */
        dynamic[3] = 4;
        dynamic[4] = 5;
        printf("realloc 확장 후: %d %d %d %d %d\n", 
               dynamic[0], dynamic[1], dynamic[2], dynamic[3], dynamic[4]);
        free(dynamic);
    }
}

/* =============================================================================
 * 2. 메모리 해제와 누수 방지
 * =============================================================================
 */
void learn_memory_free(void) {
    printf("\n========== 2. 메모리 해제 ==========\n");
    
    printf("주요 규칙:\n");
    printf("  1. malloc/calloc/realloc 할당 -> 반드시 free\n");
    printf("  2. free 후 포인터를 NULL로 설정\n");
    printf("  3. free(NULL)은 안전 (아무것도 안 함)\n");
    printf("  4. 같은 포인터를 두 번 free 하지 말 것! (Double free)\n");
    
    char *buf = (char*)malloc(100);
    if (buf) {
        /* 사용 */
        free(buf);
        buf = NULL;  /* 이제 buf를 잘못 사용해도 NULL 체크로 방어 가능 */
    }
    
    /* free(NULL)은 안전 */
    free(NULL);
    printf("free(NULL) 호출 - 문제없음\n");
}

/* =============================================================================
 * 3. 동적 문자열
 * =============================================================================
 * 실무에서 매우 자주 사용
 * strlen + 1 (null 문자 공간) 만큼 할당
 */
void learn_dynamic_string(void) {
    printf("\n========== 3. 동적 문자열 ==========\n");
    
    const char *src = "Hello, Dynamic C!";
    
    /* 문자열 복사: 길이 + 1 (null 포함) */
    size_t len = strlen(src);
    char *str = (char*)malloc(len + 1);  /* +1 for '\\0' */
    
    if (str) {
        strcpy(str, src);
        printf("동적 복사: %s\n", str);
        printf("할당된 크기: %zu bytes\n", len + 1);
        free(str);
    }
    
    /* strdup: 일부 환경에서 사용 가능 (표준은 아님) */
    /* char *dup = strdup(src); free(dup); */
}

/* =============================================================================
 * 4. 메모리 안전
 * =============================================================================
 */
void learn_memory_safety(void) {
    printf("\n========== 4. 메모리 안전 ==========\n");
    
    printf("흔한 버그와 방지법:\n");
    printf("  [1] 메모리 누수: 할당 후 free 안 함\n");
    printf("      -> 할당과 해제를 쌍으로 관리\n");
    printf("  [2] Use-after-free: 해제 후 사용\n");
    printf("      -> free 후 ptr = NULL 설정\n");
    printf("  [3] Buffer overflow: 할당 크기 초과 접근\n");
    printf("      -> 경계 검사, snprintf 사용\n");
    printf("  [4] NULL 역참조: malloc 실패 시 NULL 반환\n");
    printf("      -> 항상 NULL 체크 후 사용\n");
    
    /* 안전한 할당 패턴 예시 */
    int *safe = (int*)malloc(sizeof(int));
    if (safe == NULL) {
        fprintf(stderr, "할당 실패\n");
        return;
    }
    *safe = 42;
    /* ... 사용 ... */
    free(safe);
    safe = NULL;
    
    printf("\n안전한 패턴 적용됨.\n");
}
