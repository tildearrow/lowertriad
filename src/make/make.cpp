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
//#include "includes.h"
#include <stdio.h>
#include <sys/stat.h>
#include <string>
typedef std::string string;
struct stat tempstat;
string curfile;
FILE* f;

int filecopy(string dest, string src) {
  FILE* d;
  FILE* s;
  int c;
  d=fopen(dest.c_str(),"wb");
  if (!d) {
    return 1;
  }
  s=fopen(src.c_str(),"rb");
  if (!s) {
    fclose(d);
    return 1;
  }
  while (!feof(s)) {
    fputc(fgetc(s),d);
  }
  fclose(d);
  fclose(s);
  return 0;
}

int main(int argc, char** argv) {
  curfile="Project.json";
  if (stat(curfile.c_str(),&tempstat)==-1) {
    printf("%s: Not a LowerTriad project. Quitting.\n",argv[0]);
    return 1;
  }
  printf("Reading LowerTriad project...\n");
  f=fopen(curfile.c_str(),"rb");
  if (!f) {
    perror("error while reading Project.json");
    return 1;
  }
  // for now just copy test project
  // will add code here
  fclose(f);
  printf("Success.\n");
  return 0;
}
