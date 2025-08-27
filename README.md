## Network Simulator
This project simulates packet transmission between network nodes, including automatic acknowledgment (ACK) packets.  

-----

## Features
- Event-driven simulation: packets are scheduled and delivered in order of simulation time.
- Nodes can send and receive packets.
- Automatic ACKs for every received packet.
- Configurable number of packets to send.
- Modular design: separated into `Packet`, `Event`, `Node`, and `Simulator` classes.

------

## Project Structure
Network_Sim/
├── include/
│ ├── Packet.h
│ ├── Event.h
│ ├── Node.h
│ └── Simulator.h
├── src/
│ ├── main.cpp
│ ├── Node.cpp
│ └── Simulator.cpp
├── README.md
└── .gitignore

------

## Compilation & Running

### Using g++ (Windows / Linux / Mac)

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o network_sim 
./network_sim
