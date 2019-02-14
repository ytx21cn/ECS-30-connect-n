connectn.out : connectN.o board.o game_play.o input_validation.o check.o
	gcc -g -o connectn.out connectN.o board.o game_play.o input_validation.o check.o

connectN.o : connectN.c
	gcc -g -c -Wall -Werror connectN.c
	
board.o : board.c board.h
	gcc -g -c -Wall -Werror board.c

game_play.o : game_play.c game_play.h
	gcc -g -c -Wall -Werror game_play.c
	
input_validation.o : input_validation.c input_validation.h
	gcc -g -c -Wall -Werror input_validation.c

check.o : check.c check.h
	gcc -g -c -Wall -Werror check.c

clean:
	rm *.o connectn.out .fuse*
