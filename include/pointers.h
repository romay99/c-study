/**
 * @file pointers.h
 * @brief [2단계] C 언어 포인터 학습 - 헤더 파일
 *
 * [Java 개발자에게 가장 중요한 C 개념]
 * Java에는 포인터가 없고 참조(reference)만 있습니다.
 * C의 포인터는 "메모리 주소를 저장하는 변수"입니다.
 *
 * [이 파일에서 쓰는 C 기초]
 * #ifndef POINTERS_H  → "POINTERS_H 가 아직 정의 안 됐으면" (include guard)
 * #define POINTERS_H  → "지금 정의함" (같은 헤더가 두 번 포함되는 것 방지)
 * #endif              → 조건 블록 끝
 * 자세한 설명: C_BASICS.md 참고
 */

#ifndef POINTERS_H
#define POINTERS_H

/* 포인터 기본 개념 */
void learn_pointer_basics(void);

/* 포인터와 배열의 관계 */
void learn_pointer_and_array(void);

/* 포인터를 인자로 전달 (call by reference) */
void learn_pointer_as_argument(void);

/* 이중 포인터 (포인터의 포인터) */
void learn_double_pointer(void);

/* 함수 포인터 (Java의 람다/메서드 참조와 유사) */
void learn_function_pointer(void);

#endif /* POINTERS_H */
