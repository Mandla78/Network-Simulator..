#include "../include/Node.h"
#include "../include/Simulator.h"
#include <iostream>

extern Simulator sim; // Use global simulator

// Constructor
Node::Node(int id, const std::string& name) : id(id), name(name) {}

// Handle packet arrival
void Node::onPacketArrival(const Packet& pkt) {
    std::cout << "[" << sim.currentTime << "] " << name
              << " received packet " << pkt.id << " from " << pkt.src << "\n";

    // If not an ACK, send one back
    if (!pkt.isAck) {
        sendAck(pkt);
    }
}

// Send an ACK packet in response
void Node::sendAck(const Packet& pkt) {
    Packet ack(sim.nextPacketId++, id, pkt.src, 40, true); // Create ACK packet

    // Destination node (the original sender)
    auto dstNode = sim.nodes[ack.dst - 1];

    // Create and schedule event with small delay
    Event e(sim.currentTime + 0.01, EventType::PACKET_ARRIVAL, dstNode, ack);
    sim.scheduleEvent(e);
}
