#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Rotor {

private:
	int position;
	string wiring;

public:

	Rotor(int pos, string wire) {
		position = pos;
		wiring = wire;
	}

	char forward(char input) {
		int indexF = (Alphabet.find(input) + position) % 26;
		return wiring[indexF];
	}

	char backward(char input) {
		int indexB = (wiring.find(input) - position + 26) % 26;
		return Alphabet[indexB];
	}

	void rotate() {
		position = (position + 1) % 26;
	}

	int getPosition() {
		return position;
	}

};


class Reflector {

private:
	string wiring;

public:
	Reflector(string wire) {
		wiring = wire;
	}

	char reflectForward(char input) {
		int index = Alphabet.find(input);
		return wiring[index];
	}

	char reflectBackward(char input) {
		int index = wiring.find(input);
		return Alphabet[index];
	}

};


class Enigma {

private:
	Rotor rotor1, rotor2, rotor3;
	Reflector reflector;

public:
	Enigma(Rotor r1, Rotor r2, Rotor r3, Reflector ref) : rotor1(r1), rotor2(r2), rotor3(r3), reflector(ref) {}

	char encript(char input) {
		if (!isalpha(input)) {
			return input;
		}

		input = toupper(input);

		char step1 = rotor1.forward(input);
		char step2 = rotor2.forward(step1);
		char step3 = rotor3.forward(step2);
		char reflected = reflector.reflectForward(step3);
		char step4 = rotor3.backward(reflected);
		char step5 = rotor2.backward(step4);
		char step6 = rotor1.backward(step5);

		rotor1.rotate();
		if (rotor1.getPosition() == 0) rotor2.rotate();
		if (rotor2.getPosition() == 0) rotor3.rotate();

		return step6;
	}


	vector<char> encriptText(string text) {
		vector<char> finalText;
		for (char c : text) {
			if (c == ' ') {
				continue;
			}
			finalText.push_back(encript(c));
		}

		return finalText;
	}

	char decript(char input) {
		if (!isalpha(input)) {
			return input;
		}

		input = toupper(input);

		char step1 = rotor1.forward(input);
		char step2 = rotor2.forward(step1);
		char step3 = rotor3.forward(step2);
		char reflected = reflector.reflectBackward(step3);
		char step4 = rotor3.backward(reflected);
		char step5 = rotor2.backward(step4);
		char step6 = rotor1.backward(step5);

		rotor1.rotate();
		if (rotor1.getPosition() == 0) rotor2.rotate();
		if (rotor2.getPosition() == 0) rotor3.rotate();

		return step6;
	}

	vector<char> decriptText(string text) {
		vector<char> finalText;
		for (char c : text) {
			finalText.push_back(decript(c));
		}

		return finalText;
	}

};


int main() {

	Reflector reflector("WJDZUIKHYRMQPSALOXFCNTBVEG");

	string text;
	char mode;
	int pos1, pos2, pos3;

	cout << "Encrypt or Decrypt (type e or d)." << endl;
	cin >> mode;

	if (mode == 'e') {
		cout << "Position of first Rotor: "; cin >> pos1;
		cout << "Position of second Rotor: "; cin >> pos2;
		cout << "Position of third Rotor: "; cin >> pos3;
		cin.ignore();

		Rotor rotor1( (pos1 % 26), "MVCBXLPQAFUKJZDHRTEYINGSWO");
		Rotor rotor2( (pos2 % 26), "TNLOCKMZEPGWBIVXSDJQFRAUHY");
		Rotor rotor3( (pos3 % 26), "BDFHJLCPRTXVNZYEIWGAKMUSQO");
		Enigma enigma(rotor1, rotor2, rotor3, reflector);

		cout << endl << "Enter text: " << endl;
		getline(cin, text);

		vector<char> encriptedText = enigma.encriptText(text);
		cout << "Here is the encripted text." << endl;

		for (char c : encriptedText) {
			cout << "\033[31m" << c << "\033[0m";
		}
		cout << endl;
	}

	else if (mode == 'd') {
		cout << "Position of first Rotor: "; cin >> pos1;
		cout << "Position of second Rotor: "; cin >> pos2;
		cout << "Position of third Rotor: "; cin >> pos3;

		Rotor rotor1( (pos1 % 26), "MVCBXLPQAFUKJZDHRTEYINGSWO");
		Rotor rotor2( (pos2 % 26), "TNLOCKMZEPGWBIVXSDJQFRAUHY");
		Rotor rotor3( (pos3 % 26), "BDFHJLCPRTXVNZYEIWGAKMUSQO");
		Enigma enigma(rotor1, rotor2, rotor3, reflector);

		cout << endl << "Enter text: " << endl;
		cin >> text;

		vector<char> decriptedText = enigma.decriptText(text);
		cout << "Here is the encripted text." << endl;

		for (char c : decriptedText) {
			cout << "\033[31m" << c << "\033[0m";
		}
		cout << endl;
	}

	else {
		cout << "Type 'e' or 'd'. " << endl;
	}

	return 0;
}
