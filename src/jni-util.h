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

jobject create(JNIEnv *env, const char *classpath);

void throw_new_exception(JNIEnv *env, const char *classname, const char *message);
void throw_new_exception_cached(JNIEnv *env, const char *classname, const char *message, enum cache_entry entry);

// helper macros for value range check
#define RANGE_CHECK(var, min, max) (var < min || var > max)
#define RANGE_CHECK2(var1, var2, min, max) (RANGE_CHECK(var1, min, max) || RANGE_CHECK(var2, min, max))
#define RANGE_CHECK3(var1, var2, var3, min, max) (RANGE_CHECK2(var1, var2, min, max) || RANGE_CHECK(var3, min, max))
