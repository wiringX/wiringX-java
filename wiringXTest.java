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

import org.junit.Test;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertEquals;

public class wiringXTest {
    public static void main(String[] args) {
        wiringX.delayMicroseconds(50000);
    }

    @Test
    public void delayMicroseconds_ValidArg() {
        long interval = 1*1000*1000;

        long before = System.nanoTime();
        wiringX.delayMicroseconds(interval);
        long after = System.nanoTime();

        assertTrue(after - before >= interval);
    }

    @Test(expected = java.lang.IllegalArgumentException.class)
    public void delayMicroseconds_InvalidArg_Negative() {
        // negative
        wiringX.delayMicroseconds(-1);
    }

    @Test(expected = java.lang.IllegalArgumentException.class)
    public void delayMicroseconds_InvalidArg_OutOfRange() {
        // out of range
        wiringX.delayMicroseconds(Long.MAX_VALUE);
    }

    @Test
    public void Setup() {
        int r;
        LogConsumer logger = (int prio, String message) -> {};

        // invalid platform
        r = wiringX.Setup("", logger);
        assertNotEquals(0, r);

        // valid platform
        r = wiringX.Setup("pcduino1", logger);
        assertEquals(0, r);
    }
}
