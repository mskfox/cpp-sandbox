#include <stdexcept>

class DynamicArray {
	int *array;
	int capacity;
	int size;

public:
	explicit DynamicArray(const int capacity): capacity(capacity), size(0) {
		if (capacity <= 0) {
			throw std::invalid_argument("Capacity must be greater than 0");
		}
		array = new int[capacity];
	}

	~DynamicArray() {
		delete[] array;
	}

	[[nodiscard]] int get(const int i) const {
		if (i < 0 || i >= size) {
			throw std::out_of_range("Index out of range");
		}
		return array[i];
	}

	void set(const int i, const int n) const {
		if (i < 0 || i >= size) {
			throw std::out_of_range("Index out of range");
		}
		array[i] = n;
	}

	void pushback(const int n) {
		if (size == capacity) {
			resize();
		}
		array[size++] = n;
	}

	int popback() {
		if (size == 0) {
			throw std::out_of_range("Array is empty");
		}
		return array[--size];
	}

	void resize() {
		capacity *= 2;

		int *new_array = new int[capacity];
		for (int i = 0; i < size; i++) {
			new_array[i] = array[i];
		}

		delete[] array;
		array = new_array;
	}

	[[nodiscard]] int getSize() const {
		return size;
	}

	[[nodiscard]] int getCapacity() const {
		return capacity;
	}
};
