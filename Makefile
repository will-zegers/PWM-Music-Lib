CC=gcc
SOURCES=main.c tone/tone.c
EXECUTABLE=pwmSong

all:
	$(CC) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm pwmSong
