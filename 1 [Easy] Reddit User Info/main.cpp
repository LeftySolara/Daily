/* Challenge #1: Reddit User Info
 *
 * Ask the user for their name, age, and reddit username,
 * then tell them that information back.
 *
 * For extra credit, log this information in a file
 * to be accessed later.
 */

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

int main()
{
    string name;
    unsigned int age;
    string username;

    cout << "What is your name? ";
    cin >> name;
    cout << "How old are you? ";
    cin >> age;
    cout << "What is your reddit username? ";
    cin >> username;

    cout << "Your name is " << name << ", you are " << age
         << " years old, and your username is " << username << "." << endl;

    ofstream stream("user_info.txt", std::ios::app);
    stream << name << "," << age << "," << username << endl;

    if (stream.is_open())
        stream.close();

    return 0;
}
