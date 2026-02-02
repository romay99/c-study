/**
 * @file struct.c
 * @brief [3단계] C 언어 구조체 학습 구현
 * 
 * [Java 클래스 vs C 구조체]
 * - struct: 데이터만 (필드)
 * - 메서드 없음 -> 별도 함수로 구현
 * - 생성자/소멸자 없음 -> 수동 초기화
 * - 접근: . (구조체) 또는 -> (구조체 포인터)
 */

#include <stdio.h>
#include <string.h>
#include "struct.h"

/* =============================================================================
 * 1. 구조체 기본
 * =============================================================================
 */
void learn_struct_basics(void) {
    printf("\n========== 1. 구조체 기본 ==========\n");
    
    /* 구조체 변수 선언 및 초기화 */
    Person p1;
    strcpy(p1.name, "홍길동");  /* 문자열은 strcpy로 복사 */
    p1.age = 25;
    p1.height = 175.5f;
    
    /* 선언과 동시에 초기화 */
    Person p2 = {"김철수", 30, 180.2f};
    
    printf("p1: %s, %d세, %.1fcm\n", p1.name, p1.age, p1.height);
    printf("p2: %s, %d세, %.1fcm\n", p2.name, p2.age, p2.height);
    
    /* 구조체 복사 (memcpy 또는 대입) */
    Person p3 = p1;  /* 멤버별 복사 (shallow copy) */
    printf("p3 (p1 복사): %s\n", p3.name);
}

/* =============================================================================
 * 2. 구조체 포인터
 * =============================================================================
 * 포인터로 구조체 접근 시 -> 연산자 사용
 * (*ptr).member 와 ptr->member 는 동일
 */
void learn_struct_pointer(void) {
    printf("\n========== 2. 구조체 포인터 ==========\n");
    
    Person person = {"이영희", 28, 165.0f};
    Person *ptr = &person;
    
    /* 두 가지 접근 방법 */
    printf("(*ptr).name: %s\n", (*ptr).name);  /* 괄호 필수! .이 *보다 우선 */
    printf("ptr->name: %s (권장)\n", ptr->name);  /* 화살표가 더 읽기 쉬움 */
    
    ptr->age = 29;  /* 포인터로 멤버 수정 */
    printf("나이 수정 후: %d세\n", ptr->age);
}

/* =============================================================================
 * 3. 구조체를 함수 인자로
 * =============================================================================
 * 값 전달: 전체 복사 (구조체 크기만큼 복사 오버헤드)
 * 포인터 전달: 주소만 전달 (효율적, const로 읽기 전용 표시 가능)
 */
static void print_person(const Person *p) {
    /* const Person* : 가리키는 대상을 수정하지 않겠다는 약속 */
    printf("  - %s (%d세, %.1fcm)\n", p->name, p->age, p->height);
}

static void birthday(Person *p) {
    p->age++;  /* 나이 증가 - 수정하므로 const 아님 */
}

void learn_struct_as_argument(void) {
    printf("\n========== 3. 구조체를 함수 인자로 ==========\n");
    
    Person p = {"박민수", 24, 178.0f};
    
    printf("생일 전: ");
    print_person(&p);
    
    birthday(&p);
    printf("생일 후: ");
    print_person(&p);
}

/* =============================================================================
 * 4. 구조체 배열
 * =============================================================================
 */
void learn_struct_array(void) {
    printf("\n========== 4. 구조체 배열 ==========\n");
    
    Person team[] = {
        {"김일", 25, 175.0f},
        {"이이", 30, 180.0f},
        {"박삼", 22, 170.0f}
    };
    
    int count = sizeof(team) / sizeof(team[0]);
    printf("팀원 %d명:\n", count);
    
    for (int i = 0; i < count; i++) {
        printf("  [%d] ", i + 1);
        print_person(&team[i]);  /* 주소 전달 */
    }
}
