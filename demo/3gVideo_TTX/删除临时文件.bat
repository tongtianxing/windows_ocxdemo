@echo On
@PROMPT [Com]#
@for /r . %%a in (.) do @if exist "%%a\CVS" rd /s /q "%%a\CVS"
@for /r . %%a in (.) do @if exist "%%a\*.~*" del "%%a\*.~*"
@for /r . %%a in (.) do @if exist "%%a\clear.bat" del "%%a\clear.bat"
@del /Q .\tmp\*.*
