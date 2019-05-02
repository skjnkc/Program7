
#include "test.h"

using namespace std;
void DoSomething(const string fileIn, map<string, int> restaurantRatings, string &numRatingsTotal){
	//const string fileIn = ("ratings.txt");
	//const string fileOut = ("MovieReviews.txt");
	//ofstream fout(fileOut);
	ifstream fin(fileIn);
	string restaurantName;
	int rating;
	vector <int> charBar, JackStack, McCormick, OliveGarden, Q39, SaharaRest;
	//map<string, int> restaurantRatings;
	getline(fin, numRatingsTotal);
	while (!fin.eof()) {
		while (getline(fin, restaurantName) && fin >> rating && fin.ignore()) {
			restaurantRatings[restaurantName] = rating;
			if (restaurantName == "CharBar") {
				charBar.push_back(restaurantRatings[restaurantName]);
			}
			else if (restaurantName == "JackStack") {
				JackStack.push_back(restaurantRatings[restaurantName]);
			}
			else if (restaurantName == "McCormick") {
				McCormick.push_back(restaurantRatings[restaurantName]);
			}
			else if (restaurantName == "Olive Garden") {
				OliveGarden.push_back(restaurantRatings[restaurantName]);
			}
			else if (restaurantName == "Q39 BBQ") {
				Q39.push_back(restaurantRatings[restaurantName]);
			}
			else if (restaurantName == "Sahara Rest") {
				SaharaRest.push_back(restaurantRatings[restaurantName]);
			}
		}
	}
	cout << "Number of ratings total: " << numRatingsTotal << endl;
}