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

# Try to find wiringX
# Once done this will define
#  wiringX_FOUND - System has JUnit
#  wiringX_INCLUDE_DIRS - The LibXml2 include directories
#  wiringX_LIBRARIES - The libraries needed to use wiringX

# wiringX has no dependencies

# find public header
find_path(wiringX_INCLUDE_DIR wiringX.h)

# find library
find_library(wiringX_LIBRARY wiringX)

# call magic cmake function
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(wiringX DEFAULT_MSG wiringX_INCLUDE_DIR wiringX_LIBRARY)

# hide internal variables
mark_as_advanced(wiringX_INCLUDE_DIR wiringX_LIBRARY)

# export results
set(wiringX_INCLUDE_DIRS ${wiringX_INCLUDE_DIR})
set(wiringX_LIBRARIES ${wiringX_LIBRARY})
