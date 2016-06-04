#! /usr/bin/env tclsh8.5

source common.tcl

if {[file isdirectory $BUILD_DIR]} {
  # this is a directory
} else {
  # not a directory
  exec mkdir $BUILD_DIR
}

cd $BUILD_DIR

set result [exec cmake ..]
puts "$result"

set result [exec cmake --build .]
puts "$result"

