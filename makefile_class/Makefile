hello:  main.o f1.o f2.o f3.o f4.o
	@echo 'CC = ' $(CC)
	@echo '@ = ' $@
	@echo '? = ' $?
	@echo $< , $^
	$(CC) $^ -o $@

clean:
	$(RM) hello *.o
