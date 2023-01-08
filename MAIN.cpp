#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "check.h"
#include "check2.h"

using namespace std;

void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void loader(char *xyz)
{
    int i;
	system("cls");
	gotoxy(10,10);
	cout << "\t\t\t\t\t\t\t\tProceeding : Please Wait\n";
	gotoxy(70,12);

	for (i=0;i<56;i++)
	{
		Sleep(30);
		cout << "|";
		
	}
	system ("cls");
}

class Instruction {
	
	protected:
	
		ifstream obj;
		string d;
		
	public:
		
		Instruction ()
		{
			system("color 03");
			obj.open("Instruction.txt");
  
                    while (!obj.eof())
                    {
  	                  getline (obj, d);
  	                  cout << d << endl;
                    } 
                    obj.close();
		}
		~Instruction () {
		}
		
};
class Ministry {
	
	protected:
		
		ifstream obj;
		ofstream f;
		string d;
	
	public:	
		
		virtual void set (char x) { x = '\0';}
		virtual void get () {}
		
		void quote ()
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t__________________________________________________" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\tTRAVEL IS THE HEALTHIEST ADDICTION" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t__________________________________________________" << endl << endl;
		}
	
};
class TravelGuide : public Ministry {
	
	private:
	   
	   char choice;
	
	public:
	   
	    TravelGuide ()
	   	{
	   		choice = '\0';
		   }
		
		void set (char choice)
		{
		     this->choice = choice;
	       }
	    
	    void get ()
	    {
	    	switch (choice)
	    	{
	    		case 'a':
	    			
					system ("cls");
                    
					obj.open("Countries.txt");
  
                    while (!obj.eof() )
                    {
  	                  getline (obj, d);
  	                  cout << d << endl;
                    } 
                    obj.close();
                    
				break;
				
				case 'b':
					
					system ("cls");
					
					obj.open("Flights.txt");
  
                    while (!obj.eof() )
                    {
  	                  getline (obj, d);
  	                  cout << d << endl;
                    }
                    obj.close();
                    
				break;
				
				case 'c':
					
					system ("cls");
					
					obj.open("Packages.txt");
  
                    while (!obj.eof() )
                    {
  	                  getline (obj, d);
  	                  cout << d << endl;
                    }
                    obj.close();
						
                break;
                
                
			}
		  }	
		  ~TravelGuide () { }
};

class Reservation : public Ministry{
	
	protected:
		
		string name,passport,visa;
		int age;
		string source,destination;
		int day,month,year,lugguage,flight;
	
	public:
		
		Reservation ()
		{
			name = " ";
			age = 0; passport = " "; visa = " ";
			source = " "; destination = " ";
			lugguage =0 ; day=0; month=0; year=0; flight = 0;
		}
		
		virtual void book () = 0;
		
	    ~Reservation () { }
};

class Book : public Reservation {
	
	private:
		
		const float airporttax;
	    int flighttax; double duty;
	    float pay; int a,pa1;
	    char pa;
	    
	public:
		
		Book (float x) : airporttax (x) { }
		
		void get (int x) { 
			flighttax = x;
		}
		
		void get (double y) {
			duty = y;
		}
		
		void book () {
			system ("cls");
			
			f.open ("Data.txt",ios::app | ios::binary);
			if(!f) 
            {
                cout<<"File creation failed";
            }
            
            else {
			
			cout << "\n\n\t\t\t\t\t\t\t\tPERSONAL DETAILS" << endl << endl;
		    cout << "\t\t\t\t\t\t\t\tEnter Passenger Name       : ";
		    cin >> name;
		    cout << "\n\n\t\t\t\t\t\t\t\tEnter Passenger Age  : ";
		    cin >> age;
		    cout << "\n\n\t\t\t\t\t\t\t\tEnter Passenger Passport # : ";
		    cin >> passport;
		    cout << "\n\n\t\t\t\t\t\t\t\tEnter Passenger Visa #     : ";
		    cin >> visa;
		    	cout << "\n\n\t\t\t\t\t\t\t___________________________________________________" << endl << endl << endl;
		    	cout << "\t\t\t\t\t\t\t\tFLIGHT DETAILS";
		    	cout << "\n\n\t\t\t\t\t\t\t\t\tFrom   : ";
		        cin >> source;
		        cout << "\n\n\t\t\t\t\t\t\t\t\tTo     : ";
		        cin >> destination;
		        cout << "\n\n\t\t\t\t\t\t\t\tEnter Departure Date : "<<endl;
		        cout<<"\t\t\t\t\t\t\t\tDay :";
		        cin >> day;
		        cout<<"\t\t\t\t\t\t\t\tMonth : ";
		        cin>>month;
		        cout<<"\t\t\t\t\t\t\t\tYear : ";
		        cin>>year;
		        cout << "\n\n\t\t\t\t\t\t\t\t      lugguage (lbs): ";
		        cin >> lugguage;
		        cout << "\n\n\t\t\t\t\t\t\t\tFlight # (last digit) : ";
		        cin >> flight;
		        f << "\t " << name  << "\n\t "<< source << "\n\t " << destination << "\n\t " << flight << "\n\t " << day<<"/"<<month<<"/"<<year << endl;
		        f << "\n\t________________________________________" << endl << endl;
		        f.close ();
		       
		        cout << "\n\n\t\t\t\t\t\t\t___________________________________________________" << endl << endl;
		        cout << "\t\t\t\t\t\t\t\tDo you want package (Y/N) : ";
		        cin >> pa;
		        
		        if (pa == 'Y')
		        {
		        	cout << "\n\n\t\t\t\t\t\t\t\tEnter Package Code : ";
		        	cin >> pa1;
		        	loader ('\0');
				}
				else
				{	
				    pa1 = 0;
		            loader ('\0');
				}
		}
			
		    }
	
		void paypayment ();
	
		friend void payment(Book obj);		
		        
		void display (){
			 try 
	            {
	  	            if (pay == 0)
	  	               throw pay;
	  	  
	  	            else if (pay < 0)
	  	                throw 0;
	            }
	  
	    catch (double x)
	    {
	  	  cout << "\n\n\t\t\t\t\t\tRepay the Payment";
	    }
	  
	    catch (int y)
	    {
	  	  cout << "\n\n\t\t\t\t\t\tAmount should not be negative";
	    }
	  
	}
	
	void generateticket ()
	{
		int seat;
		time_t t;
		
		srand((unsigned) time(&t));
		seat = rand () % 10;
		
		gotoxy (100,5);
		cout << "TICKET" << endl << endl << endl;
		cout << "\t\t\t\t\t\t_____________________________________________________________________________________________________________________" << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tTRAVEL ADMINISTRATION" << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\tNAME : " << name << endl << endl << "\t\t\t\t\t\t\t\tFLIGHT # : 100011" << flight << "\t\t\tDATE : " <<day<<"/"<<month<<"/"<<year << "\t\t\tSEAT : " << seat << endl << endl;
		cout << "\t\t\t\t\t\t\t\tFROM : " << source << "\t\t\tTO : " << destination;
	
		switch (flight)
		{
			case 1:
			  cout << "\t\t\tTIME : 9:00 AM";
			  break;
		    case 2:
			  cout << "\t\t\tTIME : 12:00 PM";
			  break;
			case 3:
			  cout << "\t\t\tTIME : 8:00 AM";
			  break;
			case 4:
			  cout << "\t\t\tTIME : 11:00 PM";
			  break;
			case 5:
			  cout << "\t\t\tTIME : 7:00 AM";
			  break;
			case 6:
			  cout << "\t\t\tTIME : 9:00 AM";
			  break;
			case 7:
			  cout << "\t\t\tTIME : 1:00 PM";
			  break;
			case 8:
			  cout << "\t\t\tTIME : 4:00 PM";
			  break;
			case 9:
			  cout << "\t\t\tTIME : 18:00 PM";
			  break;
			case 10:
			  cout << "\t\t\tTIME : 22:00 PM";
			  break;
			default:
			  break;
		}
		cout << "\n\n\t\t\t\t\t\t_____________________________________________________________________________________________________________________";
		
	}
};


void payment (Book obj) 
{   
	
	  obj.pay = (double)obj.a;
	  
	  obj.display();
	  
	  loader ('\0');
}

void Book::paypayment()
{
	float total,ap;
	
	gotoxy (100,5);
	cout << "PAYMENT PROCEDURE";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t___________________________________________________";
	
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t    Airline Payment : $ " << checkpayment (flight);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tAirport Tax : $ " << airporttax;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t Flight Tax : $ " << flighttax;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t       Duty : $ " << duty;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t    Package : $ " << checkpackage (pa1);
	
	if (lugguage > 50){
    
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t______________________________________";
    total = checkpayment (flight)+checkpackage (pa1)+airporttax+flighttax+duty+200;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t      Total : $ " << total;	
	
	}
	
	else {
	
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t______________________________________";
	total = checkpayment (flight)+checkpackage (pa1)+airporttax+flighttax+duty;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t      Total : $ " << total;
	
	}
	
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t______________________________________";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tAmount Pay  : $ ";
	cin >> a; pay=a;
	
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t______________________________________";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t    Balance : $ " << total - a;
}

class List {
    
	public:
	
	ifstream obj;
	string n1;
	
	void detail (){
	
	obj.open("Data.txt");
  
    while (!obj.eof())
    {
  	  getline (obj, n1);
  	  cout << "\t\t\t\t\t\t\t\t\t\t\t" << n1 << endl;
        } 
    
	obj.close();
    }
};

class Delete
{		
	public:
	
	char space,newLine;	
	string name,name1,temp;
	int age,tmp,count;	
	
	void check()
	{
	
	    count=0;
        ifstream read("Data.txt");
    
	    while(read!=NULL)
        {
        	
        	read>>temp;
    	    count++;
	        
			}
	        
 	read.close();
 	
    ofstream star;
	star.open("t.txt");
	star.close(); 
	
	fstream star1("t.txt");
	fstream file1("Data.txt");
	
	cout<<"\n\n\t\t\t\t\t\t\t\tEnter Name whose data to be deleted : ";
	cin>>name1;
	
	for(int i=0;i<count-6;i++)
	{
		file1>>temp;		
		
		if(temp==name1)
		{
			file1>>tmp;
			cout<<"\n\n\t\t\t\t\t\t\t\tFound! And Data Deleted";
		}
		
		else
		{
			star1<<temp<<endl;
		}
	}
	 
	star1.close();
	file1.close();
	
	remove("Data.txt");
	rename("t.txt","Data.txt");
	
	}
};

template <class N>

N Notice (N n)
{
	
	fstream fp;
	
	fp.open ("Notice.txt",ios::app | ios::binary);
	cout << "\t\t\t\t\t\t\t\tNotice : ";
	cin >> n;
	
	fp << "\n\t " << n;
	fp.close();
	return n;
	
}

template <class Q>

Q Query (Q q)
{
	fstream fp;
	
	fp.open ("Query.txt",ios::app | ios::binary);
	cout << "\t\t\t\t\t\t\t\tQuery : ";
	cin >> q;
	
	fp << "\n\t " << q;
	fp.close();
	return q;
}

template <class S>

S Suggestion (S s)
{
	fstream obj;
	
	obj.open ("Suggestion.txt",ios::app | ios::binary);
	cout << "\t\t\t\t\t\t\t\tSuggestion : ";
	cin >> s;
	
	obj << "\n\t " << s;
	obj.close();
	return s;
}

template <class E>

E Exit (E e)
{
	ifstream obj;
	
	obj.open("Exit.txt");
  
    while (!obj.eof())
    {
  	  getline (obj, e);
  	  cout << "\t\t\t\t\t\t\t\t\t\t\t" << e << endl;
        } 
    
	obj.close();
}

int main ()
{
	
	char ch='n';
	char choice;
	string d;
    
	Ministry *MN; 
	TravelGuide TG; 

	Book B(1500.85);

	Instruction In;
	cout << "\n\n\t\t\t\t\tPress any key to continue : ";
    getchar();
    loader ('\0');
    
	start:
	B.quote();
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t* TRAVEL GUIDE. \n\t\t\t\t\t\t\t\t\t\t\t\ta) Countries.  \n\t\t\t\t\t\t\t\t\t\t\t\tb) Flights Schedule.  \n\t\t\t\t\t\t\t\t\t\t\t\tc) Packages.";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t* MANAGE BOOKING. \n\n\n\t\t\t\t\t\t\t\t\t\t\t **  USER PORTAL  \n\t\t\t\t\t\t\t\t\t\t\t\td) Book Ticket.  \n\n\n\t\t\t\t\t\t\t\t\t\t\t **  ADMIN PORTAL  \n\t\t\t\t\t\t\t\t\t\t\t\te) List All Tickets.  \n\t\t\t\t\t\t\t\t\t\t\t\tf) Cancel Tickets. \n\t\t\t\t\t\t\t\t\t\t\t\tg) Add Up Notice";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t* RECOMMENDATION. \n\t\t\t\t\t\t\t\t\t\t\t\th) Query.  \n\t\t\t\t\t\t\t\t\t\t\t\ti) Suggestion.   \n\t\t\t\t\t\t\t\t\t\t\t\tj) Exit.";
	cout << "\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice : ";
	cin >> choice;
	
	MN = &TG;
	
	if (choice == 'a' || choice == 'b' || choice == 'c'){
	
	MN->set(choice);
	MN->get();
	
	cout << "\n\n\n\t\t\t\t\t\tPress any key to go back : ";
	getch ();
	system ("cls");
	goto start;
	
	}
	
	else if (choice == 'd'){
	
	B.get(3000);
	B.get(5500.75);
	
	do {
	      B.book();
	      B.paypayment();
	      B.display();
	      
		  cout << "\n\n\n\t\t\t\t\t\tContinue to Generate Ticket : ";
	      getch ();
          
		  loader ('\0');
	      system ("cls");
	      B.generateticket();
	      
		  cout<<"\n\n\n\t\t\t\t\t\t\tDo you want to add another data (Y/N) : ";
		  ch = getche();
		  
	}
	 
	while(ch=='y' || ch=='Y');
	
	cout << "\n\n\n\t\t\t\t\t\tPress any key to go back : ";
	getch ();
	system ("cls");
	goto start;
	
	system ("cls");
	
	}
	
	else if (choice == 'e')
	{
	
	   system ("cls");
	   gotoxy (100,5);
	   cout << "Costumer Details" << endl << endl;
	   
	   List Li;
	   Li.detail();
	   
	   cout << "\n\n\n\t\t\t\t\t\tPress any key to go back : ";
	   getch ();
	   system ("cls");
	   goto start;
		
	}
	
	else if (choice == 'f')
	{
		
	   system ("cls");
	   gotoxy (100,5);
	   cout << "Cancellation the Details" << endl << endl;
	   
	   Delete D;
	   D.check();
	   
	   cout << "\n\n\n\t\t\t\t\t\tPress any key to go back : ";
	   getch ();
	   system ("cls");
	   goto start;
	}
	
	else if (choice == 'g')
	{
		system ("cls");
	    gotoxy (100,5);
	    cout << "Notice Regarding Filghts" << endl << endl;
	  
	    Notice (d);
	    
	    cout << "\n\n\n\t\t\t\t\t\tPress any key to go back : ";
	    getch ();
	    system ("cls");
	    goto start;
	}
	
	else if (choice == 'h')
	{
	   
	   system ("cls");
	   gotoxy (100,5);
	   cout << "Query Portal" << endl << endl;
	   
	   Query (d);
	   
	    cout << "\n\n\n\t\t\t\t\t\tPress any key to go back : ";
	    getch ();
	    system ("cls");
	    goto start;
	   
	}
	
	else if (choice == 'i')
	{
	   system ("cls");
	   gotoxy (100,5);
	   cout << "Suggestion Portal" << endl << endl;
	   
	   Suggestion (d);
	   
	    cout << "\n\n\n\t\t\t\t\t\tPress any key to go back : ";
	    getch ();
	    system ("cls");
	    goto start;
	}
	
	else if (choice == 'j') 
	{   
		system ("cls");
	    Exit (d);
		return 0;
	}
	else 
	{
		cout<<"\n\t\t\t\t\t\tYOU DID NOT MAKE RIGHT CHOICE";
		  cout << "\n\t\t\t\t\t\tPress any key to go back : ";
	    getch ();
	    system ("cls");
	    goto start;
	}
	
	return 0;
}
























































































































































































