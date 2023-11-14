@ECHO OFF

:: ===================== VARIABLEs ============================================================================
set "outputFile=.\out\main.exe"
set "UnlinkedFile=.\out\main.o"
set "sourceFile=.\source\main.cpp"
set "SFMLHeader=.\library\SFML-2.6.1\include\"
set "SFMLLibFolder=.\library\SFML-2.6.1\lib\"
set "SFMLLib=-lsfml-graphics -lsfml-window -lsfml-system"
:: =============================================================================================================


:: This bat file is used to compile the code into a executable. The .exe will be found in .\out\
echo The game " StickFighter vs the tower of pain " will be build and compiled...

if "%~1" EQU "" ( goto PROD ) else if "%~1" EQU "-d" ( goto DEBUG )


:DEBUG
g++ -Wall -c %sourceFile% -o %UnlinkedFile% -I%SFMLHeader%
g++ -Wall %UnlinkedFile% -o %outputFile% -L%SFMLLibFolder% %SFMLLib%
goto END

:PROD
echo To have access to a terminal with the window in order to debug, use -d with this bat file
g++ -Wall -c %sourceFile%  -o %UnlinkedFile% -I%SFMLHeader%
g++ -Wall %UnlinkedFile% -o %outputFile% -L%SFMLLibFolder% %SFMLLib% -mwindows

:END
del %UnlinkedFile%
echo END