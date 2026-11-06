# 🗡️ Rogue-like Game in C with ncurses

A terminal-based **Rogue-like** dungeon crawler built entirely in **C** using the **ncurses** library. This project demonstrates core systems programming concepts, including manual memory management (pointers, dynamic allocation), terminal rendering, and procedural generation. 

If you appreciate classic text-based adventures, deep dungeon crawling, and the raw performance of C, you're in the right place! ✨

## 📌 Features

- **Procedural Generation:** Randomly generated dungeon maps on every run, ensuring a unique experience.
- **Terminal UI:** Fully text-based environment leveraging the ncurses library for rendering and input handling.
- **Combat & Entities:** Basic enemy AI, combat mechanics, and a resource/item collection system.
- **Core Mechanics:** Classic Rogue elements including permadeath, grid-based movement, and dynamic stats tracking.
- **User Authentication:** Integrated terminal-based registration and login system.

## 📸 Showcases

<div align="center">
  <img src="assets/Screenshot 2026-11-06 160858.png" width="45%" alt="Register Menu">
  <img src="assets/Screenshot 2026-11-06 160911.png" width="45%" alt="Sign Up Form">
</div>
<br>
<div align="center">
  <img src="assets/Screenshot 2026-11-06 160921.png" width="45%" alt="Pre-Game Menu">
  <img src="assets/Screenshot 2026-11-06 160930.jpg" width="45%" alt="Scoreboard">
</div>
<br>
<div align="center">
  <img src="assets/Screenshot 2026-11-06 161015.png" width="45%" alt="Dungeon Map Overview">
  <img src="assets/Screenshot 2026-11-06 161022.png" width="45%" alt="Dungeon Crawling Gameplay">
</div>
<br>
<div align="center">
  <img src="assets/Screenshot 2026-11-06 161044.png" width="45%" alt="Weapons Inventory">
  <img src="assets/Screenshot 2026-11-06 161204.png" width="45%" alt="Food Inventory">
</div>

## ⚙️ How to Build & Run

### Prerequisites
- `gcc` compiler installed.
- `ncurses` development library installed (`libncurses5-dev` or `ncurses-devel`).

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
Building on Windows is best achieved using **WSL (Windows Subsystem for Linux)** or **MinGW/MSYS2**, as configuring ncurses natively on Windows requires additional dependencies.

## 🎹 Controls

- **Move:** Arrow keys or `W`, `A`, `S`, `D`
- **Pick up item:** `g`
- **Attack:** `Spacebar`
- **Pause Menu:** `p`
- **Quit:** `q`

## 🏆 Gameplay Mechanics

- **Explore:** Navigate through procedurally generated rooms and corridors.
- **Survive:** Enemies spawn dynamically; engage them carefully to preserve health and energy.
- **Manage Inventory:** Collect weapons, magic items, and food to sustain your run. 
- **The Goal:** Survive the dungeon layers as long as possible and claim the top spot on the local scoreboard! 🕹️
