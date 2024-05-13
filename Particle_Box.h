#pragma once
#include <vector>
#include <string>
class Particle_Box
{
private:
	double l; //Box-width
	double m; //particle mass 
	int n; //energy level 
	std::string selection;
	const int num_points{1000};
	//Declaring constants required 
	const double pi{ 3.14159 };
	const double h{6.626E-34};
	const double m_e{9.1E-31};
	const double m_n{1.7E-27};
	const double m_u{3.9023E-25}; // Note this is for U-235 the fissile form of Uranium (lower critical masss!)
	const double m_p{3.9687E-25}; // Note this is for Pu-239, which is formed by 2*Beta decay of U-238 + neutron
public:
	//Vectors for sections 1 & 2 of this project, for wavefunctions, and Eigenenergies for each particle 
	std::vector <double> x_values;
	std::vector <double> y_values;
	std::vector <std::vector <double>> energies;
	//Declaring getter and setter methods for object provate attributes
	void set_l();
	void set_m();
	void set_n();
	//Declaring these as const, as we definitely don't want to alter values 
	double get_l() const;
	double get_m() const;
	int get_n() const;
	// For a gievn particle, energy level, and box width, return the energy
	double energy(int n, double m, double l);
	//Default Constructors & Destructors
	Particle_Box();
	~Particle_Box();
	//Our wavefunction solution
	double wavefunc(double x, int n);
	//A driver for the above wavefunction method. Uses our private x & y vectors
	void calc_wavefunction_vals();
	//Uses our energies method. This returns Eigenvalues for all 4 particles within a range
	void energy_levels(int begin, int end);
	//Methods for both Monte Carlo methods, to get both position expectation value, and energy expectation value for eigenvalue
	double monte_carlo_energy(int num_iters, int energy_level );
	double monte_carlo_position(int num_iters, int energy_level);
};

