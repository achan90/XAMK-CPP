#include <iostream>
#include <regex>

std::string myClock(void) {
	std::string hours = "";
	std::string minutes = "";
	std::string seconds = "";
	std::string result = "";

	std::regex rgx1("\\d{1}");
	std::regex rgx2("\\d{2}");

	std::cout << std::endl << "Tunnit (0-23): ";
	std::cin >> hours;
	std::cout << "Minuutit(0-59): ";
	std::cin >> minutes;
	std::cout << "Sekunnit: ";
	std::cin >> seconds;

	if (std::regex_match(hours, rgx1)) {
		if (std::regex_match(minutes, rgx1)) {
			if (std::regex_match(seconds, rgx1)) {
				result = "0" + hours + ":0" + minutes + ":0" + seconds;
				return result;
			}
			else if (std::regex_match(seconds, rgx2)) {
				result = "0" + hours + ":0" + minutes + ":" + seconds;
				return result;
			}
		}
		else if (std::regex_match(minutes, rgx2)) {
			if (std::regex_match(seconds, rgx1)) {
				result = "0:" + hours + ":" + minutes + ":0" + seconds;
				return result;
			}
			else if (std::regex_match(seconds, rgx2)) {
				result = "0:" + hours + ":" + minutes + ":" + seconds;
				return result;
			}
		}
	}
	else if (std::regex_match(hours, rgx2)) {
		if (std::regex_match(minutes, rgx1)) {
			if (std::regex_match(seconds, rgx1)) {
				result = hours + ":0" + minutes + ":0" + seconds;
				return result;
			}
			else if (std::regex_match(seconds, rgx2)) {
				result = hours + ":0" + minutes + ":" + seconds;
				return result;
			}
		}
		else if (std::regex_match(minutes, rgx2)) {
			if (std::regex_match(seconds, rgx1)) {
				result = hours + ":" + minutes + ":0" + seconds;
				return result;
			}
			else if (std::regex_match(seconds, rgx2)) {
				result = hours + ":" + minutes + ":" + seconds;
				return result;
			}
		}
	}
}


int main(void) {

	while (1) {
		auto time = myClock();

		if (time != "00:00:00") {
			std::cout << std::endl << "Annoit ajaksi: " << time << std::endl;
		}
		else {
			std::cout << std::endl << "Annoit ajaksi: 00:00:00" << std::endl;
			break;
			}
		}

	system("pause");
	return 0;
}
