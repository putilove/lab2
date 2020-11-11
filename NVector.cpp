#include "NVector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
// Конструктор по-умолчанию
NVector::NVector (size_t size) noexcept : _data(new float[size]), _size(size) {
	for (size_t i = 0; i < size; ++i) {
		_data[i] = 0;
	}
}

// Конструктор копирования
NVector::NVector(const NVector& rhs) noexcept : _data(new float[rhs._size]), _size(rhs._size), _isNormCacheValid(rhs._isNormCacheValid), _normCache(rhs._normCache) {
	puts("COPY-CTOR");
	for (size_t i = 0; i < _size; ++i) {
		_data[i] = rhs._data[i];
	}
}

// Конструктор перемещения
NVector::NVector(NVector&& rhs) noexcept : _data(rhs._data), _size(rhs._size), _isNormCacheValid(rhs._isNormCacheValid), _normCache(rhs._normCache) {
	puts("MOVE-CTOR");
	rhs._data = nullptr;
	rhs._size = 0;
}

NVector& FillVector(NVector& v) noexcept
{
	srand(time(0));
	int k = 0;
	for (size_t i = 0; i < v.GetSize(); ++i)
	{
		k = float(-1000 + rand() % 2000);
		v[i] = (float)k / (float)(10);
		//v[i] = float(-100 + rand() % 200);
	}
	return v;
}

// Оператор присваивания копированием
NVector& NVector::operator=(const NVector& rhs) {
	puts("COPY-ASSIGN");
	NVector tmp(rhs);
	Swap(tmp);
	return *this;
}

// Оператор присваивания перемещением
NVector& NVector::operator=(NVector&& rhs) noexcept {
	puts("MOVE-ASSIGN");
	Swap(rhs);
	return *this;
}

// Кастом свап
void NVector::Swap(NVector& rhs) noexcept {
	puts("CUSTOM SWAP");
	std::swap(_data, rhs._data);
	std::swap(_size, rhs._size);
	std::swap(_isNormCacheValid, rhs._isNormCacheValid);
	std::swap(_normCache, rhs._normCache);
}

// Оператор доступа по индексу с возможностью редактирования
float& NVector::operator[](size_t index) {
	if (index >= _size) {
		throw std::logic_error("Index out of range!");
	}
	_isNormCacheValid = false;
	return _data[index];
}

// Оператор доступа по индексу
float NVector::operator[](size_t index) const {
	if (index >= _size) {
		throw std::logic_error("Index out of range!");
	}
	return _data[index];
}


size_t NVector::GetSize() const noexcept{
	return _size;
}

float NVector::GetNorm() const noexcept {
	if (_isNormCacheValid) _normCache = 0;
	for (size_t i = 0; i < _size; ++i)
		_normCache += _data[i] * _data[i];
	_normCache = sqrt(_normCache);
	_isNormCacheValid = true;
	return _normCache;
}

NVector NVector::Normalize() noexcept  {
	auto norm = GetNorm();
	for (size_t i = 0; i < _size; ++i) {
		_data[i] /= norm;
	}
	if (GetNorm() == norm) _isNormCacheValid = true;
	return *this;
}

float NVector::GetEuclideanDistance(const NVector& rhs) const noexcept {
	float distance=0;
	size_t biggest_size = 0;
	if (_size == rhs._size)
		biggest_size = _size;
	else if (_size < rhs._size)
		biggest_size = rhs._size;
	else
		biggest_size = _size;
	for (size_t i = 0; i < biggest_size; ++i) {
		
		while (i < _size && i < rhs._size) {
			distance += (_data[i] - rhs[i]) * (_data[i] - rhs[i]);
			++i;
		}
		if (i >= _size)
			distance += (0 - rhs[i]) * (0.0f - rhs[i]);
		else if (i >= rhs._size)
			distance += (_data[i] - 0) * (_data[i] - 0.0f);

	}
	return sqrt(distance);
}

float NVector::GetChebishevDistance(const NVector& rhs) const noexcept {
	float distance = 0;
	size_t biggest_size = 0;
	if (_size == rhs._size)
		biggest_size = _size;
	else if (_size < rhs._size)
		biggest_size = rhs._size;
	else
		biggest_size = _size;
	float* arrayOfDiff = new float[biggest_size];
	arrayOfDiff[0] = 0;
	for (size_t i = 0; i < biggest_size; ++i) {
		while (i < _size && i < rhs._size) {
			arrayOfDiff[i] = fabs(_data[i] - rhs[i]);
			++i;
		}
		if (i >= _size)
			arrayOfDiff[i] = fabs(0.0f - rhs[i]);
		else if (i >= rhs._size)
			arrayOfDiff[i] = fabs(float(_data[i]) - 0.0f);
	}
	distance = arrayOfDiff[0];
	for (size_t i = 0; i < biggest_size; ++i)
		if (arrayOfDiff[i] < distance)
			distance = arrayOfDiff[i];
	delete[] arrayOfDiff;
	return distance;
}

// Деструктор
NVector::~NVector() {
	delete[] _data;
}

NVector& NVector::operator+=(const NVector& rhs) {
	if (_size != rhs._size) {
		throw std::logic_error("Vectors must have the same size!");
	}
	for (size_t i = 0; i < _size; ++i) {
		_data[i] += rhs[i];
	}
	return *this;
}

NVector operator+(const NVector& lhs, const NVector& rhs) {
	if (lhs.GetSize() != rhs.GetSize()) {
		throw std::logic_error("Vectors must have the same size!");
	}
	NVector result(lhs);
	result += rhs;
	return result;
}

NVector& NVector::operator*=(const float& num) noexcept {
	for (size_t i = 0; i < _size; ++i) {
		_data[i] *= num;
	}
	return *this;
}


NVector operator*(NVector lhs, const float& num) {
	lhs *= num;
	return lhs;
}

NVector& NVector::operator/=(const float& num) noexcept {
	for (size_t i = 0; i < _size; ++i) {
		_data[i] /= num;
	}
	return *this;
}


NVector operator/(NVector lhs, const float& num){
	lhs /= num;
	return lhs;
}

float operator*(const NVector& lhs, const NVector& rhs)
{
	if (lhs.GetSize() != rhs.GetSize()) {
		throw std::logic_error("Vectors must have the same size!");
	}
	float scalar = 0;
	for (size_t i = 0; i < lhs.GetSize(); ++i) {
		scalar += lhs[i] * rhs[i];
	}
	return scalar;
}

std::ostream& operator<<(std::ostream& out, const NVector& v)
{
	out << "Vector: ";
	for (size_t i = 0; i < v.GetSize(); ++i)
		out << v[i] << " ";
	out << "\n";
	return out;
}

void Print(const NVector& v) {
	for (size_t i = 0; i < v.GetSize(); ++i) {
		std::cout << v[i];
	}
	std::cout << std::endl;
}


