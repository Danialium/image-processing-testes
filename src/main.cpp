#include <iostream>
#include <opencv2/core.hpp>

int main()
{
    cv::Mat M(4, 4, CV_8UC1);
    cv::randu(M, 0, 255);
    std::cout << "M = " << '\n' << " " << M << '\n' << '\n';
    std::cout << "Hello World" << '\n' ;
    return 0;
}