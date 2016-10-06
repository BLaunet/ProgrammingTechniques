#include "epsilon.hpp"
template <class T>
T epsilon()
{
    T eps_cand = 1;
    while(eps_cand/2 +1 != 1)
    {
        eps_cand/=2;
    }
    return eps_cand;
}

template int epsilon<int>();
template double epsilon<double>();
template float epsilon<float>();