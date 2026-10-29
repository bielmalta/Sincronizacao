sync_car: sync_car.o
	gcc sync_car.o -o sync_car -pthread

sync_car.o: sync_car.c
	gcc -Wall -Wextra -std=c11 -pthread -c sync_car.c -o sync_car.o

clean:
	rm -f sync_car.o sync_car