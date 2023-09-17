#pragma once
namespace my_set {
	template<typename T>
	class MySet {
	public:
		MySet():_data(nullptr), _size(0) {}

		MySet(T* data, int size){
			int* new_size = new int(0);

			_data = get_unique_data(data, size, new_size);
			
			_size = *new_size;

			this->sort();
			
			delete new_size;
		}

		MySet(const MySet& rhs) :_size(rhs.get_size()), _data(new T[rhs.get_size()]) {
			for (int i = 0; i < _size; i++)
			{
				_data[i] = rhs[i];
			}
		}

		MySet<T> intersection(const MySet<T>& rhs) {
			MySet copy(*this);
			for (int i = 0; i < copy.get_size(); i++)
			{
				int index = element_is_there(copy.get_data(), copy.get_size(), rhs[i]);
				if (index != -1) {
					copy.remove(index);
				}
			}
			return (*this - copy);
		}

		T& operator[](int index) {
			//Здесь проверка на правильный индекс
			return _data[index];
		}

		const T operator[](int index) const {
			//Здесь проверка на правильный индекс
			return _data[index];
		}

		MySet& operator+=(const MySet& rhs) {
			int new_size = _size + rhs.get_size();

			T* new_data = new T[new_size]();

			for (int i = 0; i < _size; ++i)
			{
				new_data[i] = _data[i];
			}
			int j = 0;
			for (int i = _size; i < new_size; ++i)
			{
				new_data[i] = rhs[j];
				++j;
			}

			delete[] _data;

			int* actual_size = new int(0);

			_data = get_unique_data(new_data, new_size, actual_size);

			delete[] new_data;

			_size = *actual_size;

			this->sort();

			return *this;
		}

		MySet& operator-=(const MySet& rhs) {
			for (int i = 0; i < rhs.get_size(); i++)
			{
				int index = element_is_there(_data, _size, rhs[i]);
				if (index != -1) {

					this->remove(index);
				}
			}
			this->sort();
			return *this;
		}

		MySet& operator+=(const T& value) {
			if (element_is_there(_data, _size, value) != -1) {
				return *this;
			}
			int new_size = _size + 1;
			T* new_data = new T[new_size];
			for (int i = 0; i < _size; i++)
			{
				new_data[i] = _data[i];
			}
			new_data[new_size - 1] = value;
			delete[] _data;
			_data = new_data;
			_size = new_size;
			this->sort();
			return *this;
		}

		MySet& operator-=(const T& value) {
			int index = element_is_there(_data, _size, value);
			if (index == -1) {
				return *this;
			}
			this->remove(index);
			return *this;
		}

		int get_size() const {
			return _size;
		}

		T* get_data() const {
			return _data;
		}

		void remove(int index) {
			//проверка на правильный индекс
			for (int i = index; i < _size - 1; i++)
			{
				T temp = _data[i];
				_data[i] = _data[i + 1];
				_data[i + 1] = temp;
			}
			_size--;
		}

		~MySet() {
			delete[] _data;
			_size = 0;
		}

	private:
		int element_is_there(T* data, int size, const T& value) {
			for (size_t i = 0; i < size; i++)
			{
				if (data[i] == value) return i;
			}
			return -1;
		}

		T* get_unique_data(T* data, int size, int* new_size) {
			T* unique_data = new T[size]();
			int i = 0;
			int j = 0;
			while (i < size && j < size) {
				if (element_is_there(unique_data, *new_size, data[j]) == -1) {
					unique_data[i] = data[j];
					*new_size += 1;
					++i;
					++j;
				}
				else ++j;
			}
			return unique_data;
		}

		void sort() {
			for (int i = 0; i < _size; i++)
			{
				for (int j = 0; j < _size-1; j++)
				{
					if (_data[j] > _data[j+1]) {
						T temp = _data[j];
						_data[j] = _data[j + 1];
						_data[j + 1] = temp;
					}
				}
			}
		}

		T* _data;

		int _size;
	};	
}
