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

	// check that array exists
	if(data == NULL) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/NullPointerException", "data must not be null", CACHE_CLASS_java_lang_NullPointerException);

		// return to java, return value will be ignored
		return 0;
	}

	// retrieve array size
	jint len = (*env)->GetArrayLength(env, data);

	// create temporary C array to hold data
	unsigned char *datac = malloc(len);
	if(datac == NULL) {
		throw_new_exception_cached(env, "java/lang/OutOfMemoryError", "Failed to allocate temporary C array", CACHE_CLASS_java_lang_OutOfMemoryError);

		// return to java, return value will be ignored
		return 0;
	}

	// copy data to temporary C array
	(*env)->GetByteArrayRegion(env, data, 0, len, (signed char *)datac);

	// transform signed to unsigned
	jint i;
	for(i = 0; i < len; i++) {
		datac[i] -= INT8_MIN;
	}

	// call original function
	int r = wiringXSPIDataRW((int)channel, (unsigned char *)datac, (int)len);

	// free temporary array
	free(datac);

	// deliver result
	return r;
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
