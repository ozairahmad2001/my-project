#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
fstream fout, fin;
class health_stats
{
	float mass;
	int age;
	int feet;
	float inch;
	float BMI;   
	char weight_cat[70];
	float bmr;
	char name[350];
	char gender[20];
	int act;
	float cal;
	int rec;
	public:
		
		void getdata()
		{
		
			cout<<"Enter record number       :"<<" ";
			cin>>rec;
			cout<<"Enter name                :"<<" ";
			cin>>name;
			cout<<"Enter gender (female/male):"<<" ";
			cin>>gender;
			cout<<"Enter age (in years)      :"<<" ";
			cin>>age;
			cout<<"Enter weight (in kg)      :"<<" ";
			cin>>mass; 
			cout<<"Enter height (in feet-inch)"<<" "<<endl;
			cout<<"\t feet  :"<<" ";
			cin>>feet;
			cout<<"\t inches:"<<" ";
			cin>>inch;
			cout<<endl;
			  cout<<"Please choose your activity type (number):"<<endl;
			  cout<<"1. Sedentary        : little or no exercise"<<endl;
			  cout<<"2. Lightly Active   : exercise/sports 1-3 times/week"<<endl;
			  cout<<"3. Moderately Active: exercise/sports 3-5 times/week"<<endl;
			  cout<<"4. Very Active      : exercise/sports 6-7 times/week"<<endl;
			  cout<<"5. Extra Active     : very hard exercise/sports or physical job"<<endl; 
			cin>>act;
			bmi();
			BMR();
			calorie();
			weight_category();

		}
		float height;
       	void bmi()
		{   
		    height =(feet*0.305)+(0.0254*inch); // height in metre
			BMI=mass/pow(height,2);
		}
		void weight_category();
		void BMR()
		{
			if (strcmpi(gender,"male")==0)
			{
				bmr=(10*mass)+6.25*(100*height)-(5*age)+5; // bmr equation
			}
			else
			bmr=(10*mass)+6.25*(100*height)-(5*age)-161; // bmr equation
		}
		void calorie()
		{
			switch(act)
			{
				case 1: 
				    cal=bmr*1.2;
				    break;
			    case 2:
			    	cal=bmr*1.375;
			    	break;
			    case 3:
			    	cal=bmr*1.55;
			    	break;
			    case 4:
			    	cal=bmr*1.725;
			    	break;
			    case 5:
			    	cal=bmr*1.9;
			    	break;
			}
		}
		void showdata ()
		{
			cout<<"Name     : "<<name<<endl;
			cout<<"Gender   : "<<gender<<endl;
			cout<<"Age      : "<<age<<" "<<"years"<<endl;
			cout<<"Weight   : "<<mass<<" "<<"kg"<<endl;
			cout<<"height   : "<<feet<<" "<<"feet"<<" "<<inch<<" "<<"inches"<<endl<<endl;
			cout<<"\t BMI(Body Mass Index)                  : "<<BMI<<" "<<"kg/m^2"<<endl;
			cout<<"\t Weight category                       : "<<weight_cat<<endl;
			cout<<"\t Normal BMI range                      : 18.2 - 25.6 kg/m^2"<<endl;
			cout<<"\t Normal BMI weight range for the height: "<<18.2*pow(height,2)<<" kg"<<" - "<<25.6*pow(height,2)<<" kg"<<endl;
			cout<<endl;
			cout<<"\t Calorie burned per day                     : "<<cal<<" "<<"calories"<<endl;
			cout<<"\t Calorie intake per day to lose 1kg per week: "<<(7*cal-7714)/7<<" "<<"calories"<<endl; // 1 kg fat has 7714 calories
			cout<<"\t Calorie intake per day to gain 1kg per week: "<<(7*cal+7714)/7<<" "<<"calories"<<endl<<endl;
		}
		int record()
		{
			return (rec);
		}
		char *name1()
		{
			return(name);
		}
		
		
};
void health_stats :: weight_category()
{
			if(BMI<15)
			{
				strcpy(weight_cat,"Very severly underweight");
			}
			else if(BMI>=15&&BMI<16)
			{
				strcpy(weight_cat,"Severly underweight");
			}
			else if(BMI>=16&&BMI<18.5)
			{
				strcpy(weight_cat,"Underweight");
			}
			else if(BMI>=18.5&&BMI<25)
			{
				strcpy(weight_cat,"Normal (healthy weight)");
			}
			else if(BMI>=25&&BMI<30)
			{
				strcpy(weight_cat,"Overweight");
			}
			else if(BMI>=30&&BMI<35)
			{
				strcpy(weight_cat,"Obese Class I (Moderately obese)");
			}
			else if(BMI>=35&&BMI<40)
			{
				strcpy(weight_cat,"Obese Class II (Severly obese)");
			}
			else if(BMI>=40&&BMI<45)
			{
				strcpy(weight_cat,"Obese Class III (Very severly obese)");
			}
				else if(BMI>=45&&BMI<50)
			{
				strcpy(weight_cat,"Obese Class IV (Morbidly obese)");
			}
				else if(BMI>=50&&BMI<60)
			{
				strcpy(weight_cat,"Obese Class V (Super obese)");
			}
				else if(BMI>=60)
			{
				strcpy(weight_cat,"Obese Class VI (Hyper obese)");
			}
		}
		
health_stats s;
int ref;
void display()
{
	system("cls");
	fin.open("health.dat",ios::binary|ios::in);
	while(fin.read((char*)&s, sizeof(s)))
	{
		s.showdata();
	}
	fin.close();
}
void search()
{
	system("cls");
	ref=0;
	fin.open("health.dat",ios::binary|ios::in);
	int roll;
	cout<<"Enter record number whose data has to be displayed"<<endl;
	cin>>roll;
	while (fin.read((char*)&s, sizeof(s)))
	{
		if(s.record()==roll)
		{
		    ref=1;
			s.showdata();
		}
	}
	fin.close();
	if(ref==0)
	{
		cout<<"Record not found"<<endl;
	}	
	cout<<endl;
}
void search1()
{
	system("cls");
	ref=0;
	fin.open("health.dat",ios::binary|ios::in);
	char roll[45];
	cout<<"Enter name whose information has to be displayed"<<endl;
	cin>>roll;
	while (fin.read((char*)&s, sizeof(s)))
	{
		char *ptr=s.name1();
		if(strcmpi(ptr,roll)==0)
		{
		    ref=1;
			s.showdata();
		}
	}
	fin.close();
	if(ref==0)
	{
		cout<<"Record not found"<<endl;
	}	
	cout<<endl;
}
void edit()
{
	system("cls");
	ref=0;
	fin.open("health.dat",ios::binary|ios::in|ios::out);
	int roll;
	cout<<"Enter record number whose data has to edited"<<endl<<endl;
	cin>>roll;
	while(fin.read((char*)&s, sizeof(s)))
	{
		if(s.record()==roll)
		{
		
			cout<<"Enter new information"<<endl<<endl;
			ref=1;
			s.getdata();
			fin.seekp(fin.tellg()-sizeof(s));
			fin.write((char*)&s,sizeof(s));
		}
	}
	fin.close();
	if (ref==0)
	{
		cout<<"Record not found"<<endl;
	}
	cout<<endl;
}
void remove1()
{
    system("cls");
	fin.open("health.dat",ios::binary|ios::in);
	fout.open("temp.dat", ios::binary|ios::out);
	int r=0;
	int dr;
	cout<<endl;
	cout<<"Enter record number of the record to be deleted: ";
	cin>>dr;
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(s.record()!=dr)
		fout.write((char*)&s,sizeof(s));
		else 
		r=1;
	}
	if(r==0)
	cout<<endl<<endl<<"Record not found"<<endl;
	fout.close();
	fin.close();
	remove("health.dat");
	rename("temp.dat","health.dat");
	cout<<endl;
}
void remove2()
{
    system("cls");
	fin.open("health.dat",ios::binary|ios::in);
	fout.open("temp.dat", ios::binary|ios::out);
	int r=0;
	char dr[56];
	cout<<endl;
	cout<<"Enter the name whose record has to be deleted: ";
	cin>>dr;
	while(fin.read((char*)&s,sizeof(s)))
	{
		char *ptr=s.name1();
		if(strcmpi(ptr,dr)!=0)
		fout.write((char*)&s,sizeof(s));
		else 
		r=1;
	}
	if(r==0)
	cout<<endl<<endl<<"Record not found"<<endl;
	fout.close();
	fin.close();
	remove("health.dat");
	rename("temp.dat","health.dat");
	cout<<endl;
}		
main ()
{
	int a;
	char ch;
	int i;
    char choice;
	cout<<"\t   THIS PROGRAM ALLOWS US TO GET INFORMATION ABOUT A PERSON'S WEIGHT AND CALORIES BURNED"<<endl<<endl;
	label:
    cout<<"\t\t\t\t---CHOOSE FROM THE FOLLOWING FILE OPERATIONS---"<<endl<<endl;
	cout<<"\t\t\t\t\t1. Create a file"<<endl;
	cout<<"\t\t\t\t\t2. Add a record"<<endl;
	cout<<"\t\t\t\t\t3. Dispay all records"<<endl;
	cout<<"\t\t\t\t\t4. Display a record for the given record number"<<endl;
	cout<<"\t\t\t\t\t5. Display a record for the given name"<<endl;
	cout<<"\t\t\t\t\t6. Edit a record"<<endl;
	cout<<"\t\t\t\t\t7. Remove the record for the given record number"<<endl;
	cout<<"\t\t\t\t\t8. Remove the record for the given name"<<endl;
	cin>>a;
	if (a==1||a==2)
	{
		system("cls");
		if(a==1)
		fout.open("health.dat",ios::out|ios::binary);
		else if(a==2)
		fout.open("health.dat",ios::app|ios::binary);
		if(!fout)
       	{
		cout<<"Error in file opening";
		exit(1);
	    }
	    do 
	    {
		s.getdata();
		fout.write((char*)&s, sizeof(s));
		s.showdata();
		cout<<endl<<endl;
		cout<<"Want to add more records? (Y/N)"<<endl;
		cin>>ch;
		cout<<endl;
    	}
	    while(ch=='y'||ch=='Y');
	    fout.close();

	}
	else if(a==3)
	{
		display();
	}
	else if(a==4)
	{
		search();
	}
	else if(a==5)
	{
		search1();
	}
	else if (a==6)
	{
		edit();
	}
	else if (a==7)
	{
		remove1();
	}
	else if(a==8)
	{
		remove2();
	}
	else
	{
		cout<<"Invalid entry/Enter valid entry"<<endl;
		cout<<endl;
		goto label;
	}
	cout<<"Want to perform any other file operation Y/N?"<<endl;
	cin>>choice;
	if(choice=='y'||choice=='Y')
	{
	cout<<endl;
	goto label;
    }
	getch();
}
