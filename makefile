CC = gcc
CFLAGS = -c
LIBS = -lX11

all: exe

exe: app.o janela.o graficos.o entrada_dados.o
	$(CC) app.o janela.o graficos.o entrada_dados.o -o exe $(LIBS)

app.o: app.c
	$(CC) $(CFLAGS) app.c

janela.o: janela.c
	$(CC) $(CFLAGS) janela.c

graficos.o: graficos.c
	$(CC) $(CFLAGS) graficos.c

entrada_dados.o: entrada_dados.c
	$(CC) $(CFLAGS) entrada_dados.c

clean:
	rm exe *.o 
