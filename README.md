# Catan

## Required Libraries
- ### [The CImg Library](https://cimg.eu/index.html)

## gcc installation

Most of the machines already have installed gcc package, so it's not necessary to install gcc.

### To check your gcc version

### Windows
Open the Command Prompt, and type:
```bash
gcc -v
```

### Arch Linux
```bash
gcc --version
```

## To install gcc

### Windows
Visit [MSYS2](https://www.msys2.org/) and download the .exe installer file

#### In the terminal, after installation do:
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```
##### _Select the option y to proceed the installation._
---

#### To check the version
```
gcc --version
```

#### Setting up the Path


### Arch Linux
```bash
sudo pacman -S gcc
```
