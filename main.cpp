#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<class T>
class SimpleVector {
public:
	T* data;
	int currentSize; //스택형태이기에 마지막인덱스만 알면 된다
	int currentCapacity;

public:
	SimpleVector() :currentSize(0) {
		data = new T[10];
	}
	SimpleVector(T number) : currentSize(0), currentCapacity(number) {//헷갈리겠다 ㅋㅋ
		data = new T[number];
	}
	SimpleVector(const SimpleVector& other) { // 복사생성자
		this->data = other.data;
		this->currentSize = other.currentSize;
		this->currentCapacity = other.currentCapacity;
	}
	~SimpleVector() {
		delete[] data;
	}
	void push_back(T something) {

		if (currentSize >= currentCapacity) {
			T* imsi = data;
			data = new T[currentCapacity + 5]; //5 늘리고
			for (int i = 0; i < currentSize; i++) {// 원레값 복사하고
				data[i] = imsi[i];
				
			}
			currentCapacity += 5;//총용량 늘려놓고
			cout << "용량 5 증가" << endl; //확인메시지
		}
		data[currentSize] = something;
		currentSize++;
	}

	void pop_back() {
		if (currentSize <= 0) {
			cout << "값이 없음" << endl;
			return;
		}
		currentSize--;
	}
	T size() {
		return currentSize;
	}

	T capacity() {
		return currentCapacity;
	}

	void sortData() {
		sort(data[0], data[size()]);
	}

	void print() {
		for (int i = 0; i < size(); i++) {
			cout << data[i] << endl;
		}
	}
};

int main() {

	int num;
	int input;
	int value;
	cin >> num;
	SimpleVector<int> array(num);

	while (true) {
		cout << "1: push, 2:pop, 3: size, 4: capacity, 5: print, 6: exit" << endl;
		cin >> input;
		switch (input) {
		case 1: cout << "입력" << endl;
			cin >> value; array.push_back(value);
			break;
		case 2: array.pop_back();
			break;
		case 3: cout << array.size()<<endl;
			break;
		case 4: cout << array.capacity()<<endl;
			break;
		case 5: array.print();
			break;
		case 6: exit(0);
		}
	}
	return 0;
}