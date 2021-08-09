#include <iostream>
#include <vector>

using namespace std;

//Note that graphs are stored as 2D arrays, where the i-th array stores the vertices that vertex i has an edge leading to.
bool adjacent(vector< vector<int> >& g, int i, int j) { //Determines whether or not there is an edge from vertex i to vertex j in the graph g.
    for (int k = 0; k < g[i].size(); k++) //Iterates through every edge leaving vertex i.
        if (g[i][k] == j) { //If there is an edge from vertex i to vertex j then we are done.
            return true;
        }
    return false;
}

void distances(vector< vector<int> >& g, int v0, vector<int>& dist) { //Calculates the distances between vertex v0 and every other vertex in the graph (or gives the distance as -1 if there is no path from v0 to the vertex).
    for (int i = 0; i < dist.size(); i++) {
        dist[i] = g.size() + 1; //The distance from v0 to each vertex is initialised to be one larger than the number of vertices in the graph.
    }
    dist[v0] = 0; //We say that there is a path from v0 to itself of length 0.
    for (int i = 0; i < g.size(); i++) { //The outermost loop iterates through the possible values for distance between vertices, which is one less than the total number of vertices.
        for (int j = 0; j < dist.size(); j++) { //The next loop iterates through each vertex.
            if (dist[j] == i) { //For each vertex j if the current distance from v0 to j is i then connections from j to other vertices are checked.
                for (int k = 0; k < g[j].size(); k ++) { //Iterates through each vertex k for which there is an edge from j to k.
                    if (dist[g[j][k]] > i + 1) { //For each vertex k for which there is an edge from j to k, if the current distance from v0 to k is listed as being larger than i + 1, then that value is replaced with i + 1, since we know there is a path of length i from v0 to j (since dist[j] = i) and a path of length 1 from j to k (since there is an edge from j to k.
                        dist[g[j][k]] = i + 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < g.size(); i++) { //Iterates through each vertex.
        if (dist[i] > g.size()) { //The distance from v0 to each vertex was initialised to be one larger than the number of vertices in the graph, so if any of the distances listed are still larger than the number of vertices in the graph then there must be no edge from v0 to that vertex.
            dist[i] = -1; //If there is no bath from v0 to i, then the distance from v0 to i is given as -1.
        }
    }
}

bool connected(vector< vector<int> >& g) { //Determines whether the graph g is connected, i.e. whether or not there is a path from every vertex to every other vertex.
    vector<int> dist(g.size());
    for (int i = 0; i < g.size(); i++) {
        distances(g, i, dist); //Iterating through the vertices in g, the distance from each vertex to each other vertex is calculated.
        for (int j = 0; j < dist.size(); j++) {
            if (dist[j] == -1) { //If any of the calculated distances are given the value -1, then there exist two vertices i and j such that there is no path from i to j. Hence the graph is not connected.
                return false;
            }
        }
    }
    return true; //If none of the calculated distances are given the value -1, then for every pair of vertices i and j there is a path from i to j and so the graph is connected.
}

int main() {
    return 0;
}
