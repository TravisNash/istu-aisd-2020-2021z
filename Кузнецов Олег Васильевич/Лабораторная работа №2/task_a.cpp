//Вариант 6
//Однонаправленный циклический список
#include <iostream>
#include <fstream>

class CircularList {

public:
	CircularList();
	//Освобождение памяти от структуры данных
	~CircularList();
	//Вставка элемента в конец
	void insert_to_end(const int value);
	//Вставка элемента перед заданным индексом
	void insert_by_index(const int index, const int value);
	//Получение значения элемента по индексу
	const int get_by_index(const int index);
	const int operator[](const int index);
	//Удаление элемента по значению
	bool delete_by_value(const int value);
	//Печать всех элементов списка
	void print_all_items();
	int get_length();
private:
	struct ListNode {
		int value;
		ListNode* next;
	};
	ListNode* first;
	int count;
};

const char* default_file_name = {"task_a_test.txt"};

int main(int argc, char** argv) 
{
	std::ifstream input_file;
	if (argc > 1) {
		input_file.open(argv[1]);
	} else {
		input_file.open(default_file_name);
	}
	CircularList* list = new CircularList();
	
	for (int i = 0; i < 8; ++i) {
		int new_value;
		input_file >> new_value;
		list->insert_to_end(new_value);
	}
	list->print_all_items();
	
	list->delete_by_value(1);
	list->delete_by_value(3);
	list->delete_by_value(8);
	list->delete_by_value(1);
	list->delete_by_value(3);

	list->print_all_items();

	list->insert_by_index(0, 12);
	list->print_all_items();
	list->insert_by_index(1, 0);
	list->print_all_items();
	list->insert_by_index(3, 2);
	list->print_all_items();
	list->insert_by_index(5, 4);
	list->print_all_items();
	list->insert_by_index(7, 6);
	list->print_all_items();
	list->insert_to_end(99);
	list->print_all_items();
	list->insert_by_index(0, 17);
	list->print_all_items();


	std::cout << "Count = " << list->get_length() << std::endl;

	int len = list->get_length();
	for (int i = 0; i < len; ++i) {
		std::cout << (*list)[i] << " ";
	}
	std::cout << std::endl;

	delete list;
	input_file.close();
}

CircularList::CircularList()
{
	first = nullptr;
	count = 0;
}

//Освобождение памяти от структуры данных
CircularList::~CircularList()
{
	if (!first) {
		return;
	}
	ListNode *deleted_node = first->next;
	while (first != deleted_node) {
		ListNode *buf = deleted_node;
		deleted_node = deleted_node->next;
		delete buf;
	}
	delete first;
}

//Вставка элемента в конец
void CircularList::insert_to_end(const int value)
{
	ListNode* insert_node = new ListNode;
	insert_node->value = value;
	
	if (first) {
		ListNode **buf = &first->next;
		while (*buf != first) {
			buf = &(*buf)->next;
		}
		*buf = insert_node;
		insert_node->next = first;
	} else {
		first = insert_node;
		first->next = first;
	}
	count++;
}

//Вставка элемента перед заданным индексом
void CircularList::insert_by_index(const int index, 
	const int value)
{
	if (!first || index > count) {
		insert_to_end(value);
		return;
	}
	bool is_in_the_first_place = ( index == 0 ) ? true : false;
	int iter_count = ( index == 0 ) ? count : index;
	ListNode** buf = &first;
	for (int i = 0; i < iter_count; ++i) {
		buf = &((*buf)->next);
	}
	ListNode* new_item = new ListNode;
	new_item->value = value;
	new_item->next = *buf;
	*buf = new_item;
	if (is_in_the_first_place) {
		first = new_item;
	}
	count++;
}

//Получение значения элемента по индексу
const int CircularList::get_by_index(const int index) 
{
	if (!first) {
		return -1;
	}
	ListNode* buf = first;
	for (int i = 0; i < index; ++i) {
		buf = buf->next;
		if (buf == first) {
			break;
		}
	}
	return buf->value;
}

//Получение значения элемента по индексу
const int CircularList::operator[](const int index)
{
	return get_by_index(index);
}

//Удаление элемента по значению
bool CircularList::delete_by_value(const int value) 
{
	if (!first) {
		return false;
	}
	ListNode** buf = &first->next;
	if (first->value == value) {
		for ( ; *buf != first; buf = &(*buf)->next) {}
		*buf = first->next;
		delete first;
		count --;
		if (count == 0) {
			first = nullptr;
		} else {
			first = *buf;
		}
		return true;
	} 
	for ( ; *buf != first; buf = &(*buf)->next) {
		if ((*buf)->value == value) {
			ListNode* deleted_item = *buf;
			*buf = (*buf)->next;
			delete deleted_item;
			count--;
			return true;
		}	
	}
	return false;
}

////Печать всех элементов списка
void CircularList::print_all_items()
{
	if(!first) {
		std::cout << "{}";
		return;
	}
	std::cout << "{ ";
	std::cout << first->value << " ";
	ListNode* buf = first->next;
	for ( ; buf != first; buf = buf->next) {
		std::cout << buf->value << " ";
	}
	std::cout << "}" << std::endl;
}

int CircularList::get_length() 
{
	return count;
}