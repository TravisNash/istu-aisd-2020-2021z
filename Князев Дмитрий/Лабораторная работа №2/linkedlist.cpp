//Однонаправленный список
//4 вариант

#include <iostream>
#include <limits>

class LinkedList 
{
private:
	struct Node {
		int value;
		Node *next;
	};

	Node *first;
public:
	LinkedList();
	//Освобождение памяти от структуры данных
	~LinkedList();
	//Вставка элемента в конец
	void setEnd(int value);
	//Вставка элемента перед заданным индексом
	void setIndex(int value, int index);
	//Получение значения элемента по индексу
	int getIndex(int index);
	//Удаление элемента по значению
	bool deleteValue(int value);
	//Печать всех элементов списка
	void print();
};


int main()
{
	LinkedList *list = new LinkedList();

	for (int i = 1; i < 11; i++) {
		list->setEnd(i);
	}
	list->print();

	list->setIndex(5, 3);
	list->setIndex(7, 0);
	list->setIndex(13, 20);
	list->print();

	list->deleteValue(5);
	list->deleteValue(7);
	list->deleteValue(13);
	list->print();

	for (int i = 9; i >= 0; i--) {
		std::cout << list->getIndex(i) << " ";
	}
	std::cout << std::endl;

	for (int i = 1; i < 11; i += 2) {
		list->deleteValue(i);
	}
	list->print();

	for (int i = 2; i < 11; i += 2) {
		list->deleteValue(i);
	}
	list->print();

	delete list;
}


LinkedList::LinkedList()
{
	first = nullptr;
}

LinkedList::~LinkedList()
{
	while (first) {
		Node *buf = first;
		first = first->next;
		delete buf;
	}
}

void LinkedList::setEnd(int value)
{
	Node **buf = &first;
	while (*buf != nullptr) {
		buf = &(*buf)->next;
	}
	*buf = new Node;
	(*buf)->value = value;
	(*buf)->next = nullptr;
}

void LinkedList::setIndex(int value, int index)
{
	Node **buf = &first;
	int i = 0;
	while (*buf != nullptr && i < index) {
		buf = &(*buf)->next;
		i++;
	}
	Node *new_item = new Node;
	new_item->value = value;
	new_item->next = *buf;
	*buf = new_item;
}

int LinkedList::getIndex(int index)
{
	Node *buf = first;
	int i = 0;
	while (buf != nullptr && i < index) {
		buf = buf->next;
		i++;
	}
	if (buf) {
		return buf->value;
	}
	return std::numeric_limits<int>::max();
}

bool LinkedList::deleteValue(int value)
{
	Node **buf = &first;
	while (*buf != nullptr && (*buf)->value != value) {
		buf = &(*buf)->next;
	}
	if (buf) {
		Node *del = *buf;
		*buf = (*buf)->next;
		delete del;
		return true;
	} 
	return false;
}

void LinkedList::print()
{
	Node *buf = first;
	while (buf) {
		std::cout << buf->value << " ";
		buf = buf->next;
	}
	std::cout << std::endl;
}
