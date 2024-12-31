#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<class T>
class SimpleVector {

	T* data;
	int currentSize; //스택형태이기에 마지막인덱스만 알면 된다
	int currentCapacity;

public:
	SimpleVector() :currentSize(0) {
		data = new T[10];
	}
	SimpleVector(T number) : currentSize(0), currentCapacity(number) {
		data = new T[number];
	}
	template<class T> //템플릿 클래스를 복사할떄는 앞에 이걸 붙여줘야 된다...
	SimpleVector(const SimpleVector& other) { // 복사생성자
		this->data = new T[other.capacity()]; //data = other.data 하면 주소를 공유하게 된다. data = 주소값 이기 떄문
		this->currentSize = other.size(); //얘는 포인터 아니라서 갠춘
		this->currentCapacity = other.capacity();//얘도
		for (int i = 0; i < other.size(); i++) { // 값 붙여넣기
			this->data[i] = other.data[i];
		}
	}
	~SimpleVector() {
		delete[] data;
		cout << "소멸확인" << endl;
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
	SimpleVector<int> Arirang(array);
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
