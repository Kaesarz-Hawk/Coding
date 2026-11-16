@echo off
title Two-Way Git Sync - Kaesarz-Hawk

:: Change this path if the folder name is different on your PC vs Laptop
cd /d "C:\Users\Kawsar Hoque\Desktop\CODING KH"

echo.
echo [1/4] Checking repository...
git rev-parse --is-inside-work-tree >nul 2>&1
if errorlevel 1 (
    echo [ERROR] Not a valid git repository. Check the folder path!
    pause
    exit /b
)

echo [2/4] Saving local changes (if any)...
git add .
git diff --cached --quiet
if errorlevel 1 (
    git commit -m "Auto sync update"
) else (
    echo       No new local changes to save.
)

echo [3/4] Downloading updates from GitHub...
git pull --rebase origin main
if errorlevel 1 (
    echo.
    echo [CONFLICT] Both devices edited the exact same lines in a file!
    echo Resolve the conflict in VS Code, then run this script again.
    pause
    exit /b
)

echo [4/4] Uploading combined changes to GitHub...
git push origin main
if errorlevel 1 (
    echo [ERROR] Push failed. Check your internet connection.
    pause
    exit /b
)

echo.
echo ==========================================
echo     Sync Complete! Both devices match.
echo ==========================================
timeout /t 3 >nul