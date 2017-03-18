package eu.jm0.wiringX;

import java.lang.IllegalArgumentException;

/*
 * In C:
 * unsigned 0 maps to signed 0
 * unsigned 127 maps to signed 127
 * unsigned 128 maps to signed -128
 * unsigned 255 maps to signed -1
 * 
 * --> implement overflow at 128
 */
public class UByte {
	private final static short MAX_VALUE = (Byte.MAX_VALUE - Byte.MIN_VALUE);
	private byte b;

	public UByte(short value) {
		Set(value);
	}

	public void Set(short value) {
		if(value < 0 || value > MAX_VALUE) {
			throw new IllegalArgumentException("Value out of Range");
		}

		/* make explicit use of integer overflow beyond Byte.MAX_VALUE */
		if(value > 127) {
			b = 127;
			b += (value - 127);
		} else {
			b = (byte)value;
		}
	}

	public short Get() {
		short r = b;
		if(r < 0) {
			r += 256;
		}
		return r;
	}

	public byte raw() {
		return b;
	}
}
