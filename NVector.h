#pragma once
#include <iostream>
class NVector {
	float* _data;
	size_t _size;
	mutable bool _isNormCacheValid = false;
	mutable float _normCache = 0.0f;
public:
	NVector(size_t size) noexcept;									// Конструктор по-умолчанию
	NVector(const NVector& rhs);									// Конструктор копирования
	NVector(NVector&& rhs) noexcept;								// Конструктор перемещения
	size_t GetSize() const;											// Получить размер
	float GetNorm() const ;											// Получить норму(высчитывает)
	NVector Normalize() ;											// Нормировать вектор
	float GetEuclideanDistance(const NVector& rhs) const;			// Получить Евклидово расстояние(высчитывает)
	float GetChebishevDistance(const NVector& rhs) const;			// Получить Чебышево расстояние(высчитывает)
	NVector& operator=(const NVector& rhs);							// Оператор присваивания копированием
	NVector& operator=(NVector&& rhs) noexcept;						// Оператор присваивания перемещением
	NVector& operator+=(const NVector& rhs);						// Унарное сложение векторов
	NVector& operator*=(const float& num) noexcept;					// Унарное умножение на скаляр
	NVector& operator/=(const float& num) noexcept;					// Деление на скаляр
	void Swap(NVector& rhs) noexcept;								// Кастомный свап
	float& operator[](size_t index);								// Доступ по индексу с возможностью редактирования
	float operator[](size_t index) const;							// Доступ по индексу (просмотр)
	bool operator==(const NVector& rhs);
	bool operator!=(const NVector& rhs);
	
	~NVector();														//Деструкторрр
};

NVector& FillVector(NVector& v) noexcept;
NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator*(NVector lhs, const float& num);
NVector operator/(NVector lhs, const float& num);
float operator*(const NVector& lhs,const NVector& rhs);
std::ostream& operator<< (std::ostream& out, const NVector& v);
//void Print(const NVector& v);
int InputControl();