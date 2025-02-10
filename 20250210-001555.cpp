#include <iostream>
#include <map>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // Candidates
    vector<string> candidates = {"Adah", "Believe", "Abu", "Mimi"};
    map<string, int> votes; // Store votes

    // Initialize votes for each candidate
    for (const string& candidate : candidates) {
        votes[candidate] = 0;
    }

    cout << "Welcome to the Voting System!" << endl;
    cout << "=============================" << endl;

    // Display candidates
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i] << endl;
    }

    // Voting process
    while (true) {
        cout << "\nEnter the number of the candidate you want to vote for (or 0 to finish voting): ";
        int choice;
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input! Please enter a valid number.\n";
            continue;
        }

        if (choice == 0) break; // Exit voting

        if (choice >= 1 && choice <= candidates.size()) {
            votes[candidates[choice - 1]]++;
            cout << "Vote registered for " << candidates[choice - 1] << "!\n";
        } else {
            cout << "Invalid choice! Please choose a valid number from the list.\n";
        }
    }

    // Display results
    cout << "\nVoting Results:\n";
    cout << "=============================" << endl;
    string winner;
    int maxVotes = 0;

    for (const auto& pair : votes) {
        cout << pair.first << ": " << pair.second << " votes\n";
        if (pair.second > maxVotes) {
            maxVotes = pair.second;
            winner = pair.first;
        }
    }

    // Announce winner
    if (maxVotes == 0) {
        cout << "No votes were cast.\n";
    } else {
        cout << "\nThe winner is: " << winner << " with " << maxVotes << " votes!\n";
    }

    return 0;
}
