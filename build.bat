@ECHO OFF

:: ===================== VARIABLEs ============================================================================
set "outputFile=.\out\main.exe"
set "sourceFile=.\source\main.cpp"
:: =============================================================================================================

:: This bat file is used to compile the code into a executable. The .exe will be found in .\out\
echo The game " StickFighter vs the tower of pain " will be build and compiled...
g++.exe %sourceFile% -o %outputFile%
echo The file .\out\main.exe was created successfully
echo END