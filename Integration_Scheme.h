#pragma once
#include "Point.h"
#include <vector>

namespace Com_Methods
{
	//����� ����� ��������������
	class Integration_Scheme
	{
	protected:
		//���� ��������������
		std::vector<double> Nodes;
		//���� ������������ �������
		std::vector<double> Weights;
	public:
		//���� ������������ ������
		enum Integration_Scheme_Type
		{
			Gauss1,
			Gauss2,
			Gauss3,
			Gauss4,
			Gauss5,
			Trapezium,
			Parabolas,
		};
	};
}

