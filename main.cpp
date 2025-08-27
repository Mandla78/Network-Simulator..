#include <iostream>
#include "../include/Simulator.h"
#include "../include/Node.h"
#include "../include/Packet.h"

int main() {
    int numPackets;

    // Ask user how many packets to send
    std::cout << "Enter number of packets Host1 should send to Host2: ";
    std::cin >> numPackets;

    // Create two hosts
    sim.nodes.push_back(std::make_shared<Node>(1, "Host1"));
    sim.nodes.push_back(std::make_shared<Node>(2, "Host2"));

    // Schedule initial packets from Host1 → Host2
    for (int i = 0; i < numPackets; i++) {
        Packet pkt(sim.nextPacketId++, 1, 2, 1024, false);
        auto dstNode = sim.nodes[pkt.dst - 1];
        Event e(i * 0.05, EventType::PACKET_ARRIVAL, dstNode, pkt);
        sim.scheduleEvent(e);

        std::cout << "Scheduled packet " << pkt.id
                  << " from Host1 to Host2 at time " << e.t << "\n";
    }

    // Run the simulation
    sim.run();
    return 0;
}
