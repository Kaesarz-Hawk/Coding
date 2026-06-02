@echo off
setlocal enabledelayedexpansion
cd /d "C:\Users\Kawsar Hoque\Desktop\CODING KH"

:: ─────────────────────────────────────────
::  Colors
:: ─────────────────────────────────────────
set "ESC="
for /f %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"
set "RESET=%ESC%[0m"
set "CYAN=%ESC%[96m"
set "GREEN=%ESC%[92m"
set "YELLOW=%ESC%[93m"
set "RED=%ESC%[91m"
set "MAGENTA=%ESC%[95m"
set "BOLD=%ESC%[1m"
set "DIM=%ESC%[2m"

cls

:: ─────────────────────────────────────────
::  Banner
:: ─────────────────────────────────────────
echo.
echo %CYAN%%BOLD%  ██╗  ██╗██╗  ██╗    ██████╗ ██╗   ██╗███████╗██╗  ██╗%RESET%
echo %CYAN%%BOLD%  ██║ ██╔╝██║  ██║    ██╔══██╗██║   ██║██╔════╝██║  ██║%RESET%
echo %CYAN%%BOLD%  █████╔╝ ███████║    ██████╔╝██║   ██║███████╗███████║%RESET%
echo %CYAN%%BOLD%  ██╔═██╗ ██╔══██║    ██╔═══╝ ██║   ██║╚════██║██╔══██║%RESET%
echo %CYAN%%BOLD%  ██║  ██╗██║  ██║    ██║     ╚██████╔╝███████║██║  ██║%RESET%
echo %CYAN%%BOLD%  ╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝%RESET%
echo.
echo %DIM%  ─────────────────────────────────────────────────────%RESET%
echo %MAGENTA%                  Git Auto Push  ^|  Kaesarz-Hawk%RESET%
echo %DIM%  ─────────────────────────────────────────────────────%RESET%
echo.

:: ─────────────────────────────────────────
::  Loading animation
:: ─────────────────────────────────────────
call :animate "  Initializing..." 4

:: ─────────────────────────────────────────
::  Check git repo
:: ─────────────────────────────────────────
git rev-parse --is-inside-work-tree >nul 2>&1
if errorlevel 1 (
    echo.
    echo %RED%  [✗] Not a git repository! Aborting.%RESET%
    echo.
    timeout /t 3 >nul
    exit
)
echo %GREEN%  [✓] Repository detected%RESET%
echo.

:: ─────────────────────────────────────────
::  Stage all changes
:: ─────────────────────────────────────────
call :animate "  Staging changes..." 3
git add .
echo %GREEN%  [✓] All changes staged%RESET%
echo.

:: ─────────────────────────────────────────
::  Check if anything to commit
:: ─────────────────────────────────────────
git diff --cached --quiet
if %errorlevel%==0 (
    echo %YELLOW%  [~] Nothing new to commit. Already up to date.%RESET%
    echo.
    call :countdown 3
    exit
)

:: ─────────────────────────────────────────
::  Commit
:: ─────────────────────────────────────────
call :animate "  Committing..." 3
git commit -m "Auto update" >nul 2>&1
echo %GREEN%  [✓] Committed successfully%RESET%
echo.

:: ─────────────────────────────────────────
::  Pull rebase (prevent rejection)
:: ─────────────────────────────────────────
call :animate "  Syncing with remote..." 3
git pull --rebase origin main >nul 2>&1
echo %GREEN%  [✓] Synced with remote%RESET%
echo.

:: ─────────────────────────────────────────
::  Push
:: ─────────────────────────────────────────
call :animate "  Pushing to GitHub..." 4
git push origin main >nul 2>&1

if errorlevel 1 (
    echo %YELLOW%  [~] Normal push blocked. Trying force-with-lease...%RESET%
    echo.
    call :animate "  Force pushing safely..." 3
    git push --force-with-lease origin main >nul 2>&1

    if errorlevel 1 (
        echo %RED%  [!] Force-with-lease failed. Going nuclear...%RESET%
        call :animate "  Force pushing (hard)..." 3
        git push --force origin main >nul 2>&1

        if errorlevel 1 (
            echo %RED%  [✗] Push failed completely. Check your connection or credentials.%RESET%
            echo.
            timeout /t 5 >nul
            exit
        )
    )
)

:: ─────────────────────────────────────────
::  Success
:: ─────────────────────────────────────────
echo %GREEN%  [✓] Pushed to GitHub successfully%RESET%
echo.
echo %DIM%  ─────────────────────────────────────────────────────%RESET%
echo.
echo %GREEN%%BOLD%        ✦  All done. The grind never stops.  ✦%RESET%
echo.
echo %DIM%  ─────────────────────────────────────────────────────%RESET%
echo.
call :countdown 3
exit

:: ─────────────────────────────────────────
::  FUNCTIONS
:: ─────────────────────────────────────────

:animate
set "msg=%~1"
set "steps=%~2"
set "frames=/ - \ |"
set /a i=0
<nul set /p ="%CYAN%%msg% %RESET%"
:anim_loop
for %%f in (%frames%) do (
    <nul set /p ="%%f"
    ping -n 1 -w 200 127.0.0.1 >nul
    <nul set /p =^H
    set /a i+=1
    if !i! geq %steps% goto anim_done
)
goto anim_loop
:anim_done
echo.
exit /b

:countdown
set /a secs=%~1
:cd_loop
<nul set /p ="%DIM%  Closing in %secs%s...%RESET%"
ping -n 2 127.0.0.1 >nul
set /a secs-=1
echo.
if %secs% gtr 0 goto cd_loop
exit /b