#include<iostream>
#include<string>
#include<fstream>
int GetVehicleFormFile(struct VEHICAL[]);
void PresistVehicle(struct VEHICAL[]);
using namespace std;
struct VEHICAL {
	char Type;
	string Color;
	string Manufactur;
	int Year;
	int CC;
};
void VehicalInput(struct VEHICAL[], int);
string InputColor();
void SearchAndDisplayVehical(string, struct VEHICAL[], int);
void DisplayVehical(struct VEHICAL*);

int main() {
	string fileName = "store.txt";
	struct VEHICAL vehical[5];

	ifstream MyReadFile(fileName, ios::in);

	// If file exists
	if (MyReadFile) {
		cout << "File exists. You can search the data." << endl << endl;
		string myText;
		int n = 0;
		int lineCounter = 0;
		while (getline(MyReadFile, myText)) {
			// Output the text from the file
			if (lineCounter == 0) {
				vehical[n].Type = myText.at(0);
			}
			else if (lineCounter == 1) {
				vehical[n].Color = myText;
			}
			else if (lineCounter == 2) {
				vehical[n].Manufactur = myText;
			}
			else if (lineCounter == 3) {
				int num = std::stoi(myText);
				vehical[n].Year = num;
			}
			else if (lineCounter == 4) {
				int num = std::stoi(myText);
				vehical[n].CC = num;
			}
			lineCounter += 1;
			if (lineCounter == 5) {
				lineCounter = 0;
				n += 1;
			}
		}
		cout << endl;

		// Close the file
		MyReadFile.close();


		string takeUserInput = "";
		do {
			string color = InputColor();
			SearchAndDisplayVehical(color, vehical, n);

			cout << endl << "Do you want to continue (y/n) ?";
			cin >> takeUserInput;
			system("CLS");
		} while (takeUserInput == "Y" || takeUserInput == "y");
	}
	// If file doesn't exist
	else {
		cout << "File doesn't exist. Please save data first." << endl << endl;

		int n = 0;
		do {
			cout << "Enter how many entries you want to make : ";
			cin >> n;

		} while (n < 1 || n > 5);


		VehicalInput(vehical, n);

		// Create and open a text file
		ofstream MyFile(fileName, ios::trunc);

		// Write to the file
		for (int i = 0; i < n; i++) {
			MyFile << vehical[i].Type << endl;
			MyFile << vehical[i].Color << endl;
			MyFile << vehical[i].Manufactur << endl;
			MyFile << vehical[i].Year << endl;
			MyFile << vehical[i].CC << endl;
		}
		// Close the file
		MyFile.close();

		cout << endl << "Data saved successfully";
	}

	//cout << endl << "Data saved\n" << endl;
	// string takeUserInput = "";
	// do{
	// 	string color = InputColor();
	// 	SearchAndDisplayVehical(color, vehical, n);

	// 	cout << endl << "Do you want to continue (y/n) ?";
	// 	cin >> takeUserInput;
	// 	system("CLS");
	// } while (takeUserInput == "Y" || takeUserInput == "y");

	//// Create a text string, which is used to output the text file
	//string myText;

	//// Read from the text file
	//ifstream MyReadFile(fileName, ios::in);

	//// Use a while loop together with the getline() function to read the file line by line
	//while (getline(MyReadFile, myText)) {
	//	// Output the text from the file
	//	cout << myText << endl;
	//}
	//cout << endl;
	//// Close the file
	//MyReadFile.close();
}
void VehicalInput(struct VEHICAL v[], int n) {
	//m.open("Data.txt");

	for (int i = 0; i < n; i++) {
		do {
			cout << "Enter type ";
			cin >> v[i].Type;
		} while (v[i].Type != 'C' && v[i].Type != 'c' && v[i].Type != 'M' && v[i].Type != 'm');
		cout << "Enter colour" << endl;
		//getline(cin, v[i].Color);
		cin >> v[i].Color;
		cout << "Enter Manufactor year" << endl;
		//getline(cin, v[i].Manufactur);
		cin >> v[i].Manufactur;
		cout << "Vehical year" << endl;
		cin >> v[i].Year;
		cout << "Vehical CC" << endl;
		cin >> v[i].CC;
		//m << "Type," << v[i].Type << ",Color," << v[i].Color << ",Manufactor," << v[i].Manufactur << ",CC," << v[i].CC << endl;

	}
	system("CLS");
}
string InputColor() {
	cout << "Enter the vehical color\n";
	string c;
	//getline(cin, c);
	cin >> c;
	return c;
}
void SearchAndDisplayVehical(string c, struct VEHICAL v[], int n) {
	for (int i = 0; i < n; i++) {
		if (c == v[i].Color) {
			DisplayVehical(&v[i]);
		}
	}
}
void DisplayVehical(struct VEHICAL* v) {
	cout << "Type : " << (*v).Type << endl;
	cout << "colour : " << (*v).Color << endl;
	cout << "Manufactor : " << (*v).Manufactur << endl;
	cout << "Year : " << (*v).Year << endl;
	cout << "CC : " << (*v).CC << endl<< endl;
}