@echo off
call bin\buildsuper_x64-win.bat tom\tom_bindings.cpp
copy custom_4coder.dll ..\custom_4coder.dll
