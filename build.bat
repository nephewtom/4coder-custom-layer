@echo off
call bin\buildsuper_x64.bat 4coder_tom\tom_bindings.cpp
copy custom_4coder.dll ..\custom_4coder.dll
