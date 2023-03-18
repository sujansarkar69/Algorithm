#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    // Get current time
    time_t now = time(0);

    // Convert current time to tm struct
    tm *current_time = localtime(&now);

    // Prompt user for birth year
    int birth_year;
    cout << "Enter birth year: ";
    cin >> birth_year;

    // Prompt user for birth month
    int birth_month;
    cout << "Enter birth month: ";
    cin >> birth_month;

    // Prompt user for birth day
    int birth_day;
    cout << "Enter birth day: ";
    cin >> birth_day;

    // Convert birth year, month, and day to tm struct
    tm birthday = {0, 0, 0, birth_day, birth_month - 1, birth_year - 1900};

    // Calculate difference between current time and birth time
    double seconds = difftime(now, mktime(&birthday));
    double years = seconds / 31557600; // 31557600 seconds in a year

    // Output age in years
    cout << "Your age is " << years << " years." << endl;

    

    return 0;
}
