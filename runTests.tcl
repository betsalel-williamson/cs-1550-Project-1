#! /usr/bin/env tclsh8.5

source common.tcl

if {[file isdirectory $TEST_EXE]} {
  # this is a directory
} else {
  # not a directory
  exec $BUILD_SCRIPT_FILE
}

set result [exec $TEST_EXE]

# display the results
puts "$result"
