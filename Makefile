OBJS = core/window.c

build:
	gcc -o app main.c $(OBJS) -lgdi32