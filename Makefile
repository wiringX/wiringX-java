CC=gcc
CFLAGS=-fPIC -g -I/usr/lib64/jvm/java/include -I/usr/lib64/jvm/java/include/linux
LDFLAGS=-lwiringX
OBJECTS=gdbserver.o jlogconsumer.o jni-util.o jwiringx.o jwiringx_gpio.o jwiringx_i2c.o jwiringx_serial.o jwiringx_spi.o

JAVAC=javac
JAVACP=.:/usr/share/java/junit.jar

# generic targets
all: libwiringX_java.so

test: all wiringXTest.class
	LD_LIBRARY_PATH=. java -cp $(JAVACP) org.junit.runner.JUnitCore wiringXTest

clean:
	rm -fv *.so *.o *.class jwiringx.h

# shared target rules
%.class: %.java
	$(JAVAC) -cp $(JAVACP) $<

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

# specific target rules
jwiringx.h: wiringX.class
	javah -o jwiringx.h wiringX

libwiringX_java.so: $(OBJECTS)
	$(CC) -shared -shared $(LDFLAGS) -o $@ $^
