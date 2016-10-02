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

#include <jni.h>
#include <stdlib.h>

#include "jlogconsumer.h"

// utlity functions
#include "jni-util.h"

struct logger {
	JNIEnv *env;
	jobject obj;
	jmethodID mid;
} l = {0};

int registerLogConsumer(JNIEnv *env, jobject obj) {
	// if already registered, clean up first
	deregisterLogConsumer();

	// look up expected class
	static jclass class = NULL;
	if(!class) {
		class = (*env)->FindClass(env, "eu/jm0/wiringX/LogConsumer");
		if(class == NULL) {
			// classnotfound
			// exception should have been thrown
			return -1;
		}
		// refcount object for later use
		class = (*env)->NewGlobalRef(env, class);
	}

	// check for expected interface type
	if(!(*env)->IsInstanceOf(env, obj, class)) {
		// throw exception
		throw_new_exception(env, "java/lang/ClassCastException", "Not an instance of LogConsumer", &classcache_classcastexception);

		// return with failure
		return -1;
	}

	// lookup method (int, String)
	jmethodID mid = (*env)->GetMethodID(env, class, "accept", "(ILjava/lang/String;)V");
	if(mid == NULL) {
		// methodnotound
		// exception should have been thrown
		return -1;
	}

	// store handles
	l.env = env;
	l.obj = (*env)->NewGlobalRef(env, obj);
	l.mid = mid;

	// all good
	return 0;
}

void deregisterLogConsumer() {
	// is there anzthing to free?
	if(l.env == NULL)
		// apparently not
		return;

	// free references
	(*l.env)->DeleteGlobalRef(l.env, l.obj);

	// set 0
	l.env = NULL;
	l.obj = NULL;
	l.mid = NULL;
}

void logconsumerhandler(int prio, const char * format, ...) {
	va_list args;

	// calculate out string length
	va_start (args, format);
	int length = vsnprintf(NULL, 0, format, args);
	va_end(args);

	// allocate c-string
	char *messagec = (char *)malloc(length+1);
	// TODO: check if allocation worked

	// build actual message string
	va_start (args, format);
	vsprintf(messagec, format, args);
	va_end(args);

	// free vararg list
	va_end(args);

	// create Java string
	jstring message = (*l.env)->NewStringUTF(l.env, messagec);
	if(message == NULL) {
		// not good, allocating string failed
		// return to C
		// TODO: check what happens to exception
		free(messagec);
		return;
	}

	// free c-string
	free(messagec);

	// call registered java function
	(*l.env)->CallVoidMethod(l.env, l.obj, l.mid, (jint)prio, message);
	if((*l.env)->ExceptionCheck(l.env)) {
		// an exception occured
		return;
	}

	// done
	return;
}
