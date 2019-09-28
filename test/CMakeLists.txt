## Testing the project
cmake_minimum_required(VERSION 2.6)

#include files including headers in the src
include_directories( . .. ~/workspace/lib/c/test/minunit ../include contrib/c_procs/include )

#add test sources
file( GLOB TEST_SOURCES *.c *.cpp )

file( GLOB LIB_SOURCE_FILES ../src/httputils/*.cpp contrib/c_procs/src/strutils.c )
add_library( source_lib ${LIB_SOURCE_FILES} )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set enable testing
enable_testing()
link_libraries( ${LIBRARIES} )
link_libraries( source_lib )

#adding tests foreach test source file
foreach(filename ${TEST_SOURCES})
	
	#get the file name of the source file
	if(WIN32) 
		string(REGEX REPLACE ".*\\" "" testname "${filename}" )
	else(WIN32)
			string(REGEX REPLACE ".*/" "" testname "${filename}" )
	endif(WIN32)

	#remove .c extension
	string(REGEX REPLACE ".[a-z]+$" "" testname "${testname}" )

	#create executable
	add_executable( ${testname} ${OBJECTS} ${filename} )
	#configure for testing
	add_test( ${testname} ${testname} )
endforeach(filename)
