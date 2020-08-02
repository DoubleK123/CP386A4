# Do not edit the contents of this file.
warnings_BAD: *.c
	gcc -Werror -Wall -g -std=gnu99 -o assignment_4 *.c -lrt
	
warnings_OK: *.c
	gcc -Wall -g -std=gnu99 -o assignment_4 *.c 
	
clean: *.c
	rm assignment_4
