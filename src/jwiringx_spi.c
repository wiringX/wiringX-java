/*
 * MIT License
 * 
 * Copyright (c) 2016 Josua Mayer <josua.mayer97@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// generated JNI declerations
#include "eu_jm0_wiringX_wiringX.h"

// object cache
#include "jni-cache.h"

// utlity functions
#include "jni-util.h"

// limits for converting numeric types
#include <limits.h>

// the real wiringX
#include <wiringX.h>

jint Java_eu_jm0_wiringX_wiringX_SPIGetFd(JNIEnv *env, jclass class, jint channel) {
	// check arguments for valid range
	if(RANGE_CHECK(channel, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXSPIGetFd((int)channel);
}

jint Java_eu_jm0_wiringX_wiringX_SPIDataRW(JNIEnv *env, jclass class, jint channel, jbyteArray data) {
	// check arguments for valid range
	if(RANGE_CHECK(channel, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	/*
	 * Most platforms today have char as an 8 bit wide type.
	 * However there are weird platforms which cannot easily be supported.
	 */
#	if CHAR_BIT != 8
#		error size of char is not 8
#	endif

	// map data to a C array jbyte
	jbyte *datac = (*env)->GetByteArrayElements(env, data, NULL);
	if(!datac) {
		// an exception occured
		// return to java, return value will be ignored
		return 0;
	}

	// retrieve array size
	jint len = (*env)->GetArrayLength(env, data);

	// call original function
	// jbyte currently maps to signed char, which is compatible to unsigned char
	return wiringXSPIDataRW((int)channel, (unsigned char *)datac, (int)len);
}

jint Java_eu_jm0_wiringX_wiringX_SPISetup(JNIEnv *env, jclass class, jint channel, jint speed) {
	// check arguments for valid range
	if(RANGE_CHECK2(channel, speed, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXSPISetup((int)channel, (int)speed);
}
