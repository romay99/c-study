/**
 * @file basics.h
 * @brief C 언어 기본 문법 학습 - 헤더 파일
 * 
 * [Java와의 차이점]
 * Java에서는 클래스가 하나의 단위이지만,
 * C에서는 .h(헤더)와 .c(구현) 파일이 분리됩니다.
 * 헤더 파일에는 함수 선언(시그니처)만, .c 파일에는 구현을 넣습니다.
 * 이는 Java의 인터페이스와 구현 분리와 유사한 개념입니다.
 */

#ifndef BASICS_H
#define BASICS_H

/* 매크로 가드: 같은 헤더가 여러 번 include 되더라도 한 번만 컴파일되도록 */

/* ==================== 함수 선언부 ==================== */

/**
 * 1. 변수와 데이터 타입 학습
 * Java의 primitive type과 C의 비교
 */
void learn_variables_and_types(void);

/**
 * 2. 연산자 학습
 */
void learn_operators(void);

/**
 * 3. 제어문 (if, switch, 반복문)
 */
void learn_control_flow(void);

/**
 * 4. 배열
 * Java와 달리 C 배열은 크기가 고정이며, length 속성이 없습니다.
 */
void learn_arrays(void);

/**
 * 5. 문자열
 * C에는 String 클래스가 없고, char 배열로 처리합니다.
 */
void learn_strings(void);

#endif /* BASICS_H */
