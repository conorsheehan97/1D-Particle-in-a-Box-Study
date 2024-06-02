# 1D-Particle-in-a-Box-Study

# Introduction 
This project involves a detailed study of the Quantum Mechanical 1D particle in a box scenario. Using an object-oriented programming (OOP) approach, we calculate wavefunctions and energies, and employ Monte Carlo methods to determine energy levels and position operator expectation values.

# Included in this repository:
### C++ Files 
- Header File
- Implementation File
- Test File 
### Python Jupyter Notebook:
- For producing graphs based on the C++ output.
### PDF Document:
 - Provides the mathematical basis for this study, including a derivation of the analytical wavefunction and eigenvalue energies.
 - Includes an analysis of how Monte Carlo methods are applied in this study.
 - Discusses the results obtained from the simulations.

# Methodology
## User Input and Initilization
The C++ implementation involves getting user input for the box length and the particle to investigate, chosen from four options: Electron, Neutron, Uranium-235, or Plutonium-239. Once these attributes are set, four primary methods can be implemented:
### 1 Wavefunction Calculation:
- Calculates n wavefunctions from a beginning N value to an end N value based on user input.
- These wavefunctions are written to their own text files, with parameter information and eigenenergies included.
### 2 Eigenvalue Energy Calculation:
- Calculates eigenvalue energies for the four particles over a user-defined range.
- Results are written to a text file, graphed in Python, and analyzed to ensure the trend aligns with the known equation.
### 3 Monte Carlo Energy Calculation:
- Uses Monte Carlo methods to approximate the energies over a user-defined range for Plutonium-239.
- The mathematical basis of this comparison is included in the PDF.
- Results are compared to the analytically known energies from the previous segment and discussed.
### 4 Monte Carlo Position Operator Expectation Value:
- Uses Monte Carlo methods to predict the expectation value of the position operator $\hat{x}$ for the ground state.
- The basis of this prediction and comparison is detailed in the PDF.
- Results are compared to the known analytical result.

# Conclusions
This project provides a comprehensive analysis of the Quantum Mechanical 1D particle in a box scenario using both analytical and numerical methods. By leveraging an OOP approach in C++ and thorough data analysis in Python, we have created a robust framework for studying wavefunctions, eigenenergies, and the application of Monte Carlo methods. The results offer valuable insights and a clear visualization of the theoretical concepts and numerical approximations within this quantum mechanical system.
