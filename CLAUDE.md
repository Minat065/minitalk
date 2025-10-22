# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Minitalk is a 42 School project implementing inter-process communication (IPC) using UNIX signals. The project consists of a server-client architecture where the client sends messages to the server bit-by-bit using only SIGUSR1 and SIGUSR2 signals.

**Project Requirements:**
- Server must display its PID on startup
- Client takes 2 parameters: server PID and message string
- Communication must use ONLY SIGUSR1 and SIGUSR2 signals
- Server must display messages without delay (100 chars in 1 second is too slow!)
- Server must handle multiple clients sequentially without restart
- Must follow 42 Norm
- No memory leaks, no unexpected crashes

## Build Commands

```bash
# Build mandatory part (server and client)
make

# Build bonus part (server_bonus and client_bonus)
make bonus

# Clean object files
make clean

# Full clean (objects + executables)
make fclean

# Rebuild from scratch
make re

# Check Norm compliance
norminette srcs/ includes/
```

## Running the Programs

**Mandatory:**
```bash
# Terminal 1: Start server (displays PID)
./server

# Terminal 2: Send message (replace <PID> with server's PID)
./client <PID> "Your message here"
```

**Bonus:**
```bash
# Terminal 1: Start bonus server
./server_bonus

# Terminal 2: Send message with acknowledgment
./client_bonus <PID> "Your message here"
# Output: "Message received by server!"
```

## Architecture

### Signal-Based Communication Protocol

**Critical Constraint:**
Linux does NOT queue signals of the same type if one is already pending. This is why the implementation uses an acknowledgment handshake - the client waits for confirmation before sending the next bit to prevent signal loss.

**Mandatory Implementation:**
- Server receives bits via SIGUSR1 (0) and SIGUSR2 (1)
- Server sends SIGUSR1 acknowledgment back to client after each bit
- Client waits for acknowledgment before sending next bit (handshake protocol)
- Server reconstructs bytes from 8 bits and outputs characters

**Bonus Implementation:**
- Implements full message acknowledgment (not just per-bit)
- Client first sends its PID (32 bits) to the server
- Server acknowledges each bit with SIGUSR2 during transmission
- After receiving complete message (marked by newline), server sends SIGUSR1 to client
- Client displays "Message received by server!" upon final acknowledgment
- Unicode character support

### Allowed Functions (Mandatory Part)

- write
- ft_printf (or equivalent)
- signal
- sigemptyset
- sigaddset
- sigaction
- kill
- getpid
- malloc
- free
- pause
- sleep
- usleep
- exit

### Global Variables

**One global variable per program is allowed** (one for client, one for server), and its use must be justified. In this implementation:

- **Server:** Uses `g_data` (struct) to maintain state across signal handler invocations
- **Client:** Uses `g_ack_received` (volatile sig_atomic_t) for signal synchronization

The justification: Signal handlers cannot receive custom parameters, so state must be stored in global scope.

### Data Structure

Both implementations use a `t_data` struct to maintain state:

**Mandatory (server.c:18-23):**
```c
typedef struct s_data {
    char   current_char;  // Character being reconstructed
    int    bit_count;     // Bits received for current character
    pid_t  client_pid;    // PID from siginfo_t for acknowledgment
}
```

**Bonus (minitalk_bonus.h:21-27):**
```c
typedef struct s_data {
    char   current_char;  // Character being reconstructed
    int    bit_count;     // Bits received (0-31 for PID, then 0-7 for chars)
    pid_t  client_pid;    // Client PID after initial handshake
    pid_t  server_pid;    // Server's own PID
}
```

### Key Implementation Details

**Signal Handler State Machine (bonus):**
- Phase 1: Server receives 32-bit client PID (server_bonus.c:24-38)
  - Accumulates PID bit by bit using static variable
  - Sends SIGUSR2 acknowledgment after each bit
  - After 32 bits, transitions to Phase 2
- Phase 2: Server receives 8-bit characters until newline (server_bonus.c:40-61)
  - On newline: server sends SIGUSR1 to client and resets state

**Bit Transmission:**
- Bits sent MSB-first (most significant bit first)
- Client loops with `usleep(50)` waiting for acknowledgment (client.c:34-35)
- Global volatile sig_atomic_t flag used for signal synchronization

**Error Handling:**
- Client validates argument count (must be exactly 3: program, PID, message)
- Invalid PID (≤0) returns error with usage message
- No unexpected termination (segfault, bus error, double free)
- All heap memory properly freed

**Performance:**
- usleep(50) provides balance between reliability and speed
- Per-bit acknowledgment prevents signal loss while maintaining throughput
- Server processes bits immediately without buffering delays

## Testing

Reference TEST_COMMANDS.md for comprehensive test cases including:
- Basic text, special characters, empty messages
- Long messages (100-10000 characters)
- Multiple sequential/concurrent clients
- Error conditions (no args, invalid PID, missing message)
- Performance tests (100 sequential messages)

## Dependencies

- libft: Custom C library in `libft/` directory
  - Contains ft_printf, ft_atoi, and other utility functions
  - Built automatically as dependency via Makefile (make -C libft)

## Code Organization

```
minitalk/
├── srcs/
│   ├── server.c         # Mandatory server
│   ├── client.c         # Mandatory client
│   ├── server_bonus.c   # Bonus server with bidirectional ack
│   └── client_bonus.c   # Bonus client with PID exchange
├── includes/
│   ├── minitalk.h       # Header for mandatory (nearly empty)
│   └── minitalk_bonus.h # Header for bonus (t_data definition)
├── libft/               # Dependency library
├── objs/                # Compiled object files (created by make)
└── TEST_COMMANDS.md     # Comprehensive test suite
```

## Important Notes for Development

- Always compile with `-Wall -Wextra -Werror`
- Use SA_SIGINFO flag with sigaction to get sender PID
- Bonus features only evaluated if mandatory part is perfect
- During evaluation, may be asked to make small modifications to verify understanding
- The per-bit handshake is ESSENTIAL - without it, signals are lost due to Linux signal queuing behavior
