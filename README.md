# Keylogger

A simple keylogger in C++ that sends any collected information back to the penetration tester

# Usage

1. Change the ip and port according to the attacker machine
2. Compile the program and transfer the exe file generated to the target machine
3. Setup a netcat listner in the attacker machine. For linux ```nc -nvlp 5555```
4. Run the file in the target machine and get the keystrokes in the netcat



Note: Change the buffer size accordingly 
