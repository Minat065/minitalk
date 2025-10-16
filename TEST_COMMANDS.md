# Minitalk Test Commands

## Setup

**Terminal 1:** Start server and note the PID
```bash
./server
```

**Terminal 2:** Run tests (replace `<PID>` with actual server PID)

---

## Mandatory Tests

### Basic Functionality
```bash
# Simple text
./client <PID> "Hello"

# Text with spaces
./client <PID> "Hello World"

# Numbers
./client <PID> "42Tokyo"

# Special characters
./client <PID> '!@#$%^&*()[]{}:;",.<>?/\|'

# Empty message
./client <PID> ""
```

### Long Messages
```bash
# 100 characters
./client <PID> "$(python3 -c 'print("A"*100)')"

# 500 characters
./client <PID> "$(python3 -c 'print("B"*500)')"

# 1000 characters
./client <PID> "$(python3 -c 'print("X"*1000)')"
```

### Multiple Messages
```bash
# Sequential
./client <PID> "First"
./client <PID> "Second"
./client <PID> "Third"

# Rapid fire
for i in {1..10}; do ./client <PID> "Message$i"; done
```

### Error Handling
```bash
# No arguments
./client

# Missing message
./client <PID>

# Invalid PID
./client 999999 "test"
```

---

## Bonus Tests (if implemented)

```bash
# Start bonus server
./server_bonus

# Test with acknowledgment
./client_bonus <PID> "Hello"
# Expected: Server displays message, client shows "Message received by server!"

# Multiple clients simultaneously
./client_bonus <PID> "Client1" &
./client_bonus <PID> "Client2" &
./client_bonus <PID> "Client3" &
wait
```

---

## Build Tests

```bash
# Clean build
make fclean && make

# Check for warnings
make 2>&1 | grep -i warning

# Bonus build
make bonus

# Norminette (if required)
norminette srcs/ includes/
```

---

## Stress Tests

```bash
# 100 sequential messages
for i in {1..100}; do ./client <PID> "Test$i"; done

# Large message (10000 chars)
./client <PID> "$(python3 -c 'print("Z"*10000)')"

# Mixed rapid messages
for i in {1..50}; do ./client <PID> "Short" & ./client <PID> "$(python3 -c 'print("L"*100)')"; done
```
