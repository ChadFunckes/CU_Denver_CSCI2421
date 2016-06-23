// FILE: grocery.cxx
// A small test program to test the simulate function for series of grocery store line.

#include <iostream>   // Provides cout
#include <vector>	  // Provides vector
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <queue>      // Provides queue
#include "grocery.h"  // Provides averager, bool_source, washer
using namespace std;
using namespace main_savitch_8A;

void simulate
(double arrival_prob, unsigned int total_time);
// Precondition: 0 <= arrival_prob <= 1.
// Postcondition: The function has simulated a grocery where arrival_prob 
// is the probability of a customer arriving in any second, and total_time
// is the total number of seconds for the simulation. 
// After the simulation, the function two pieces of information to cout: 
// (1) The number of cars washed
// (2) The average waiting time of a customer.

int main( )
{
    simulate(0.25, 6000);
    return EXIT_SUCCESS;
}

void simulate
(double arrival_prob, unsigned int total_time)
// Library facilities used: iostream, queue, washing.h
{
    washer machine[5]; // creates 5 machines
	averager wait_times[5]; // creates 5 wait time counters
	vector<queue<unsigned int> > arrival_times; // Waiting customer’s time stamps
	for (unsigned i = 0; i < 5; i++) {			// push 5 queues into the vector with random process times	
		arrival_times.push_back(queue<unsigned int>()); 
		machine[i].set_time(rand()% 600+10);
	}
    unsigned int next;						 // A value taken from the queue
    bool_source arrival(arrival_prob); 
    unsigned int current_second;
	unsigned int line_length = 0;
	unsigned int short_line;

    // Write the parameters to cout.
	for (unsigned i = 0; i < 5; i++){
		cout << "Seconds register " << i <<" takes to finish " << machine[i].get_time() << endl;
	}
    cout << "Probability of customer arrival during a second: ";
    cout << arrival_prob << endl;
	cout << "Total simulation seconds: " << total_time << endl << endl;

	for (current_second = 1; current_second <= total_time; ++current_second)
	{   // Simulate the passage of one second of time.

		// Check whether a new customer has arrived.
		if (arrival.query()){
			short_line = 0; // set shortest line to line 0 by default
			line_length = arrival_times[0].size(); // set shortest comparison length to line 0 by default
		// find the shortest line to place the person into
			if (arrival_times[1].size() < arrival_times[2].size() && arrival_times[1].size() < line_length){
				line_length = arrival_times[1].size();
				short_line = 1;
			}
			else if (arrival_times[2].size() < arrival_times[3].size() && arrival_times[2].size() < line_length){
				line_length = arrival_times[2].size();
				short_line = 2;
			}
			else if (arrival_times[3].size() < arrival_times[4].size() && arrival_times[3].size() < line_length){
				line_length = arrival_times[3].size();
				short_line = 3;
			}
			else if (arrival_times[4].size() < line_length){ // line 4 will get the peron if no lines are shorter than 1
				line_length = arrival_times[4].size();
				short_line = 4;
			}
			// put the person in the shortest line
			arrival_times[short_line].push(current_second);
		}

		for (unsigned i = 0; i < 5; i++){

			// Check whether we can start another checkout.
			if ((!machine[i].is_busy()) && (!arrival_times[i].empty()))
			{
				next = arrival_times[i].front();
				arrival_times[i].pop();
				wait_times[i].next_number(current_second - next);
				machine[i].start_washing();
			}

			// Tell the register to simulate the passage of one second.
				machine[i].one_second();
		}
	}

    // Write the summary information about the simulation.
	unsigned int total = 0;
	unsigned int avg = 0;
	for (unsigned int i = 0; i < 5; i++){

		cout << "Customers served in line " << i << ": " << wait_times[i].how_many_numbers() << endl;
		total = total + wait_times[i].how_many_numbers();
		if (wait_times[i].how_many_numbers() > 0){
			cout << "Average wait: " << wait_times[i].average() << " sec" << endl;
			avg = avg + wait_times[i].average();
		}
	}
	avg = avg / 5;

	cout << "Total served: " << total << endl;
	cout << "Total average: " << avg << endl;
}
