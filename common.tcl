#! /usr/bin/env tclsh8.5

set BUILD_DIR _build

set PROJECT_NAME Project1

set BUILD_SCRIPT_FILE ./build.tcl

set TEST_SCRIPT_FILE ./test.tcl

set TEST_EXE $BUILD_DIR/sysCall_tests/BasicTest/RunBasicTest

set MAIN_EXE $BUILD_DIR/$PROJECT_NAME