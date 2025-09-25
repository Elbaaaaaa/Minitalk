# Minitalk

Minitalk is a project written in C that demonstrates inter-process communication using signals. The goal of the project is to create a simple messaging system where messages are sent from a client process to a server process, one bit at a time, via UNIX signals.

## Features

- Server receives messages from multiple clients using signals.
- Client encodes and sends messages to the server.
- Demonstrates low-level signal handling and bitwise operations in C.

## Usage

1. **Compile the project:**
   ```sh
   make
   ```

2. **Start the server:**
   ```sh
   ./server
   ```
   The server will display its process ID (PID).

3. **Send a message from the client:**
   ```sh
   ./client <server_pid> "your message here"
   ```
   Replace `<server_pid>` with the PID shown by the server.

## Requirements

- GCC compiler
- UNIX-like operating system

## Notes

- The server must be running before sending messages from the client.
- This project is intended for educational purposes to learn about signals and process communication in C.

## Author

- [Elbaaaaaa](https://github.com/Elbaaaaaa)
