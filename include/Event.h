#ifndef EVENT_H
#define EVENT_H


#include "Packet.h"
#include <memory>

class Node; // Forward declaration to avoid circular dependency

enum class EventType { PACKET_ARRIVAL }; // Event types

/// EVENT
// Represents a scheduled action in the simulation.
// Contains the time when it should occur, its type, the target node, and the associated packet.
struct Event {
    double t;
    EventType type;
    std::shared_ptr<Node> node;       // Node that will handle the event
    Packet pkt;

    // Constructor
    Event(double t, EventType type, std::shared_ptr<Node> node, const Packet& pkt)
        : t(t), type(type), node(node), pkt(pkt) {}
};

#endif
