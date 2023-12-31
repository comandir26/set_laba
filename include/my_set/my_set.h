#pragma once
#include<random>
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

		MySet(int size, const T begin, const T end) : _size(size), _data(new T[size]) {
			std::random_device rd;
			std::mt19937 gen(rd()); 
			std::uniform_real_distribution<> dis(begin, end);
			for (int i = 0; i < size; ++i) {
				auto value = 0.0;
				int index = 0;
				while (index != -1) {
					value = dis(gen);
					index = element_is_there(_data, _size, value);
				}
				_data[i] = value;
			}
			this->sort();
		}

		MySet(const MySet& rhs) :_size(rhs.get_size()), _data(new T[rhs.get_size()]) {
			for (int i = 0; i < rhs.get_size(); i++)
			{
				_data[i] = rhs[i];
			}
		}

		MySet& operator=(const MySet& rhs) {
			MySet copy(rhs);
			swap(copy);
			return *this;
		}

		bool operator==(const MySet& rhs){
			if (_size!= rhs.get_size()) return false;
			for (int i = 0; i < _size; i++)
			{
				if (std::abs(_data[i] - rhs[i]) >= epsilon) return false;
			}
			return true;
		}

		bool operator!=(const MySet& rhs){
			return !(*this == rhs);
		}

		MySet<T> intersection(const MySet<T>& rhs) {
			auto dif = *this - rhs;

			return (*this - dif);
		}

		void swap(MySet<T>& rhs) noexcept{
			std::swap(_data, rhs.get_data());
			std::swap(_size, rhs.get_size());
		}

		T& operator[](int index) {
			if (index < 0 || index >= _size) {
				throw std::out_of_range("MySet::operator[], index is out of range");
			}			
			return _data[index];
		}

		const T& operator[](int index) const {
			if (index < 0 || index >= _size) {
				throw std::out_of_range("MySet::operator[] const, index is out of range");
			}
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
			///this->sort();
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

		int find(const T& value) const {
			for (int i = 0; i < _size; i++)
			{
				if (_data[i] == value) return i;
			}
			return -1;
		}

		int get_size() const{
			return _size;
		}

		int& get_size() {
			return _size;
		}

		const T* get_data() const{
			return _data;
		}

		T*& get_data(){
			return _data;
		}

		void remove(int index) {
			if (index < 0 || index >= _size) {
				throw std::out_of_range("MySet::remove, index is out of range");
			}
			for (int i = index; i < _size - 1; i++)
			{
				T temp = _data[i];
				_data[i] = _data[i + 1];
				_data[i + 1] = temp;
			}
			_size--;
		}

		MySet get_all_repeats(T* data, int size) {
			auto repeats = MySet<T>();
			for (int i = 0; i < _size; i++)
			{
				int count = 0;
				for (int j = 0; j < size; j++)
				{
					if (_data[i] == data[j]) ++count;
				}
				if (count > 1) {
					repeats += _data[i];
				}
			}
			return repeats;
		}

		template<typename R>
		MySet operator+(const R& rhs) {
			MySet copy(*this);
			return copy += rhs;
		}
		template<typename R>
		MySet operator-(const R& rhs) {
			MySet copy(*this);
			return copy -= rhs;
		}

		~MySet() {
			delete[] _data;
			_size = 0;
		}

	private:
		int element_is_there(T* data, int size, const T& value) {
			for (int i = 0; i < size; i++)
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

		inline static const double epsilon = 0.001;

		T* _data;

		int _size;
	};

	template <> 
	MySet<std::string>::MySet(int size, std::string begin, std::string end) : _size(size), _data(new std::string[size])
	{
		int asc_start = begin[0];
		int asc_end = end[0];
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(asc_start, asc_end);
		for (int i = 0; i < _size; i++)
		{
			char* word = new char[6]();
			for (int j = 0; j < 5; j++)
			{
				word[j] = dis(gen);
			}
			word[6] = '\n';
			_data[i] = std::string(word);
		}
	}

	template <>
	MySet<std::pair<int, double>>::MySet(int size, std::pair<int, double> begin, std::pair<int, double> end) : _size(size), _data(new std::pair<int, double>[size])
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis_first(begin.first, end.first);
		std::uniform_real_distribution<> dis_second(begin.second, end.second);
		for (int i = 0; i < size; i++)
		{
			_data[i] = std::make_pair(dis_first(gen), dis_second(gen));
		}
	}

	template<typename T, typename R>
	std::ostream& operator<<(std::ostream& os, std::pair<T, R>& pair) {
		std::cout << "(" << pair.first << ", " << pair.second << ")";
		return os;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, MySet<T>& set) {
		for (size_t i = 0; i < set.get_size(); i++)
		{
			std::cout << set[i] << " ";
			if (i == 9) std::cout << "\n";
		}
		return os;
	}
}
