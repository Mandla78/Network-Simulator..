#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>
#include "Packet.h"
#include "Event.h"

class Simulator; // Forward declaration

/// Node
// Represents a network node (e.g., host, router)
// A node can receive packets and send acknowledgments
class Node {
public:
    int id;
    std::string name;
    Node(int id, const std::string& name);

    // Called when a packet arrives at this node
    void onPacketArrival(const Packet& pkt);

private:
    // Helper function to send an ACK packet back to the source
    void sendAck(const Packet& pkt);
};

#endif
