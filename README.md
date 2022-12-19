
<!-- README.md is generated from README.Rmd. Please edit that file -->

# wavefunction

<!-- badges: start -->
<!-- badges: end -->

The **wavefunction** package is used to calculate the hydrogen wave
function given the quantum numbers *n*, *l*, and *m* and a set of
spherical coordinates given in *r*, $\Theta$, and $\Phi$. The
**wavefunction** package uses the [Boost
implementation](https://www.boost.org/doc/libs/1_80_0/libs/math/doc/html/math_toolkit/sf_poly/sph_harm.html)
of the spherical harmonics via the
[bh](https://github.com/eddelbuettel/bh) package. This allows much
faster and more efficient calculations of the hydrogen wave function.

## Installation

### Download from GitHub with devtools

The easiest way to install the package is by using
[devtools](https://devtools.r-lib.org/) in the R console. Installing
with devtools only takes one step and installs the package straight from
GitHub:

    devtools::install_github("hmlea/wavefunction")

### Build and Install Manually

You can also build and install the package manually:

1.  Clone the repository with
    `git clone https://github.com/hmlea/wavefunction.git`
2.  Build the package using `R CMD build wavefunction`
3.  Install the package with `R CMD install wavefunction_1.0.tar.gz`
4.  (Optional) Delete the package now that it is installed with
    `rm wavefucntion_1.0.tar.gz`

## Usage

Given quantum numbers and a set of spherical coordinates, the $\Psi$
value of the hydrogen wave function can be calculated with the following
function:

    cpp_psi(n, l, m, r, theta, phi)

-   `n`   The principle quantum number, n
-   `l`   The azimuthal quantum number, l
-   `m`   The magnetic quantum number, m
-   `r`   The radius in spherical coordinates
-   `theta`   The angle $\Theta$ in spherical coordinates
-   `phi`   The angle $\Phi$ in spherical coordinates
