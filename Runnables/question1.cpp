#include <iostream>
#include <ctime>
#include "Dijkstra.h" 
using namespace std;

int main() {
    // Load the Florida graph in DIMACS format

    const int numPairs = 200;
    Dijkstra<GRAPH> dijkstra;

    double totalRuntime = 0.0;

    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < numPairs; ++i) {
         uniform_int_distribution<Vertex> vertexDistribution(0, );
        Vertex source = vertexDistribution(gen);
        Vertex destination = vertexDistribution(gen);
        
        // Measure the runtime of Dijkstra's algorithm
        clock_t start = clock();
        
        // Call Dijkstra's algorithm
        dijkstra.run(source, destination);

        clock_t end = clock();
        double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        totalRuntime += runtime;


        // Example:
        cout << "Shortest Path from " << source << " to " << destination << " = ";
        vector<Vertex> path = dijkstra.getPath(destination);
        for (Vertex vertex : path) {
            cout << vertex << " -> ";
        }
        cout << "Distance = " << dijkstra.getDistance(destination) << endl;
    }

    // Print the total runtime for 200 random Dijkstra's algorithm runs
    cout << "Total runtime in seconds for 200 random Dijkstra: " << totalRuntime << endl;

    return 0;
}

