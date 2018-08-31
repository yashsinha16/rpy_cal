#include "fun.h"

int main() {
  /**importing json file*/

  std::ifstream fin("data.json");
  json parsed_data = json::parse(fin);
  /**Vector for roll,pitch and yaw*/
  std::vector<double> roll;
  std::vector<double> pitch;
  std::vector<double> yaw;
  /**Vector for storing acc values to calculate roll,pitch and yaw */

  std::vector<sensor *> myvector;

  for (auto entry : parsed_data) {
    myvector.push_back(new rpy("rpysensor", entry.value("ACC_X", 0.0l),
                               entry.value("ACC_Y", 0.0l),
                               entry.value("ACC_Z", 0.0l)));
    // cout<<myvector[myvector.size()-1]->getvalue("x");
  }

  // cout<<myvector[55]->getvalue("x");

  for (auto it : myvector) {
    double ACC_X = it->getvalue("x");
    // cout<<ACC_X;
    double ACC_Y = it->getvalue("y");
    double ACC_Z = it->getvalue("z");
    /**formula for calculating roll,pitch and yaw*/

    double pr1 = atan2((-1) * ACC_X, sqrt(ACC_Y * ACC_Y + ACC_Z * ACC_Z));
    double pr2 = atan(ACC_Z / sqrt(ACC_X * ACC_X + ACC_Y * ACC_Y));
    double pr3 = atan(ACC_Y / sqrt(ACC_X * ACC_X + ACC_Z * ACC_Z));
    roll.push_back(pr3);
    pitch.push_back(pr1);
    yaw.push_back(pr2);
  }
  /**Printing different readings and no of data points*/
  cout << "Roll Readings in radians:::: " << endl;
  DisplayReading(roll);
  cout << "Pitch Readings in radians:::: " << endl;
  DisplayReading(pitch);
  cout << "Yaw Readings in radians:::: " << endl;
  DisplayReading(yaw);

  cout << "NO OF DATA POINTS: " << roll.size() << "\n";

  //-------------------------
  /**Calling this function for similar stuff with light class*/
  LightCond(parsed_data);
  /**Deleting the reference*/
  for (auto it = myvector.begin(); it != myvector.end(); it++) delete *it;

  return 0;
}
