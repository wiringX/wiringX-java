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

// utlity functions
#include "jni-util.h"

// the real wiringX
#include <wiringX.h>

jint Java_eu_jm0_wiringX_wiringX_ValidGPIO(JNIEnv *env, jclass c, jint pin) {
    return (jint)wiringXValidGPIO((int)pin);
}

jint Java_eu_jm0_wiringX_wiringX_pinMode(JNIEnv *env, jclass c, jint pin, jobject mode) {
    // look-up PinMode class
    jclass class = (*env)->FindClass(env, "eu/jm0/wiringX/PinMode");
    if(class == NULL) {
        // exception was thrown, return to java
        return 0;
    }

    // check type
    if(!(*env)->IsInstanceOf(env, mode, class)) {
        // type mismatch, throw exception
        throw_new_exception(env, "java/lang/ClassCastException", "Not an instance of PinMode");\
        return 0;
    }

    // get ordinal method
    jmethodID mid = (*env)->GetMethodID(env, class, "ordinal", "()I");
    if(mid == NULL) {
        // methodnotfound
        // exception already thrown
        return 0;
    }

    // get ordinal value
    jint ordinal = (*env)->CallIntMethod(env, mode, mid);
    if((*env)->ExceptionCheck(env)) {
        // an exception occured
        return 0;
    }

    // convert to C enum
    // Java Ordinals start from 0 and go to N in order of declaration
    enum pinmode_t modec;
    switch(ordinal) {
        case 0: modec = PINMODE_NOT_SET; break;
        case 1: modec = PINMODE_INPUT; break;
        case 2: modec = PINMODE_OUTPUT; break;
        case 3: modec = PINMODE_INTERRUPT; break;
        default:
            // not good, throw an exception
            throw_new_exception(env, "java/lang/EnumConstantNotPresentException", "");
            return 0;
    }

    // call original function
    return (jint)pinMode((int)pin, modec);
}

jint Java_eu_jm0_wiringX_wiringX_digitalWrite(JNIEnv *env, jclass c, jint pin, jobject value) {
    // look-up DigitalValue class
    jclass class = (*env)->FindClass(env, "eu/jm0/wiringX/DigitalValue");
    if(class == NULL) {
        // exception was thrown, return to java
        return 0;
    }

    // check type
    if(!(*env)->IsInstanceOf(env, value, class)) {
        // type mismatch, throw exception
        throw_new_exception(env, "java/lang/ClassCastException", "Not an instance of DigitalValue");\
        return 0;
    }

    // get ordinal method
    jmethodID mid = (*env)->GetMethodID(env, class, "ordinal", "()I");
    if(mid == NULL) {
        // methodnotfound
        // exception already thrown
        return 0;
    }

    // get ordinal value
    jint ordinal = (*env)->CallIntMethod(env, value, mid);
    if((*env)->ExceptionCheck(env)) {
        // an exception occured
        return 0;
    }

    // convert to C enum
    // Java Ordinals start from 0 and go to N in order of declaration
    enum digital_value_t valuec;
    switch(ordinal) {
        case 0: valuec = LOW; break;
        case 1: valuec = HIGH; break;
        default:
            // not good, throw an exception
            throw_new_exception(env, "java/lang/EnumConstantNotPresentException", "");
            return 0;
    }

    // call original function
    return (jint)digitalWrite((int)pin, valuec);
}

jint Java_eu_jm0_wiringX_wiringX_digitalRead(JNIEnv *env, jclass c, jint pin) {
    return (jint)digitalRead((int)pin);
}

jint Java_eu_jm0_wiringX_wiringX_waitForInterrupt(JNIEnv *env, jclass c, jint pin, jint timeout) {
    return (jint)waitForInterrupt((int)pin, (int)timeout);
}

jint Java_eu_jm0_wiringX_wiringX_ISR(JNIEnv *env, jclass c, jint pin, jobject mode) {
    // look-up DigitalValue class
    jclass class = (*env)->FindClass(env, "eu/jm0/wiringX/ISRMode");
    if(class == NULL) {
        // exception was thrown, return to java
        return 0;
    }

    // check type
    if(!(*env)->IsInstanceOf(env, mode, class)) {
        // type mismatch, throw exception
        throw_new_exception(env, "java/lang/ClassCastException", "Not an instance of ISRMode");\
        return 0;
    }

    // get ordinal method
    jmethodID mid = (*env)->GetMethodID(env, class, "ordinal", "()I");
    if(mid == NULL) {
        // methodnotfound
        // exception already thrown
        return 0;
    }

    // get ordinal value
    jint ordinal = (*env)->CallIntMethod(env, mode, mid);
    if((*env)->ExceptionCheck(env)) {
        // an exception occured
        return 0;
    }

    // convert to C enum
    // Java Ordinals start from 0 and go to N in order of declaration
    enum isr_mode_t modec;
    switch(ordinal) {
        case 0: modec = ISR_MODE_UNKNOWN; break;
        case 1: modec = ISR_MODE_RISING; break;
        case 2: modec = ISR_MODE_FALLING; break;
        case 3: modec = ISR_MODE_BOTH; break;
        case 4: modec = ISR_MODE_NONE; break;
        default:
            // not good, throw an exception
            throw_new_exception(env, "java/lang/EnumConstantNotPresentException", "");
            return 0;
    }

    // call original function
    return (jint)wiringXISR((int)pin, modec);
}

