#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

Date parseDate(const  string& dateStr) {
    Date date;
     istringstream ss(dateStr);
    char delimiter;

    ss >> date.year >> delimiter >> date.month >> delimiter >> date.day;

    return date;
}

int calculateAge(const Date& birthdate, const Date& currentDate) {
    int age = currentDate.year - birthdate.year;

    // Adjust age based on the month and day of birthdate
    if (currentDate.month < birthdate.month ||
        (currentDate.month == birthdate.month && currentDate.day < birthdate.day)) {
        age--;
    }

    return age;
}

int main() {
     string birthdateStr;
     cout << "Enter your birthdate (YYYY-MM-DD): ";
     cin >> birthdateStr;

    Date birthdate = parseDate(birthdateStr);

    // Get current system date
    // We do not use any time-related functions to fetch the current date

    // Calculate current date based on system
    // Assuming we do not use time functions, we can use a simple approach
    // Here, we will use the system date directly from the Date structure

    // Get the current date based on system
    Date currentDate;
    // Example of currentDate set to system date
    currentDate.year = 2024; // Replace with actual system year
    currentDate.month = 7;   // Replace with actual system month
    currentDate.day = 17;    // Replace with actual system day

    int age = calculateAge(birthdate, currentDate);
    cout << endl;

     cout << "Your age is: " << age << " years." <<  endl;

    return 0;
}
