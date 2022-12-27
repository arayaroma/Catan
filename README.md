# Catan
[Catan](https://en.wikipedia.org/wiki/Catan), previously known as The Settlers of Catan or simply Settlers,
is a multiplayer board game designed by Klaus Teuber. It's the game to make in the course: "Estructuras de Datos" using the **Data Structures** followed in class.

## Requirements

- ### C/C++ Compiler & Debugger
  - gcc
  - g++
  - gdb

- ### Visual Studio Code Extensions
  - C/C++ Extension Pack
  - C/C++ Makefile Project
  - Code Runner

## Installation

## Windows 
#### Installing the software
Visit [MSYS2](https://www.msys2.org/) and download the software.
After installation, click **run MSYS2 now** option and type the following command

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```
Then press y to proceed the installation.

### Installing necessary packages
Open the windows key and search MSYS2, and open the blue icon and paste the following commands

### **To update the system**
```bash
pacman -Syu
```
### **To install the compiler (gcc and g++)**
###### For 64 bit
```bash
pacman -S mingw-w64-x86_64-gcc
```

#### For 32 bit
```bash
pacman -S mingw-w64-i686-gcc
```

### **To install the debugger (gdb)**
#### For 64 bit
```bash
pacman -S mingw-w64-x86_64-gdb
```

#### For 32 bit
```bash
pacman -S mingw-w64-i686-gdb
```

### To check
gcc version : ``gcc --version``
g++ version : ``g++ --version``
gdb version : ``gdb --version``

### Set the Path enviroment variable
add ``C:\msys64\mingw64\bin`` to the Path, search in your system where is located the **bin** directory of **mingw64**


## Arch Linux

### **To update the system**
```bash
pacman -Syu
```
#### **Using the yay package helper**

```bash
yay -S gcc g++ gdb
```

### To check
gcc version : ``gcc --version``
g++ version : ``g++ --version``
gdb version : ``gdb --version``
