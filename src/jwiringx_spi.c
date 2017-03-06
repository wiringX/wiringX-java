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
#include <stdint.h>

// malloc/free
#include <stdlib.h>

// the real wiringX
#include <wiringX.h>

/*
 * Most platforms today have char as an 8 bit wide type.
 * However there are weird platforms which cannot easily be supported.
 */
#if CHAR_BIT != 8
#error size of char is not 8
#endif

jint Java_eu_jm0_wiringX_wiringX_SPIGetFd(JNIEnv *env, jclass class, jint handle) {
	// check arguments for valid range
	if(RANGE_CHECK(handle, 0, UINT8_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXSPIGetFd((uint8_t)handle);
}

jint Java_eu_jm0_wiringX_wiringX_SPIDataRW(JNIEnv *env, jclass class, jint handle, jbyteArray data) {
	// check arguments for valid range
	if(RANGE_CHECK(handle, 0, UINT8_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// check that data exists
	if(data == NULL) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/NullPointerException", "data must not be null", CACHE_CLASS_java_lang_NullPointerException);

		// return to java, return value will be ignored
		return 0;
	}

	// retrieve data size
	jint len = (*env)->GetArrayLength(env, data);

	// map data to C array
	jbyte *datac = (*env)->GetByteArrayElements(env, data, NULL);
	if(datac == NULL) {
		// exception was thrown already, return to java
		return 0;
	}

	// call original function
	// data is to be treated unsigned, Java code must perform the necessary transformations
	int r = wiringXSPIDataRW((uint8_t)handle, (unsigned char *)datac, (int)len);

	// write back changes and release C array
	(*env)->ReleaseByteArrayElements(env, data, datac, JNI_COMMIT);

	// deliver result
	return r;
}

jint Java_eu_jm0_wiringX_wiringX_SPISetup(JNIEnv *env, jclass class, jint device, jint channel, jint speed) {
	// check arguments for valid range
	if(RANGE_CHECK2(device, channel, 0, UINT8_MAX) || RANGE_CHECK(speed, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXSPISetup((uint8_t)device, (uint8_t)channel, (int)speed);
}
