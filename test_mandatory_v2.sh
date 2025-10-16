#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Test counter
TESTS_PASSED=0
TESTS_FAILED=0
TOTAL_TESTS=0

print_test_header() {
    echo -e "\n${BLUE}========================================${NC}"
    echo -e "${BLUE}Test $1: $2${NC}"
    echo -e "${BLUE}========================================${NC}"
}

print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}✓ PASSED${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${RED}✗ FAILED${NC}"
        ((TESTS_FAILED++))
    fi
    ((TOTAL_TESTS++))
}

# Cleanup function
cleanup() {
    pkill -f "./server" 2>/dev/null
    pkill -f "./client" 2>/dev/null
    rm -f /tmp/minitalk_*.txt
}

trap cleanup EXIT

# Check executables
echo -e "${YELLOW}Checking executables...${NC}"
if [ ! -f "./server" ] || [ ! -f "./client" ]; then
    echo -e "${RED}Executables not found. Running make...${NC}"
    make
fi
echo -e "${GREEN}Executables found!${NC}"

# ========================================
# Manual Test Instructions
# ========================================
echo -e "\n${BLUE}========================================${NC}"
echo -e "${BLUE}MINITALK MANDATORY TEST SUITE${NC}"
echo -e "${BLUE}========================================${NC}"
echo ""
echo -e "${YELLOW}This test requires TWO terminals:${NC}"
echo ""
echo -e "${GREEN}Terminal 1 (Server):${NC}"
echo -e "  cd $(pwd)"
echo -e "  ./server"
echo ""
echo -e "${GREEN}Terminal 2 (Client - Run these tests):${NC}"
echo -e "  export SERVER_PID=<PID from server>"
echo ""

# ========================================
# Interactive Tests
# ========================================
echo -e "${YELLOW}Would you like to run INTERACTIVE tests? (y/n)${NC}"
read -r INTERACTIVE

if [ "$INTERACTIVE" != "y" ]; then
    echo -e "${YELLOW}Skipping interactive tests. Running automated tests only...${NC}"
else
    echo ""
    echo -e "${BLUE}=== Starting Interactive Tests ===${NC}"
    echo ""
    echo -e "${YELLOW}Please start the server in another terminal and enter its PID:${NC}"
    read -r SERVER_PID

    if [ -z "$SERVER_PID" ]; then
        echo -e "${RED}No PID entered. Exiting.${NC}"
        exit 1
    fi

    # Test 1: Simple message
    print_test_header "1" "Simple message: 'Hello'"
    echo -e "${YELLOW}Running: ./client $SERVER_PID \"Hello\"${NC}"
    ./client $SERVER_PID "Hello"
    echo -e "${YELLOW}Check server output. Did you see 'Hello\\n'? (y/n)${NC}"
    read -r result
    [ "$result" = "y" ] && print_result 0 || print_result 1

    # Test 2: Message with spaces
    print_test_header "2" "Message with spaces: 'Hello World'"
    echo -e "${YELLOW}Running: ./client $SERVER_PID \"Hello World\"${NC}"
    ./client $SERVER_PID "Hello World"
    echo -e "${YELLOW}Check server output. Did you see 'Hello World\\n'? (y/n)${NC}"
    read -r result
    [ "$result" = "y" ] && print_result 0 || print_result 1

    # Test 3: Special characters
    print_test_header "3" "Special characters: '!@#\$%^&*()'"
    echo -e "${YELLOW}Running: ./client $SERVER_PID \"!@#\\\$%^&*()\"${NC}"
    ./client $SERVER_PID '!@#$%^&*()'
    echo -e "${YELLOW}Check server output. Did you see '!@#\$%^&*()'? (y/n)${NC}"
    read -r result
    [ "$result" = "y" ] && print_result 0 || print_result 1

    # Test 4: Numbers
    print_test_header "4" "Numbers: '1234567890'"
    echo -e "${YELLOW}Running: ./client $SERVER_PID \"1234567890\"${NC}"
    ./client $SERVER_PID "1234567890"
    echo -e "${YELLOW}Check server output. Did you see '1234567890'? (y/n)${NC}"
    read -r result
    [ "$result" = "y" ] && print_result 0 || print_result 1

    # Test 5: Long message
    print_test_header "5" "Long message"
    LONG_MSG="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor."
    echo -e "${YELLOW}Running: ./client $SERVER_PID \"$LONG_MSG\"${NC}"
    ./client $SERVER_PID "$LONG_MSG"
    echo -e "${YELLOW}Check server output. Did the full message appear correctly? (y/n)${NC}"
    read -r result
    [ "$result" = "y" ] && print_result 0 || print_result 1

    # Test 6: Multiple messages
    print_test_header "6" "Multiple messages"
    echo -e "${YELLOW}Running three messages in sequence...${NC}"
    ./client $SERVER_PID "First"
    sleep 0.5
    ./client $SERVER_PID "Second"
    sleep 0.5
    ./client $SERVER_PID "Third"
    echo -e "${YELLOW}Check server output. Did all three messages appear? (y/n)${NC}"
    read -r result
    [ "$result" = "y" ] && print_result 0 || print_result 1

    # Test 7: Unicode
    print_test_header "7" "Unicode characters"
    echo -e "${YELLOW}Running: ./client $SERVER_PID \"こんにちは\"${NC}"
    ./client $SERVER_PID "こんにちは"
    echo -e "${YELLOW}Check server output. Did Unicode display (any result OK)? (y/n)${NC}"
    read -r result
    [ "$result" = "y" ] && print_result 0 || print_result 0  # Always pass
fi

# ========================================
# Automated Tests (Error Handling)
# ========================================
echo ""
echo -e "${BLUE}=== Running Automated Tests ===${NC}"

# Test: No arguments
print_test_header "A1" "Client with no arguments"
./client 2>/dev/null
EXIT_CODE=$?
if [ $EXIT_CODE -ne 0 ]; then
    echo -e "${GREEN}Client correctly returned error (exit code: $EXIT_CODE)${NC}"
    print_result 0
else
    echo -e "${RED}Client should fail with no arguments${NC}"
    print_result 1
fi

# Test: Only one argument
print_test_header "A2" "Client with only PID"
./client 12345 2>/dev/null
EXIT_CODE=$?
if [ $EXIT_CODE -ne 0 ]; then
    echo -e "${GREEN}Client correctly returned error (exit code: $EXIT_CODE)${NC}"
    print_result 0
else
    echo -e "${RED}Client should fail with only one argument${NC}"
    print_result 1
fi

# Test: Build check
print_test_header "A3" "Compilation with flags"
make fclean > /dev/null 2>&1
make 2>&1 | tee /tmp/minitalk_build.txt
if grep -q "error" /tmp/minitalk_build.txt; then
    echo -e "${RED}Compilation errors found${NC}"
    print_result 1
elif grep -q "warning" /tmp/minitalk_build.txt; then
    echo -e "${YELLOW}Warnings found (check if acceptable)${NC}"
    grep "warning" /tmp/minitalk_build.txt
    print_result 1
else
    echo -e "${GREEN}Clean compilation${NC}"
    print_result 0
fi

# ========================================
# Final Summary
# ========================================
echo -e "\n${BLUE}========================================${NC}"
echo -e "${BLUE}Test Summary${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "Total tests: $TOTAL_TESTS"
echo -e "${GREEN}Passed: $TESTS_PASSED${NC}"
echo -e "${RED}Failed: $TESTS_FAILED${NC}"

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "\n${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    echo -e "\n${RED}Some tests failed! ✗${NC}"
    exit 1
fi
