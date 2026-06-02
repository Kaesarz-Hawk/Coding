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
echo %CYAN%%BOLD%  ██╗  ██╗██╗  ██╗    ██████╗ ██╗   ██╗███████╗██╗  ██╗%RESET%
echo %CYAN%%BOLD%  ██║ ██╔╝██║  ██║    ██╔══██╗██║   ██║██╔════╝██║  ██║%RESET%
echo %CYAN%%BOLD%  █████╔╝ ███████║    ██████╔╝██║   ██║███████╗███████║%RESET%
echo %CYAN%%BOLD%  ██╔═██╗ ██╔══██║    ██╔═══╝ ██║   ██║╚════██║██╔══██║%RESET%
echo %CYAN%%BOLD%  ██║  ██╗██║  ██║    ██║     ╚██████╔╝███████║██║  ██║%RESET%
echo %CYAN%%BOLD%  ╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝%RESET%
echo.
echo %DIM%  ────────────────────────────────────────────────%RESET%
echo %MAGENTA%            Git Auto Push  ^|  Kaesarz-Hawk%RESET%
echo %DIM%  ────────────────────────────────────────────────%RESET%
echo.

echo %CYAN%  [1/4] Checking repository...%RESET%
git rev-parse --is-inside-work-tree >nul 2>&1
if errorlevel 1 (
    echo %RED%  [x] Not a git repo! Aborting.%RESET%
    timeout /t 4 >nul
    exit /b
)
echo %GREEN%  [✓] Repository OK%RESET%
echo.

echo %CYAN%  [2/4] Staging all changes...%RESET%
git add .
echo %GREEN%  [✓] Staged%RESET%
echo.

echo %CYAN%  [3/4] Checking for changes...%RESET%
git diff --cached --quiet
if %errorlevel%==0 (
    echo %YELLOW%  [~] Nothing to commit. Already up to date.%RESET%
    echo.
    timeout /t 3 >nul
    exit /b
)
git commit -m "Auto update"
echo %GREEN%  [✓] Committed%RESET%
echo.

echo %CYAN%  [4/4] Pushing to GitHub...%RESET%
git pull --rebase origin main
git push origin main
if errorlevel 1 (
    echo %YELLOW%  [~] Retrying with force-with-lease...%RESET%
    git push --force-with-lease origin main
    if errorlevel 1 (
        echo %RED%  [!] Trying force push...%RESET%
        git push --force origin main
        if errorlevel 1 (
            echo %RED%  [x] Push failed. Check credentials or connection.%RESET%
            pause
            exit /b
        )
    )
)

echo.
echo %GREEN%  [✓] Pushed successfully!%RESET%
echo.
echo %DIM%  ────────────────────────────────────────────────%RESET%
echo %GREEN%%BOLD%       ✦  Done. The grind never stops.  ✦%RESET%
echo %DIM%  ────────────────────────────────────────────────%RESET%
echo.
timeout /t 3 >nul