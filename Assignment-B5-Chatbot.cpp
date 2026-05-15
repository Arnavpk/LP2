#include <iostream>
#include <string>
using namespace std;

int main() {
    string userInput;

    cout << "Welcome to Customer Support Chatbot!\n";
    cout << "Type 'exit' to end the chat.\n\n";

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        if (userInput == "exit") {
            cout << "Bot: Thank you for visiting. Goodbye!\n";
            break;
        }

        else if (userInput == "hello" || userInput == "hi") {
            cout << "Bot: Hello! How can I help you today?\n";
        }

        else if (userInput == "price") {
            cout << "Bot: Our product price starts from Rs. 999.\n";
        }

        else if (userInput == "services") {
            cout << "Bot: We offer repair, installation, and maintenance services.\n";
        }

        else if (userInput == "hours") {
            cout << "Bot: We are open from 9 AM to 6 PM, Monday to Saturday.\n";
        }

        else if (userInput == "contact") {
            cout << "Bot: You can contact us at support@example.com.\n";
        }

        else {
            cout << "Bot: Sorry, I didn't understand that. Please try again.\n";
        }
    }

    return 0;
}