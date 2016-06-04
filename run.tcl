#! /usr/bin/env tclsh8.5

source common.tcl

#proc testsPass {
#
#}

if {[file isdirectory $MAIN_EXE]} {
  # this is a directory
} else {
  # not a directory
  exec $BUILD_SCRIPT_FILE
}

## if tests pass
#if {testsPass()}{
#    # then run
    set result [exec $MAIN_EXE]

    # display the results
    puts "$result"
#}

