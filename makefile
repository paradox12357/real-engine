# this is the build file for project 
# it is autogenerated by the xmake build system.
# do not edit by hand.

!if "$(VERBOSE)" != "1"
VV=@
!endif

AS=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.34.31933\bin\HostX64\x64\ml64.exe
MRC=C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64\rc.exe
CXX=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.34.31933\bin\HostX64\x64\cl.exe
CC=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.34.31933\bin\HostX64\x64\cl.exe

LD=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.34.31933\bin\HostX64\x64\link.exe
SH=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.34.31933\bin\HostX64\x64\link.exe
AR=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.34.31933\bin\HostX64\x64\link.exe


realengine_CXXFLAGS=-nologo -W3 -O2 -fp:fast -std:c++17 -Isrc /EHsc -DNDEBUG
realengine_CXXFLAGS=-nologo -W3 -O2 -fp:fast -std:c++17 -Isrc /EHsc -DNDEBUG
realengine_ARFLAGS=-nologo -machine:x64 /opt:ref /opt:icf
helloworld_CXXFLAGS=-nologo -W3 -O2 -fp:fast -std:c++17 -Isrc /EHsc -DNDEBUG
helloworld_CXXFLAGS=-nologo -W3 -O2 -fp:fast -std:c++17 -Isrc /EHsc -DNDEBUG
helloworld_LDFLAGS=-nologo -dynamicbase -nxcompat -machine:x64 -libpath:build\windows\x64\release /opt:ref /opt:icf realengine.lib

default:  realengine helloworld

all:  realengine helloworld

.PHONY: default all  realengine helloworld

realengine: build\windows\x64\release\realengine.lib
build\windows\x64\release\realengine.lib: build\.objs\realengine\windows\x64\release\src\Engine.cpp.obj
	@echo linking.release realengine.lib
	-@mkdir build\windows\x64\release > NUL 2>&1
	$(VV)"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.34.31933\\bin\\HostX64\\x64\\link.exe" -lib $(realengine_ARFLAGS) -out:build\windows\x64\release\realengine.lib build\.objs\realengine\windows\x64\release\src\Engine.cpp.obj

build\.objs\realengine\windows\x64\release\src\Engine.cpp.obj: src\Engine.cpp
	@echo compiling.release src\Engine.cpp
	-@mkdir build\.objs\realengine\windows\x64\release\src > NUL 2>&1
	$(VV)"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.34.31933\\bin\\HostX64\\x64\\cl.exe" -c $(realengine_CXXFLAGS) -Fobuild\.objs\realengine\windows\x64\release\src\Engine.cpp.obj src\Engine.cpp

helloworld: build\windows\x64\release\helloworld.exe
build\windows\x64\release\helloworld.exe: build\windows\x64\release\realengine.lib build\.objs\helloworld\windows\x64\release\demo\helloworld.cpp.obj
	@echo linking.release helloworld.exe
	-@mkdir build\windows\x64\release > NUL 2>&1
	$(VV)"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.34.31933\\bin\\HostX64\\x64\\link.exe" $(helloworld_LDFLAGS) -out:build\windows\x64\release\helloworld.exe build\.objs\helloworld\windows\x64\release\demo\helloworld.cpp.obj

build\.objs\helloworld\windows\x64\release\demo\helloworld.cpp.obj: demo\helloworld.cpp
	@echo compiling.release demo\helloworld.cpp
	-@mkdir build\.objs\helloworld\windows\x64\release\demo > NUL 2>&1
	$(VV)"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.34.31933\\bin\\HostX64\\x64\\cl.exe" -c $(helloworld_CXXFLAGS) -Fobuild\.objs\helloworld\windows\x64\release\demo\helloworld.cpp.obj demo\helloworld.cpp

clean:  clean_realengine clean_helloworld

clean_realengine: 
	@del /F /Q build\windows\x64\release\realengine.lib > NUL 2>&1 || rmdir /S /Q build\windows\x64\release\realengine.lib > NUL 2>&1
	@del /F /Q build\windows\x64\release\realengine.pdb > NUL 2>&1 || rmdir /S /Q build\windows\x64\release\realengine.pdb > NUL 2>&1
	@del /F /Q build\.objs\realengine\windows\x64\release\src\Engine.cpp.obj > NUL 2>&1 || rmdir /S /Q build\.objs\realengine\windows\x64\release\src\Engine.cpp.obj > NUL 2>&1

clean_helloworld:  clean_realengine
	@del /F /Q build\windows\x64\release\helloworld.exe > NUL 2>&1 || rmdir /S /Q build\windows\x64\release\helloworld.exe > NUL 2>&1
	@del /F /Q build\windows\x64\release\helloworld.pdb > NUL 2>&1 || rmdir /S /Q build\windows\x64\release\helloworld.pdb > NUL 2>&1
	@del /F /Q build\.objs\helloworld\windows\x64\release\demo\helloworld.cpp.obj > NUL 2>&1 || rmdir /S /Q build\.objs\helloworld\windows\x64\release\demo\helloworld.cpp.obj > NUL 2>&1

