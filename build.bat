@echo off
@SET FLAGS = "-lgdi32"

gcc -o app main.c -lgdi32
app