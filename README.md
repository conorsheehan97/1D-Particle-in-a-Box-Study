# 1D-Particle-in-a-Box-Study
This project involves a study of the Quantum Mechanical 1D particle in a box scenario. We use an OOP approach to study this situation, calculate wavefunctions, energies, and use Monte Carlo methods to calculate energy levels, and position operator expectation values.

See included in this repository, the CPP Header, Implementation & Test File. Also included is the Python Jupyter notebook for producing Graphs based on the CPP output. Also see the PDF attached, which gives a Mathematical basis for this study, including a derivation of the analytical Wavefunction and Eigenvalue energies. It also includes an analysis of how Monte Carlo methods can be used in this study. Discussion of results is also included here. 

The CPP implementation, involves getting user input for Box Length. The user also chooses what particle they wish to investigate, by choosing one of 4 masses: Electron, Neutron, Uranium-235, or Plutonium-239. Once these attributes are set, 4 methods can be implemented. 

Firstly, a wavefunction calculator, which calculates n wavefunctions from a beginning N value to an end N value based on user input. These wavefunctions are then written to their own txt file, with parameter information and Eigenenergies included. 

Secondly, we calculate Eigenvalue Energies for the 4 particles, in a user defined range. We then write these values to a text file, graph in Python, and analyse the results, ensuring the trend makes sense in comparison to the known equation.

Thirdly, we use Monte Carlo methods to calculate the approximate energies again in a user defined range for Plutonium-239. The mathematical basis of this comparison is included in the PDF. We compare these results to the analytically known energies from the second segment above, and discuss results.

Finally we again use Monte Carlo methods to predict the expectation value of the Position operator x_hat for the ground state. The basis of this prediction & comparison is included in the PDF. We then compare this result to the known analytical result.
