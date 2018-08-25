#ifndef INCLUDE_TEST_H__
#define INCLUDE_TEST_H__

template<typename T>
class Test
{
public:
    Test(std::vector<T> vec)
        : _vec(vec) {}
// 如果在std被using之后，可以不用std::
    std::vector<T>& get_vec() { return _vec; }

private:
    std::vector<T> _vec;
};

#endif