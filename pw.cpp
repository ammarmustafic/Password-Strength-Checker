#include <iostream>
#include <string>

using namespace std;

bool hasLowerCase(const string& password) {
    for (char c : password) {
        if (islower(c)) {
            return true;
        }
    }
    return false;
}

bool hasUpperCase(const string& password) {
    for (char c : password) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

bool hasDigit(const string& password) {
    for (char c : password) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}

bool hasSpecialChar(const string& password) {
    for (char c : password) {
        if (!isalnum(c)) {
            return true;
        }
    }
    return false;
}

bool isStrongPassword(const string& password) {
    if (password.length() < 8) {
        return false;
    }

    if (!hasLowerCase(password)) {
        return false;
    }

    if (!hasUpperCase(password)) {
        return false;
    }

    if (!hasDigit(password)) {
        return false;
    }

    if (!hasSpecialChar(password)) {
        return false;
    }

    return true;
}

void suggestPasswordStrength(const string& password) {
    if (password.length() < 8) {
        cout << "Add more characters to increase password length." << endl;
    }

    if (!hasLowerCase(password)) {
        cout << "Include at least one lowercase letter." << endl;
    }

    if (!hasUpperCase(password)) {
        cout << "Include at least one uppercase letter." << endl;
    }

    if (!hasDigit(password)) {
        cout << "Include at least one digit." << endl;
    }

    if (!hasSpecialChar(password)) {
        cout << "Include at least one special character." << endl;
    }
}

int main() {
    string password;

    cout << "Enter your password: ";
    getline(cin, password);

    if (isStrongPassword(password)) {
        cout << "Strong password!" << endl;
    } else {
        cout << "Weak password!" << endl;
        cout << "Suggestions to improve password:" << endl;
        suggestPasswordStrength(password);
    }

    return 0;
}
