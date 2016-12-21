#include <iostream>
#include <random>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    
    std::mt19937 mt(42);
    double max_mt = (double)mt.max();
    int n_of_experience = 1000;
    double sum_mt = 0;
    double sum_mt_squared = 0;
    double sum_drand = 0;
    double sum_drand_squared = 0;
    for (int j = 0; j < n_of_experience; j++) {
        int n_of_trial = 100000;
        int n_hits_mt = 0;
        int n_hits_drand = 0;
        for (int i = 0; i< n_of_trial; ++i) {
            if(sqrt(pow(mt()/max_mt, 2) + pow(mt()/max_mt, 2)) < 1)
                n_hits_mt++;
            if(sqrt(pow(drand48(), 2) + pow(drand48(), 2)) < 1)
                n_hits_drand++;
        }
        sum_mt+=4*n_hits_mt/(double)n_of_trial;
        sum_mt_squared+=pow(4*n_hits_mt/(double)n_of_trial,2);
        sum_drand+=4*n_hits_drand/(double)n_of_trial;
        sum_drand_squared+=pow(4*n_hits_drand/(double)n_of_trial,2);
    }
    double mean_mt = sum_mt/n_of_experience;
    double std_mt = sqrt(sum_mt_squared/n_of_experience-pow(mean_mt,2));
    
    double mean_drand = sum_drand/n_of_experience;
    double std_drand = sqrt(sum_drand_squared/n_of_experience-pow(mean_drand,2));
    
    std::cout.precision(15);
    std::cout << "Mean result for mt generator : " << mean_mt << std::endl;
    std::cout << "Std for mt generator : " << std_mt << std::endl;
    
    std::cout << "Mean result for drand generator : " << mean_drand << std::endl;
    std::cout << "Std for drand generator : " << std_drand << std::endl;
    
    std::cout << "True value for Pi : " << M_PI << std::endl;
    
    std::cout << "Abs(mean - Pi) for mt generator : " << fabs(mean_mt-M_PI) << std::endl;
    std::cout << "Abs(mean - Pi) for drand generator : " << fabs(mean_drand-M_PI) << std::endl;

    return 0;
}
