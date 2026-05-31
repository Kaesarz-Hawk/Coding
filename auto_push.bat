@echo off
cd /d "C:\Users\Kawsar Hoque\Desktop\CODING KH"

echo ==========================
echo Git Auto Push Starting...
echo ==========================

REM Make sure repo is valid
git rev-parse --is-inside-work-tree >nul 2>&1
if errorlevel 1 (
    echo ERROR: Not a git repository!
    pause
    exit
)

REM Stage changes
git add .

REM Check if anything is actually staged
git diff --cached --quiet
if %errorlevel%==0 (
    echo No changes to commit.
    exit
)

REM Commit safely
git commit -m "Auto update"

REM Try pulling first (prevents push rejection)
git pull --rebase origin main

REM Push
git push origin main

REM Check result
if errorlevel 1 (
    echo.
    echo PUSH FAILED - trying force push safety mode...
    git push --force-with-lease origin main
)

echo ==========================
echo Done.
echo ==========================
pause