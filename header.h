#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;
/**Defining base class sensor*/
class sensor {
  std::string name;

 public:
  /**Constructor of base class*/
  sensor(string s) : name(s) {}
  virtual void display() {}
  virtual double getvalue(string) {}
  virtual double getvaluelux() {}
};
/**Defining derived class rpy(roll,pitch and yaw)*/
class rpy : public sensor {
 private:
  double x;
  double y;
  double z;
  /**Constructor of derived class*/
 public:
  rpy(string s, double r, double p, double y) : sensor(s), x(r), y(p), z(y) {}
  void display();
  double getvalue(string s);
};
/**Defining another derived class for light sensing*/
class Light : public sensor {
 private:
  int intensity;
  /**Defining the constructor*/
 public:
  Light(string s, int a) : sensor(s), intensity(a) {}
  void display();

  double getvaluelux() {
    cout << intensity << endl;

    return intensity;
  }
};
