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

#include "jni-util.h"

jobject create(JNIEnv *env, const char *classpath) {
	jobject result;

	// look-up class
	jclass class = (*env)->FindClass(env, classpath);
	if(class == NULL)
		return NULL;

	// look-up constructor
	jmethodID cid = (*env)->GetMethodID(env, class, "<init>", "()V");
	if(cid == NULL)
		return NULL;

	// create object
	result = (*env)->NewObject(env, class, cid);

	// free local resources
	(*env)->DeleteLocalRef(env, class);

	// done
	return result;
}

void throw_new_exception(JNIEnv *env, const char *classname, const char *message, jclass *cachevar) {
	// lookup class from cache variable, if any
	jclass class = NULL;
	if(cachevar && *cachevar) {
		class = *cachevar;
	} else {
		class = (*env)->FindClass(env, classname);

		if(class == NULL) {
			// classnotfound
			// exception already thrown
			return;
		}

		// store class in cache variable, if any
		if(cachevar) {
			// refcount object for later use
			class = (*env)->NewGlobalRef(env, class);
			*cachevar = class;
		}
	}

	// throw it
	(*env)->ThrowNew(env, class, message);
}

// class cache variables
jclass classcache_classcastexception = NULL;
jclass classcache_enumconstantnotpresentexception = NULL;
jclass classcache_illegalargumentexception = NULL;
