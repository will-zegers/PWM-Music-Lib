#include "stdio.h"
#include "stdlib.h"
#include "tone.h"
#include "melody.h"

int main(int argc, char* argv[]) {

	init();

	playSong(song, sizeof(song) );
	
	cleanUp();

	return 0;
}
