package main

import (
	t "tone/src/tone"
)

import "C"

func main() {
	t.PlaySong(t.GetSong() )
}
