//MT KHOWANE.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struct to store artist information
struct Artist {
    string name;
    string genre;
    double performanceFee;
    bool available;
};

// Function prototypes
int loadArtistsFromUser(Artist arr[]); // Declaration for loading artist data
void displayArtistInfo(Artist arr[], int count, bool onlyAvailable=false, string genre=""); // Declaration for displaying artists
double calcPerformanceTotal(Artist arr[], int count); // Declaration for calculating total fees

int main() {
    const int MAX_ARTISTS = 20;
    Artist artists[MAX_ARTISTS];
    int numArtists = loadArtistsFromUser(artists);  // Calling the load function

    int choice;
    do {
        cout << "\n--- Festival Line-Up Menu ---\n";
        cout << "1. Display All Artists\n";
        cout << "2. Display Only Available Artists\n";
        cout << "3. Display Artists by Genre\n";
        cout << "4. Show Total Performance Fees\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from buffer

        switch(choice) {
            case 1:
                displayArtistInfo(artists, numArtists);  // Calling to display all artists
                break;
            case 2:
                displayArtistInfo(artists, numArtists, true);  // Calling to display only available artists
                break;
            case 3: {
                string genre;
                cout << "Enter genre to filter by: ";
                getline(cin, genre);  // Taking genre input
                displayArtistInfo(artists, numArtists, false, genre);  // Calling to display artists by genre
                break;
            }
            case 4: {
                double total = calcPerformanceTotal(artists, numArtists);  // Calling to calculate total fees
                cout << "Total performance fees (available artists): R"
                     << total << endl;
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while(choice != 0);

    return 0;
}

// Function to load artist data from the user
int loadArtistsFromUser(Artist arr[]) {
    int n;
    cout << "How many artists do you want to enter? ";
    cin >> n;
    cin.ignore();  // To consume the newline character

    for(int i = 0; i < n; i++) {
        cout << "\nEnter details for Artist " << (i + 1) << ":\n";
        cout << "Name: ";
        getline(cin, arr[i].name);
        cout << "Genre: ";
        getline(cin, arr[i].genre);
        cout << "Performance Fee: ";
        cin >> arr[i].performanceFee;
        cout << "Available? (1 for Yes, 0 for No): ";
        int avail;
        cin >> avail;
        arr[i].available = (avail == 1);
        cin.ignore();  // To consume the newline character
    }
    return n;  // Returning the number of artists
}

// Function to display artist info
void displayArtistInfo(Artist arr[], int count, bool onlyAvailable, string genre) {
    cout << left << setw(20) << "Name"
         << setw(15) << "Genre"
         << setw(10) << "Fee"
         << setw(12) << "Available" << endl;
    cout << "------------------------------------------------\n";

    for(int i = 0; i < count; i++) {
        if(onlyAvailable && !arr[i].available) continue;  // If only available artists, skip unavailable
        if(genre != "" && arr[i].genre != genre) continue;  // If genre is provided, filter by it

        cout << left << setw(20) << arr[i].name
             << setw(15) << arr[i].genre
             << setw(10) << arr[i].performanceFee
             << setw(12) << (arr[i].available ? "Yes" : "No")
             << endl;
    }
}

// Function to calculate total performance fees of available artists
double calcPerformanceTotal(Artist arr[], int count) {
    double total = 0;
    for(int i = 0; i < count; i++) {
        if(arr[i].available) {
            total += arr[i].performanceFee;  // Add performance fee of available artists
        }
    }
    return total;  // Returning total performance fee
}

