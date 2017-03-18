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
public class UByteArray {
	private byte[] b;
	
	public UByteArray(int size) {
		b = new byte[size];
	}

	public void Set(int index, short value) {
		if(value < 0 || value > Byte.MAX_VALUE - Byte.MIN_VALUE) {
			throw new IllegalArgumentException("Value out of Range");
		}

		/* make explicit use of integer overflow beyond Byte.MAX_VALUE */
		if(value > 127) {
			b[index] = 127;
			b[index] += (value - 127);
		} else {
			b[index] = (byte)value;
		}
	}

	public short Get(int index) {
		short r = b[index];
		if(r < 0) {
			r += 256;
		}
		return r;
	}

	public byte[] raw() {
		return b;
	}
}
