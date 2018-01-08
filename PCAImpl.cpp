// Calistirmak icin g++ PCAImpl.cpp -I./eigen-git-mirror 
// eigen-git-mirror'i indirmek icin: https://github.com/eigenteam/eigen-git-mirror

#include<iostream>
#include<Eigen/Dense>
#include<vector>
#include<utility>
#include<algorithm>

using Eigen::MatrixXd;

bool compare(std::pair<int,double> p1, std::pair<int,double> p2){ return p1.second - p2.second; }
int main(){
    Eigen::MatrixXd m(2,2);
    m(0,1) = 1;
    m(0,0) = 0.5;
    m(1,0) = 0.5;
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

    // Kovaryans Matrisi Cikarimi
    Eigen::MatrixXd cov = (centered.adjoint() * centered) / ( m.rows() - 1 ) ;
    std::cout << cov << std::endl;
    
    // Eigenvector ayristirmasi
    Eigen::SelfAdjointEigenSolver<MatrixXd> eig_solver(2);

    eig_solver.compute(cov);
    std::cout << eig_solver.eigenvalues() << std::endl;
    std::cout << eig_solver.eigenvectors() << std::endl;

    // Indirgeme
    // Eigenvalue matrisi varyans büyük olan sutunlar icin buyuk degerler verir.
    // n boyutlu bir veriyi k boyutlu bir veriye indirgemek icin
    // en buyuk varyansa(eigenvaluelara) sahip k kadar sutun secilir.

    // sirasiyla en buyuk eigenvaluelara sahip k kadar sutunun indekslerini alacagiz.
    // sonra da k sutunlu bir matris olusturup orjinal verimizdeki sutunlari buna atayacagiz.
    Eigen::VectorXd eigvals = eig_solver.eigenvalues();
    // indisler icin basit bir vector olusturalim:
    std::vector< std::pair<int, double> > l;
    std::cout << eigvals.size() << std::endl;
    for(int i = 0; i < eigvals.size();i++)
    {
        l.push_back(std::pair<int,double>(i, eigvals(i)));
    }
    // sort vector of pairs by second element
    std::sort(l.begin(), l.end(), compare);
    int k = 1;
    // en iyi k elemani al
    for(int i = 0; i<k; i++)
    {
        std::cout <<"Indis: " << l[i].first << " Eigenvalue: " << l[i].second << std::endl;
    }
    return 0;
}