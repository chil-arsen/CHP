@echo off
:menu
cls
echo ============================
echo         MAIN MENU      
echo ============================
echo 1. Display IPv4 and IPv6 addresses
echo 2. Network route (traceroute)
echo 3. Get IP address of a hostname
echo 4. Encrypt file or text
echo 5. Decrypt file or text
echo 6. Compress file or text
echo 7. Decompress file or text
echo 8. Calculate file checksum
echo 9. Exit
echo ============================
set /p choice=Choose an option (1-9): 

if "%choice%"=="1" goto show_ip
if "%choice%"=="2" goto traceroute
if "%choice%"=="3" goto resolve_ip
if "%choice%"=="4" goto encrypt
if "%choice%"=="5" goto decrypt
if "%choice%"=="6" goto compress
if "%choice%"=="7" goto decompress
if "%choice%"=="8" goto checksum
if "%choice%"=="9" exit
goto menu

:show_ip
cls
echo IPv4 and IPv6 addresses:
ipconfig | findstr "IPv4 IPv6"
pause
goto menu

:traceroute
cls
set /p host=Enter the hostname or URL: 
tracert %host%
pause
goto menu

:resolve_ip
cls
set /p host=Enter the hostname or URL: 
nslookup %host%
pause
goto menu

:encrypt
cls
set /p input=Enter the name of the file or text to encrypt:
set /p password=Enter the encryption password:
echo %input% | openssl enc -aes-256-cbc -a -salt -pass pass:%password% > encrypted.txt
echo Encrypted data has been saved in `encrypted.txt`.
pause
goto menu

:decrypt
cls
set /p input=Enter the name of the encrypted file:
set /p password=Enter the decryption password:
openssl enc -aes-256-cbc -a -d -salt -in %input% -pass pass:%password% > decrypted.txt
echo Decrypted data has been saved in `decrypted.txt`.
pause
goto menu

:compress
cls
set /p input=Enter the name of the file to compress:
tar -cf %input%.tar %input%
echo File has been compressed.
pause
goto menu

:decompress
cls
set /p input=Enter the name of the compressed file (.tar):
tar -xf %input%
echo File has been decompressed.
pause
goto menu

:checksum
cls
set /p input=Enter the file name:
certutil -hashfile %input% SHA256
pause
goto menu
