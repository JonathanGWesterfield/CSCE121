#include <iostream>
#include <string>
#include <limits>
#include "Library.h"
using namespace std;

void printMenu() {
	cout << "Menu: " << endl;
	cout << "1: Add Book" << endl;
	cout << "2: Delete Book" << endl;
	cout << "3: Print Book" << endl;
	cout << "4: List Books" << endl;
	cout << "5: Check Out Book" << endl;
	cout << "6: Check In Book" << endl;
	cout << "7: Set Library Name" << endl;
	cout << "8: Show Library Name" << endl;
	cout << "Q: Quit" << endl;
}

int getISBN() {
	int isbn;
	cout << "Enter ISBN: ";
	cin >> isbn;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// remove end of line for next input
	return isbn;
}

void addBook(Library& lib) {
	string title, author;
	cout << "Enter title: ";
	getline(cin, title);
	cout << "Enter author: ";
	getline(cin, author);
	int isbn = getISBN();
	lib.addBook(isbn, title, author);
}

string getLibraryName() {
	string name;
	cout << "Enter name of library: ";
	getline(cin, name);
	return name;
}

void processChoice(char choice, Library& lib) {
	switch (choice) {
	case '1':
		addBook(lib);
		break;
	case '2':
		lib.deleteBook(getISBN());
		break;
	case '3':
		cout << lib.printBook(getISBN());
		break;
	case '4':
		cout << lib.listBooks();
		break;
	case '5':
		lib.checkout(getISBN());
		break;
	case '6':
		lib.checkin(getISBN());
		break;
	case '7':
		lib.setName(getLibraryName());
		break;
	case '8':
		cout << "Library Name: " << lib.getName() << endl;
		break;
	}
}

int main() {
	string name;
	char choice = ' ';
	Library lib = Library(getLibraryName());

	while (choice != 'q') {
		printMenu();
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// strip end of line for next input
		choice = tolower(choice);
		try {
			processChoice(choice, lib);
		}
		catch (runtime_error& exc) {
			cout << exc.what() << endl;
		}
	}
	cout << "Goodbye";
}