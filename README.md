# Squazzle
This project is a video game that I am making so I can have a better usage of all my unproductive "free" time.<br>
This is a little Puzzle game with square where you have to reproduce the original image.<br>
More information about the gameplay will be added here.<br>

## how to build the program
1. you need to download [cmake](https://cmake.org/download/). The minimum version requirement is 3.26<br>
2. You need to install [MingW64](https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z) and add it to you PATH variable.<br>
<i>Note : This version is the one used by the SFML development team.</i><br>
3. You need an IDE ;)<br>
4. When everything is properly set up, you just need to run build.bat. It will automaticaly build the exe file in the ./out/ folder<br>
Argument for the .bat file :
```
-r, -R, --Release          To build in release mode
-d, -D, --Debug            To build in debug mode
```
<i>Note : if you do not give any argument, Release mode will be chosed by default</i><br>

you do not need to install SFML since it is already in the repo and already configured inside the cmake file. Also, if you add any .h or .cpp file, 
please update cmakeLists.txt file in consequences. <br>

## How to participate
If you want to add anything just create a pull request and I'll try to answer you as fast as possible ! <br>

have fun !<br>
