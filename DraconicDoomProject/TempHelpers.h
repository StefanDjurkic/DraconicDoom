/******************************************************************************************\
This file is part of Draconic Doom.

"Draconic Doom" is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

"Draconic Doom" is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with "Draconic Doom".  If not, see <https://www.gnu.org/licenses/>.

/******************************************************************************************/

/******************************************************************************************\
"Draconic Doom", Version 0.0.2
FileName: TempHelpers.h
Author:  Stefan Djurkic
Contact: <https://www.StefanDjurkic.com> || stefandjurkic@gmail.com
Copyright 2018 Stefan Djurkic
See readme for more information on this program
/******************************************************************************************/
#ifndef _TEMPHELPERS_H_ 
#define _TEMPHELPERS_H_
#include <iostream>
#include <string>
#include <vector>
#include "Constants.h"
#include "HelperFunctions.h"
#include "SaveLoad.h"
using namespace Helper_Functions;
using namespace Save_Load;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
namespace Temp_Helpers
{
	/* Template function that returns the greatest of three variables */
	template<typename T>
	T& GreatestNum(T& a, T& b, T& c)
	{
		T& tempVar = (a < b) ? b : a;						// tempvar equates to the greater of a or b
		return (tempVar > c) ? tempVar : c;					// return tempvar which equates to the greater of a/b or c
	}

	/* Transforms a portion of a 2d vector (denoted by sector) to a 1d vector with template parameters */
	template<typename T>
	vector <T> TransformVector2d(int sector, vector <vector <T>> vect2d)
	{
		vector <T> vect1d;									// The 1d vector to be returned
		for (int i = 0; i < vect2d[sector].size(); i++)		// Loop through the size of the vector 
		{	
			vect1d.push_back(vect2d[sector][i]);			// Add to the vector with push_back 
		}
		return vect1d;										// Return the vector
	}

	/*Marked for change*/
	/* Loads an encounter with template parameter value which indicates the position in the file and a file name */
	template<typename T>
	std::vector<T> LoadEncounter(std::string File, T value)
	{
		std::ifstream file(File);									 // File in question
		T name;														 // Name we are looking for
		T target;													 // Variable for which we input from a file and then use to input into a vector
		std::vector<T> encounter;									 // Vector to be returned
		int size = 0; 												 
		if (file.is_open())											 // If the file is open we proceed
		{															 
			while (name != value)									 // While name doesn't equate to the desired value loop
			{														 
				file >> name;										 // Input the file position to name
				if (name == value)									 // If name does equate to value
				{													 
					file >> size;									 // We know the next number is a size integer
					for (int i = 0; i < size; i++)					 // Loop for the given size
					{
						file >> target; encounter.push_back(target); // Add into our vector target variables
					}
				}
				else
				{
					file.ignore(1000, '\n');						// Skip a line
				}
			}	
			file.close();                                           // Make sure to close the file
		};				                                            
		return encounter;                                           // Return the vector
	}
	
	/* this function loads a string from a text file based on a desired value */
	template<typename T>
	T LoadString(std::string File, T value)
	{
		std::ifstream file(File);									// Declare an ifstream object called file
		T name;			                                            // Declare a name variable of type T
		T target;		                                            // Declare a target variable of type T
		int size = 0;	                                            // Initialize an integer size to 0 
		if (file.is_open())											// If the file is open
		{
			while (name != value)									// While name does not equate to our value
			{
				file >> name;										// Input the current file position to name
				if (name == value)									// If name does equate to value
				{
					file >> size;									// Input a size integer to our size variable
					for (int i = 0; i < RandomGen(1, size); i++) 
					{ 
					file >> target;									// Input into target the value
					}
				}
				else
				{
					file.ignore(1000, '\n');						// Skip a line
				}
			}
			file.close();											// Close our file
		}	
		return target;												// Return the target
	}
	
	/* Save a 1d vector to a file */
	template<typename T>
	void Save1dVector(const char * file1d, std::vector <T> saveVect1d, int removeFile)
	{
		if (removeFile != 0)						// do we delete the file?
		{
			remove(file1d);
		}
		std::ofstream outfile;						// Declare an ofstream object named outfile
		outfile.open(file1d, std::ios::app);		// Open and append file1d
		if (outfile.is_open())						// If outfile is open
		{
			for (int x = 0; x < saveVect1d.size(); x++)
			{
				outfile << saveVect1d[x] << " ";    // Output to a file our 1d vector by position
			}
			outfile << "\n";						// Set a new line
		}
		outfile.close();							// Close the file
	}
}
#endif //end of header
