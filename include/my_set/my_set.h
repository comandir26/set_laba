#pragma once
namespace my_set {
	template<typename T>
	class MySet {
	public:
		MySet();

		MySet(T* data, int size);

		//MySet(int size, T begin, T end);

		T& operator[](int index);
		
		const T operator[](int index) const;

		//MySet operator+(const MySet& rhs);

		int get_size() const {
			return _size;
		}

		T* get_data() const {
			return _data;
		}
	private:
		T* _data;
		int _size;
	};
}