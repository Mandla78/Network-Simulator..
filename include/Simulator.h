#ifndef SIMULATOR_H
#define SIMULATOR_H


#include <vector>
#include <memory>
#include "Event.h"
#include "Node.h"

/// Simulator
// Controls the simulation, including time, events, and nodes.
// Responsible for scheduling and executing events in order.
class Simulator {
public:
    double currentTime;
    std::vector<Event> events;
    std::vector<std::shared_ptr<Node>> nodes; // List of participating nodes
    int nextPacketId;

    Simulator(); // Constructor

    // Schedule a new event in the simulation
    void scheduleEvent(const Event& e);

    // Run the simulation (process all events in order)
    void run();

private:
    // Sort events by time (earliest first)
    void sortEvents();
};

// Global instance of Simulator
extern Simulator sim;

#endif
