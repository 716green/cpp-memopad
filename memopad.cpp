#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <streambuf>
using namespace std;

int main () {
  // Define vars
  ofstream cppNotes;
  string note;

  // Read Existing Note and save body to noteBody string variable
  ifstream t("memopad.txt");
  string noteBody((istreambuf_iterator<char>(t)),
      istreambuf_iterator<char>());

  cout << "Welcome to memopad" << endl;
  // Open file named cppNotes.txt in root folder of this app
  cppNotes.open("memopad.txt");

  // Prompt user for note and save user input to "note" string variable
  cout << "Enter 'clear' to clear memopad\n\nEnter Note:" << endl;
  getline(cin, note);


  if (note == "clear") {
    noteBody = "";
    note = "";
    cout << "memos cleared" << endl;
  } 

  // Create string of previous body followed by new note with line breaks
  cppNotes << noteBody << "\n" << note << "\n";

  cppNotes.close();
  return 0;
}