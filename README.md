# PWM Music Library for embedded Linux systems
Implemented and tested on Beaglebone Black running Debian 8.4, kernel 4.4.11

## Setup
First, enable PWM on P9.22. Easiest way is to run the enable_pwm_P9.22 script included in this repo. Run ``make`` to build the sample song [Super Mario Brothers theme :)], which will place the *pwmSong* binary in the project folder.

Alternatively, there's some sample Go code and wrapper functions that access the underlying C library for application using the Go language. This can be built, for example, with a command like `go build main.go` (using the example *main.go* file). Note that since the application makes use of cgo, you *can't* use `go run main.go` (at least as far as a I can tell).

## Run
Currently, the program needs to be run as root since it accesses the pin files of the eLinux system. 

The present implementation just reads a song in *melody.h*, and plays through each note (composed of tones and beat) accordingly.
