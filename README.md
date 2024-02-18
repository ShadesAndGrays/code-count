## Code Counter
A simple program for checking the total number of lines of text in a given directory.

---

### Compile 

Ensure you have all the depencies installed in the standard directory

Using a package manager:

##### yay
```
yay -S fmt
yay -S cmake
```
##### pacman
```
pacman -S fmt
pacman -S cmake
```
---

### Usage
- I have no idea what goes on with dot files.
- A line must have 4 characters at least

Run the cmake command in the Project ditectory
```
cmake -S . -B build
cmake --build build
./build/code-count
```

To use globally copy the code-count binary to a expose PATH directory

---
### Dependencies
- fmt
- cmake

---
#### Side Note
This is just a fancy little side project I worked on in less than a day so it's not really complicated

Thank you for looking at this project 
