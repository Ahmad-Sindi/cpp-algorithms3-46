#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*
 * Algorithm Challenge – Level 3 | #46 Convert Line Data to Record Structure
 *
 * This program demonstrates how to convert a single line of text data (stored in a file-like format) into a structured record using C++.
 *
 * The algorithm simulates reading a client record from a text document,
 * then:
 *   1. Splits the line using a custom separator.
 *   2. Converts the extracted values into a structured data type.
 *   3. Prints the structured record in a readable format.
 *
 * This approach is commonly used in real-world systems that rely on text files or flat files for data storage instead of databases.
 */

// Structure that represents a client record
struct StructClientData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

// Splits a string based on a given delimiter and returns tokens as a vector
vector<string> SplitString(string S1, string Delimiter)
{
    vector<string> vString;
    short Position = 0;
    string Token;

    // Loop until no delimiter is found
    while ((Position = S1.find(Delimiter)) != string::npos)
    {
        Token = S1.substr(0, Position);

        // Avoid storing empty tokens
        if (Token != "")
        {
            vString.push_back(Token);
        }

        // Remove processed part from the string
        S1.erase(0, Position + Delimiter.length());
    }

    // Store the last remaining part
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

// Converts a single line of text into a structured client record
StructClientData ConvertLineToRecord(string Line, string Separator = "#//#")
{
    StructClientData Client;
    vector<string> vClientData;

    // Split the line into individual fields
    vClientData = SplitString(Line, Separator);

    // Map the extracted values to the structure
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // Convert string to double

    return Client;
}

// Prints the client record in a formatted output
void PrintClientRecord(StructClientData Client)
{
    cout << "The following is the extracted client record:\n";
    cout << "Account Number  : " << Client.AccountNumber << endl;
    cout << "PIN Code        : " << Client.PinCode << endl;
    cout << "Name            : " << Client.Name << endl;
    cout << "Phone Number    : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

int main()
{
    // Simulated line read from a text document
    string stLine = "A150#//#22566#//#Hassan Ahmad#//#987654321#//#15000.500";

    cout << "Line Record:\n" << stLine << "\n\n";

    // Convert line data into a structured record
    StructClientData ClientData = ConvertLineToRecord(stLine);

    // Display the extracted record
    PrintClientRecord(ClientData);

    return 0;
}
