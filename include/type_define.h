#ifndef TYPE_DEF_H_
#define TYPE_DEF_H_

#include <iostream>

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

using std::cout;
using std::endl;

using Eigen::Matrix;

typedef Matrix<double, 2, 1> mat21_t;
typedef Matrix<double, 2, 2> mat22_t;


#endif