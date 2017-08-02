hello:  main.c f1.o f2.o f3.o f4.o
	@echo '@ = ' $@
	@echo '? = ' $?
	$(CC) $? -o $@

.c.o:
	@echo '< = ' $<
	@echo '*.c = ' $*.c
	@echo '* = ' $*
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) hello *.o 
