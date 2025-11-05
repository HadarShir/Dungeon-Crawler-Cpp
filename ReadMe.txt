# Dungeon Crawler – C++ Text-Based Adventure

## Overview
**Dungeon Game** is a text-based adventure game where the player navigates through a series of rooms, each potentially containing monsters.  
The player can heal at campfires, fight monsters, and progress through the dungeon to reach the outside and win the game.

The player is represented as an entity with life and damage properties, capable of reducing damage and healing.  
The dungeon consists of connected rooms, and the player moves between them based on available paths.  
Each room may contain different attributes — monsters to fight or healing opportunities at campfires.  
When encountering a monster, the player must fight to continue progressing.  
The game ends when the player either escapes the dungeon or loses when their life reaches zero.

---

## 🧩 System Architecture
- **Player.h / Player.cpp** – defines the base player entity and its subclasses (Fighter, Sorcerer).  
- **Monster.h / Monster.cpp** – defines enemy classes (Dragon, Goblin) and their attributes.  
- **Room.h / Room.cpp** – represents the dungeon rooms, their connections, and contents.  
- **Game.h / Game.cpp** – manages the main gameplay loop, player actions, and transitions between rooms.  
- **ConfigReader.h / ConfigReader.cpp** – loads and validates configuration files defining the dungeon structure.  
- **main.cpp** – entry point of the game, initializes the player and starts the adventure.  
- **Makefile** – compiles the source files and creates the executable `Dungeon`.

---

## ⚙️ Key Features
- Full **object-oriented design** using inheritance and polymorphism.  
- Dynamic **memory management** with proper allocation and deallocation.  
- Turn-based **combat system** between the player and monsters.  
- Input-based configuration file defining the dungeon layout.  
- Clear and modular architecture for readability and maintenance.

---

## 🧠 Technologies
- **Language:** C++  
- **Paradigms:** Object-Oriented Programming, Dynamic Memory Management  
- **Compiler:** g++  
- **Build Tool:** Makefile  

---

## 👩‍💻 Author
Developed by **Hadar Shir**  
B.Sc. Information Systems and Software Engineering  
Ben-Gurion University of the Negev  

---

## 📚 Notes
This project demonstrates practical knowledge in **C++ architecture**, **OOP design**, **memory safety**, and **interactive text-based systems**, applied through a complete playable dungeon adventure.
