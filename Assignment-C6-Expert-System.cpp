#include <iostream>
using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n===== HELP DESK EXPERT SYSTEM =====\n";
        cout << "1. Internet not working\n";
        cout << "2. Computer not starting\n";
        cout << "3. Slow system performance\n";
        cout << "4. Printer not working\n";
        cout << "5. Software installation issue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting system. Thank you!\n";
            break;
        }

        cout << "\n--- Solution ---\n";

        switch(choice) {
            case 1:
                cout << "Check router power.\n";
                cout << "Restart router.\n";
                cout << "Check cables.\n";
                cout << "Contact ISP if problem persists.\n";
                break;

            case 2:
                cout << "Check power supply.\n";
                cout << "Check battery/UPS.\n";
                cout << "Ensure cables are properly connected.\n";
                break;

            case 3:
                cout << "Close unused programs.\n";
                cout << "Check for viruses.\n";
                cout << "Increase RAM if needed.\n";
                break;

            case 4:
                cout << "Check printer connection.\n";
                cout << "Ensure printer is ON.\n";
                cout << "Reinstall printer drivers.\n";
                break;

            case 5:
                cout << "Check system requirements.\n";
                cout << "Run installer as administrator.\n";
                cout << "Disable antivirus temporarily.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}