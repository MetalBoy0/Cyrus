@echo off
setlocal

set "PYTHON_EXECUTABLE=python.exe"
set "PYTHON_SCRIPT=pngtobmp.py"

REM Check if a file was dragged onto the batch file
if "%~1"=="" (
    echo No file was dragged onto the batch file.
    exit /b
)

REM Check if the dragged file is a PNG file
set "FILE_EXTENSION=%~x1"
if /i not "%FILE_EXTENSION%"==".png" (
    echo The dragged file is not a PNG file.
    exit /b
)

REM Run the Python script with the dragged file as an argument
"%PYTHON_EXECUTABLE%" "%PYTHON_SCRIPT%" "%~1"

endlocal