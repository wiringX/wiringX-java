# MIT License
# 
# Copyright (c) 2016 Josua Mayer <josua.mayer97@gmail.com>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

find_package(Java REQUIRED)
find_package(JUnit REQUIRED)

include(UseJava)
set(jwiringX-test_SOURCES
	eu/jm0/wiringX/wiringXTest.java
)
add_jar(jwiringX-test SOURCES ${jwiringX-test_SOURCES} VERSION ${PROJECT_VERSION} INCLUDE_JARS jwiringX ${JUnit_PATH})

# construct classpath from dependencies
if (CMAKE_HOST_WIN32 AND NOT CYGWIN AND CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
	set(CMAKE_JAVA_INCLUDE_FLAG_SEP ";")
else ()
	set(CMAKE_JAVA_INCLUDE_FLAG_SEP ":")
endif()
foreach(_JAVA_INCLUDE_JAR jwiringX jwiringX-test)
	get_target_property(_JAVA_JAR_PATH ${_JAVA_INCLUDE_JAR} JAR_FILE)
	if(_JAVA_JAR_PATH)
		set(CMAKE_JAVA_INCLUDE_PATH_FINAL "${CMAKE_JAVA_INCLUDE_PATH_FINAL}${CMAKE_JAVA_INCLUDE_FLAG_SEP}${_JAVA_JAR_PATH}")
	endif()
endforeach()
set(CMAKE_JAVA_INCLUDE_PATH_FINAL "${CMAKE_JAVA_INCLUDE_PATH_FINAL}${CMAKE_JAVA_INCLUDE_FLAG_SEP}${JUnit_PATH}")

add_test(NAME jwiringX-test COMMAND ${Java_JAVA_EXECUTABLE} ${JVMARGS} -classpath ${CMAKE_JAVA_INCLUDE_PATH_FINAL} org.junit.runner.JUnitCore eu.jm0.wiringX.wiringXTest)
set_tests_properties(jwiringX-test PROPERTIES ENVIRONMENT "LD_LIBRARY_PATH=$<TARGET_FILE_DIR:wiringx-java>")
add_dependencies(check jwiringX-test)
