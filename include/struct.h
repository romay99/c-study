/**
 * @file struct.h
 * @brief C 언어 구조체 학습 - 헤더 파일
 * 
 * [Java의 클래스와 비교]
 * C의 struct는 Java의 클래스와 유사하지만 중요한 차이가 있습니다:
 * - struct에는 메서드(함수)가 없고 데이터만 있습니다
 * - 상속, 다형성 등 OOP 개념이 없습니다
 * - 명시적으로 메모리를 관리해야 합니다
 */

#ifndef STRUCT_H
#define STRUCT_H

/* Person 구조체 정의 - Java의 class Person { ... }와 유사 */
typedef struct {
    char name[50];      /* 이름 */
    int age;            /* 나이 */
    float height;       /* 키 (cm) */
} Person;

/* 구조체 기본 사용법 */
void learn_struct_basics(void);

/* 구조체 포인터 사용 */
void learn_struct_pointer(void);

/* 구조체를 함수 인자로 전달 */
void learn_struct_as_argument(void);

/* 구조체 배열 */
void learn_struct_array(void);

#endif /* STRUCT_H */
