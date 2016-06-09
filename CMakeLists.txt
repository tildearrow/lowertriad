# Copyright (c) 2016 tildearrow
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
cmake_minimum_required(VERSION 2.8)
project(lowertriad)
if(WIN32)
  link_directories(../winlib/x86)
  include_directories(wininclude)
endif(WIN32)
if(APPLE)
  include_directories(/usr/local/include/)
  link_directories(/usr/local/lib/)
endif(APPLE)
if(NOT WIN32)
  execute_process(COMMAND bash -c "git log | head -1 | sed 's/commit //' | sed 's/\^/\"/' | sed 's/\$/\"/' " OUTPUT_VARIABLE GITCOMMIT)
  add_definitions("-DGIT_COMMIT=${GITCOMMIT}")
else(NOT WIN32)
  add_definitions("-DGIT_COMMIT=will_be_fixed")
endif(NOT WIN32)
add_executable(lowertriad-make src/make/make.cpp)
add_executable(lowertriad-test src/engine/engine.cpp)
add_executable(lowertriad-ide src/ide/ui.cpp src/ide/gfxeditor.cpp src/ide/eteditor.cpp src/ide/sceneeditor.cpp src/ide/file.cpp src/ide/main.cpp src/ide/font.cpp)
if(WIN32)
  target_link_libraries(lowertriad-ide SDL2 SDL2main SDL2_ttf)
else(WIN32)
  target_link_libraries(lowertriad-ide SDL2 SDL2_ttf)
endif(WIN32)
target_compile_features(lowertriad-ide PRIVATE cxx_range_for)
