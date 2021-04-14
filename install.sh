#!/bin/sh

PROJECT_PATH="src/"
INSTALL_PATH="/usr/bin/"
MAN_PATH=$(manpath)

abort()
{
  echo ""
  echo "[!] An error was encountered. Please check the output above for more information"
  rm -rf bin
  exit 1
}

trap 'abort' 0
set -e


echo "/-----------------|"
echo "| == 0xPatcher == |"
echo "|----------Log_s--/"

echo ""

echo "[*] Installing g++"
sudo apt-get install g++ > /dev/null

echo "[*] Compiling project"
mkdir bin
g++ -std=c++11 src/utils/exceptions.cpp -o bin/exceptions.o -c
g++ -std=c++11 src/utils/dev_tools.cpp -o bin/dev_tools.o -c
g++ -std=c++11 src/param_parser/param_parser.cpp -o bin/parser.o -c
g++ -std=c++11 src/patcher/patcher.cpp -o bin/patcher.o -c
g++ -std=c++11 src/main.cpp bin/exceptions.o bin/dev_tools.o bin/parser.o bin/patcher.o -o patch

echo "[*] Installing system wide"
sudo mv patch "$INSTALL_PATH"
rm -rf bin

trap : 0
echo ""
echo "[+] Done !"