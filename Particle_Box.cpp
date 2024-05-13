#include "Particle_Box.h"
#include "gnuplot-iostream.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <random>

void Particle_Box::set_l()
{
	//Here we use a do-while loop to ensure that a numeric data type is entered
	double length;
	bool input = false;
	do {
		std::cout << "\nWhat L-Value for the box? This will be converted to Angstroms\n";
		if (std::cin >> length) {
			// Input was successful, clear any error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			l = length * 1E-10;
			input = true;
		}
		else {
			// Clear the error flags and discard any invalid input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter an integer/double.\n";
		}

		
	} while (!input);
}
void Particle_Box::set_m()
{
	//Similar to the L setter method, we use a do while loop here. This simply assigns one of the mass constant to the m attribute
	char choice;
	do {
		
		std::cout << "\n----------------------------------------------------------------\n";
		std::cout << "For which particle would you like to see the solution for?" << std::endl;
		std::cout << "Electron - Press e" << std::endl;
		std::cout << "Neutron - Press n" << std::endl;
		std::cout << "Uranium - Press u" << std::endl;
		std::cout << "Plutonium - Press p" << std::endl;
		std::cout << "\n----------------------------------------------------------------\n";
		std::cin >> choice;
		switch (choice)
		{
		case 'e':
		case 'E':
			std::cout << "\nYou have chosen Electron" << std::endl;
			this->m = m_e; 
			this->selection = "Electron"; break;
		case 'n':
		case 'N':
			std::cout << "\nYou have chosen Neutron" << std::endl;
			this->m = m_n; 
			this->selection = "Neutron"; break;
		case 'u':
		case 'U':
			std::cout << "\nYou have chosen Uranium" << std::endl;
			this->m = m_u; 
			this->selection = "Uranium"; break;
		case 'p':
		case 'P':
			std::cout << "\nYou have chosen Plutonium" << std::endl;
			this->m = m_p; 
			this->selection = "Plutonium"; break;
		}
	} while (choice != 'e' && choice != 'E' && choice != 'n' && choice != 'N' && choice != 'u' && choice != 'U' && choice != 'p' && choice != 'P');
}
void Particle_Box::set_n()
{
	//Exact same as the l setter method. Do-while as this is a post check method
	int num;
	bool input = false;
	do {
		std::cout << "\nWhich Energy Level would you like to see?\n";
		if (std::cin >> num)
		{
			// Input was successful, clear any error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			input = true;
		}
		else
		{
			// Clear the error flags and discard any invalid input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter an integer/double.\n";
		}
		
	} while (!input);
}
double Particle_Box::get_l() const 
{
	return l;
}
int Particle_Box::get_n() const
{
	return n;
}
double Particle_Box::get_m() const
{
	return m;
}
double Particle_Box::energy(int n, double m, double l)
{
	//This method returns the energy of a particle for a given eigenvalue & length based on the analytically derived formula
	double energy = (pow(h,2)*pow(n,2)) / (8*m*pow(l,2));
	return energy;
}
double Particle_Box::wavefunc(double x, int n)
{
	//This method returns the wave function. Note the normalisation constant is set to 1 here, to ensure our graph ranges from [-1,1]
	double norm_constant = sqrt(2 / l);
	double normalise = 1 / norm_constant;
	return (normalise*norm_constant * (sin((n * pi * x) / l)));

};
void Particle_Box::calc_wavefunction_vals()
{
	//Here we use the predefined wave function method. Based on object attributes we calculate Psi(x), and write the results
	// to a text file, so that we can graph the results in Python. We also start the txt file with the Energy of the solution and 
	//parameters. The results being appended to vectors ended up being uneccessary, but at the time I thought I may need the results again
	double interval_width = (l / num_points);
	double x_0{ 0 }, x_n;
	double result;
	std::string filename = "Eigenvalue_" + std::to_string(this->n) + "_Particle_" + selection + ".txt";
	//Open the file
	std::ofstream dataFile(filename);
	if (!dataFile.is_open()) {
		std::cerr << "Unable to open file for writing!\n";
	}
	dataFile << "Eigenvalue : " << n <<  " - Energy : " << energy(this->n, this->m, this->l) << " J - " << selection << "\n";
	for (int i = 0; i < num_points; i++)
	{
		x_n = x_0 + i * interval_width;
		result = wavefunc(x_n,n);
		x_values.push_back(x_n);
		y_values.push_back(result);
		dataFile << x_n << " " << result << "\n";
	}
	// Close the file
	dataFile.close();
}
Particle_Box::Particle_Box()
{
	//Setting default parameters
	n = 1;
	l = 200E-10;
	m = m_e;
}
Particle_Box::~Particle_Box()
{
}
void Particle_Box::energy_levels(int begin, int end)
{
	//Initially make sure values are in correct order
	if (begin > end)
	{
		double temp = end;
		end = begin;
		begin = temp; 
	}
	if (begin == end)
	{
		std::cout << "\nYou entered two equal values, please enter differing values\n";
		exit(0);
	}
	else
	{

		std::string filename = "Eigenenergies_from_" + std::to_string(begin) + "_to_" + std::to_string(end) + ".txt";
		//Open the file
		std::ofstream dataFile(filename);
		if (!dataFile.is_open()) {
			std::cerr << "Unable to open file for writing!\n";
		}
		//Define headers
		dataFile << "Electron \t Neutron \t Uranium-235 \t Plutonium \n";
		for (int i = begin; i <= end; i++)
		{
			//Again, adding results to our vector of vectors in case we want them later
			energies.push_back({ energy(i, m_e, l),energy(i, m_n, l),energy(i, m_u, l),energy(i, m_p, l) });
			//Use our energy method in order to file up the text file, with [end-begin] rows
			dataFile << energy(i, m_e, l) << "\t" << energy(i, m_n, l) << "\t" << energy(i, m_u, l) << "\t" << energy(i, m_p, l) << "\n";
		}
		// Close the file
		dataFile.close();
	}

}
double Particle_Box::monte_carlo_energy(int num_iters, int energy_level)
{
	//The first Monte Carlo method. We use a uniform distribution between 0 and L, and seed the Mersenne Twister
	double total_energy{0}, average_energy;
	//Kinetic Energy Prefix
	double kin_energy = ((pow(h, 2)) / (pow(2 * pi, 2) * 2 * m_p))*(pow(energy_level*pi,2)/pow(l,2));
	// Seed the random number generator
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator

	// Define the range for random numbers
	double min = 0.0;
	double max = 200.0;

	// Create a uniform distribution for generating random numbers in the range [min, max)
	std::uniform_real_distribution<double> dist(min, max);
	for (int i = 0; i <= num_iters; i++)
	{
		// Generate a random number
		double random_number = dist(gen);
		random_number *= 1E-10; //Converting to Angstroms
		//Summing all random x_i energies
		total_energy += kin_energy * abs(wavefunc(random_number, energy_level));
	}
	average_energy = total_energy / num_iters;
	//returning the average value
	return average_energy;
}
double Particle_Box::monte_carlo_position(int num_iters, int energy_level) 
{
	//Our second Monte Carlo implementation 
	double total{0}, average;
	// Seed the random number generator
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator

	// Define the range for random numbers
	double min = 0.0;
	double max = l/1E-10;

	// Create a uniform distribution for generating random numbers in the range [min, max)
	std::uniform_real_distribution<double> dist(min, max);
	for (int i = 0; i <= num_iters-1; i++)
	{
		// Generate a random number
		double random_number = dist(gen);
		//std::cout << random_number;
		random_number *= 1E-10; //Converting to Angstroms
		//Similar to above, sum the total pos*wavefunc(pos)^2
		total += wavefunc(random_number, energy_level)*wavefunc(random_number,energy_level)*random_number;
	}
	average = 2*total / num_iters;
	return average;
};