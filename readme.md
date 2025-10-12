# 🚌 Bus Ticket Booking System (C Language)

## 📖 Overview

This is a **C-based Bus Ticket Booking System** that allows users to register, log in, and manage their bus seat reservations.
It provides an interactive menu interface for booking, viewing, and cancelling tickets, along with user account management.
All data is stored in text files for persistence between sessions.

---

## ✨ Features

### 🔐 User Account Management

- Register a new account (saved to `Acc.txt`)
- Login with existing credentials
- Prevent duplicate usernames
- Auto-login after registration

### 🎫 Ticket Management

- **Book seats** for available bus routes
- **View current seat status** (occupied or empty)
- **Cancel bookings** and automatically process refund notice
- Support for **multiple bus routes**
- Each bus route saves data into its own files:
  - `trX.txt` → remaining seats
  - `statusX.txt` → passenger names
  - `numberX.txt` → seat numbers

### 🧾 System Management

- Displays all available bus routes
- Tracks seat availability (up to 32 per bus)
- File-based data storage (no database required)
- Interactive console UI

---

## 🚍 Available Routes

| Bus No | Route           |
| ------ | --------------- |
| 1      | KL → Penang    |
| 2      | KL → Johor     |
| 3      | Penang → KL    |
| 4      | Penang → Johor |
| 5      | Johor → KL     |
| 6      | Johor → Penang |

---


## 💾 File Structure

| File            | Description                        |
| --------------- | ---------------------------------- |
| `Acc.txt`     | Stores registered user credentials |
| `trX.txt`     | Remaining seat count for each bus  |
| `statusX.txt` | Passenger names for each bus       |
| `numberX.txt` | Seat numbers for each bus          |
| `main.c`      | Main source code file              |

---

## 🧩 How It Works

- **Seat data** and **passenger data** are stored per bus number.
- Each booking updates the corresponding files (`status`, `number`, and seat count `trX.txt`).
- Cancelling a ticket updates the same files and marks seats as empty.
- The program can be restarted, and all booking data is retained.

---

## 🛠️ Compilation and Execution

### On Windows:

You can compile and run using GCC (MinGW) or any C IDE:

```bash
gcc main.c -o BusBookingSystem
BusBookingSystem.exe
```
