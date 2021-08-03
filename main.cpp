#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

	string user;
	cout << "name khodra vared konid : ";
	cin >> user;
	
	
	if(user=="admin"){
		string foods;
		int count;
		cout << "ghaza haye hafte ra moshakhas konid : " <<endl <<"tedad ghaza hara vared konid : "<<endl ;
		cin >> count;
		for(int i=0; i<count; i++){
			cout << "(" << (i+1) <<") : ";
			string tmp;
			cin >> tmp;
			foods += tmp + "\n";
		}
		
		ofstream w("food_list.txt");
		w<<foods;
		w.close();
		cout << "ba tashakor , ghaza ha zakhire shod";
	
	
	} else {
		
		cout << "[1] -> namayesh ghaza haye rezerv shoma" << endl << "[2] -> sabt ghaza in hafte" << endl;
		int code;
		cin >> code;
		if(code == 2){
			cout << "ghaza haye in hafte : " << endl;
			string list;
			ifstream readFile("food_list.txt");
			int i=1;
			while( getline(readFile, list) ){
				cout << i << ") " << list << endl;
				i++;
			}
			
			int charj=0;
			cout << "hesab khod ra sharj konid  (toman) :  "<<endl;
			cin>> charj;
			cout << "hesab shoma "<< charj <<" sharj shod."<<endl;
	
			string days[6] = {"Shanbe", "YekShanbe", "DoShanbe", "SeShanbe", "CharShanbe", "PanjShanbe"};
			string food;
			cout << "(sharj feli -> " << charj <<" ) ghaza haye in hafte khod ra mosha khas konid :" << endl;
			
			string student_food;
			for(int i=0; i<6; i++){
				cout << "(sharj feli -> " << charj <<" ) " << days[i] << " > ";
				cin >> food;
				charj -= 4500;
				
				student_food += days[i] + " : (" + food + ")\n";
			}
			
			ofstream w("student_food.txt");
			w<<student_food;
			w.close();
			
			cout <<endl<<endl<< "barname ghazayee shoma sabt shod";
		}
		else {
			cout << "shoma be in sorat ghaza rezerv kardid \n" << endl;
			ifstream readFile("student_food.txt");
			string row;
			while( getline(readFile, row) ){
				cout << row << endl;
			}
		}
		
		
	}
	
	
	
	return 0;
}
