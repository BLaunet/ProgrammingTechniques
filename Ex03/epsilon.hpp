#ifndef EPSILON_HPP
#define EPSILON_HPP
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
#endif