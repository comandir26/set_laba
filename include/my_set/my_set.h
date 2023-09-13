#pragma once
namespace my_set {
	template<typename T>
	class MySet {
	public:
		MySet();
		MySet(T* data, size_t size);
		//MySet(int number, );
	private:
		T* _data;
		size_t _size;
	};
}