# 🗡️ Rogue-like Game in C with ncurses

A simple **Rogue-like** game built using **C** and the **ncurses** library. This was my very first project in game development for the terminal, and after a long time, I decided to publish it on GitHub. If you’re into terminal games, dungeon crawling, and the classic Rogue style, you’re in the right place! ✨

---

## 📌 Features

- Fully text-based environment using ncurses
- Random map generation on each run
- Basic enemies and combat system
- Items and resource collection system
- Basic permadeath mechanic

---

## 🎮 Demo

(Add some screenshots or gifs of the game running here)

---

## ⚙️ How to Build & Run

### Requirements

- gcc installed
- ncurses library installed

### Linux / macOS (Makefile)

```bash
make
./rogue
```

### Linux / macOS (CMake)

```bash
mkdir build && cd build
cmake ..
make
./rogue
```

### Windows

You can use **MinGW** or **WSL** on Windows. Note that setting up ncurses on Windows requires additional configuration.

---

## 🎹 Controls

- Move: Arrow keys or `WASD`
- Pick up item: `g`
- Attack: `space`
- Quit: `q`

---

## 🏆 Gameplay Mechanics

- Each new game generates a fresh random dungeon map.
- Enemies spawn in different locations and engage in combat when you approach.
- The main goal: survive as long as possible! 🕹️

---

## 🤝 Contributing

This project was built for learning purposes, but feel free to open Pull Requests or Issues with suggestions and improvements.

---

## 📜 License

This project is licensed under the MIT License.
