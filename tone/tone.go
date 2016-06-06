package tone

// #include "tone.h"
// #include "../melody.h"
import "C"

func init() {
	C.init()
}

func GetSong() [256]C.struct_note {
	return C.song
}

func PlaySong(song [256]C.struct_note) {
	for _,note := range song {
		if (note.tone == C.END) { break }
		C.playNote(note)
		C.stopTone()
	}
}
