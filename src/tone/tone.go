package tone

// #include "tone.h"
// #include "melody.h"
// #include "unistd.h"
import "C"

func ini() {
	C.init()
}

func GetSong() []C.struct_note {
	return C.song
}

func GetSongAt(idx int) []C.struct_note {
	return C.song[idx:]
}

func PlayNote(idx int) {
	note := GetSong()[idx]
	if (note.tone == C.R) {
		C.rest()
	} else {
		C.playTone( (note.tone) )
	}
	C.usleep( C.__useconds_t(note.beat) )
}

func PlaySong(song []C.struct_note) {
	for _,note := range song {
		C.stopTone()
		C.playNote(note)
	}
	C.stopTone()
}
