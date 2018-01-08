// Calistirmak icin g++ BasicEigen.cpp -I./eigen-git-mirror 
// eigen-git-mirror'i indirmek icin: https://github.com/eigenteam/eigen-git-mirror
#include<iostream>
#include<Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    Eigen::MatrixXd m(2,2);
    m(0,1) = 1;
    std::cout << m << std::endl;
    return 0;
}