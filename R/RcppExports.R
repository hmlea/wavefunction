# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#' Calculates the wave function of the hydrogen atom
#' 
#' @description
#' Calculates the wave function of the hydrogen atom using the
#' Boost implementation of the spherical harmonics. Note that this function
#' returns psi and not the absolute value of psi squared.
#'
#' @param n The principle quantum number, n
#' @param l The azimuthal quantum number, l
#' @param m The magnetic quantum number, m
#' @param r The radius of the spherical coordinates
#' @param theta The angle θ of the spherical coordinates
#' @param phi The angle φ of the spherical coordinates
#' @return The value of ψ calculated with the hydrogen wavefunction equation
#' @examples
#' psi(2, 1, 0, 0.5, 2, 5)
#' psi(4, 2, -1, 0.7, pi/2, pi)
psi <- function(n, l, m, r, theta, phi) {
    .Call(`_wavefunction_psi`, n, l, m, r, theta, phi)
}

