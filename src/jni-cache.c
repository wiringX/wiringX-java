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

// JNI
#include <jni.h>

// declarations
#include "jni-cache.h"

// actual cache
jobject cache[CACHE_MAX] = {NULL};

jobject cache_get(enum cache_entry entry) {
	return cache[entry];
}

void cache_put(JNIEnv *env, enum cache_entry entry, jobject obj) {
	cache[entry] = (*env)->NewGlobalRef(env, obj);
}

void cache_delete(JNIEnv *env, enum cache_entry entry) {
	jobject obj = cache[entry];
	if(obj) {
		(*env)->DeleteGlobalRef(env, obj);
		cache[entry] = NULL;
	}
}

void cache_clear(JNIEnv *env) {
	for(size_t i = 0; i < CACHE_MAX; i++) {
		cache_delete(env, i);
	}
}
