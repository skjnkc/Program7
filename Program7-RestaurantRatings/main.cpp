//Sierra Jones
//Skjnkc@mail.umkc.edu
//Due: may 10, 2019
//Professor Gharibi

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

void MovieStats(vector<int> a, string name, map<string, int> &restaurantRatings) {
	double sum = 0;
	double avg;
	int numReviews;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	avg = sum / a.size();
	numReviews = a.size();
	restaurantRatings[name] = numReviews;
	cout << name << " average review: " << avg << "/5 stars with " << a.size() << " reviews." << endl;
}

int main() {
	const string fileIn = ("ratings.txt");
	const string fileOut = ("MovieReviews.txt");
	ofstream fout(fileOut);
	ifstream fin(fileIn);
	string restaurantName, numRatingsTotal;
	int rating;
	vector <int> charBar, JackStack, McCormick, OliveGarden, Q39, SaharaRest;
	map<string, int> restaurantRatings;
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
	cout << "Movie Stats are: " << endl;
	MovieStats(charBar, "CharBar", restaurantRatings);
	MovieStats(JackStack, "JackStack", restaurantRatings);
	MovieStats(McCormick, "McCormick", restaurantRatings);
	MovieStats(OliveGarden, "Olive Garden", restaurantRatings);
	MovieStats(Q39, "Q39 BBQ", restaurantRatings);
	MovieStats(SaharaRest, "Sahara Rest", restaurantRatings);
	cout << "With a total of " << numRatingsTotal << " reviews." << endl;



	/*map<string, int>::const_iterator iter;
	for (iter = restaurantRatings.begin(); iter != restaurantRatings.end(); iter++) {
		cout << iter->first << " - " << iter->second << endl;
	}*/
}

