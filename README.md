# Skui
A program to send serial commands via buttons




## Install

### Linux 

First you have to install the following packages:

```bash
sudo apt install libqt5serialport5-dev -y
```
Navigate to the project folder 
Now the cmake stuff:
```bash
mkdir build
```
```bash
cmake -H. -Bbuild
```
```bash
cd build
```
```bash
make
```
Now you have the executable
```bash
./serialgui
```
