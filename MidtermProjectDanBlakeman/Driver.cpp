//Daniel Blakeman
//CIS 2207-502
//Midterm Project - Rainfall Statistics
#include <iostream>
#include "Rainfall.h"
#include "List.cpp"
#include "Node.cpp"
using namespace std;

int main()
{
	char entry = 'A';
	LinkedList<Rainfall>* newList = new LinkedList<Rainfall>;

	do
	{
		string month = "January";
		float amount = 0;
		int position = 1;
		Rainfall* newEntry = new Rainfall;
		
		//Menu
		cout << endl;
		cout << "Rainfall Statistics Menu" << endl;
		cout << "A -- Add a month of statistics" << endl;
		cout << "E -- Edit a month of statistics" << endl;
		cout << "P -- Print report" << endl;
		cout << "Q -- Quit" << endl;
		cout << "Enter Selection: ";
		cin >> entry;

		switch (entry)
		{
		case 'A':
		{
			cout << "Enter Month: ";
			cin >> month;
			newEntry->setMonth(month);
			cout << endl;

			cout << "Enter Rainfall Amount (In Inches): ";
			cin >> amount;
			newEntry->setRainAmount(amount);
			cout << endl;

			newList->insert(position, *newEntry);
			position++;
			break;
		}
		case 'E':
		{
			Rainfall* monthEntry = new Rainfall();
			Rainfall* lastEntry = new Rainfall;
			cout << "Enter Month: ";
			cin >> month;
			int x = 1;
			for(x = 1; x <= newList->getLength(); x++)
			{
				*monthEntry = newList->getEntry(x);
				if (monthEntry->getMonth() == month)
				{
					cout << "Please enter new rainfall amount (In Inches): ";
					cin >> amount;
					monthEntry->setRainAmount(amount);
					newList->replace(x, *monthEntry);
				}
			}
			
			*lastEntry = newList->getEntry(newList->getLength());
			if (lastEntry->getMonth() != month)
				cout << "Error: Invalid Month" << endl;
			break;
		}
		case 'P':
		{	
			//Variables and Objects
			Rainfall output;
			float totalRainfall = 0;
			float averageRainfall = 0;
			Rainfall mostRainfall = newList->getEntry(1);
			Rainfall leastRainfall = newList->getEntry(1);

			//Output
			cout << endl;
			cout << "Full Report: " << endl;
			for (auto x = 1; x <= newList->getLength(); x++)
			{

				output = newList->getEntry(x);

				//Total Rainfall
				totalRainfall += output.getRainAmount();
				

				//Average Rainfall
				averageRainfall = totalRainfall / newList->getLength();
				

				//Most Rainfall
				if (output.getRainAmount() > mostRainfall.getRainAmount())
					mostRainfall = output;

				//Least Rainfall
				if (output.getRainAmount() < mostRainfall.getRainAmount())
					mostRainfall = output;
			}

			//Output
			cout << "Total Rainfall: " + to_string(totalRainfall) << endl;
			cout << "Average Rainfall: " + to_string(averageRainfall) << endl;
			cout << "Most Rainfall: " + mostRainfall.getMonth() + " had " + to_string(mostRainfall.getRainAmount()) + " inches." << endl;
			cout << "Least Rainfall: " + leastRainfall.getMonth() + " had " + to_string(leastRainfall.getRainAmount()) + " inches." << endl;
			break;
		}
		case 'Q':
			break;
		}
	} while (entry != 'Q');
	
	return 1;
}