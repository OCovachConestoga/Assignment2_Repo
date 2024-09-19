#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// create the struct for student data
struct STUDENT_DATA {
	string firstName;
	string lastName;
};

int main() {

	// Create the list for the students
	vector<STUDENT_DATA> studentData;

	// Open the file of student names
	ifstream fin("StudentData.txt");

	// Checks if the file had issues opening
	if (!fin.is_open()) {
		cout << "ISSUE OPENING FILE" << endl;
		return 1;
	}

	// Create a temporary string to use for parsing
	string finString;

	// Loop through the file and parse the data
	while (std::getline(fin, finString)) {

		// Create temp variables and objects
		STUDENT_DATA tempStudent;

		// Convert to istringstream to parse data correctly
		istringstream line(finString);

		// Read the names from the string stream
		std::getline(line, tempStudent.firstName, ',');
		std::getline(line, tempStudent.lastName);


		// Add the student to the vector space
		studentData.push_back(tempStudent);
	}

	// Only runs this section in debug mode
	#ifdef _DEBUG
	// Loop through the vector space and print the names to show the data has been parsed
	for (STUDENT_DATA student : studentData) {
		cout << student.firstName << "," << student.lastName << endl;
	}
	#endif


	return 1;
}