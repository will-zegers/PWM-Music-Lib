#include "stdio.h"
#include "stdlib.h"
#include "tone/tone.h"
#include "tone/melody.h"

int main(int argc, char* argv[]) {

	init();

	playSong(song);
	
	cleanUp();

	return 0;
}
