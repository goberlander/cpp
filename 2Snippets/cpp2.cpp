#include <iostream>  
using namespace std;  

int main()  
{
    const int NUM_FISH = 5;
    int fish[NUM_FISH];
    int fisherMenCount = 0;
    int totalFish = 0;
    // You must finish this program. It should ask how
    // many fish were caught by fishermen 1-20, and
    // store this data in the array fish.
    while(fisherMenCount < NUM_FISH)
    {
        cout << "How many fish were caught by fishermen 1-20: " << endl;
        cin >> fish[NUM_FISH];
        fisherMenCount++;
        totalFish += fish[NUM_FISH];
       
    }
     cout << totalFish;

    return 0;
}