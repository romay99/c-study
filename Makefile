# =============================================================================
# C 언어 학습 프로젝트 - Makefile
# =============================================================================
# Java의 Maven/Gradle과 달리, C에서는 Makefile로 빌드 과정을 정의합니다.
# make 명령어로 이 파일을 읽어 컴파일을 수행합니다.
# =============================================================================

# CC: 컴파일러 지정 (gcc 또는 clang)
CC = gcc

# CFLAGS: 컴파일 옵션
#   -Wall: 모든 경고 메시지 출력 (Java의 -Xlint와 유사)
#   -Wextra: 추가 경고
#   -g: 디버깅 정보 포함
#   -std=c11: C11 표준 사용
CFLAGS = -Wall -Wextra -g -std=c11

# 디렉토리 정의
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# 소스 파일들 (*.c)
SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)

# 오브젝트 파일들 (*.c -> *.o)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# 최종 실행 파일
TARGET = $(BIN_DIR)/c-study

# include 경로 추가 (헤더 파일 찾기)
INCLUDES = -I$(INC_DIR)

# =============================================================================
# 빌드 규칙
# =============================================================================

# 기본 타겟: all
# make 또는 make all 실행 시 실행 파일 생성
all: directories $(TARGET)

# bin, build 디렉토리 생성
directories:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/01_basics $(BUILD_DIR)/02_pointers $(BUILD_DIR)/03_struct $(BUILD_DIR)/04_memory

# 링킹: 오브젝트 파일들을 묶어 실행 파일 생성
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo "빌드 완료: $(TARGET)"

# 컴파일: .c -> .o (각 소스 파일을 오브젝트로)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# make clean: 빌드 산출물 삭제
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "클린 완료"

# make run: 빌드 후 실행
run: all
	./$(TARGET)

.PHONY: all clean run directories
