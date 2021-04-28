//Code for to on/off LED3

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define LED3_PATH "/sys/class/leds/beaglebone:green:usr3"   //Se define el led a utilizar

void removeTrigger(){
	std::fstream fs;
     	fs.open( LED3_PATH "/trigger", std::fstream::out);
  	fs << "none";
	fs.close();
}

int main(int argc, char* argv[]){
	   if(argc!=2){
		   cout << "Error wrong number of arguments\n" <<endl;
		
	   }
	   
	   string option(argv[1]);
	   std::fstream fs;
     	   cout << "Starting the LED flash program" << endl;
	   cout << "The LED Path is: " << LED3_PATH << endl;

	   //comparation of arguments

	   if(option=="on"){
		   removeTrigger();
	 	   fs.open (LED3_PATH "/brightness", std::fstream::out);
		   fs << "1";
		   fs.close();
	   }

	   else if (option=="off"){
		   removeTrigger();
	   	   fs.open (LED3_PATH "/brightness", std::fstream::out);
		   fs << "0";
		   fs.close();
	   }
	   return 0;
}


