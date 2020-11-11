#pragma once
#include <iostream>
class NVector {
	float* _data;
	size_t _size;
	mutable bool _isNormCacheValid = false;
	mutable float _normCache = 0.0f;
public:
	NVector(size_t size) noexcept;									// ����������� ��-���������
	NVector(const NVector& rhs) noexcept;							// ����������� �����������
	NVector(NVector&& rhs) noexcept;								// ����������� �����������
	size_t GetSize() const noexcept;								// �������� ������
	float GetNorm() const noexcept;									// �������� �����(�����������)
	NVector Normalize() noexcept;									// ����������� ������
	float GetEuclideanDistance(const NVector& rhs) const noexcept;	// �������� ��������� ����������(�����������)
	float GetChebishevDistance(const NVector& rhs) const noexcept;	// �������� �������� ����������(�����������)
	NVector& operator=(const NVector& rhs);							// �������� ������������ ������������
	NVector& operator=(NVector&& rhs) noexcept;						// �������� ������������ ������������
	NVector& operator+=(const NVector& rhs);						// ������� �������� ��������
	NVector& operator*=(const float& num) noexcept;					// ������� ��������� �� ������
	NVector& operator/=(const float& num) noexcept;					// ������� �� ������
	void Swap(NVector& rhs) noexcept;								// ��������� ����
	float& operator[](size_t index);								// ������ �� ������� � ������������ ��������������
	float operator[](size_t index) const;							// ������ �� ������� (��������)
	
	~NVector();
};

NVector& FillVector(NVector& v) noexcept;
NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator*(NVector lhs, const float& num);
NVector operator/(NVector lhs, const float& num);
float operator*(const NVector& lhs,const NVector& rhs);
std::ostream& operator<< (std::ostream& out, const NVector& v);
void Print(const NVector& v);