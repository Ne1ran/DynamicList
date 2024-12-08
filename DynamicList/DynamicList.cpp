#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char delimiter = ' ';

struct FlashDrive
{
	string name;
	int capacity;
	int frequency;
	FlashDrive* next;
	FlashDrive* previous;

	FlashDrive(string name, int capacity, int frequency) : name(name), capacity(capacity), frequency(frequency), next(nullptr), previous(nullptr) {}
};

class DoubleLinkedArray {
private:
	FlashDrive* first;
	FlashDrive* last;

public:
	DoubleLinkedArray() : first(nullptr), last(nullptr) {} // Инициализация

	// Добавление элемента в список. Получаем на вход данные
	void append(string name, int capacity, int frequency) {
		FlashDrive* flashDrive = new FlashDrive(name, capacity, frequency); // Создаем структуру
		if (last) { // Если последний элемент есть, то добавляем новый как последний.
			last->next = flashDrive; 
			flashDrive->previous = last;
			last = flashDrive;
		}
		else { // Если его нет, то первый=последний=добавленный, т.е. в массиве ничего не было.
			first = last = flashDrive;
		}
	}

	// Вывод всех элементов списка
	void display() {
		FlashDrive* current = first;
		while (current != nullptr) {
			std::cout << current->name << " " << current->capacity << " " << current->frequency << std::endl;
			current = current->next;
		}
	}
};

// Да, я использую динамический массив в работе по созданию динамического массива.
// Это больше нужно для упрощения работы и возможности ввода разных данных, т.к. я не хочу хардкодить данные для ввода.
// Обычная реализация метода Split из более высокоуровневых языков (C#, Java)
std::vector<std::string> split(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	for (char ch : str) {
		if (ch == delimiter) {
			if (!token.empty()) {
				tokens.push_back(token);
				token.clear();
			}
		}
		else {
			token += ch;
		}
	}

	if (!token.empty()) {
		tokens.push_back(token);
	}

	return tokens;
}

void main() {


	setlocale(0, "Russian");

	cout << "Предметная область работы - 'Флэш-накопители'." << endl;
	cout << "Вводите данные элемента списка через пробел. Для завершения, напишите 0." << endl;
	cout << "Пример: 'Флешка1 12 900', после этого нажмите Enter и введите следующую запись. Важно отделять данные пробелом." << endl;
	cout << "После ввода данных вы получите соответствующее сообщение. Теперь можно работать с командами." << endl;
	cout << "Расшифровка команд: 0 - завершение работы, 2 - вывод на экран текущего списка, 4 - дополнение в конец списка" << endl;

	DoubleLinkedArray flashArray;

	while (true)
	{
		string command;
		getline(cin, command);

		if (command == "0") {
			break;
		}

		std::vector<std::string> words = split(command, delimiter);

		if (words.size() == 0) {
			cout << "Введенная запись пуста." << endl;
			continue;
		}

		if (words.size() < 3) {
			cout << "В введенной записи нет всех значений." << endl;
			continue;
		}
		
		try
		{
			string flashName = words[0];
			int flashCapacity = stoi(words[1]);
			int flashFrequency = stoi(words[2]);
			flashArray.append(flashName, flashCapacity, flashFrequency);
		}
		catch (const std::exception&)
		{
			cout << "Ошибка при вводе данных." << endl;
		}
	}

	cout << "Операция ввода завершилась! Теперь идет считывание команд!" << endl;
	while (true)
	{
		string command;
		getline(cin, command);

		if (command == "0") {
			break;
		}

		if (command == "2") {
			cout << "Вывод всех данных на экран:" << endl;
			flashArray.display();
			continue;
		}

		if (command == "4") {
			cout << "Ожидаю данных о флеш-накопителе... Для отмены напишите команду '0':" << endl;
			string command;
			getline(cin, command);

			if (command == "0") {
				cout << "Перестаю считывать данные по 4 команде." << endl;
				break;
			}

			std::vector<std::string> words = split(command, delimiter);

			if (words.size() == 0) {
				cout << "Введенная запись пуста." << endl;
				continue;
			}

			if (words.size() < 3) {
				cout << "В введенной записи нет всех значений." << endl;
				continue;
			}

			try
			{
				string flashName = words[0];
				int flashCapacity = stoi(words[1]);
				int flashFrequency = stoi(words[2]);
				flashArray.append(flashName, flashCapacity, flashFrequency);
				cout << "Данные введены. Напишите следующую команду для работы!" << endl;
			}
			catch (const std::exception&)
			{
				cout << "Ошибка при вводе данных." << endl;
			}

			continue;
		}
	}

	cout << "Вы завершили работу!" << endl;
	system("pause");
}