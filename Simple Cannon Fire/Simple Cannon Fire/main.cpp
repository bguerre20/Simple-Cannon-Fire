#include <iostream> <cmath> <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
	//initiate all needed variables for the game
	double angle = 0, gunpowder = 0, distance = 0, velocity = 0, shot = 0;
	int seed = 0, win = 0;

	//Basic error checking for seed value, assuming numbers only, get seed value
	while(seed <=0) {
		cout<<"Please enter a positive integer seed value:"<<endl;
		cin>>seed;
	}
	srand(seed);
	rand();
	distance = (double)rand() / (RAND_MAX + 1) * 1000;
	cout<<"The Target is: " << distance << "m away."<<endl;

	//Over-arking game loop, wont exit until win condition is met
	while(win == 0) {
		////Basic error checking for angle value, assuming numbers only, get angle and convert to radians
		while(angle <=0) {
			cout<<"Please enter an angle between 0 and 90:"<<endl;
			cin>>angle;
			angle = (angle * 3.141592653589793238463) / 180;
		}

		////Basic error checking for gunpowder value, assuming numbers only
		while(gunpowder <=0) {
			cout<<"Please enter an amount of gunpowder in kilograms:"<<endl;
			cin>>gunpowder;
		}

		//calculate velocity and shot , then compare to win zone, terminate loop if win, else continue playing
		velocity = gunpowder * 50;
		shot = (((velocity * sin(angle)) / 9.8 ) * 2 ) * (velocity * cos(angle));
		if( abs(shot - distance) <= 1) {
			cout<<"It's a hit! You win!"<<endl;
			win = 1;
		}
		else {
			win = 0;
			if(shot - distance < 0)
				cout<<"You were short: "<< abs(shot-distance) << "m\n"<<endl;
			else
				cout<<"You were long: "<< abs(shot-distance) << "m\n"<<endl;
		}

		//clear variables just in case we keep playing
		cin.clear();
		angle = 0, gunpowder = 0, velocity = 0, shot = 0;
	}	

	return 0;


}


