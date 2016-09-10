CC=gcc
CFLAGS=-fPIC -g -I/usr/lib64/jvm/java/include -I/usr/lib64/jvm/java/include/linux
LDFLAGS=-lwiringX
OBJECTS=gdbserver.o jlogconsumer.o jni-util.o jwiringx.o jwiringx_gpio.o jwiringx_i2c.o jwiringx_serial.o jwiringx_spi.o

JAVAC=javac
JAVACP=.:/usr/share/java/junit.jar

# generic targets
all: libwiringX_java.so

test: all eu/jm0/wiringX/wiringXTest.class
	LD_LIBRARY_PATH=. java -cp $(JAVACP) org.junit.runner.JUnitCore eu.jm0.wiringX.wiringXTest

clean:
	rm -fv *.so *.o *.class jwiringx.h

# shared target rules
%.class: %.java
	$(JAVAC) -cp $(JAVACP) $<

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

# specific target rules
jwiringx.h: eu/jm0/wiringX/wiringX.class
	javah -o jwiringx.h eu.jm0.wiringX.wiringX

libwiringX_java.so: $(OBJECTS)
	$(CC) -shared -shared $(LDFLAGS) -o $@ $^
