package main

import (
	t "./tone"
)

import "C"

func main() {
	t.PlayNote(20)
	t.PlayNote(21)
	t.PlayNote(22)
	t.PlayNote(23)
//	t.PlaySong(20, t.GetSong(), nil )
}
