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

// helper macro for value range check
#define RANGE_CHECK(var, min, max) (var < min || var > max)
#define RANGE_CHECK2(var1, var2, min, max) (RANGE_CHECK(var1, min, max) || RANGE_CHECK(var2, min, max))
#define RANGE_CHECK3(var1, var2, var3, min, max) (RANGE_CHECK2(var1, var2, min, max) || RANGE_CHECK(var3, min, max))

jint Java_eu_jm0_wiringX_wiringX_I2CRead(JNIEnv * env, jclass class, jint fd) {
	// check arguments for valid range
	if(RANGE_CHECK(fd, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXI2CRead((int)fd);
}

jint Java_eu_jm0_wiringX_wiringX_I2CReadReg8(JNIEnv * env, jclass class, jint fd, jint reg) {
	// check arguments for valid range
	if(RANGE_CHECK2(fd, reg, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXI2CReadReg8((int)fd, (int)reg);
}

jint Java_eu_jm0_wiringX_wiringX_I2CReadReg16(JNIEnv * env, jclass class, jint fd, jint reg) {
	// check arguments for valid range
	if(RANGE_CHECK2(fd, reg, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXI2CReadReg16((int)fd, (int)reg);
}

jint Java_eu_jm0_wiringX_wiringX_I2CWrite(JNIEnv * env, jclass class, jint fd, jint data) {
	// check arguments for valid range
	if(RANGE_CHECK2(fd, data, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXI2CWrite((int)fd, (int)data);
}

jint Java_eu_jm0_wiringX_wiringX_I2CWriteReg8(JNIEnv * env, jclass class, jint fd, jint reg, jint data) {
	// check arguments for valid range
	if(RANGE_CHECK3(fd, reg, data, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXI2CWriteReg8((int)fd, (int)reg, (int)data);
}

jint Java_eu_jm0_wiringX_wiringX_I2CWriteReg16(JNIEnv * env, jclass class, jint fd, jint reg, jint data) {
	// check arguments for valid range
	if(RANGE_CHECK3(fd, reg, data, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXI2CWriteReg16((int)fd, (int)reg, (int)data);
}

jint Java_eu_jm0_wiringX_wiringX_I2CSetup(JNIEnv * env, jclass class, jstring path, jint deviceID) {
	// check arguments for valid range
	if(RANGE_CHECK(deviceID, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// create UTF-8 encoded C-string from given jstring
	const char *pathc = (*env)->GetStringUTFChars(env, path, NULL);
	if(pathc == NULL) {
		// allocating a C-String failed!
		// at this point an exception should have already been thrown.
		// The return value is now irrelevant.
		return 0;
	}

	// call original function
	int r = wiringXI2CSetup(pathc, (int)deviceID);

	// free previously created C-string
	(*env)->ReleaseStringUTFChars(env, path, pathc);

	// return result
	return r;
}
