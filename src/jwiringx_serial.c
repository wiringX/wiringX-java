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

/*
 * Most platforms today have char as an 8 bit wide type.
 * However there are weird platforms which cannot easily be supported.
 */
#if CHAR_BIT != 8
#error size of char is not 8
#endif

jint Java_eu_jm0_wiringX_wiringX_wiringXSerialOpen(JNIEnv *env, jclass class, jstring device, jobject config) {
	// create UTF-8 encoded C-string from given jstring
	const char *devicec = (*env)->GetStringUTFChars(env, device, NULL);
	if(devicec == NULL) {
		// allocating a C-String failed!
		// at this point an exception should have already been thrown.
		// The return value is now irrelevant.
		return 0;
	}

	// get SerialConfig class from cache
	jclass scclass = cache_get(CACHE_CLASS_eu_jm0_wiringX_SerialConfig);
	if(!scclass) {
		// look-up class
		scclass = (*env)->FindClass(env, "eu/jm0/wiringX/SerialConfig");
		if(scclass == NULL) {
			// exception was thrown, return to java
			return 0;
		}
		// store in cache for later use
		cache_put(env, CACHE_CLASS_eu_jm0_wiringX_SerialConfig, class);
	}

	// check type
	if(!(*env)->IsInstanceOf(env, config, scclass)) {
		// type mismatch, throw exception
		throw_new_exception_cached(env, "java/lang/ClassCastException", "Not an instance of PinMode", CACHE_CLASS_java_lang_ClassCastException);

		// return to java, return value will be ignored
		return 0;
	}

	// look-up fields
	jfieldID fbaud = (*env)->GetFieldID(env, scclass, "baud", "TODO");
	jfieldID fdatabits = (*env)->GetFieldID(env, scclass, "databits", "TODO");
	jfieldID fparity = (*env)->GetFieldID(env, scclass, "parity", "TODO");
	jfieldID fstopbits = (*env)->GetFieldID(env, scclass, "stopbits", "TODO");
	jfieldID fflowcontrol = (*env)->GetFieldID(env, scclass, "flowcontrol", "TODO");

	// retrieve data from fields
	jint baud = (*env)->GetIntField(env, config, fbaud);
	jint databits = (*env)->GetIntField(env, config, fdatabits);
	jint parity = (*env)->GetIntField(env, config, fparity);
	jint stopbits = (*env)->GetIntField(env, config, fstopbits);
	jint flowcontrol = (*env)->GetIntField(env, config, fflowcontrol);

	// check fields for valid range
	if(RANGE_CHECK5(baud, databits, parity, stopbits, flowcontrol, 0, UINT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// create native wiringXSerial_t type from fields
	struct wiringXSerial_t configc;
	configc.baud = (unsigned int)baud;
	configc.databits = (unsigned int)databits;
	configc.parity = (unsigned int)parity;
	configc.stopbits = (unsigned int)stopbits;
	configc.flowcontrol = (unsigned int)flowcontrol;

	// call original function
	int r = wiringXSerialOpen(devicec, configc);

	// free previously created C-string
	(*env)->ReleaseStringUTFChars(env, device, devicec);

	// return result
	return r;
}

void Java_eu_jm0_wiringX_wiringX_wiringXSerialFlush(JNIEnv *env, jclass class, jint fd) {
	// check arguments for valid range
	if(RANGE_CHECK(fd, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java
		return;
	}

	// call original function
	wiringXSerialFlush((int)fd);
}

void Java_eu_jm0_wiringX_wiringX_wiringXSerialClose(JNIEnv *env, jclass class, jint fd) {
	// check arguments for valid range
	if(RANGE_CHECK(fd, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java
		return;
	}

	// call original function
	wiringXSerialClose((int)fd);
}

void Java_eu_jm0_wiringX_wiringX_wiringXSerialPutChar(JNIEnv *env, jclass class, jint fd, jbyte data) {
	// check arguments for valid range
	if(RANGE_CHECK(fd, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java
		return;
	}
	// jbyte is signed char, no range check required

	// call original function
	wiringXSerialPutChar(fd, (unsigned char)data);
}

void Java_eu_jm0_wiringX_wiringX_wiringXSerialPuts(JNIEnv *env, jclass class, jint fd, jstring data) {
	// check arguments for valid range
	if(RANGE_CHECK(fd, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java
		return;
	}

	// create UTF-8 encoded C-string from given jstring
	const char *datac = (*env)->GetStringUTFChars(env, data, NULL);
	if(datac == NULL) {
		// allocating a C-String failed!
		// at this point an exception should have already been thrown.
		return;
	}

	// call original function
	wiringXSerialPuts(fd, datac);

	// free previously created C-string
	(*env)->ReleaseStringUTFChars(env, data, datac);
}

void Java_eu_jm0_wiringX_wiringX_wiringXSerialPrintf(JNIEnv *env, jclass class, jint fd, jstring format, jobjectArray args) {
	// check arguments for valid range
	if(RANGE_CHECK(fd, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java
		return;
	}

	// TODO figure out how this should be implemented. C-style format? Java-style format?
	// perhaps it is best to perform the format parsing in java, and then use puts with the result.
	throw_new_exception_cached(env, "java/lang/UnsupportedOperationException", "Not yet implemented", CACHE_CLASS_java_lang_UnsupportedOperationException);
}

jint Java_eu_jm0_wiringX_wiringX_wiringXSerialDataAvail(JNIEnv *env, jclass class, jint fd) {
	// check arguments for valid range
	if(RANGE_CHECK(fd, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXSerialDataAvail((int)fd);
}

jint Java_eu_jm0_wiringX_wiringX_wiringXSerialGetChar(JNIEnv *env, jclass class, jint fd) {
	// check arguments for valid range
	if(RANGE_CHECK(fd, INT_MIN, INT_MAX)) {
		// throw exception
		throw_new_exception_cached(env, "java/lang/IllegalArgumentException", "Value out of Range", CACHE_CLASS_java_lang_IllegalArgumentException);

		// return to java, return value will be ignored
		return 0;
	}

	// call original function
	return wiringXSerialGetChar((int)fd);
}
