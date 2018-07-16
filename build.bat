@echo off

REM TODO(bjorn): Comment out what the flags represent.

SET defines=-DHANDMADE_SLOW=1 -DHANDMADE_INTERNAL=1 
SET errors=-WX -W4 -wd4201 -wd4100 -wd4189 -wd4505 -wd4101
SET flags=-MTd -nologo -GR -EHa -Od -Oi -Z7 -FC 
SET links=user32.lib gdi32.lib winmm.lib
SET linkflags=-incremental:no -opt:ref

SET "source=%~dp0"

SET "builddir=%source%..\build\windows"

SET "externallibs=%source%libs"

SET "tempdir=%builddir%\temp"

if not exist "%tempdir%" mkdir "%tempdir%"
pushd "%tempdir%"

REM 64-bit build

SET "platformsource=%source%win32_game.cpp"

cl %defines% %errors% %flags% -Fmwin32_game.map "%platformsource%" -link %linkflags% %links%

REM 32-bit build
REM TODO(bjorn): compile for 32-bit, use vcvarsall?
REM cl %defines% %errors% %flags% %platformsource% %linker_flags% -subsystem:windows,5.1 %links%

popd

CALL :SUB_CompileAGame mathy_stuff

REM CALL :SUB_CompileAGame handmade

REM CALL :SUB_CompileAGame air_world

REM CALL :SUB_CompileAGame pixel_puzzler

REM CALL :SUB_CompileAGame text_editor

GOTO :EOF

::----------------------------------

:SUB_CompileAGame
SET "filename=%1"

SET "gamedir=%builddir%\%filename%"
if not exist "%gamedir%" mkdir "%gamedir%"
pushd "%gamedir%"

del *.pdb >nul 2>nul

REM 64-bit build

SET "gamesource=%source%%filename%.cpp"

cl %defines% %errors% %flags% -I%externallibs% -Fm%filename%.map "%gamesource%" -LD -link %linkflags% -EXPORT:GameGetSoundSamples -EXPORT:GameUpdateAndRender -PDB:%filename%_%random%.pdb -OUT:game.dll

@xcopy ..\temp . /Y >nul 2>&1

popd
EXIT /B

:EOF
