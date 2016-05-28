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
import org.junit.Before;
import org.junit.After;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertEquals;

public class wiringXTest {
    // collect log
    StringBuilder sb = null;
    
    @Before
    public void Setup() {
        // create new log buffer
        sb = new StringBuilder();

        // setup wiringX for every test
        wiringX.Setup("pcduino1", (int prio, String message) -> sb.append("wiringX: PRIO " + prio + ": " + message + "\n"));
    }

    @After
    public void GC() {
        // clean up after every test
        wiringX.GC();

        // flush log buffer
        System.err.print(sb.toString());
        sb = null;
    }

    // Utility

    @Test
    public void Platform() {
        String platform = wiringX.Platform();
        assertEquals("pcduino1", platform);
    }
    
    @Test
    public void delayMicroseconds_ValidArg() {
        // check if delay is at least whats specified
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

    // GPIO

    @Test
    public void ValidGPIO() {
        wiringX.ValidGPIO(0);
    }

    @Test
    public void pinMode() {
        // ensure all possible values are accepted
        wiringX.pinMode(0, PinMode.NOT_SET);
        wiringX.pinMode(0, PinMode.INPUT);
        wiringX.pinMode(0, PinMode.OUTPUT);
        wiringX.pinMode(0, PinMode.INTERRUPT);
    }

    @Test
    public void digitalWrite() {
        wiringX.digitalWrite(0, DigitalValue.LOW);
        wiringX.digitalWrite(0, DigitalValue.HIGH);
    }

    @Test
    public void digitalRead() {
        wiringX.digitalRead(0);
    }

    @Test
    public void waitForInterrupt() {
        // timeout = 1s
        wiringX.waitForInterrupt(0, 1*1000);
    }

    @Test
    public void ISR() {
        wiringX.ISR(0, ISRMode.UNKNOWN);
        wiringX.ISR(0, ISRMode.RISING);
        wiringX.ISR(0, ISRMode.FALLING);
        wiringX.ISR(0, ISRMode.BOTH);
        wiringX.ISR(0, ISRMode.NONE);
    }
}
