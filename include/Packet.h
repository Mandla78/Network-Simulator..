#ifndef PACKET_H
#define PACKET_H

/// PACKET
// Represents a network packet exchanged between nodes.
// Each packet has an ID, source, destination, size, and ACK flag.
class Packet {
public:
    int id;         // Unique packet ID
    int src;        // Source node ID
    int dst;        // Destination node ID
    int sizeBytes;  // Size of packet in bytes
    bool isAck;     // True if this is an acknowledgment (ACK) packet

    // Constructor with default values
    Packet(int id = 0, int src = 0, int dst = 0, int sizeBytes = 0, bool isAck = false)
        : id(id), src(src), dst(dst), sizeBytes(sizeBytes), isAck(isAck) {}
};

#endif
