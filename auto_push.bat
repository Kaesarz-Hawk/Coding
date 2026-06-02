@echo off
setlocal enabledelayedexpansion
cd /d "C:\Users\Kawsar Hoque\Desktop\CODING KH"

for /f %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"
set "GREEN=%ESC%[92m"
set "CYAN=%ESC%[96m"
set "YELLOW=%ESC%[93m"
set "RED=%ESC%[91m"
set "MAGENTA=%ESC%[95m"
set "BOLD=%ESC%[1m"
set "DIM=%ESC%[2m"
set "RESET=%ESC%[0m"

cls
echo.
echo.
ping -n 2 127.0.0.1 >nul
echo %CYAN%%BOLD%  ##   ##  ##  ##    #####  ##  ##  #####  ##  ##%RESET%
ping -n 1 127.0.0.1 >nul
echo %CYAN%%BOLD%  ##  ##   ##  ##    ##  ## ##  ##  ##     ##  ##%RESET%
ping -n 1 127.0.0.1 >nul
echo %CYAN%%BOLD%  #####    ######    #####  ##  ##  #####  ######%RESET%
ping -n 1 127.0.0.1 >nul
echo %CYAN%%BOLD%  ##  ##   ##  ##    ##      ####   ##     ##  ##%RESET%
ping -n 1 127.0.0.1 >nul
echo %CYAN%%BOLD%  ##   ##  ##  ##    ##       ##    #####  ##  ##%RESET%
ping -n 2 127.0.0.1 >nul
echo.
echo %DIM%  -----------------------------------------------%RESET%
ping -n 1 127.0.0.1 >nul
echo %MAGENTA%          Git Auto Push  ^|  Kaesarz-Hawk%RESET%
ping -n 1 127.0.0.1 >nul
echo %DIM%  -----------------------------------------------%RESET%
echo.
ping -n 3 127.0.0.1 >nul

echo %CYAN%  [1/4] Checking repository...%RESET%
ping -n 2 127.0.0.1 >nul
git rev-parse --is-inside-work-tree >nul 2>&1
if errorlevel 1 (
    echo %RED%  [x] Not a git repo! Aborting.%RESET%
    timeout /t 4 >nul
    exit /b
)
echo %GREEN%  [+] Repository OK%RESET%
echo.
ping -n 2 127.0.0.1 >nul

echo %CYAN%  [2/4] Staging all changes...%RESET%
ping -n 2 127.0.0.1 >nul
git add .
echo %GREEN%  [+] Staged%RESET%
echo.
ping -n 2 127.0.0.1 >nul

echo %CYAN%  [3/4] Checking for changes...%RESET%
ping -n 2 127.0.0.1 >nul
git diff --cached --quiet
if %errorlevel%==0 (
    echo %YELLOW%  [~] Nothing to commit. Already up to date.%RESET%
    echo.
    ping -n 2 127.0.0.1 >nul
    timeout /t 3 >nul
    exit /b
)
git commit -m "Auto update"
echo %GREEN%  [+] Committed%RESET%
echo.
ping -n 2 127.0.0.1 >nul

echo %CYAN%  [4/4] Pushing to GitHub...%RESET%
ping -n 2 127.0.0.1 >nul
git pull --rebase origin main
git push origin main
if errorlevel 1 (
    echo %YELLOW%  [~] Retrying with force-with-lease...%RESET%
    ping -n 2 127.0.0.1 >nul
    git push --force-with-lease origin main
    if errorlevel 1 (
        echo %RED%  [!] Trying force push...%RESET%
        ping -n 2 127.0.0.1 >nul
        git push --force origin main
        if errorlevel 1 (
            echo %RED%  [x] Push failed. Check credentials or connection.%RESET%
            pause
            exit /b
        )
    )
)

echo.
ping -n 2 127.0.0.1 >nul
echo %GREEN%  [+] Pushed successfully!%RESET%
echo.
ping -n 2 127.0.0.1 >nul
echo %DIM%  -----------------------------------------------%RESET%
ping -n 1 127.0.0.1 >nul
echo %GREEN%%BOLD%       *  Done. The grind never stops.  *%RESET%
ping -n 1 127.0.0.1 >nul
echo %DIM%  -----------------------------------------------%RESET%
echo.
ping -n 3 127.0.0.1 >nul
timeout /t 3 >nul