#pragma once
#include <iostream>
class NVector {
	float* _data;
	size_t _size;
	mutable bool _isNormCacheValid = false;
	mutable float _normCache = 0.0f;
public:
	NVector(size_t size) noexcept;									// ����������� ��-���������
	NVector(const NVector& rhs);									// ����������� �����������
	NVector(NVector&& rhs) noexcept;								// ����������� �����������
	size_t GetSize() const;											// �������� ������
	float GetNorm() const ;											// �������� �����(�����������)
	NVector Normalize() ;											// ����������� ������
	float GetEuclideanDistance(const NVector& rhs) const;			// �������� ��������� ����������(�����������)
	float GetChebishevDistance(const NVector& rhs) const;			// �������� �������� ����������(�����������)
	NVector& operator=(const NVector& rhs);							// �������� ������������ ������������
	NVector& operator=(NVector&& rhs) noexcept;						// �������� ������������ ������������
	NVector& operator+=(const NVector& rhs);						// ������� �������� ��������
	NVector& operator*=(const float& num) noexcept;					// ������� ��������� �� ������
	NVector& operator/=(const float& num) noexcept;					// ������� �� ������
	void Swap(NVector& rhs) noexcept;								// ��������� ����
	float& operator[](size_t index);								// ������ �� ������� � ������������ ��������������
	float operator[](size_t index) const;							// ������ �� ������� (��������)
	bool operator==(const NVector& rhs);
	bool operator!=(const NVector& rhs);
	
	~NVector();														//������������
};

NVector& FillVector(NVector& v) noexcept;
NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator*(NVector lhs, const float& num);
NVector operator/(NVector lhs, const float& num);
float operator*(const NVector& lhs,const NVector& rhs);
std::ostream& operator<< (std::ostream& out, const NVector& v);
//void Print(const NVector& v);
int InputControl();