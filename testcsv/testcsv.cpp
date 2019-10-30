////#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main() {
//
//	ifstream ip("data.csv");
//
//	if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';
//
//	string firstname;
//	string lastname;
//	string age;
//	string weight;
//
//	/*if (ip.good())
//	{
//		std::string str;
//		getline(ip, str);
//	}*/
//	while (ip.good()) {
//
//		getline(ip, firstname, ',');
//		getline(ip, lastname, ',');
//		getline(ip, age, ',');
//		getline(ip, weight, '\n');
//
//		std::cout << "Name: " << firstname << " " << lastname << '\n';
//		std::cout << "Age: " << age << '\n';
//		std::cout << "Weight: " << weight << '\n';
//		std::cout << "-------------------" << '\n';
//	}
//
//	ip.close();
//}


//#include <iostream>
//#include <sstream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//int main() {
//	ifstream ip("data.csv");
//	std::string line;
//	while (std::getline(ip, line, '"')) {
//		std::stringstream ss(line);
//		while (std::getline(ss, line, ',')) {
//			cout << line << endl;
//		}
//		if (std::getline(ip, line, '"')) {
//			cout << line;
//		}
//	}
//}

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
	/*std::stringstream ss;
	ss << "\"Primary, Secondary, Third\", \"Primary\", , \"Secondary\", 18, 4, 0, 0, 0";

	while (ss >> std::ws) {
		std::string csvElement;

		if (ss.peek() == '"') {
			ss >> std::quoted(csvElement);
			std::string discard;
			std::getline(ss, discard, ',');
		}
		else {
			std::getline(ss, csvElement, ',');
		}

		std::cout << csvElement << "\n";
	}*/
	int* a = new int(37);
	std::cout << *a;
}