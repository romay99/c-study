@echo off
REM =============================================================================
REM C 언어 학습 프로젝트 - Windows 빌드 스크립트
REM =============================================================================
REM 사용법: build.bat
REM 
REM 필요 사항: GCC (MinGW, MSYS2, 또는 TDM-GCC)
REM   - https://www.mingw-w64.org/
REM   - https://www.msys2.org/
REM   - PATH에 gcc가 등록되어 있어야 함
REM =============================================================================

set CC=gcc
set CFLAGS=-Wall -Wextra -g -std=c11
set INCLUDES=-Iinclude

if not exist bin mkdir bin

echo [1/5] main.c 컴파일...
%CC% %CFLAGS% %INCLUDES% -c src/main.c -o main.o
if errorlevel 1 goto error

echo [2/5] basics.c 컴파일...
%CC% %CFLAGS% %INCLUDES% -c src/basics/basics.c -o basics.o
if errorlevel 1 goto error

echo [3/5] pointers.c 컴파일...
%CC% %CFLAGS% %INCLUDES% -c src/pointers/pointers.c -o pointers.o
if errorlevel 1 goto error

echo [4/5] struct.c 컴파일...
%CC% %CFLAGS% %INCLUDES% -c src/struct/struct.c -o struct.o
if errorlevel 1 goto error

echo [5/5] memory.c 컴파일 및 링크...
%CC% %CFLAGS% %INCLUDES% -c src/memory/memory.c -o memory.o
if errorlevel 1 goto error

%CC% main.o basics.o pointers.o struct.o memory.o -o bin/c-study.exe
if errorlevel 1 goto error

del main.o basics.o pointers.o struct.o memory.o 2>nul
echo.
echo 빌드 완료: bin\c-study.exe
echo 실행: bin\c-study.exe
goto end

:error
echo.
echo 빌드 실패! GCC가 설치되어 있는지 확인하세요.
echo MinGW/MSYS2: https://www.msys2.org/
exit /b 1

:end
