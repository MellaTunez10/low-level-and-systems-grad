# Hive-DB

A lightweight, low-level, encrypted Key-Value Database Engine written in pure C. This project is built as a continuous, modular exercise to explore memory architecture, low-level file I/O, custom data structures, and systems programming principles.

## 🚀 Project Evolution

Unlike standard CRUD applications, `Hive-DB` is engineered to interact directly with hardware primitives (RAM and Disk storage). It evolves tracking sequential milestones:

- **v0.1 (Current):** In-Memory parsing engine with modular architectural design, command-line interface (CLI) argument mapping, and embedded cryptographic serialization.
- **v0.2 (Upcoming):** Disk Persistence Layer utilizing sequential Append-Only Logging (AOF) via Linux file system streams.
- **v0.3 (Upcoming):** Low-level memory indexing using custom Hash Tables for $O(1)$ lookup performance.

---

## 🏗️ Architecture & Component Design

The engine utilizes a strict **modular compilation model** to isolate core database operations from terminal interface drivers:

- **`database.h`**: The architectural contract defining core data structures (`DbRecord`) and safely guarded by preprocessor include blocks.
- **`database.c`**: The low-level implementation engine managing data mutations and cryptographic transformations.
- **`main.c`**: The execution driver acting as a defensive boundary validating CLI input, tracking argument configurations, and parsing execution flags.

### Data Layout (Memory Alignment)

Records are structurally mapped directly into fixed sequential memory segments to maximize CPU cache performance:

```text
+-------------------------+------------------------------------+
|     key [50 Bytes]      |     encrypted_value [200 Bytes]    |
+-------------------------+------------------------------------+
| Base Memory Address     | Base Offset + 50 Bytes             |
```
