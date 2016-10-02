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

#include "jni-cache.h"
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

void throw_new_exception(JNIEnv *env, const char *classname, const char *message) {
	// look-up class
	jclass class = (*env)->FindClass(env, classname);

	if(class == NULL) {
		// classnotfound
		// exception already thrown
		return;
	}

	// throw it
	(*env)->ThrowNew(env, class, message);
}

void throw_new_exception_cached(JNIEnv *env, const char *classname, const char *message, enum cache_entry entry) {
	// get class from cache
	jclass class = cache_get(entry);
	if(class == NULL) {
		// look-up class
		class = (*env)->FindClass(env, classname);

		if(class == NULL) {
			// classnotfound
			// exception already thrown
			return;
		}

		// store in cache
		cache_put(env, entry, class);
	}

	// throw it
	(*env)->ThrowNew(env, class, message);
}
