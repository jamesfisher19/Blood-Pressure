#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//1. The patient's high-density lipoprotein (HDL) level,
//2. The patient's low-density lipoprotein (LDL) level,
//3. The patient's systolic and
//4. The patient's diastolic blood pressure values.

//Declare functions
void evaluate_cholesterol(float, float, string&, string&);
void evaluate_blood_pressure(float, float, string&, string&);
float ratio_function(float HDL, float LDL, float, string);
//Declare varibales to read file
string name;
char status;
float visits, HDL, LDL, systolic, diastolic;
string high, low, s_eval, d_eval;
float ratio;
string ratio_interpretation;

ifstream inFile;
int main() {
  //Call functions

  //ratio_function( HDL,  LDL, ratio, ratio_interpretation);

  int line;
  int patients;
  string person_name = name;
  inFile.open("infile.txt");

  cout << "How many patients are there? ";
  cin >> patients;

  for (int i=0; i < patients; i++) {
    inFile >> name >> status >> visits;
    cout << " " << endl << "Current Patient's Name- " << name << endl << " " << endl;
    for (int j=0; j < visits; j++) {
      inFile >> HDL >> LDL >>  systolic >> diastolic;
      cout << "Cholesterol Profile" << endl;
      cout << "  " << "HDL: " <<HDL << " LDL: " << LDL << endl;
      ratio_function(HDL, LDL, ratio, ratio_interpretation);
      evaluate_cholesterol( HDL, LDL, high, low);
      cout << "Blood Pressure Profile" << endl;
      cout << "  " <<"Systolic: " <<systolic << " Diastolic: " << diastolic << endl;      
      evaluate_blood_pressure(systolic, diastolic, s_eval, d_eval);     
      cout << " " << endl << " " << endl;     

    }
  }
}

//Evaluate cholesterol
void evaluate_cholesterol(float HDL, float LDL, string& high, string& low)
  {
    //HDL
    if (HDL < 40) {
      high = "HDL is too low";
      cout << "  " << high << endl;
    }
    else if (HDL >= 40 && HDL < 60){
      high = "HDL is okay";
      cout << "  " << high << endl;
      }
    else if (HDL >= 60){
      high = "HDL is Excellent";
      cout << "  " << high << endl;
      }    
    //LDL
    if (LDL < 100){
      low = "LDL is optimal";
      cout << "  " << high << endl;
    }
    else if (LDL >=100 && LDL < 130){
      low = "LDL is Near Optimal";
      cout << "  " << high << endl;
      }
    else if (LDL >= 130 && LDL < 160){
      low = "LDL is Borderline High";
      cout << "  " << high << endl;
    }
    else if (LDL >= 160 && LDL < 190){
      low = "LDL is High";
      cout << "  " << high << endl;
    }
    else if (LDL >= 190){
      low = "LDL Very High";
      cout << "  " << high << endl;
    }
}


//Evaluate blood pressure 
void evaluate_blood_pressure(float systolic, float diastolic, string& s_eval, string& d_eval){
  //Systolic
  if (systolic < 120){
    s_eval = "Systolic reading is Optimal";
    cout << "  " << s_eval << endl;
  }
  else if (systolic < 130){
    s_eval = "Systolic reading is Normal";
    cout << "  " << s_eval << endl;
  }
  else if (systolic < 140){
    s_eval = "Systolic reading is Normal High";
    cout << "  " << s_eval << endl;
  }
  else if (systolic < 160){
    s_eval = "Systolic reading is in Stage 1 hypertension";
    cout << "  " << s_eval << endl;
  }
  else if (systolic < 180){
    s_eval = "Systolic reading is in Stage 2 hypertension";
    cout << "  " << s_eval << endl;
  }
  else if (systolic >= 180){
    s_eval = "Systolic reading is in Stage 3 hypertension";
    cout << "  " << s_eval << endl;
  }       


  //Diastolic
  if (diastolic < 80){
    d_eval = "Diastolic reading is Optimal";
    cout << "  " << d_eval << endl;
  }
  else if (diastolic < 85){
    d_eval = "Diastolic reading is Normal";
    cout << "  " << d_eval << endl;
  }
  else if (diastolic < 90){
    d_eval = "Diastolic reading is Normal High";
    cout << "  " << d_eval << endl;
  }
  else if (diastolic < 100){
    d_eval = "Diastolic reading is in Stage 1 hypertension";
    cout << "  " << d_eval << endl;
  }
  else if (diastolic < 110){
    d_eval = "Diastolic reading is in Stage 2 hypertension";
    cout << "  " << d_eval << endl;
  }
  else if (diastolic >= 110){
    d_eval = "Diastolic reading is in Stage 3 hypertension";
    cout << "  " << d_eval << endl;
  }         
}


//Ratio 
float ratio_function(float HDL, float LDL, float ratio, string ratio_interpretation){
  ratio = HDL/LDL ;
  cout << "  " << "Ratio: " << ratio << endl;
  if (ratio > 0.3){
    ratio_interpretation = "Ratio of HDL to LDL is good";
    cout << "  " << ratio_interpretation << endl;
  }
  else if (ratio <=0.3){
    ratio_interpretation = "Ratio of HDL to LDL is not good";
    cout << "  " << "Ratio: " <<ratio_interpretation << endl;
  }
  return ratio;
}