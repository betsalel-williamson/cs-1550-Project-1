#! /usr/bin/env tclsh8.5

source common.tcl

if {[file isdirectory $TEST_EXE]} {
  # this is a directory
} else {
  # not a directory
  exec $BUILD_SCRIPT_FILE
}

if { [catch {set result [exec $TEST_EXE]} reason] } {

puts "Failed: $reason"

} else {

puts $result

}

proc searchResultsForPassed {result} {
    if {[lsearch -all -inline $result *PASSED*] >= 0} {
        return -code ok
     } else { 
        return -code error
    }
}



