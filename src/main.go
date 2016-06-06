package main

import (
	t "./tone"
)

import "C"

func main() {
	t.PlaySong(t.GetSong(), nil )
}
