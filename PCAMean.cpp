// Calistirmak icin g++ PCAMean.cpp -I./eigen-git-mirror 
// eigen-git-mirror'i indirmek icin: https://github.com/eigenteam/eigen-git-mirror

#include<iostream>
#include<Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    Eigen::MatrixXd m(2,2);
    m(0,1) = 1;
    
    // Matrisin aritmetik ortalamasi
    std::cout << m.mean() << std::endl;
    // Matris sutunlarinin aritmetik ortalamasi
    std::cout << m.colwise().mean() << std::endl;

    return 0;
}