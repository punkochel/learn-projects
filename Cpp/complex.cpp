#include <cmath>
#include <cstdio>

struct str_complex {
private:
    double re, im;
public:
    str_complex(double a_re, double a_im)
    {
        re = a_re;
        im = a_im;
    }
    double modulo()
    {
        return sqrt(re*re + im*im);
    }
};

int main()
{
    str_complex z(2.3, 3.7);
    double mod;
    mod = z.modulo();
    printf("Result: %.2f\n", mod);
    return 0;
}
