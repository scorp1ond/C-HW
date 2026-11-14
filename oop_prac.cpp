#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cmath>

// Task 1: Student.
class Student {
private:
	std::string fullName;
	std::string birthDate;
	std::string phone;
	std::string city;
	std::string country;
	std::string institution;
	std::string institutionCity;
	std::string institutionCountry;
	std::string groupNumber;

public:
	const std::string& getFullName() const { return fullName; }
	const std::string& getBirthDate() const { return birthDate; }
	const std::string& getPhone() const { return phone; }
	const std::string& getCity() const { return city; }
	const std::string& getCountry() const { return country; }
	const std::string& getInstitution() const { return institution; }
	const std::string& getInstitutionCity() const { return institutionCity; }
	const std::string& getInstitutionCountry() const { return institutionCountry; }
	const std::string& getGroupNumber() const { return groupNumber; }

	void setFullName(const std::string& value) { fullName = value; }
	void setBirthDate(const std::string& value) { birthDate = value; }
	void setPhone(const std::string& value) { phone = value; }
	void setCity(const std::string& value) { city = value; }
	void setCountry(const std::string& value) { country = value; }
	void setInstitution(const std::string& value) { institution = value; }
	void setInstitutionCity(const std::string& value) { institutionCity = value; }
	void setInstitutionCountry(const std::string& value) { institutionCountry = value; }
	void setGroupNumber(const std::string& value) { groupNumber = value; }

	bool input() {
		Student data;
		std::cout << "Full name: ";
		if (!std::getline(std::cin, data.fullName)) return false;
		std::cout << "Birth date (DD.MM.YYYY): ";
		if (!std::getline(std::cin, data.birthDate)) return false;
		std::cout << "Phone: ";
		if (!std::getline(std::cin, data.phone)) return false;
		std::cout << "City: ";
		if (!std::getline(std::cin, data.city)) return false;
		std::cout << "Country: ";
		if (!std::getline(std::cin, data.country)) return false;
		std::cout << "Educational institution: ";
		if (!std::getline(std::cin, data.institution)) return false;
		std::cout << "Institution city: ";
		if (!std::getline(std::cin, data.institutionCity)) return false;
		std::cout << "Institution country: ";
		if (!std::getline(std::cin, data.institutionCountry)) return false;
		std::cout << "Group number: ";
		if (!std::getline(std::cin, data.groupNumber)) return false;
		*this = data;
		return true;
	}

	void print() const {
		std::cout << "Full name: " << fullName
			<< "\nBirth date: " << birthDate
			<< "\nPhone: " << phone
			<< "\nCity: " << city
			<< "\nCountry: " << country
			<< "\nEducational institution: " << institution
			<< "\nInstitution city: " << institutionCity
			<< "\nInstitution country: " << institutionCountry
			<< "\nGroup number: " << groupNumber << '\n';
	}
};

// Task 2: Point in three-dimensional space.
class Point {
private:
	double x = 0;
	double y = 0;
	double z = 0;

public:
	double getX() const { return x; }
	double getY() const { return y; }
	double getZ() const { return z; }
	void setX(double value) { x = value; }
	void setY(double value) { y = value; }
	void setZ(double value) { z = value; }

	bool input() {
		double newX, newY, newZ;
		std::cout << "Enter x, y, z: ";
		if (!(std::cin >> newX >> newY >> newZ) ||
			!std::isfinite(newX) || !std::isfinite(newY) || !std::isfinite(newZ)) {
			return false;
		}
		x = newX;
		y = newY;
		z = newZ;
		return true;
	}

	void print() const {
		std::cout << "Point: (" << x << ", " << y << ", " << z << ")\n";
	}

	bool saveToFile(const std::string& filename) const {
		std::ofstream file(filename);
		if (!file) return false;
		file << std::setprecision(std::numeric_limits<double>::max_digits10)
			<< x << ' ' << y << ' ' << z << '\n';
		file.close();
		return !file.fail();
	}

	bool loadFromFile(const std::string& filename) {
		std::ifstream file(filename);
		double newX, newY, newZ;
		if (!(file >> newX >> newY >> newZ) ||
			!std::isfinite(newX) || !std::isfinite(newY) || !std::isfinite(newZ)) {
			return false;
		}
		// A valid file contains exactly three coordinates and optional whitespace.
		file >> std::ws;
		if (!file.eof()) return false;
		x = newX;
		y = newY;
		z = newZ;
		return true;
	}
};

void task1() {
	Student student;
	if (!student.input()) {
		std::cout << "Input error\n";
		return;
	}
	std::cout << "\nStudent information:\n";
	student.print();
	std::cout << "\nName through accessor: " << student.getFullName() << '\n';
}

void task2() {
	Point point;
	if (!point.input()) {
		std::cout << "Invalid coordinates\n";
		return;
	}
	point.print();
	std::cout << "X through accessor: " << point.getX() << '\n';
	if (!point.saveToFile("point.txt")) {
		std::cout << "Cannot save point.txt\n";
		return;
	}
	Point loaded;
	if (!loaded.loadFromFile("point.txt")) {
		std::cout << "Cannot load point.txt\n";
		return;
	}
	std::cout << "Saved to point.txt. Loaded point:\n";
	loaded.print();
}

int main() {
	int choice = 0;
	std::cout << "Choose task (1 - Student, 2 - Point): ";
	if (!(std::cin >> choice)) {
		std::cout << "Invalid task number\n";
		return 1;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (choice) {
	case 1: task1(); break;
	case 2: task2(); break;
	default:
		std::cout << "Invalid task number\n";
		return 1;
	}
	return 0;
}
