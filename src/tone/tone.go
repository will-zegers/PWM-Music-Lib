package tone

// #include "tone.h"
// #include "../melody.h"
// #include "unistd.h"
import "C"

import (
	"net"
	"encoding/binary"
)

func init() {
	C.init()
}

func GetSong() [1024]C.struct_note {
	return C.song
}

func PlaySong(song [1024]C.struct_note, Conn *net.UDPConn) {
	for i,note := range song {
		if (note.tone == C.END) { break }
		if (note.tone == C.R) {
			C.rest() 
		} else {
			C.playTone(note.tone)
		}
		go func() {
			buf := make([]byte, 64)
			binary.PutVarint(buf, int64(i) )
			Conn.Write(buf)
		}()
		C.usleep( C.__useconds_t(note.beat) )
		C.stopTone()
	}
}
