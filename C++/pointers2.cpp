#include <iostream>
#include <iomanip>
using namespace std;

class Player {
	private:
		string name;
		int health;
	
	public:
		Player(string playerName, int playerHealth) :
			name(playerName), health(playerHealth) {}
		
		void status()
		{
			cout << "\nPlayer: " << setw(20) << name << endl;
			cout << "Health: " << setw(20) << health << endl;
			cout << "Ready to start game!" << endl;
		}
};

int main()
{
	Player player1("Twisted Carrot", 100);
	
	Player* playerPtr = &player1;
	cout << "Value stored in playerPtr: " << playerPtr << endl;
	cout << "Access the object stored in playerPtr and call its status() method..." << endl;
	playerPtr->status(); // Or use: (*playerPtr).status();
}