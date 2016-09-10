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
#include "jwiringx.h"

// logconsumer implementation
#include "jlogconsumer.h"

// the real wiringX
#include <wiringX.h>

// limits for converting numeric types
#include <limits.h>

// variadics
#include <stdarg.h>

jint Java_wiringX_Setup(JNIEnv *env, jclass c, jstring platform, jobject logger) {
    // create UTF-8 encoded C-string from given platform string
    const char *platformc = (*env)->GetStringUTFChars(env, platform, NULL);
    if(platformc == NULL) {
        // allocating a C-String failed!
        // at this point an exception should have already been thrown.
        // The return value is now irrelevant.
        return 0;
    }

    // register logger, if any
    void *handler = NULL;
    if(logger != NULL) {
        int r = registerLogConsumer(env, logger);
        if(r != 0) {
            // unexpected failure
            // exceptions have already been thrown
            return -1;
        }

        // looks good
        handler = &logconsumerhandler;
    }

    // call original function
    int r = wiringXSetup((char *)platformc, handler);

    // free resources
    (*env)->ReleaseStringUTFChars(env, platform, platformc);
    
    // return result
    return r;
}

void Java_wiringX_GC(JNIEnv *env, jclass c) {
    // call original function
    wiringXGC();

    // free handle on logger
    deregisterLogConsumer();
}

// Utility

jstring Java_wiringX_Platform(JNIEnv *env, jclass c) {
    // call original function
    const char *platformnamec = wiringXPlatform();

    // create new string object
    jstring platformname = (*env)->NewStringUTF(env, platformnamec);
    if(platformname == NULL) {
        // not good, allocating string failed
        // exception already thrown, return to java
        return NULL;
    }

    // all good, return string
    return platformname;
}

void Java_wiringX_delayMicroseconds(JNIEnv *env, jclass c, jlong delay) {
    // check arguments for valid value-range (unsigned int)
    if(delay < 0 || delay > UINT_MAX) {
        // lookup exception class
        jclass illegalargumentexceptionclass = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        if(illegalargumentexceptionclass == NULL)
            return;

        // throw it
        (*env)->ThrowNew(env, illegalargumentexceptionclass, "Value out of Range");
        // TODO: check return-value

        // free exception class reference
        (*env)->DeleteLocalRef(env, illegalargumentexceptionclass);
        
        // return to java
        return;
    }

    // call original function
    delayMicroseconds((int)delay);
}

jint Java_wiringX_SelectableFd(JNIEnv *env, jclass c, jint pin) {
    return (jint)wiringXSelectableFd((int)pin);
}

