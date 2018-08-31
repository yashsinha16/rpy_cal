/**cpp program for the functions implemented*/
#include "fun.h"
/**Reading and displaying the respective vectors*/
void DisplayReading(vector<double> v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;
  }
}

void LightCond(json j_complete) {
  std::vector<sensor *> myvector;

  for (auto entry : j_complete) {
    myvector.push_back(new Light("lightsensor", entry.value("LIGHT (lux)", 0)));
  }
  /**Displaying the lux readings*/
  cout << "Light Readings::::: " << endl;
  for (auto it : myvector) {
    it->display();
  }
  /**Using map for checking the condition according to lux values*/
  map<int, string> m;
  m[0] = "You are in Pitch Black conditions";
  m[1] = "You are in Very Dark condition";
  m[2] = "You are visiting Dark Indoors";
  m[3] = "It's Dim Indoors";
  m[4] = "Normal Indoor condition surrounds you";
  m[5] = "Outdoors it is";

  int Index = 0;
  int Max = -1;
  vector<int> Tracker(6, 0);

  for (auto it : myvector) {
    int LIGHT = it->getvaluelux();

    if (LIGHT > 0 && LIGHT <= 10) {
      Tracker[0]++;
      if (Tracker[0] >= Max) {
        Max = Tracker[0];
        Index = 0;
      }

    } else if (LIGHT >= 11 && LIGHT <= 50) {
      Tracker[1]++;
      if (Tracker[1] >= Max) {
        Max = Tracker[1];
        Index = 1;
      }
    } else if (LIGHT >= 51 && LIGHT <= 200) {
      Tracker[2]++;
      if (Tracker[2] >= Max) {
        Max = Tracker[2];
        Index = 2;
      }
    } else if (LIGHT >= 201 && LIGHT <= 400) {
      Tracker[3]++;
      if (Tracker[3] >= Max) {
        Max = Tracker[3];
        Index = 3;
      }
    } else if (LIGHT >= 401 && LIGHT <= 5000) {
      Tracker[4]++;
      if (Tracker[4] >= Max) {
        Max = Tracker[4];
        Index = 4;
      }
    } else {
      Tracker[5]++;
      if (Tracker[5] >= Max) {
        Max = Tracker[5];
        Index = 5;
      }
    }
  }
  /**Displaying the maximum occured condition*/
  cout << m[Index];

  for (auto it = myvector.begin(); it != myvector.end(); it++) delete *it;
}
