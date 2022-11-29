all: LIBMX create_libmx

LIBMX:
	mkdir obj
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -c -gdwarf-4 src/*.c
	mv *.o obj/
	
create_libmx:
	ar -rc libmx.a obj/*.o
	ranlib libmx.a
	
clean:
	rm -rf obj
	
uninstall:
	rm -rf obj
	rm -rf libmx.a
	
reinstall:
	make uninstall
	make
