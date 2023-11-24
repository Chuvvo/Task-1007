#pragma once
#include "vector"
#include "Point.h"
#include <iostream>
#include "Point_2D.h"
#include "Point_3D.h"
class Bezier_curve
{
	int t;
	int N;
	std::vector<Point*> points_Zi;
	std::vector<double> split;
	double Bk(int k, int n, int t);
	double Zi(int n, int t, std::vector<double> Zk);
public:
	Bezier_curve(int t, int N, std::vector<Point_2D> points) : t(t), N(N) 
	{
		fun_split();
		for (int j = 0; j <= t; j++)
		{
			Point_2D *summ = new Point_2D;
			for (int i = 0; i <= N; i++) *summ = *summ + points[i] * Bk(i, split[j]);
			points_Zi.push_back(summ);
		}
		

	}
	Bezier_curve(int t, int N, std::vector<Point_3D> points) : t(t), N(N) 
	{
		fun_split();
		for (int j = 0; j <= t; j++)
		{
			Point_3D *summ = new Point_3D;
			for (int i = 0; i <= N; i++) *summ = *summ + points[i] * Bk(i, split[j]);
			points_Zi.push_back(summ);
		}
	}
	void fun_split()
	{
		for (double i = t; i >= 0; i--)
		{
			split.push_back(((double)(t - i)) / t);
		}
	}
	double factorial(int n)
	{
		if (n == 0.)
			return 1.;
		return double(n * factorial(n - 1));
	}
	double Bk(int k, double t)
	{
		return (factorial(N) / (factorial(k) * factorial((N - k)))) * pow(t, k) * pow((1 - t),(N - k));
	}

	std::string to_string()
	{
		std::string str;
		for (int i = 0; i <= t; i++)
			str += points_Zi[i]->to_string();
		return str;
	}
	std::vector<Point*> return_points_Zi()
	{
		return points_Zi;
	}
};


