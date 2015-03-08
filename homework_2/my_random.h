//Chad Funckes
//CSC 2421
//Homework 1
//My_random Class prototypes

// Creates a psedurandom number around an input number
class My_random{
private:
	int seed;
	int multiplier;
	int increment;
	int modulus;
	
public:
	// Constructor //
	My_random();
	// Mutator Section //
	void changeSeed(int); // Changes the private variable seed to the specified input
	// Accessor Section //
	int make_Rnumber(); // Returns psedorandom number based upon the seed number.
};
