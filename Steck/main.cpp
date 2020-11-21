#include "Steck.h"




int main()
{
	TSteck<char> steckSymbol(5);
	char ch;

	for (int i = 0; i < 5; i++) // помещаем элементы в стек
	{
		cout << "Elem: ";
		cin >> ch;
		steckSymbol.push(ch);
	}
	cout << endl;
	cout << steckSymbol; // печать стека

	cout << "\n\nRemove an item from the steck\n";
	steckSymbol.del(); //Удаление элемента

	cout << steckSymbol; // печать стека

	TSteck<char> newSteck(steckSymbol); //Конструктор копирования

	cout << "\n\nCopy constructor worked\n";
	cout << newSteck;

	cout << "The second element in the queue: " << newSteck.Peek(2) << endl; //Вывод элемента 2

	TSteck<int> test(5);
	int t;
	for (int i = 0; i < 5; i++) // помещаем элементы в стек
	{
		cout << "Elem: ";
		cin >> t;
		test.push(t);
	}

	cout << "TEST PEEK   " << test.Peek(2) << endl;
	cout << test.min_elem(); //Поиск мин элемента
	cout << endl << test.max_elem(); //Макс элемента
	test.file(); //Запись в файл. 
	return 0;
}