//4 вариант
//очередь

#include <iostream>

class Queue
{

static const int start_len = 5;

private:
	int *array;
	int len;
	int first;
	int last;

	void resize();
public:
	//Инициализация
	Queue();
	Queue(const Queue * other);
	//Освобождение памяти от структуры данных
	~Queue();
	//Вставка элемента
	void add(int value);
	//Извлечение элемента
	bool get(int &get_value);
	//Клонирование
	Queue* copy();
};

int main()
{
	Queue *qq = new Queue();

	for (int i = 0; i < 5; i++) {
		qq->add(i * 2);
	}
	for (int i = 0; i < 5; i++) {
		qq->add(i + 1);
	}

	Queue *qq2 = qq->copy();

	std::cout << "First queue:\n";
	for (int i = 0; i < 11; i++) {
		int buf;
		if (qq->get(buf)) {
			std::cout << i << ": " << buf << std::endl;
		} else {
			std::cout << "Queue is empty\n";
		}
	}
	std::cout << std::endl;

	std::cout << "Second queue:\n";
	for (int i = 0; i < 11; i++) {
		int buf;
		if (qq2->get(buf)) {
			std::cout << i << ": " << buf << std::endl;
		} else {
			std::cout << "Queue is empty\n";
		}
	}

	delete qq;
	delete qq2;
}

Queue::Queue()
{
	array = new int[start_len];
	len = start_len;
	first = last = -1;
}

Queue::Queue(const Queue* other)
{
	len = other->len;
	array = new int[len];
	int j, i;
	for (i = other->first, j = 0; i < other->last; j++,i++) {
		array[j] = other->array[i];
	}
	first = 0;
	last = j;
}

Queue::~Queue()
{
	delete[] array;
}

void Queue::add(int value)
{
	if (last >= len) {
		resize();
	}
	if (first == -1) {
		first = last = 0;
	}
	array[last] = value;
	last++;
}

bool Queue::get(int &get_value)
{
	if (first == -1) {
		return false;
	}
	if (first == last) {
		first = last = -1;
		return = false;
	}	
	get_value = array[first];
	first++;
	return true;
}

void Queue::resize()
{
	int *new_array = new int[len * 2];
	for (int i = 0; i < len; i++) {
		new_array[i] = array[i];
	}
	first = 0;
	last = len;
	len *= 2;
	delete[] array;
	array = new_array;
}

Queue* Queue::copy()
{
	return new Queue(this);
}