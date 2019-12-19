#include <iostream>
#include <fstream>
#include <string>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

struct info {
  int day;
  int name_id;
  int change_val;
};

int main() {
  int change = 0; // How many times the pictures displayed have to change

  info Info[1000];
  int info_counter = 0;

  int cow_galls[3] = {7,7,7}; // How much gallons of milk the cows produce

  int max_galls; // Maximum gallon of milk among the three cows
  int max_cows[3] = {1,1,1}; // i'th cow is maximum-producer if max_cow[i] = 1

  int new_max_cows[3] = {0,0,0}; // used when it's a different day and max_cow has to get updated

  int i,j;
  info tmp_info;

  ifstream ifs;
  ifs.open("measurement.in");
  ofstream ofs;
  ofs.open("measurement.out");

  // Get Info
  int n;
  ifs >> n;
  int day, name_id, change_val;
  string name;
  for (i=0; i<n; ++i) {
    ifs >> day;
    ifs >> name;
    ifs >> change_val;
    if (name.compare("Bessie") == 0) {
      name_id = 0; // Bessie = 0
    } else if (name.compare("Elsie") == 0) {
      name_id = 1; // Elsie = 1
    } else {
      name_id = 2; // Mildred = 2
    }
    tmp_info.day = day;
    tmp_info.name_id = name_id;
    tmp_info.change_val = change_val;

    Info[info_counter] = tmp_info;
    info_counter += 1;
  }

  // Calc
  int calc_day;
  bool recorded_day = 0;
  for (calc_day=1; calc_day<=100; ++calc_day) {
    recorded_day = 0;
    for (i=0; i<n; ++i) {
      if (Info[i].day == calc_day) {
        cow_galls[Info[i].name_id] += Info[i].change_val; // Change gallon amount of cows
        recorded_day = 1;
      }
    }
    if (recorded_day) { // If the day was recorded from the farmer
      max_galls = max(max(cow_galls[0],cow_galls[1]),cow_galls[2]); // updating the maximum-producer
      new_max_cows[0] = 0; new_max_cows[1] = 0; new_max_cows[2] = 0;
      if (cow_galls[0] == max_galls) {
        new_max_cows[0] = 1;
      }
      if (cow_galls[1] == max_galls) {
        new_max_cows[1] = 1;
      }
      if (cow_galls[2] == max_galls) {
        new_max_cows[2] = 1;
      }

      if (!((max_cows[0] == new_max_cows[0]) && (max_cows[1] == new_max_cows[1]) && (max_cows[2] == new_max_cows[2]))) {
        change += 1; // Check if the picture list has to change
      }

      max_cows[0] = new_max_cows[0]; max_cows[1] = new_max_cows[1]; max_cows[2] = new_max_cows[2];
    }
  }

  ofs << change;
  return 0;
}
