// Calistirmak icin g++ PCACov.cpp -I./eigen-git-mirror 
// eigen-git-mirror'i indirmek icin: https://github.com/eigenteam/eigen-git-mirror

#include<iostream>
#include<Eigen/Dense>

using Eigen::MatrixXd;

int main(){
    Eigen::MatrixXd m(2,2);
    m(0,1) = 1;
    m(0,0) = 0.5;
    // Matrisin aritmetik ortalamasi
    std::cout << m.mean() << std::endl;
    // Matris sutunlarinin aritmetik ortalamasi
    std::cout << m.colwise().mean() << std::endl;
    // 0.25, 0.5

    // https://stackoverflow.com/questions/42811084/eigen-subtracting-vector-from-matrix-columns
    Eigen::VectorXd mean_vector = m.colwise().mean();
    // Merkezleme
    // Amacimiz sutunlardan sutun ortalamalarini cikarmak:
    // 0.25     0.5
    // -0.25    -0.5
    std::cout << m << std::endl;
    std::cout << mean_vector << std::endl;
    std::cout << m.rowwise() - mean_vector.transpose() << std::endl;
    Eigen::MatrixXd centered = m.rowwise() - mean_vector.transpose();

    Eigen::MatrixXd cov = (centered.adjoint() * centered) / ( m.rows() - 1 ) ;
    std::cout << cov << std::endl;
    return 0;
}