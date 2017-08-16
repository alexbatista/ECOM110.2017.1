BUILD_DIR=build
SOURCES = main.c circular_buffer.c

test: $(SOURCES:.c=.o)
	$(CC) $^ -o $@

dir:
	mkdir -p $(BUILD_DIR)

.c.o:
	$(COMPILE.c) -o $@ $<

clean:
	$(RM) test
	$(RM) -r $(BUILD_DIR)
