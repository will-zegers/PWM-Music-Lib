package main

import (
	t "tone/tone"
)

import "C"

func main() {
	t.PlaySong(t.GetSong() )
}
