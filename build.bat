@echo off

if "%1"=="" (
    goto RELEASE
) else if "%1" == "-R" (
    goto RELEASE
) else if "%1" == "-r" (
    goto RELEASE
) else if "%1" == "--Release" (
    goto RELEASE
) else if "%1" == "-D" (
    goto DEBUG
) else if "%1" == "-d" (
    goto DEBUG
) else if "%1" == "--Debug" (
    goto DEBUG
) else (
    goto RELEASE
)

:RELEASE
set "buildType=Release"
goto BUILD

:DEBUG
set "buildType=Debug"
goto BUILD


:BUILD
echo ========================================================================================
echo The code will be compiled. You have chosen %buildType% mode.
echo -r, -R, --Release          To build in release mode
echo -d, -D, --Debug            To build in debug mode
echo ========================================================================================
echo .
echo .
echo ========================================================================================
echo Output of cmake -DCMAKE_BUILD_TYPE=%buildType% -G "MinGW Makefiles" -B .\build\ :
cmake -DCMAKE_BUILD_TYPE=%buildType% -G "MinGW Makefiles" -B .\build\
echo ========================================================================================
echo .
echo .
echo ========================================================================================
echo output of mingw32-make.exe -C .\build\ : 
mingw32-make.exe -C .\build\
echo ========================================================================================

