#pragma once
#include <fstream>
#include "string"
#include "Point_2D.h"
#include "Point_3D.h"
#include "Bezier_curve.h"
#include <vector>
class Data
{
    std::ifstream in;
    std::ofstream out;
    std::string txt_in;
    std::string txt_out;
public:
    int R, N, T;
    Data(std::string in, std::string out) : txt_in(in), txt_out(out), R(0), N(0), T(0) {}

    void read_info()
    {
        std::vector<double> data;
        in.open(txt_in);
        if (in.is_open())
        {
            in >> R;
            in >> N;
            in >> T;
            in.close();
        }
    }
    std::vector<Point_2D> read_points_2D(int num)
    {
        std::vector<Point_2D> data;
        in.open(txt_in);
        if (in.is_open())
        {
            double x, y;
            int skip;
            in >> skip;
            in >> skip;
            in >> skip;
            for (int i = 0; i < num; i++)
            {
                in >> x;
                in >> y;
                Point_2D point(x, y);
                data.push_back(point);
            }
            in.close();
        }
        return data;
    }
    std::vector<Point_3D> read_points_3D(int num)
    {
        std::vector<Point_3D> data;
        in.open(txt_in);
        if (in.is_open())
        {
            double x, y, z;
            int skip;
            in >> skip;
            in >> skip;
            in >> skip;
            for (int i = 0; i < num; i++)
            {
                in >> x;
                in >> y;
                in >> z;
                Point_3D point(x, y, z);
                data.push_back(point);
            }
            in.close();
        }
        return data;
    }
    void write(std::vector<Point*> data)
    {
        out.open(txt_out);
        if (out.is_open())
        {
            for (int i = 0; i < data.size(); i++)
                out << data[i]->to_string() << std::endl;
            out.close();
        }
    }
};

