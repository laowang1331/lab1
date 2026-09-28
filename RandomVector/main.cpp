#include "random_vector.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));  // 初始化随机种子，让每次运行结果不同

    RandomVector rv(20, 10.0);  // 20 个 0~10 之间的随机 double

    std::cout << "Values: ";
    rv.print();

    std::cout << "Mean: " << rv.mean() << std::endl;
    std::cout << "Max:  " << rv.max() << std::endl;
    std::cout << "Min:  " << rv.min() << std::endl;

    std::cout << "\nHistogram (5 bins):" << std::endl;
    rv.printHistogram(5);

    return 0;
}
