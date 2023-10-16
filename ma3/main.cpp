#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    // Scenario 1: Search based on UserName
    // Create a new map
    map<string, TwitterData> scene_1;

    // Insert all data from twitter_data into the map
    for (int i = 0; i < 5; ++i)
    {
        scene_1[twitter_data[i].getUserName()] = twitter_data[i];
    }

    // Print out the map
    for (auto it = scene_1.begin(); it != scene_1.end(); ++it)
    {
        cout << it->first << ": " << it->second.print() << endl;
    }

    // Find the person with UserName "savage1"
    cout << scene_1["savage1"].print() << endl;

    // Remove the person with UserName "savage1"
    scene_1.erase("savage1");

    // Scenario 2: Search based on Email

    return 0;
}