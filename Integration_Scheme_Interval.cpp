#include "Integration_Scheme_Interval.h"

namespace Com_Methods
{
	//�����������: �� ���� ������� ��� ������������ �������
	Integration_Scheme_Interval::Integration_Scheme_Interval(Integration_Scheme_Type Type)
	{
		//���������� �������� ����� � ����� ��������������
		switch (Type)
		{
			//����� ������ �����-1
			case Gauss1:
			{
				Weights = { 2 };
				Nodes   = { 0 };
				break;
			}
		    case Gauss2:
            {
                Weights = { 1, 1 };
                Nodes   = { 1.0 / sqrt(3.0), -1.0 / sqrt(3.0) };
                break;
            }
            case Gauss3:
            {
                Weights = { 8.0/9, 5.0/9, 5.0/9};
                Nodes   = { 0, sqrt(3.0 / 5.0), -sqrt(3.0 / 5.0) };
                break;
            }
            case Gauss4:
            {
                Weights = { (18 + sqrt(30.0)) / 36, (18 + sqrt(30.0)) / 36,
                            (18 - sqrt(30.0)) / 36, (18 - sqrt(30.0)) / 36 };
                Nodes   = { sqrt((3.0 - 2*sqrt(6.0/5)) / 7), -sqrt((3.0 - 2*sqrt(6.0/5)) / 7),
                            sqrt((3.0 + 2*sqrt(6.0/5)) / 7), -sqrt((3.0 + 2*sqrt(6.0/5)) / 7),};
                break;
            }
            case Gauss5:
            {
                Weights = { 128.0 / 225, (322 + 13*sqrt(70.0)) / 900, (322 + 13*sqrt(70.0)) / 900,
                                         (322 - 13*sqrt(70.0)) / 900, (322 - 13*sqrt(70.0)) / 900 };
                Nodes   = { 0 , (1.0 / 3) * sqrt(5.0 - 2*sqrt(10.0 / 7)),
                               -(1.0 / 3) * sqrt(5.0 - 2*sqrt(10.0 / 7)),
                                (1.0 / 3) * sqrt(5.0 + 2*sqrt(10.0 / 7)),
                               -(1.0 / 3) * sqrt(5.0 + 2*sqrt(10.0 / 7))};
                break;
            }
            case Trapezium:
            {
                Weights = { 1,  1 };
                Nodes   = { 1, -1 };
                break;
            }
            case Parabolas:
            {
                Weights = { 4.0 / 3, 1.0 / 3, 1.0 / 3 };
                Nodes   = { 0 , 1, -1};
                break;
            }

		}
	}

	//����� ��� ���������� ������������ ���������: 
	//Begin � End - ������ � ����� ������� 
	//Num_Segments - ����� ���������
	//Func - ��������������� �������
	double Integration_Scheme_Interval:: Calculate_Integral(
								         const double &Begin,
								         const double &End,
								         int Number_Segments,
								         const std::function<double(const double &P)>&Func) const
	{
		//��������� (������������ �����)
		double Result = 0.0;
		//��������� ����� ��������
		double X0;
		//��� �� �������
		double h = (End - Begin) / Number_Segments;
		//����� �� ���� ��������� ���������
		for (int i = 0; i < Number_Segments; i++)
		{
			//��������� ����� ��������
			X0 = Begin + i * h;
			//����� �� ����� ��������������
			for (int Integ_Point = 0; Integ_Point < Nodes.size(); Integ_Point++)
			{
				//������� � ������-�������� [-1, 1]
				double P = X0 + (1 + Nodes[Integ_Point]) * h / 2.0;
				Result += Weights[Integ_Point] * Func(P);
			}
		}
		//��������� ��������� � ������ �������� �� ������� [-1, 1]
		return Result * (h / 2.0);
	}
}
