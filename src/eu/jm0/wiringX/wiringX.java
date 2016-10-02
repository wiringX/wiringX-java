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

package eu.jm0.wiringX;

public class wiringX {
	// Init
	// TODO: use vararg and primitive type
	public static native int Setup(String platform, LogConsumer logger);
	public static native void GC();

	// Utility
	public static native String Platform();
	public static native void delayMicroseconds(long delay);
	public static native int SelectableFd(int fd);

	// GPIO
	public static native int ValidGPIO(int pin);
	public static native int pinMode(int pin, PinMode mode);
	public static native int digitalWrite(int pin, DigitalValue value);
	public static native int digitalRead(int pin);
	public static native int waitForInterrupt(int pin, int timeout);
	public static native int ISR(int pin, ISRMode mode);

	// I2C
	public static native int I2CRead(int fd);
	public static native int I2CReadReg8(int fd, int reg);
	public static native int I2CReadReg16(int fd, int reg);
	public static native int I2CWrite(int fd, int data);
	public static native int I2CWriteReg8(int fd, int reg, int data);
	public static native int I2CWriteReg16(int fd, int reg, int data);
	public static native int I2CSetup(String path, int deviceID);

	// SPI
	public static native int SPIGetFd(int channel);
	public static native int SPIDataRW(int channel, byte[] data);
	public static native int SPISetup(int channel, int speed);

	// Serial
	public static native int wiringXSerialOpen(String device, SerialConfig configuration);
	public static native void wiringXSerialFlush(int fd);
	public static native void wiringXSerialClose(int fd);
	public static native void wiringXSerialPutChar(int fd, byte data);
	public static native void wiringXSerialPuts(int fd, byte[] data);
	public static native void wiringXSerialPrintf(int fd, String format, Object... args);
	public static native int wiringXSerialDataAvail(int fd);
	public static native int wiringXSerialGetChar(int fd);

	// load native library when class gets loaded
	static {
		System.loadLibrary("wiringx-java");
	}
}
