package tone

// #include "tone.h"
// #include "melody.h"
// #include "unistd.h"
import "C"

func init() {
	C.init()
}

func GetSong() [1024]C.struct_note {
	return C.song
}

func PlayNote(idx int) {
	note := GetSong()[idx]
	if (note.tone != C.PASS) {
		if (note.tone == C.R) {
			C.rest()
		} else {
			C.playTone( (note.tone) )
		}
		C.usleep( C.__useconds_t(note.beat) )
		C.stopTone()
	}
}

func PlaySong(song [1024]C.struct_note) {
	for _,note := range song {
		C.playNote(note)
	}
}
