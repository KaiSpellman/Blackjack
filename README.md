# Blackjack Simulator in C++

A command-line Blackjack game written in C++. This project simulates a game of Blackjack between a single player and the dealer, implementing core game logic such as card shuffling, hand value evaluation (including ACE logic), and win/loss conditions.

---

## Features

- Standard 52-card deck
- Dealer AI that follows typical Blackjack rules (hits until 17+)
- Player hit/stand interaction
- Accurate hand value calculation with ACE logic (11 or 1)
- Replay functionality for multiple rounds

---

## Concepts Practiced

This project demonstrates key computer science concepts, including:

- **Data Structures**: Vectors, structs, enums
- **Object-Oriented Programming**: Encapsulation via `Deck` and `Card` classes
- **Algorithms**: Fisher-Yates shuffle, hand value computation
- **Control Flow**: User-driven game loop with condition handling
- **Randomness**: Deck shuffling using `std::shuffle`
- **Input/Output**: Terminal-based user interaction

---

## How to Play

1. The game deals two cards each to the player and the dealer.
2. The dealer shows only one card initially.
3. The player can choose to:
   - `h` → **Hit**: draw another card.
   - `s` → **Stand**: end your turn.
4. The dealer then plays automatically:
   - Hits until their hand value is 17 or higher.
5. The game announces the winner, then offers a chance to play again.

---

## How to Build and Run

### Prerequisites

- C++ compiler (e.g., g++, clang++)

### Build

```bash
g++ -std=c++11 -o blackjack main.cpp
