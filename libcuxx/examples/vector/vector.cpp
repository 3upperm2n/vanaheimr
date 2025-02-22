
#include <vector>
#include <cstdio>

int main(int argc, char** argv)
{
	// constructors used in the same order as described above:
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::printf("The contents of fifth are:");
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::printf(" %d", *it);

	std::printf("\n");
}



