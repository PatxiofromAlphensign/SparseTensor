#include <util.h>
#include <vector>
#include <iostream>

namespace M {
    Value a;
    SparseTensor::SparseMatrixEntry sparse(2,5,a );
    template<typename T>
    concept floating = std::floating_point<T>;
    template<floating T>
    void f(std::vector<T> vec) {
    } 

    struct stuff {
        std::ostream& os;
        stuff(std::ostream& os ) : os(os) {}
        template<typename T>
        void operator<(T& obj) {os << obj;}
    };

    template<typename T>
    concept isfloating = std::is_floating_point_v<T>;

    struct main {
        SparseTensor::SparseMatrixEntry sp;
        main(std::ostream& os, int ab, int b, Value val) : sp(ab,b,val) {}
        template <isfloating T>
        void operator<(T& obj) {std::cout << obj;}
        };

    template< class T >
    struct is_floating_point
     : std::integral_constant<
         bool,
         std::is_same<float, typename std::remove_cv<T>::type>::value
     > {};

    template<typename T>
    concept test = true;
    };

template <M::test T>
void test(T &a) {}

int main() {

    std::vector<int> vec = {1,2};
    int t = 69;
    M::stuff(std::cout) < t;
    test(t);
    
};

