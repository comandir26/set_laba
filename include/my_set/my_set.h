#pragma once
namespace my_set {
	template<typename T>
	class MySet {
	public:
		MySet();

		MySet(T* data, int size);

		//MySet(int size, T begin, T end);

		MySet(const MySet& rhs);

		const T& operator[](int index);
		
		const T operator[](int index) const;

		MySet& operator+= (const MySet& rhs);

		MySet& operator-= (const MySet& rhs);

		MySet intersection(const MySet& rhs);

		int get_size() const {
			return _size;
		}

		T* get_data() const {
			return _data;
		}

		void remove(int index);

		~MySet();
	private:
		T* _data;
		int _size;
	};
	
	template<typename T>
	int element_is_there(T* data, int size, const T& value);
	/*
	template<typename T>
	MySet<T> operator+(const MySet<T>& lhs, const MySet<T>& rhs);

	template<typename T>
	MySet<T> operator-(const MySet<T>& lhs, const MySet<T>& rhs);
	*/
}
