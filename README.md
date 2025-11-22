
# Simple WebSocket Echo Server

This project implements a minimal WebSocket server in pure C. Its primary purpose is to support testing scenarios where a deterministic WebSocket endpoint is required.

## Features

1. **PING/PONG Handling**
   When the server receives a WebSocket `PING` frame, it responds with a valid `PONG` frame.

2. **Echo Behavior**
   When the server receives any non-control WebSocket message (e.g., text or binary frames), it sends the message back to the client unchanged.

## Technical Specifications

* **Language:** C (ISO C / GNU C extensions as needed)
* **Compiler:** GCC (GNU Compiler Collection)
* **I/O Model:** Simple synchronous socket handling (unless changed in implementation)
* **Dependencies:** libcrypto

## Expected I/O Behavior

| Input Frame Type | Server Response                                 |
| ---------------- | ----------------------------------------------- |
| PING             | Sends a valid PONG frame                        |
| Text/Binary Data | Echoes the received payload                     |
| Close            | Performs the standard WebSocket close handshake |

## Intended Use

* Automated testing of WebSocket clients
* Local development or diagnostic tooling
* Environment validation where minimal WebSocket behavior is needed

## Build and Run (Example)

```
gcc -o ws_server main.c tcp.c -lcrypto
./ws_server <port>
```
