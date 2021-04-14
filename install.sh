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
g++ src/param_parser/ParamParser.cpp -o bin/parser.o -c
g++ src/patch.cpp bin/parser.o -o patch

echo "[*] Installing system wide"
sudo mv patch "$INSTALL_PATH"
rm -rf bin

trap : 0
echo ""
echo "[+] Done !"