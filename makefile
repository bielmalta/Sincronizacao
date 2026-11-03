
sync_car: sync_car.o sync_car-runner.o
	gcc sync_car.o sync_car-runner.o -o sync_car -pthread

sync_car.o: sync_car.c sync_car.h
	gcc -Wall -Wextra -std=c11 -D_DEFAULT_SOURCE -pthread -c sync_car.c -o sync_car.o

sync_car-runner.o: sync_car-runner.c sync_car.h
	gcc -Wall -Wextra -std=c11 -D_DEFAULT_SOURCE -pthread -c sync_car-runner.c -o sync_car-runner.o

clean:
	rm -f sync_car.o sync_car-runner.o sync_car
