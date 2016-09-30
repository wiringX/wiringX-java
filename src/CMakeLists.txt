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
find_package(JNI REQUIRED)
find_package(wiringX REQUIRED)

# Java part
set(jwiringX_SOURCES
	eu/jm0/wiringX/DigitalValue.java
	eu/jm0/wiringX/ISRMode.java
	eu/jm0/wiringX/LogConsumer.java
	eu/jm0/wiringX/PinMode.java
	eu/jm0/wiringX/SerialConfig.java
	eu/jm0/wiringX/wiringX.java
	eu/jm0/wiringX/wiringXTest.java
)

include(UseJava)
add_jar(jwiringX SOURCES ${jwiringX_SOURCES} VERSION ${PROJECT_VERSION} INCLUDE_JARS ${JUnit_PATH})

install_jar(jwiringX ${CMAKE_INSTALL_JARDIR})

# JNI Header part

# The following lines of code were been copied from libalexandria on September 30, 2016, and adapted.
# https://github.com/hagemt/libalexandria/blob/master/include/libalexandria/laJ/CMakeLists.txt
# 
# Copyright (c) 2012 Tor E Hagemann <hagemt@rpi.edu>
# 
# This is the original copyright notice of libalexandria
# 
# libalexandria is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# libalexandria is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with libalexandria.  If not, see <http://www.gnu.org/licenses/>.
# 
macro(javah JAVA_TARGET)
add_custom_target(javah_${JAVA_TARGET} DEPENDS ${JAVA_TARGET}
  COMMAND "${Java_JAVAH_EXECUTABLE}" -jni -d "${CMAKE_CURRENT_SOURCE_DIR}" ${ARGN}
  #COMMAND "cmake -E touch ${CMAKE_CURRENT_LIST_FILE}"
  WORKING_DIRECTORY "./${CMAKE_FILES_DIRECTORY}/${JAVA_TARGET}.dir"
  COMMENT "Updating JNI headers for ${JAVA_TARGET}" VERBATIM
)
# TODO fix problem where this isn't properly configured
# TODO need SOURCES for generation? pass ${JNI_HEADER_FILES}
# TODO FUTURE neater method?
# TODO There is a bug in UseJava.cmake that causes CMAKE_JAVA_LIBRARY_OUTPUT_PATH=/
# HACK This is an absolute path, and unusable. As a hack, use . instead
endmacro(javah)
javah(jwiringX "eu.jm0.wiringX.wiringX")
# End of libalexandria
# TODO: create a FindJavah module to properly search for the javah binary

# C part
set(wiringx-java_SOURCES
	eu_jm0_wiringX_wiringX.h
	gdbserver.c
	jlogconsumer.c
	jlogconsumer.h
	jni-util.c
	jni-util.h
	jwiringx.c
	jwiringx_gpio.c
	jwiringx_i2c.c
	jwiringx_serial.c
	jwiringx_spi.c
)

add_library(wiringx-java MODULE ${wiringx-java_SOURCES})

set_property(SOURCE eu_jm0_wiringX_wiringX.h PROPERTY GENERATED TRUE)
add_dependencies(wiringx-java javah_jwiringX)

target_include_directories(wiringx-java PRIVATE ${JNI_INCLUDE_DIRS} ${wiringX_INCLUDE_DIRS})
target_link_libraries(wiringx-java ${JNI_LIBRARIES} ${wiringX_LIBRARIES})

install(TARGETS wiringx-java LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
