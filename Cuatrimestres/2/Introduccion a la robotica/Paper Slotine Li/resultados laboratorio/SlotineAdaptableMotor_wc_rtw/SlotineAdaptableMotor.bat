set MATLAB=C:\Archivos de programa\MATLAB\R2007a
set MSVCDir=c:\archivos de programa\microsoft visual studio\vc98

set MSDevDir=c:\archivos de programa\microsoft visual studio\common\msdev98
"C:\Archivos de programa\MATLAB\R2007a\rtw\bin\win32\envcheck" INCLUDE "c:\archivos de programa\microsoft visual studio\vc98\include"
if errorlevel 1 goto vcvars32
"C:\Archivos de programa\MATLAB\R2007a\rtw\bin\win32\envcheck" PATH "c:\archivos de programa\microsoft visual studio\vc98\bin"
if errorlevel 1 goto vcvars32
goto make

:vcvars32
set VSCommonDir=c:\archivos de programa\microsoft visual studio\common
call "C:\Archivos de programa\MATLAB\R2007a\toolbox\rtw\rtw\private\vcvars32_600.bat"

:make
cd .
nmake -f SlotineAdaptableMotor.mk  GENERATE_REPORT=0 ADD_MDL_NAME_TO_GLOBALS=1 TMW_EXTMODE_TESTING=0 VISUAL_VER=6.0
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
