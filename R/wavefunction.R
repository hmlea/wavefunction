#' wavefunction
#' 
#' Calculate the wave function of the hydrogen atom using the Boost
#' implementation of the spherical harmonics.
#'
#' @name wavefunction
#' @docType package
#' @author Hayden Leatherwood \email{hmleatherwood@gmail.com} - 2022
#' @title Calculate the Hydrogen Wave Function
#' @description Calculate the wave function of the hydrogen atom using the
#' Boost implementation of the spherical harmonics.
#' @details The \emph{wavefunction} package calculates the wave function of the
#' hydrogen atom using the Boost implementation of the spherical harmonics. Note
#' that the \link[wavefunction]{psi} function returns the value of psi
#' and not that of the absolute value of psi squared.
#' @seealso \link[wavefunction]{psi}
#' 
#' @useDynLib wavefunction, .registration = TRUE
#' @export psi
#' @importFrom Rcpp evalCpp
NULL