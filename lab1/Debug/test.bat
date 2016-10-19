triangle.exe 1
IF NOT ERRORLEVEL -4 GOTO err

triangle.exe 1 1 1 1
IF NOT ERRORLEVEL -4 GOTO err

triangle.exe 1 2 3
IF NOT ERRORLEVEL -3 GOTO err

triangle.exe 1.1 2.2 4.4
IF NOT ERRORLEVEL -3 GOTO err

triangle.exe 1 0 3
IF NOT ERRORLEVEL -2 GOTO err

triangle.exe -3.888 -3.888 -3.888
IF NOT ERRORLEVEL -2 GOTO err

triangle.exe -2.77 -2.77 3
IF NOT ERRORLEVEL -2 GOTO err

triangle.exe 0 0 0
IF NOT ERRORLEVEL -2 GOTO err

triangle.exe 1 -3.3 3
IF NOT ERRORLEVEL -2 GOTO err

triangle.exe 1 b 3
IF NOT ERRORLEVEL -1 GOTO err

triangle.exe 1 b b
IF NOT ERRORLEVEL -1 GOTO err

triangle.exe 1.0 2.11 3.10
IF NOT ERRORLEVEL 0 GOTO err

triangle.exe 2.77 2.77 3
IF NOT ERRORLEVEL 1 GOTO err

triangle.exe 3.888 3.888 3.888
IF NOT ERRORLEVEL 2 GOTO err


echo Тестирование завершено успешно.
pause
EXIT /b

:err
echo Тестирование завершено неуспешно.
pause
EXIT /b