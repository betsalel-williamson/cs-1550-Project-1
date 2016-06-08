#! /usr/bin/env tclsh8.5

set BUILD_DIR _build

set PROJECT_NAME Main

set BUILD_SCRIPT_FILE ./build.tcl

set TEST_SCRIPT_FILE ./test.tcl

set TEST_EXE $BUILD_DIR/test/Test_project

set MAIN_EXE $BUILD_DIR/$PROJECT_NAME