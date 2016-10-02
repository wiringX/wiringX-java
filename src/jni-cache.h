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

/*
 * This is an object cache for JNI objects
 * It creates, stores and frees global references to objects
 */

enum cache_entry {
	// Exceptions
	CACHE_CLASS_java_lang_ClassCastException,
	CACHE_CLASS_java_lang_EnumConstantNotPresentException,
	CACHE_CLASS_java_lang_IllegalArgumentException,

	// internal classes
	CACHE_CLASS_eu_jm0_wiringX_DigitalValue,
	CACHE_CLASS_eu_jm0_wiringX_ISRMode,
	CACHE_CLASS_eu_jm0_wiringX_LogConsumer,
	CACHE_CLASS_eu_jm0_wiringX_PinMode,

	// last entry to determine size
	CACHE_MAX
};

/*
 * read given entry from cache
 * may return NULL
 */
jobject cache_get(enum cache_entry entry);

/*
 * stores a global reference to given object in given cache entry
 * will overwrite anything in the cache
 */
void cache_put(JNIEnv *env, enum cache_entry entry, jobject obj);

/*
 * deletes global reference stored in given cache entry
 * does nothing when cache entry is already empty
 */
void cache_delete(JNIEnv *env, enum cache_entry entry);

/*
 * deletes all entries in the cache
 */
void cache_clear(JNIEnv *env);
