<<<<<<< HEAD
using namespace std;
#include "Dijkstra.h" 

int main() {
    // Load the Florida graph in DIMACS format 

    const int numPairs = 200;
    Dijkstra<GRAPH> forwardDijkstra; 
    Dijkstra<GRAPH> backwardDijkstra; 

    double totalRuntime = 0.0;
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < numPairs; ++i) {
        Vertex source = vertexDistribution(gen);
        Vertex destination = vertexDistribution(gen);
        
        // Measure the runtime of Bi-directional Search
        clock_t start = clock();
         
        runBidirectionalSearch(forwardDijkstra, backwardDijkstra, source, destination);

        clock_t end = clock();
        double runtime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        totalRuntime += runtime;


        // Example:
        cout << "Shortest Path from " << source << " to " << destination << " = ";
        vector<Vertex> path = combinePaths(forwardDijkstra.getPath(destination), backwardDijkstra.getPath(source));
        for (Vertex vertex : path) {
            cout << vertex << " -> ";
        }
        cout << "Distance = " << calculateTotalDistance(path, forwardDijkstra, backwardDijkstra) << endl;
    }

    cout << "Total runtime in seconds for 200 random modified Dijkstra: " << totalRuntime << endl;

    return 0;
}
=======

>>>>>>> 77d9db69751448e985c17f4980d344221567e94a
