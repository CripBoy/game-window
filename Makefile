 OBJS = src/window.c src/util.c

build:
	gcc -o app main.c $(OBJS) -lgdi32