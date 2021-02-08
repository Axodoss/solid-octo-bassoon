@echo off

SET ProjectPath=%CD%
SET BuildPath=build
SET LCC=%ProjectPath%\gbdk\bin\lcc

IF NOT EXIST %BuildPath% MKDIR %BuildPath%

PUSHD %BuildPath%

CALL %LCC% -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o %ProjectPath%\src\main.c
CALL %LCC% -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o main.gb main.o

POPD