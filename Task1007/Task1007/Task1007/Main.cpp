#include "Point_2D.h"
#include "Point_3D.h"
#include "vector"
#include "Bezier_curve.h"
#include "Data.h"
using namespace std;

int main()
{
	Data data("input.txt", "output.txt");
	data.read_info();
	if (data.R == 2)
	{
		Bezier_curve curve(data.T, data.N - 1, data.read_points_2D(data.N));
		data.write(curve.return_points_Zi());
		system("Draw_2D.py");
	}
	if (data.R == 3)
	{
		Bezier_curve curve(data.T, data.N - 1, data.read_points_3D(data.N));
		data.write(curve.return_points_Zi());
		system("Draw_3D.py");
	}
	return 0; 
}