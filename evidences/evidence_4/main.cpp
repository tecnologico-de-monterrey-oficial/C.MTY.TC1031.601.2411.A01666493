#include "include/EuropeCities.h"

void displayMenu() {
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1. Display cities in alphabetical order" << std::endl;
    std::cout << "2. Save cities to file (output-1.out)" << std::endl;
    std::cout << "3. Display adjacency list" << std::endl;
    std::cout << "4. Save adjacency list to file (output-2.out)" << std::endl;
    std::cout << "5. Display graph traversals" << std::endl;
    std::cout << "6. Find shortest path between two cities" << std::endl; // New option
    std::cout << "7. Exit" << std::endl;
}

int main() {
    std::string filename = "data/EuropeCities.csv";
    EuropeCities europeCities;

    europeCities.readCSV(filename);

    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Cities in alphabetical order:" << std::endl;
                europeCities.printCities();
                break;
            case 2:
                europeCities.saveCitiesToFile("data/output-1.out");
                std::cout << "Cities saved to output-1.out" << std::endl;
                break;
            case 3:
                std::cout << "Adjacency List:" << std::endl;
                europeCities.printAdjList();
                break;
            case 4:
                europeCities.saveAdjListToFile("data/output-2.out");
                std::cout << "Adjacency list saved to output-2.out" << std::endl;
                break;
            case 5: {
                std::string startCity;
                std::cout << "Enter a valid start city: ";
                std::cin >> startCity;

                std::string bfsFilename = "data/output-3.out";
                std::string dfsFilename = "data/output-4.out";

                europeCities.bfs(startCity, bfsFilename);
                std::cout << "BFS traversal saved to " << bfsFilename << std::endl;

                europeCities.dfs(startCity, dfsFilename);
                std::cout << "DFS traversal saved to " << dfsFilename << std::endl;
                break;
            }
            case 6: {
                std::string startCity, endCity;
                std::cout << "Enter the start city: ";
                std::cin >> startCity;
                std::cout << "Enter the end city: ";
                std::cin >> endCity;

                europeCities.findShortestPath(startCity, endCity);
                break;
            }
            case 7:
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}