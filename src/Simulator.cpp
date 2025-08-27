#include "../include/Simulator.h"
#include <algorithm>
#include <iostream>

// Define global simulator instance
Simulator sim;

// Constructor
Simulator::Simulator() : currentTime(0.0), nextPacketId(1) {}

// Add new event to the event list
void Simulator::scheduleEvent(const Event& e) {
    events.push_back(e);
}

// Sort events in ascending order of scheduled time
void Simulator::sortEvents() {
    std::sort(events.begin(), events.end(),
              [](const Event& a, const Event& b) { return a.t < b.t; });
}

// Run the simulation until no events remain
void Simulator::run() {
    while (!events.empty()) {
        sortEvents();          // Process earliest event first
        Event ev = events.front();
        events.erase(events.begin());

        currentTime = ev.t;    // Advance time
        if (ev.type == EventType::PACKET_ARRIVAL && ev.node) {
            ev.node->onPacketArrival(ev.pkt);
        }
    }

    std::cout << "Simulation finished at time " << currentTime << "\n";
}
