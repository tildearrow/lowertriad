/*
 * Copyright (c) 2016 tildearrow
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef INCLUDES_H
#define INCLUDES_H
#include <stdio.h>
#include <time.h>
#include <string>
#include <vector>
#include <stdarg.h>
#include <errno.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
// sorry. this program won't compile on windows anymore.
// at least until i get a new computer.
#include <sys/stat.h>
#include <unistd.h>
typedef std::string string;
#ifdef _WIN32
#error no.
const string DS="\\";
#else
const string DS="/";
#endif

#define COPYRIGHT "Copyright (c) 2016 tildearrow (and contributors)"

// NOTE: when making a release, change this value to:
// - 0: development version (devX)
// - 1: alpha version (alphaX)
// - 2: beta version (betaX)
// - 3: release candidate (vX.Y.Z-rcN)
// - 4: final release (vX.Y.Z)
// - 5: git release (git X) (avoid use if releasing please)
// - any other value results in (unknown)
#define vertype 5

#define devver 0
#define alphaver 0
#define betaver 0
#define relMajor 0
#define relMinor 0
#define relMinor2 0
#define relRC 0

// format version goes here
#define formatver 0

#endif
