/**
 * @file memory.h
 * @brief [4단계] C 언어 메모리 관리 학습 - 헤더 파일
 * 
 * [Java와의 결정적 차이]
 * Java: 가비지 컬렉터가 자동으로 메모리 회수
 * C: malloc/free로 수동 관리 - 메모리 누수와 해제 후 사용 버그 주의!
 */

#ifndef MEMORY_H
#define MEMORY_H

/* 동적 메모리 할당 (malloc, calloc, realloc) */
void learn_dynamic_allocation(void);

/* 메모리 해제와 누수 방지 */
void learn_memory_free(void);

/* 문자열 동적 할당 (실무에서 자주 사용) */
void learn_dynamic_string(void);

/* 메모리 관련 주의사항과 안전한 코딩 패턴 */
void learn_memory_safety(void);

#endif /* MEMORY_H */
