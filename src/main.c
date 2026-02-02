/**
 * @file main.c
 * @brief C 언어 학습 프로젝트 - 메인 진입점
 * 
 * Java의 public static void main(String[] args)와 유사
 * C의 main 함수: int main(int argc, char *argv[])
 *   - argc: 인자 개수 (프로그램 이름 포함)
 *   - argv: 인자 문자열 배열
 *   - 반환값: 0=성공, 0이 아님=에러 (OS에 전달)
 */

#include <stdio.h>
#include "basics.h"
#include "pointers.h"
#include "struct.h"
#include "memory.h"

/**
 * 메뉴 출력 및 선택
 * @return 선택한 번호 (1~5)
 */
static int show_menu(void) {
    int choice;
    
    printf("\n");
    printf("========================================\n");
    printf("   C 언어 학습 프로젝트 - 메뉴\n");
    printf("========================================\n");
    printf("  1. 기본 문법 (변수, 제어문, 배열, 문자열)\n");
    printf("  2. 포인터 (C의 핵심!)\n");
    printf("  3. 구조체 (Java 클래스와 유사)\n");
    printf("  4. 메모리 관리 (malloc/free)\n");
    printf("  5. 전체 실행 (모든 예제)\n");
    printf("  0. 종료\n");
    printf("========================================\n");
    printf("선택: ");
    
    if (scanf("%d", &choice) != 1) {
        /* 입력 오류 시 버퍼 비우기 */
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return -1;
    }
    
    return choice;
}

/**
 * 메인 함수
 */
int main(int argc, char *argv[]) {
    /* argc, argv 사용 예 (선택 사항) */
    if (argc > 1 && argv[1][0] == '-') {
        printf("C 학습 프로젝트 - 인자: %s\n", argv[1]);
    }
    
    printf("Java Spring 개발자를 위한 C 언어 학습에 오신 것을 환영합니다!\n");
    
    int running = 1;
    while (running) {
        int choice = show_menu();
        
        switch (choice) {
            case 1:
                learn_variables_and_types();
                learn_operators();
                learn_control_flow();
                learn_arrays();
                learn_strings();
                break;
                
            case 2:
                learn_pointer_basics();
                learn_pointer_and_array();
                learn_pointer_as_argument();
                learn_double_pointer();
                learn_function_pointer();
                break;
                
            case 3:
                learn_struct_basics();
                learn_struct_pointer();
                learn_struct_as_argument();
                learn_struct_array();
                break;
                
            case 4:
                learn_dynamic_allocation();
                learn_memory_free();
                learn_dynamic_string();
                learn_memory_safety();
                break;
                
            case 5:
                /* 전체 실행 */
                learn_variables_and_types();
                learn_operators();
                learn_control_flow();
                learn_arrays();
                learn_strings();
                learn_pointer_basics();
                learn_pointer_and_array();
                learn_pointer_as_argument();
                learn_double_pointer();
                learn_function_pointer();
                learn_struct_basics();
                learn_struct_pointer();
                learn_struct_as_argument();
                learn_struct_array();
                learn_dynamic_allocation();
                learn_memory_free();
                learn_dynamic_string();
                learn_memory_safety();
                break;
                
            case 0:
                running = 0;
                printf("학습을 종료합니다. 화이팅!\n");
                break;
                
            default:
                printf("잘못된 선택입니다. 0~5 중에서 선택하세요.\n");
        }
    }
    
    return 0;  /* 정상 종료 */
}
