@echo off
setlocal enabledelayedexpansion
title KH // TWO-WAY GIT SYNC ENGINE

:: Change this path if the folder name is different on your PC vs Laptop
cd /d "C:\Users\Kawsar Hoque\Desktop\CODING KH"

for /f %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"
set "GREEN=%ESC%[92m"
set "DGREEN=%ESC%[32m"
set "CYAN=%ESC%[96m"
set "YELLOW=%ESC%[93m"
set "RED=%ESC%[91m"
set "BOLD=%ESC%[1m"
set "DIM=%ESC%[2m"
set "RESET=%ESC%[0m"

:: --- ANIMATED KH BOOT SEQUENCE ---
cls
echo.
echo %DGREEN%  01001011 01001000 // INITIALIZING SECURE SHELL...%RESET%
ping -n 1 -w 120 127.0.0.1 >nul

cls
echo.
echo %GREEN%%BOLD%  ##  ##%RESET%
echo %GREEN%%BOLD%  ##  ##%RESET%
echo %GREEN%%BOLD%  #####%RESET%
echo %GREEN%%BOLD%  ##  ##%RESET%
echo %GREEN%%BOLD%  ##  ##%RESET%
ping -n 1 -w 120 127.0.0.1 >nul

cls
echo.
echo %GREEN%%BOLD%  ##  ##    ##  ##%RESET%
echo %GREEN%%BOLD%  ##  ##    ##  ##%RESET%
echo %GREEN%%BOLD%  #####     ######%RESET%
echo %GREEN%%BOLD%  ##  ##    ##  ##%RESET%
echo %GREEN%%BOLD%  ##  ##    ##  ##%RESET%
echo.
echo %DIM%  =================================================%RESET%
echo %CYAN%%BOLD%   [SYSTEM] KAESARZ-HAWK // TWO-WAY SYNC PROTOCOL%RESET%
echo %DIM%  =================================================%RESET%
ping -n 1 -w 150 127.0.0.1 >nul

:: --- HACKING MATRIX / HEX STREAM EFFECT ---
echo.
for /L %%i in (1,1,6) do (
    set "hex1=!RANDOM!!RANDOM!"
    set "hex2=!RANDOM!!RANDOM!"
    echo %DGREEN%  0x!hex1! :: DECRYPTING NODE_%%i [OK] :: STREAM_!hex2!%RESET%
    ping -n 1 -w 70 127.0.0.1 >nul
)
echo.

:: --- [1/4] CHECKING REPOSITORY ---
echo %CYAN%  [1/4] VERIFYING LOCAL GIT REPOSITORY...%RESET%
git rev-parse --is-inside-work-tree >nul 2>&1
if errorlevel 1 (
    echo %RED%%BOLD%  [!] CRITICAL ERROR: Not a valid git repo. Check path!%RESET%
    pause
    exit /b
)
echo %GREEN%  [+] TARGET LOCKED: REPOSITORY VERIFIED%RESET%
echo.

:: --- [2/4] SAVING LOCAL CHANGES ---
echo %CYAN%  [2/4] SCANNING & PACKAGING LOCAL PAYLOAD...%RESET%
git add .
git diff --cached --quiet
if errorlevel 1 (
    git commit -m "Auto sync update" >nul 2>&1
    echo %GREEN%  [+] PAYLOAD ENCRYPTED & COMMITTED%RESET%
) else (
    echo %YELLOW%  [~] NO NEW LOCAL MODIFICATIONS DETECTED%RESET%
)
echo.

:: --- [3/4] DOWNLOADING UPDATES ---
echo %CYAN%  [3/4] ESTABLISHING UPLINK // PULLING REMOTE DATA...%RESET%
git pull --rebase origin main >nul 2>&1
if errorlevel 1 (
    echo.
    echo %RED%%BOLD%  [!] CONFLICT DETECTED: Same lines edited on both machines!%RESET%
    echo %YELLOW%      Open VS Code to resolve conflicts, then re-run.%RESET%
    pause
    exit /b
)
echo %GREEN%  [+] REMOTE PACKETS MERGED SUCCESSFULLY%RESET%
echo.

:: --- [4/4] UPLOADING COMBINED CHANGES ---
echo %CYAN%  [4/4] TRANSMITTING COMBINED DATA TO GITHUB...%RESET%
git push origin main >nul 2>&1
if errorlevel 1 (
    echo %RED%%BOLD%  [!] TRANSMISSION FAILED: Check network or credentials.%RESET%
    pause
    exit /b
)
echo %GREEN%  [+] UPLINK COMPLETE: CLOUD & LOCAL SYNCHRONIZED%RESET%
echo.

:: --- CLOSING SEQUENCE ---
echo %DIM%  =================================================%RESET%
echo %GREEN%%BOLD%     * ACCESS GRANTED // BOTH DEVICES IN SYNC *%RESET%
echo %DIM%  =================================================%RESET%
echo %DGREEN%  Terminating session in 2 seconds...%RESET%
timeout /t 2 >nul
exit