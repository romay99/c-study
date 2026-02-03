/**
 * @file basics.h
 * @brief [1단계] C 언어 기본 문법 학습 - 헤더 파일
 *
 * [Java와의 차이점]
 * Java에서는 클래스가 하나의 단위이지만,
 * C에서는 .h(헤더)와 .c(구현) 파일이 분리됩니다.
 * 헤더 파일에는 함수 선언(시그니처)만, .c 파일에는 구현을 넣습니다.
 * 이는 Java의 인터페이스와 구현 분리와 유사한 개념입니다.
 *
 * ========== C 기초: 이 파일에서 쓰이는 것들 (Java만 알면 여기서 설명) ==========
 *
 * #ifndef BASICS_H
 *   - "BASICS_H 라는 이름이 아직 정의되지 않았으면" 이라는 조건입니다.
 *   - #if + n + def = "if not defined" (정의되지 않았으면)
 *   - Java에는 없는 문법입니다. C에서는 "이 헤더를 한 번만 쓰게" 막는 데 씁니다.
 *
 * #define BASICS_H
 *   - "BASICS_H 라는 이름을 지금 정의했다"고 표시합니다.
 *   - 여기서는 값을 넣지 않아서, 그냥 "정의됨" 여부만 체크할 때 씁니다.
 *   - Java의 상수(final)와 비슷하게 쓰일 때는 #define MAX 100 처럼 값을 넣습니다.
 *
 * #endif
 *   - #ifndef 로 시작한 블록의 끝을 나타냅니다. (아래 맨 끝에 있음)
 *
 * 왜 #ifndef ~ #define ~ #endif 를 쓰나요?
 *   - C에서 #include 는 "그 파일 내용을 그대로 복붙"하는 거라서,
 *     같은 .h 를 여러 번 include 하면 같은 선언이 두 번 나와서 컴파일 에러가 납니다.
 *   - 그래서 "처음 한 번만 이 안쪽을 쓰고, 두 번째부터는 스킵"하게 만든 게
 *     이 세 줄입니다. 이걸 "include guard(헤더 가드)" 라고 부릅니다.
 *
 * 자세한 설명은 프로젝트 루트의 C_BASICS.md 를 보세요.
 * =============================================================================
 */

#ifndef BASICS_H   /* BASICS_H가 아직 정의 안 됐으면 아래부터 실행 */
#define BASICS_H   /* 지금 정의함 → 다음에 또 include 되면 #ifndef가 거짓이 되어 스킵 */

/* 여기 아래는 "함수 선언"만 있습니다. 실제 구현은 basics.c 에 있습니다. */

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

#endif /* BASICS_H */  /* #ifndef BASICS_H 블록 끝 */
