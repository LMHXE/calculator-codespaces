CC = g++
CFLAGS = -Wall -I./include
LDFLAGS = -L./lib -lmath_operations
BIN = calculator
LIB = libmath_operations.so

.PHONY: all clean install uninstall

all: $(LIB) $(BIN)

$(LIB): src/math_operations.cpp
	$(CC) -shared -fPIC $(CFLAGS) $^ -o lib/$@

$(BIN): src/main.cpp $(LIB)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) -Wl,-rpath=./lib

clean:
	rm -f $(BIN) lib/$(LIB)

install: all
	install -d /usr/local/lib
	install -d /usr/local/bin
	install lib/$(LIB) /usr/local/lib
	install $(BIN) /usr/local/bin
	ldconfig

uninstall:
	rm -f /usr/local/lib/$(LIB)
	rm -f /usr/local/bin/$(BIN)
	ldconfig

check:
	@echo "Проверка динамической библиотеки:"
	ldd $(BIN) | grep $(LIB)
	@echo "\nИнформация об авторе:"
	./$(BIN) author