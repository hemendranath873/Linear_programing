#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// Custom data types for handling the user credentials
struct User
{
    string userId;
    string password;
};

bool login(const vector<User> &users)
{
    string userId, password;
    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> password;

    for (const auto &user : users)
    {
        if (user.userId == userId && user.password == password)
        {
            return true;
        }
    }
    return false;
}

void menu();
void tourMenu();
void findShortestPath(const vector<vector<int>> &distanceMatrix, int start, const vector<string> &places);

int main()
{
    vector<User> users = {{"user1", "pass1"}, {"user2", "pass2"}};
    bool loggedIn = false;

    while (!loggedIn)
    {
        cout << "Welcome to the Tour Management System\n";
        if (login(users))
        {
            loggedIn = true;
            menu();
        }
        else
        {
            cout << "Incorrect User ID or Password. Please try again.\n";
        }
    }

    return 0;
}

void menu()
{
    int choice;
    do
    {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Plan a Tour\n";
        cout << "2. Help or Guide\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tourMenu();
            break;
        case 2:
            cout << "Tour Guide: Information about tours, famous places, and emergency situations.\n";
            break;
        case 3:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    } while (choice != 3);
}

void tourMenu()
{
    int choice;
    do
    {
        cout << "\n--- Tour Menu ---\n";
        cout << "1. Plan a visit to Famous Places\n";
        cout << "2. Find Hotels\n";
        cout << "3. Discover Restaurants\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            vector<string> places;
            int n;
            cout << "\nEnter the number of famous places you want to visit (minimum 5): ";
            cin >> n;
            if (n < 5)
            {
                cout << "Please enter at least 5 places.\n";
                break;
            }
            places.resize(n);
            cout << "Enter the names of the famous places you want to visit:\n";
            for (int i = 0; i < n; ++i)
            {
                cout << "Place " << i + 1 << ": ";
                cin >> places[i];
            }

            int start;
            cout << "Enter the index of the starting place (0 for " << places[0] << ", 1 for " << places[1] << ", ...): ";
            cin >> start;
            if (start < 0 || start >= n)
            {
                cout << "Invalid starting place index. Please try again.\n";
                break;
            }

            vector<vector<int>> distanceMatrix(n, vector<int>(n));
            cout << "Enter the distances between each pair of places (in km):\n";
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i != j)
                    {
                        cout << "Distance from " << places[i] << " to " << places[j] << ": ";
                        cin >> distanceMatrix[i][j];
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter numeric values only.\n";
                            return;
                        }
                    }
                    else
                    {
                        distanceMatrix[i][j] = 0; // Distance from a place to itself is 0
                    }
                }
            }

            findShortestPath(distanceMatrix, start, places);
            break;
        }
        case 2:
            {
            vector<string> hotels;
            int n;
            cout << "\nEnter the number of famous Hotels you want to visit (minimum 5): ";
            cin >> n;
            if (n < 5)
            {
                cout << "Please enter at least 5 Hotels.\n";
                break;
            }
            hotels.resize(n);
            cout << "Enter the names of the famous Hotels you want to visit:\n";
            for (int i = 0; i < n; ++i)
            {
                cout << "Hotels " << i + 1 << ": ";
                cin >> hotels[i];
            }

            int start;
            cout << "Enter the index of the starting place (0 for " << hotels[0] << ", 1 for " << hotels[1] << ", ...): ";
            cin >> start;
            if (start < 0 || start >= n)
            {
                cout << "Invalid starting hotel index. Please try again.\n";
                break;
            }

            vector<vector<int>> distanceMatrix(n, vector<int>(n));
            cout << "Enter the distances between each pair of hotels (in km):\n";
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i != j)
                    {
                        cout << "Distance from " << hotels[i] << " to " << hotels[j] << ": ";
                        cin >> distanceMatrix[i][j];
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter numeric values only.\n";
                            return;
                        }
                    }
                    else
                    {
                        distanceMatrix[i][j] = 0; // Distance from a place to itself is 0
                    }
                }
            }

            findShortestPath(distanceMatrix, start, hotels);
            break;
        }
        case 3:
            {
            vector<string> restaurants;
            int n;
            cout << "\nEnter the number of famous Restaurants you want to visit (minimum 5): ";
            cin >> n;
            if (n < 5)
            {
                cout << "Please enter at least 5 Restaurants.\n";
                break;
            }
            restaurants.resize(n);
            cout << "Enter the names of the famous Restaurants you want to visit:\n";
            for (int i = 0; i < n; ++i)
            {
                cout << "Restaurants " << i + 1 << ": ";
                cin >> restaurants[i];
            }

            int start;
            cout << "Enter the index of the starting restaurant (0 for " << restaurants[0] << ", 1 for " << restaurants[1] << ", ...): ";
            cin >> start;
            if (start < 0 || start >= n)
            {
                cout << "Invalid starting restaurant index. Please try again.\n";
                break;
            }

            vector<vector<int>> distanceMatrix(n, vector<int>(n));
            cout << "Enter the distances between each pair of restaurants (in km):\n";
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i != j)
                    {
                        cout << "Distance from " << restaurants[i] << " to " << restaurants[j] << ": ";
                        cin >> distanceMatrix[i][j];
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter numeric values only.\n";
                            return;
                        }
                    }
                    else
                    {
                        distanceMatrix[i][j] = 0; // Distance from a place to itself is 0
                    }
                }
            }

            findShortestPath(distanceMatrix, start, restaurants);
            break;
        }
        case 4:
            cout << "Returning to the main menu...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);
}

void findShortestPath(const vector<vector<int>> &distanceMatrix, int start, const vector<string> &places)
{
    int n = distanceMatrix.size();
    vector<int> vertex;
    for (int i = 0; i < n; i++)
    {
        if (i != start)
        {
            vertex.push_back(i);
        }
    }

    int minPath = numeric_limits<int>::max();
    vector<int> bestPath;

    do
    {
        int currentPathWeight = 0;
        int k = start;
        for (int i = 0; i < vertex.size(); i++)
        {
            currentPathWeight += distanceMatrix[k][vertex[i]];
            k = vertex[i];
        }
        currentPathWeight += distanceMatrix[k][start];

        if (currentPathWeight < minPath)
        {
            minPath = currentPathWeight;
            bestPath = vertex;
        }

    } while (next_permutation(vertex.begin(), vertex.end()));

    cout << "\nThe shortest path has a total distance of: " << minPath << " km.\n";
    cout << "The path is:\n";
    cout << places[start];
    for (int i = 0; i < bestPath.size(); ++i)
    {
        cout << " -> " << places[bestPath[i]];
    }
    cout << " -> " << places[start] << "\n";
}
