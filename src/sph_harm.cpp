// Copyright Hayden Leatherwood 2022.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// https://www.boost.org/LICENSE_1_0.txt)

// [[Rcpp::depends(BH)]]

#include <iostream>
#include <cmath>
#include <boost/math/special_functions/laguerre.hpp>
#include <boost/math/special_functions/spherical_harmonic.hpp>
#include <Rcpp.h>

using namespace Rcpp;
using namespace std;

// simple factorial function for the radial component
int fact(int number) {
    int output = 1;

    if (number == 0 || number == 1) {
        return output;
    } else {
        for (int i = 1; i <= number; i++) {
            output *= i;
        }
    }

    return output;
}

// might need to typecast these and change floats to double for more precision
float radial_comp(int n, int l, float r) {
    // Bohr radius might need to be added, set p to (2*Z) / (n*a0)
    // float a0 = 0.0529;  // in nm
    // Z is atomic number, might change later
    float Z = 1.0;
    float p = (2*Z) / (float)n;
    float pr = p*r;

    float radical = pow(p, 3) * (fact(n-l-1))/(2*n*fact(n+l));
    float assoc_lag = boost::math::laguerre((n-l-1), (2*l+1), pr);

    return sqrt(radical) * exp(-(pr/2)) * pow(pr, l) * assoc_lag;
}

// returns the real part of the complex spherical harmonics
float real_sph_harm_conj(int l, int m, float theta, float phi) {
    int phase = pow(-1, m);
    int m_dash = -m;
    return phase * boost::math::spherical_harmonic_r(l, m_dash, theta, phi);
}

// returns the imaginary part of the complex spherical harmonics
float i_sph_harm_conj(int l, int m, float theta, float phi) {
    int phase = pow(-1, m);
    int m_dash = -m;
    return phase * boost::math::spherical_harmonic_i(l, m_dash, theta, phi);
}

// calculates the real spherical harmonics
float real_sph_harm(int l, int m, float theta, float phi) {
    if (m > 0) {
        float norm_factor = pow(-1, m) / sqrt(2);
        float real_harm = boost::math::spherical_harmonic_r(l, m, theta, phi);
        float real_conj_harm = real_sph_harm_conj(l, m, theta, phi);
        return norm_factor * (real_harm + real_conj_harm);
    } else if (m < 0) {
        // this does saves some complex number arithmatic by only working with the imaginary part
        // however, if need be, this can be done using "std::complex"
        float i_norm_factor = pow(-1, m) / sqrt(2);
        int m_abs = abs(m);
        float i_harm = boost::math::spherical_harmonic_i(l, m_abs, theta, phi);
        float i_conj_harm = i_sph_harm_conj(l, m_abs, theta, phi);
        return i_norm_factor * (i_harm - i_conj_harm);
    } else {
        return boost::math::spherical_harmonic_r(l, m, theta, phi);
    }
}

// wavefunction calculations with the radial and spherical components

//' Calculates the wave function of the hydrogen atom
//' 
//' @description
//' Calculates the wave function of the hydrogen atom using the
//' Boost implementation of the spherical harmonics. Note that this function
//' returns psi and not the absolute value of psi squared.
//'
//' @param n The principle quantum number, n
//' @param l The azimuthal quantum number, l
//' @param m The magnetic quantum number, m
//' @param r The radius of the spherical coordinates
//' @param theta The angle θ of the spherical coordinates
//' @param phi The angle φ of the spherical coordinates
//' @return The value of ψ calculated with the hydrogen wavefunction equation
//' @examples
//' psi(2, 1, 0, 0.5, 2, 5)
//' psi(4, 2, -1, 0.7, pi/2, pi)
// [[Rcpp::export]]
float psi(int n, int l, int m, float r, float theta, float phi) {
    float radial = radial_comp(n, l, r);
    float spherical = real_sph_harm(l, m, theta, phi);
    return radial * spherical;
}

