package eu.jm0.wiringX;

import java.lang.IllegalArgumentException;

public class UByte {
	private byte b;
	
	public UByte(short value) {
		Set(value);
	}

	public void Set(short value) {
		if(value < 0 || value > Byte.MAX_VALUE - Byte.MIN_VALUE) {
			throw new IllegalArgumentException("Value out of Range");
		}

		b = (byte) (value + Byte.MIN_VALUE);
	}

	public short Get() {
		short r = b;
		r -= Byte.MIN_VALUE;
		return r;
	}

	public byte raw() {
		return b;
	}
}
