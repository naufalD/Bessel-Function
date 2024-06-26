#include <cmath>

double j_pm_one(double x, int l, double j_l, double j_lpmone){
    return ((2.0*l+1.0)/x)*j_l-j_lpmone;
}

double alg_up(double x, int l){
    double j_nplusone {1};
    double j_n {(sin(x)/(x*x))-(cos(x)/x)};
    double j_nminusone {sin(x)/x};

    if (l==0){
        return j_nminusone;
    }

    for (int i {1}; i<=l-1; ++i){
        j_nplusone = j_pm_one(x, i, j_n, j_nminusone);
        j_nminusone = j_n;
        j_n = j_nplusone;
    }
    return j_n;
}

double alg_down(double x, int l){
    double j_nplusone {1};
    double j_n {1};
    double j_nminusone {1};
    double j_result {1};

    for (int i {30}; i >= 0; --i){
        j_nminusone = j_pm_one(x, i+1, j_n, j_nplusone);
        j_nplusone = j_n;
        j_n = j_nminusone;
        if (i==l){
            j_result = j_n;
        }
    }
    return j_result*((sin(x)/x)/j_n);
}
