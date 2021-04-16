# 0xPatcher
0xPatcher helps you quickly patch some bytes in a file.

## Changelog

### V.1.0.0
 - Patch one byte at a given index
 - -o and -v flags
 - Know bugs :
    - Display problem when combining -o and -v flags 

## Installation
### Linux
Clone the repo and run the installation script. It should provide a system wide installation.
```bash
git clone https://github.com/Log-s/0xPatcher.git
cd 0xPatcher
sudo ./install.sh
```
### Windows / MacOS
> There is no Windows or MacOS support yet

## Usage

```
patch file byte offset [OPTIONS]

    options :
        -o / --output : when specified, this option allows you to write the result
                        in a copy of the file, and to leave that file untouched
        
        -v / --verbose : when specified, you'll get feedaback, even when no errors
                         no errors where encountered
                       
    Examples :
        patch mario.png 5f 8
        patch mario.png 0x73 16 -v -o mario_copy.pdf
```

## Upcoming

The next release should include the support of multiple bytes patching at the same index.

I consider adding a config file feature. This would allow the user to pass a configuration file to the program with
multiple bytes and indexes. This would avoid calling the binary multiple times, from a python script for example (wich
is pretty time consuming). A single call with a custom made input file would do the job.

I also consider adding support for more operating systems (Windows/macOS).
