#pragma once
#include "Integration_Scheme.h"
#include <functional>
#include <cmath>

namespace Com_Methods
{
	class Integration_Scheme_Interval : protected Integration_Scheme
	{
	public:
		//�����������: �� ���� ������� ��� ������������ �������
		Integration_Scheme_Interval(Integration_Scheme_Type Type);
		//����� ��� ���������� ������������ ���������: 
		//Begin � End - ������ � ����� ������� 
		//Num_Segments - ����� ���������
		//Func - ��������������� �������
		double Calculate_Integral(const double &Begin,
								  const double &End,
								  int Number_Segments,
								  const std::function<double(const double &P)>&Func) const;
	};
}

