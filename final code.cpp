#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

struct customer
{
	char name[50];
	int dob,doj,age;
	char gender;
	char facilty_opted[50];
	char address[100];
	long long int phno;

};
struct customer arr[100];
static int i=0;

int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


bool admin_login()
{
    char userId[30],passwrd[30];
    char uid[] = "admin",upassword[] = "mygym";
    int chances = 3;
    char ch;
    int IdNo;

    while (chances)
    {
        cout<< "Enter USERNAME -- ";
        cin >> userId;
        cout << endl;
        
        cout<< "Enter PASSWORD -- ";
        ch = getch();
        int passIndex;
    	for(passIndex=0; passIndex<30; passIndex++)
    	{
    		ch = getch();
    		if(ch == '\n' || ch=='\r')
    			break;
    		passwrd[passIndex]=ch;
    		printf("*");

    	}
    	passwrd[passIndex] = '\0';
   
        if (strcmp(uid, userId) == 0 && strcmp(passwrd, upassword) == 0)
        {
            cout<< "\nCORRECT USERNAME AND PASSWORD\n";
            cout << "\033[2J\033[1;1H";
            break;
        }
        else
        {
            cout<< "\nINVALID USERNAME AND PASSWORD\n";
            cout <<"----------------------------------------------------------------";
            cout << "\nPLEASE ENTER THE VALID USERNAME AND PASSWORD\n\n";
            chances--;
            cout <<"only  " << chances << " chances left \n\n";

            if(!chances)
            {
            	int IDNo;
                cout<< "SORRY NO MORE CHANCES LEFT \n\n";
                cout<< "ENTER YOUR UNIQUE ID --"<<endl;

                cin >> IDNo;

                if(IDNo != 9771)
                	return 0;
            }
        }
    }

    return 1;
}


void update_aboutus()
{

    ifstream t;
    t.open("Aboutus.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<<str << endl;
	t.close();


	char c;
    cout << "\n Do you want to update the content? (Y/N) : " ;
    cin >> c;
    if(c == 'Y' || c == 'y')
  	{
    	 char s[10000];
    	 cout << "\nEnter the updated content : \n";
    	 getchar();
    	 cin.getline(s, 10000);
    	 ofstream outfile;
    	    outfile.open("Aboutus.txt");
            outfile << s;
		    outfile.close();

    }
   
    return;

}

void update_whygym()
{
	ifstream t;
    t.open("whygym.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();

		
char c;
    cout << "\nDo you want to update the content? (Y/N) : " ;
    cin >> c;
    if(c == 'Y' || c == 'y')
    {
    	 char s[10000];
    	 cout << "\nEnter the updated content : \n";
    	 getchar();
    	 cin.getline(s, 10000);
    	 ofstream outfile;
    	    outfile.open("whygym.txt");
             outfile << s;
		    outfile.close();

    }
    return;
}

void update_facilities()
{
	
	ifstream t;
    t.open("facilities.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();


	char c;
    cout << "\nDo you want to update the content? (Y/N) : " ;
    cin >> c;
    if(c == 'Y' || c == 'y')
    {
    	 char s[10000];
    	 cout << "\nEnter the updated content : \n";
    	 getchar();
    	 cin.getline(s, 10000);
    	 ofstream outfile;
    	 outfile.open("facilities.txt");
         outfile << s;
		 outfile.close();

    return;
	}
}

void update_packages()
{
	ifstream t;
    t.open("packages.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();
	char c;
    cout << "\nDo you want to update the content? (Y/N) : " ;
    cin >> c;
    if(c == 'Y' || c == 'y')
    {
    	 char s[10000];
    	 cout << "\nEnter the updated content : \n";
    	 getchar();
    	 cin.getline(s, 10000);
    	 ofstream outfile;
    	 outfile.open("packages.txt");
         outfile << s;
		 outfile.close();

    return;

	}
 
}


void manage_records()
{

    ifstream t;
    t.open("records.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();
	return;
}

void emp_trainers()
{
	ifstream t;
    t.open("emptrainers.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();

 char c;
    cout << "\nDo you want to update the content? (Y/N) : " ;
    cin >> c;
    if(c == 'Y' || c == 'y')
    {
    	 char s[10000];
    	 cout << "\nEnter the updated content : \n";
    	 getchar();
    	 cin.getline(s, 10000);
    	 ofstream outfile;
    	 outfile.open("emptrainers.txt");
         outfile << s;
		 outfile.close();
    }
    return;

}


void update_contact()
{
	ifstream t;
    t.open("contact.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();

 char c;
    cout << "\nDo you want to update the content? (Y/N) : " ;
    cin >> c;
    if(c == 'Y' || c == 'y')
    {
    	 char s[10000];

    	 cout << "\nEnter the updated content : \n";
    	 getchar();
    	 cin.getline(s, 10000);

    	 ofstream outfile;
    	 outfile.open("contact.txt");

    	  char *pch;
    	  pch = strtok (s,"#");
		  while (pch != NULL)
		  {
		    outfile << pch << endl; 
		    pch = strtok (NULL, "#");
		  }
		 outfile.close();
    }
    return;

}

/*******************/
/*******************/

void admin(){

	int opt1;
	do {


			cout<< "\n\n***** WELCOME TO MUSCLESUP GYM & SPA *****\n\n";
			cout<< "1 ABOUT US\n";
			cout<< "2 WHY GYM ???\n";
			cout<< "3 FACILITIES AVAILABLE\n";
			cout<< "4 UPDATE PACKAGES\n";
			cout<< "5 VIEW RECORDS \n";
			cout<< "6 TRAINERS TIMINGS\n";
			cout<< "7 UPDATE CONTACT DETAILS\n";
			cout<< "8 EXIT\n\n";
			cout<< "PLEASE ENTER YOUR CHOICE\n";
			cin>> opt1;
			cout << "\033[2J\033[1;1H";
			switch(opt1){
				case 1 : update_aboutus();
						break;
				
				case 2 : update_whygym();
						break;

				case 3 : update_facilities();
						break;

				case 4 : update_packages();
						break;

				case 5 : manage_records();
						break;
				
				case 6 : emp_trainers();
			  	    	break;
			    
				case 7 : update_contact();
						break;
				case 8 :
						break;
				
				default : cout << "PLEASE ENTER VALID INPUT\n"; 
						break;

			}

		}while(opt1 != 8);	
}

/******************/
/*CUSTOMER*/
/*****************/

void view_aboutus()
{
    ifstream t;
    t.open("Aboutus.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<<str << endl;
	t.close();

}

void view_whygym()
{
	ifstream t;
    t.open("whygym.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
  
    cout<< str << endl;
	t.close();

		
}

void view_facilities()
{
	ifstream t;
    t.open("facilities.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();

}

void view_packages()
{
	fstream t;
	t.open("packages.txt", ios::in);
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();
}



void join_now()
{

    struct customer c;

	 cout << "\nREADY TO JOIN ??\n";
	 cout << "PLEASE FILL THE REGISTERATION FORM\n";
	 cout << "NAME :  ";
	 getchar();

	 cin.getline(c.name,50); 
	 cout << "\nDATE OF BIRTH(DDMMYY) :   ";
	 cin >>c.dob;
	 cout<< "\nENTER THE JOINING DATE(DDMMYY) : ";
	 cin>>c.doj;	
	 cout << "\nAGE :   ";	
	 cin >> c.age;	
	 cout << "\nMOBILE NO. :   ";
	 cin>>c.phno;	
	 cout << "\nADDRESS :   ";
	 getchar();	
	 cin.getline(c.address, 100);	
	 cout<<"\nFACILITY OPTED :   ";	
	 cin.getline(c.facilty_opted, 100);

	 arr[i] = c;

	 i++;
     
     string s = "\n*****************";
     s += ("\nNAME :" + string(c.name));
     s += ("\nDOB(DDMMYY) : " + to_string(c.dob));
     s += ("\nDOJ(DDMMYY) : " + to_string(c.doj));
     s += ("\nAGE : " + to_string(c.age));
     s += ("\nMOBILE NO. : " + to_string(c.phno));
     s += ("\nADDRESS : " + string(c.address));
     s += ("\nFACILITY OPTED : " + string(c.facilty_opted));
     s += "\n****************\n";
     ofstream outfile;
	 outfile.open("records.txt", ofstream::app);
     outfile << s;
	    
	 outfile.close();
}

void view_contact()
{
	ifstream t;
    t.open("contact.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();

}


void view_trainers()
{
	ifstream t;
    t.open("emptrainers.txt"); 
	string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    cout<< str << endl;
	t.close();

}


void customer(){
	int opt2;

	do {
			cout << " \n\n******* WELCOME TO MUSCLESUP GYM & SPA *******\n\n";
			cout<< "1 ABOUT THE GYM\n";
			cout<< "2 WHY GYM ???\n";
			cout<< "3 FACILITIES AVAILABLE\n";
			cout<< "4 PACKAGES OFFERED\n";
			cout<< "5 JOIN NOW\n";
			cout<< "6 TRAINERS TIMINGS\n";
			cout<< "7 CONTACT US\n";
			cout<< "8 EXIT\n\n";
			cout<< "PLEASE ENTER YOUR CHOICE\n";
			cin>> opt2;
			cout << "\033[2J\033[1;1H";
			switch(opt2){
				case 1 : view_aboutus();
					    break;

				case 2 : view_whygym();
						break;	     

				case 3 : view_facilities();
						break;

				case 4 : view_packages();
				    	break;

				case 5 : join_now();
					    break;
				
				case 6 : view_trainers();
			  		    break;

				case 7 : view_contact();
						break;
				case 8 : 
						break;
				default : cout << "\n\nPLEASE ENTER VALID INPUT\n\n"; 


			}
		}while(opt2 !=  8);

}


int main(){
cout << "\033[2J\033[1;1H";
	int choice;
	
	do {
			cout<< "\n\n ******* WELCOME TO MUSCLESUP GYM & SPA *******\n\n";
			cout<< "ENTER YOUR CHOICE \n"<<"1 ADMIN\n"<< "2 CUSTOMER\n"<<"3 EXIT\n\n";
			cin >> choice ;
			cout << "\033[2J\033[1;1H";
			switch(choice){
				case 1 : 	cout << "\t------ WELCOME ADMIN ------\n\n";
							if(admin_login())
							{
								cout << "\033[2J\033[1;1H";
								admin();
							}
							break;
				case 2 :   	cout << "\t------ WELCOME CUSTOMER ------\n\n";
							customer();
							break;
				case 3 : 
							break;
				default:    cout <<"PLEASE ENTER THE VALID INPUT\n";
							break;
			}
		}while(choice!=3);

	return 0;	

}