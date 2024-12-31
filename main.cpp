#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<class T>
class SimpleVector {
public:
	T* data;
	int currentSize; //���������̱⿡ �������ε����� �˸� �ȴ�
	int currentCapacity;

public:
	SimpleVector() :currentSize(0) {
		data = new T[10];
	}
	SimpleVector(T number) : currentSize(0), currentCapacity(number) {//�򰥸��ڴ� ����
		data = new T[number];
	}
	SimpleVector(const SimpleVector& other) { // ���������
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
			data = new T[currentCapacity + 5]; //5 �ø���
			for (int i = 0; i < currentSize; i++) {// ������ �����ϰ�
				data[i] = imsi[i];
				
			}
			currentCapacity += 5;//�ѿ뷮 �÷�����
			cout << "�뷮 5 ����" << endl; //Ȯ�θ޽���
		}
		data[currentSize] = something;
		currentSize++;
	}

	void pop_back() {
		if (currentSize <= 0) {
			cout << "���� ����" << endl;
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
		case 1: cout << "�Է�" << endl;
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