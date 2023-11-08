#include <iostream>
using namespace std;

// Structure to represent a memory block
struct MemoryBlock {
    int blockSize;
    bool allocated;
};

int main() {
    int memorySize, numProcesses;

    cout << "Enter the size of memory: ";
    cin >> memorySize;
    
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    // Create an array of memory blocks
    MemoryBlock memory[memorySize];

    for (int i = 0; i < memorySize; i++) {
        memory[i].blockSize = 0;
        memory[i].allocated = false;
    }

    int processSizes[numProcesses];

    // Input the sizes of processes
    for (int i = 0; i < numProcesses; i++) {
        cout << "Enter the size of Process " << i + 1 << ": ";
        cin >> processSizes[i];
    }

    int lastAllocated = 0;

    for (int i = 0; i < numProcesses; i++) {
        int processSize = processSizes[i];

        // Search for the next fit memory block
        while (true) {
            if (!memory[lastAllocated].allocated && memory[lastAllocated].blockSize >= processSize) {
                memory[lastAllocated].allocated = true;
                memory[lastAllocated].blockSize = processSize;
                cout << "Allocated Process " << i + 1 << " to Memory Block " << lastAllocated << endl;
                break;
            }

            lastAllocated = (lastAllocated + 1) % memorySize; // Wrap around if needed
        }
    }

    cout << "Memory Block Allocation:\n";
    for (int i = 0; i < memorySize; i++) {
        if (memory[i].allocated) {
            cout << "Block " << i << " is allocated with size " << memory[i].blockSize << endl;
        } else {
            cout << "Block " << i << " is free" << endl;
        }
    }

    return 0;
}
