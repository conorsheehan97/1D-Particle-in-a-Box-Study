#include <iostream>
#include <iomanip>
#include "Particle_Box.h"


using namespace std;

int main()
{
	//Calculating Wavefunctions for different Energy Levels

	/*Particle_Box obj;
	obj.set_l();
	obj.set_m();
	int num_times;
	cout << "\nHow many wavefunctions would you like to check?\n";
	cin >> num_times;
	for (int i = 0; i < num_times; i++)
	{
		obj.set_n();
		obj.calc_wavefunction_vals();
	}*/

	//------------------------------------------------------------------------------

	// Energy for Eigenvalues Section 

	/*Particle_Box obj2;
	obj2.set_l();
	int begin, end;
	cout << "\nWhat Eigenenergies would you like to calculate? Please enter a range in the format [begin,end]  \n";
	cin >> begin;
	cin >> end;
	obj2.energy_levels(begin, end);*/

	//-------------------------------------------------------------------------------

	/*Particle_Box obj3;
	obj3.set_l();
	obj3.set_m();
	double m = obj3.get_m();
	double l = obj3.get_l();
	int num,begin,end;
	cout << "\n-----------------------------------------------------------\n";
	cout << "Monte Carlo to Analytical comparison:\n";
	cout << "\nEnter a beginning Energy level, followed by end\n";
	cin >> begin;
	cin >> end;
	//Open the file
	std::ofstream dataFile("Monte_Carlo_Energy.txt");
	if (!dataFile.is_open()) {
		std::cerr << "Unable to open file for writing!\n";
	}
	dataFile << "Monte Carlo" << "\t" << "Analytical Solution" << "\n";
	for (int i = begin; i <= end; i++)
	{
		dataFile << obj3.monte_carlo_energy(10000, i) << "\t" << obj3.energy(i,m,l) << "\n";
	}
	// Close the file
	dataFile.close();*/

	//-----------------------------------------------------------------------------------------------

	//Calculating the Position Operator Expectation Value
	Particle_Box obj4;
	obj4.set_l();
	obj4.set_n();
	cout << "\n--------------------------------------------------------------\n";
	cout << "Expectation Value Calculation:\n\n";
	cout << setprecision(5);
	double result = obj4.monte_carlo_position(10000, 1);
	cout << "The expected value of a particle in the Ground State, in our 1D box occurs at: " << result << "\n";
	cout << "This is fractionally " << (result/obj4.get_l()) << " of the Box of width: " << obj4.get_l();
	cout << "\n--------------------------------------------------------------\n";
	system("PAUSE");
	return EXIT_SUCCESS;
}


