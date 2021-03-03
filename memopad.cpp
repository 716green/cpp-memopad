#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <streambuf>

#include "functions.h"

using namespace std;

int main()
{
  // Define vars
  ofstream cppNotes;
  string note;

  // Read Existing Note and save body to noteBody string variable
  ifstream t("memopad.txt");
  string noteBody((istreambuf_iterator<char>(t)),
                  istreambuf_iterator<char>());

  cout << "Welcome to memopad" << endl;

// Prompt user for note and save user input to "note" string variable
PROMPT:
  cout << "=====memopad=====\n"
       << "'clear' memopad\n" 
       << "'read' notes\n"
       << "'close' memopad\n"
      //  todo - save
      //  << "'save' as\n"
       << "or\n" 
       << "Enter Note:" 
       << endl;
  getline(cin, note);

  if (note == "clear")
  {
    // Clear notes
    noteBody = "";
    note = "";
    cout << "memos cleared" << endl;
  }
  // else if (note == "save")
  // {

  //   if (is_whitespace(noteBody))
  //   {
  //     cout << "No Notes" << endl;
  //     goto PROMPT;
  //   }
  //   else
  //   {
  //     // Display Notes
  //     cout << "=================" 
  //     << noteBody 
  //     << "=================\n"
  //     << endl;
  //   }
  //   // Get filename
  //   string filename;
  //   getline(cin, filename);
  //   // todo - add new file


  // }
  else if (note == "read")
  {
    // Display current notes and back to prompt

    // Check if memopad consists only of whitespaces
    bool whiteSpacesOnly = is_whitespace(noteBody);
    if (whiteSpacesOnly)
    {
      cout << "No Notes" << endl;
    }
    else
    {
      // Display Notes
      cout << "=================" << noteBody << "=================\n"
           << endl;
    }
    goto PROMPT;
  }
  else if (note == "close")
  {
    // close without modification
    cppNotes << noteBody;
  }
  else if (!note.empty())
  {
    // Create string of previous body followed by new note with line breaks
    // Open file named cppNotes.txt in root folder of this app
    cppNotes.open("memopad.txt");

    cppNotes << noteBody << "\n"
             << note << "\n";
    cppNotes.close();
  }
  else
  {
    cppNotes << noteBody;
  }

  cppNotes.close();
  return 0;
}

// Function to test for notes that are only whitespace (empty notes)
bool is_whitespace(const string &s)
{
  for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
  {
    if (!isspace(*it))
    {
      return false;
    }
  }
  return true;
}