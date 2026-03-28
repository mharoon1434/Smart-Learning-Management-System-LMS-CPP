#include<iostream>
#include<vector>
#include<string>

using namespace std;
int progress;
int courseenrol;
class Instructor;
class Course;
class Assigniment{
	private:
		string assignimentdiscription;
	public:
		Assigniment(string na){
			assignimentdiscription=na;
		}
    string getdiscription(){
        return assignimentdiscription;
    }
		void enrollQuiz();
};
class Helpmatrial{
	private:
		string link;
	public:
		Helpmatrial(string na){
			link=na;
		}
    string getlink(){
        return link;
    }
		void enrollQuiz();
};
class Course{
	private:
		string nameOfCourse;
		double duration;
		int numberOfVideo;
		int reviews;
		string instructor;
	public:
        vector<Assigniment> assg;
        vector<Helpmatrial> hm;
		Course(){
	}
		Course(string na,double dur,int video,string name, string link){
			nameOfCourse=na;
			duration=dur;
			numberOfVideo=video;
			instructor=name;
			for(int i=0; i<video; i++){
            string nameass="Assigniment of  "+ na;
            assg.push_back(Assigniment(nameass));
            hm.push_back(Helpmatrial(link));
        }	
		}
    
		void setnameofcourse(string na){
			nameOfCourse=na;
		}
		void setduration(double du){
			duration=du;
		}
		void setnumberofvedio(int v){
			numberOfVideo=v;
		}
		string getnameofcourse(){
		return nameOfCourse;
		}
		string getinstructor(){
			return instructor;
		}
		double getduration(){
			return duration;
		}
		int getnofovideo(){
			return numberOfVideo;
		}
		friend void Display(vector<Course> c){
	     	int sz=c.size();
			for(int i=0; i<sz; i++){
				cout<<"Press "<<i+1<<" for "<<c[i].nameOfCourse[i];
			}
		}
		static void printdetails(vector<Course> &c){
			int sz=c.size();
			cout<<"Name\t\tDuration\t\tinstructor\n";
			for(int i=0; i<sz; i++){
				cout<<c[i].nameOfCourse<<"\t\t"<<c[i].duration<<"\t\t"<<c[i].instructor<<endl;
			}
		}
		Course uploadcourse(string name){
			cout<<"Willcome "<<name<<endl;
			string namecours;
			cin.ignore();
			cout<<"Enter the Name of Course\n";
			cin>>namecours;
			cin.ignore();
			double dur;
			cout<<"Enter the Duration of Course\n";
			cin>>dur;
			int video;
			cout<<"Enter the the No. video\n";
			cin>>video;
            string link;
            cout<<"Enter the video link\n";
            cin.ignore();
            cin>>link;
			Course s(namecours,dur,video,name,link);
				return s;
		} 
void changeCourse(){
			cout<<"Where you Make a change\n";
			int num;
			cout<<"Press 1 for Course Name\nPress 2 for reset Duration\nPress 3 for changeing No. of video\n";
			cin>>num;
	    if(num==1){
				changename();	
			}
		else if(num==2){
			changeduration();
		}
		else if(num==3){
			changevedionumber();
		}
	}
     int changeduration(){
		double dur;
				cout<<"Enter the new duration to your Course privious one is "<<duration<<endl;
				cin>>dur;
				setduration(dur);
				int c;
				cout<<"For more changing press 1 \nFor main manu 2\n0 for Exit\n";
				cin>>c;
				if(c==1){
				changeCourse();
					
				}
				if(c==2){
					main();
				}
				if(c==1){
				return 0;	
				}
            return 0;
	}
	int changevedionumber(){
		int no;
				cout<<"Enter the number of video the privioue number of video is "<<numberOfVideo<<endl;
				cin>>no;
				setnumberofvedio(no);
				int c;
				cout<<"For more changing press 1 \nFor main manu 2\n0 for Exit\n";
				cin>>c;
				if(c==1){
				changeCourse();
					
				}
				if(c==2){
					main();
				}
				if(c==1){
				return 0;	
				}
            return 0;
	}
	int changename(){
		string name;
				cout<<"Enter the new name of your Course privious one is "<<nameOfCourse<<endl;
				cin>>name;
				setnameofcourse(name);
				int c;
				cout<<"For more changing press 1 \nFor main manu 2\n0 for Exit\n";
				cin>>c;
				if(c==1){
				changeCourse();
					
				}
				if(c==2){
					main();
				}
				if(c==1){
				return 0;	
				}
            return 0;
	}
	static int printManu(vector<Course> t){
	system("cls");
	int num=1;
	int sz=t.size();
	for(int i=0; i<sz; i++){
		cout<<num<<"- for enrol in "<<t[i].getnameofcourse()<<endl;
		num++;
			}
		cout<<"Press 0 for Main\n";
	int ch;
	cin>>ch;
	for(int i=0; i<sz; i++){
	if(ch==i+1){
		return i;
	}
	if(ch==0){
		main();
	}
	
	}
 return 0;
}

static int coursecontent(vector <Course> &cs,int i){
    int sz=cs[i].assg.size();
    int ch;
        for(int j=0; j<sz; j++){
        cout<<cs[i].assg[j].getdiscription()<<" topic number "<<j+1<<endl;
    }
    cout<<"\n\n";
       for(int j=0; j<sz; j++){
        cout<<cs[i].hm[j].getlink()<<"  that is  link of video number  "<<j+1<<endl;
    }
    cout<<"1- for Assigniment\n2- for Helping matrial\n";
    cin>>ch;
    return ch;
    }  
};
class User{
	private:
		string name;
		string email;
	public:
		User(){
		}
		User(string na, string em){
			name=na;
			email=em;
		}
		string getName(){
			return name;
		}
		string getEmails(){
			return email;
		}
	
};
vector<Course> courses;
class Student:public User{
	private:
	     string nameofcourse;
	     int id;
	public:
		Student(string name, string email,string course,int id):User(name,email){
			nameofcourse=course;
			this->id=id;
		}
		int getid(){
			return id;
		}
		string getnameofcourse(){
			return nameofcourse;
		}
		friend void isenrollcourse(vector<Student> &stud, string course,bool isnot){
			int sz=stud.size();
			for(int i=0; i<sz; i++){
				if(stud[i].nameofcourse==course){
					isnot==false;
					cout<<stud[i].getName()<<" ";
				}
				
			}
			if(isnot==true) {
					cout<<"0";
				}
		}
static int printdetais(vector <Student> &stud,vector <int> &index){
			cout<<"Welcome back your are enroll in following course\n";
			int sz=index.size();
			for(int i=0; i<sz; i++){
				cout<<stud[index[i]].getnameofcourse()<<endl;
				cout<<"Press "<< index[i]<<" "<<" to get access of matrial\n";
			}
			int num;
			cin>>num;
			for(int i=0; i<sz; i++){
			if(num==index[i]){
				return index[i];
			}
		}
		int ch;
		cout<<"Not a correct opition\n";
		cout<<"Press 1 for main\n";
		cin>>ch;
				if(ch==1){
					main();
				}
            return 0;
		}
		static void nameofenrollcourse(vector<Student> crs,int id, vector<int> &index){
			int sz=crs.size();
			for(int i=0; i<sz; i++){
			if(crs[i].getid()==id){
				index.push_back(i);
			}
		}
		}
		friend void totalstudentenroll(vector<int> change,vector<Student> &stud,vector<Course> &cours){
			cout<<"Course Name\tStudent Name\n";
			int sz=change.size();
			for(int i=0; i<sz; i++){
				cout<<cours[change[i]].getnameofcourse()<<"\t\t";
					bool isnot=true;
				string name=cours[change[i]].getnameofcourse();
				isenrollcourse(stud,name,isnot);
				cout<<endl;
			}
		}
		static int EnrollCourse(vector<Course> courses, vector<Student> stdu,int i){
			string name;
			string email;
           courseenrol++;
			cout<<"Enter your Name\n";
			cin>>name;
			cout<<"Enter your email\n";
			cin>>email;
			int id;
			cout<<"Enter id\n";
			cin>>id;
			stdu.push_back(Student(name,email,courses[i].getnameofcourse(),id));
			cout<<"Enroll successfully\n";
			int num;
			cout<<"1- for access course matrials\n";
			cout<<"2- for main Manu\n";
			cout<<"0 for Exit\n";
			cin>>num;
			if(num==1){
				
			}
			if(num==2){
				main();
			}
			if(num==0){
				return 0;
			}
        return 0;
		}
};
class Instructor:public User{
	private:
		double id;
		string education;
	public:
		Instructor(string na,string em,string edu,double id):User(na,em){
			education=edu;
			this->id=id;
		}
			double getid(){
			return id;
		}
	friend int checkforRight(double id, vector<Instructor>& inst){
			int sz=inst.size();
			bool istrue=false;
			for(int i=0; i<sz; i++){
			    if(inst[i].getid()==id){
			    istrue=true;
				return i+1;
			}
		}
		return 0-1;
	}
friend vector<int> updatecourse(vector<Course> cors,vector<Instructor> inst,int i);
	vector<int> mycourse(vector<Course> cors,vector<Instructor> inst,int i){
		cout<<"Course related to You\n";
		int sz=cors.size();
		vector<int> cl;
		for(int j=0; j<sz; j++){
			if(cors[j].getinstructor()==inst[i].getName()){
				cl.push_back(j);		
			}
		}
		return cl;
	}
	int createCourse(vector<Course> &cors,string name){
		Course c;
  	        c=c.uploadcourse(getName());
            string link=c.hm[0].getlink();	        
			cors.push_back(Course(c.getnameofcourse(),c.getduration(),c.getnofovideo(), name,link));
			cout<<"Course Add successfully\n";
				int nu;
    	    	cout<<"Enter 1 for adding one more \n2 for main manu\n0 for exit\n";
    	    	cin>>nu;
    	    	if(nu==1){
    	    		system("cls");
    	    		createCourse(cors,name);
				}
				if(nu==2){
					main();
				}
				else if(nu==0){
					return 0;
				}
            return 0;
        }
        string getEducation(){
        	return education;
		}
		static void printDetalis(vector<Instructor> inst){
			int sz=inst.size();
			cout<<"Name\t\tEducation\n";
			for(int i=0; i<sz; i++){
				cout<<inst[i].getName()<<"\t"<<inst[i].getEducation()<<"\n";
			}
		}	
};
void enrollinassigniment(){
    progress++;
    cout<<"Your Enroll successfully\n";
    cout<<"your Scores 9.5 marks in assigniment\n";
}
int mycoursedetails(vector<int> cl ,vector<Course> cour){
	int sz=cl.size();
	int num;
	    for(int i=0;i<sz;i++){
	    	cout<<"Your course is prsent on "<<cl[i]<<" have name "<<cour[cl[i]].getnameofcourse()<<endl;
		}
		cout<<"Enter the index for change\n";
		cin>>num;
		for(int i=0; i<sz; i++){
			if(cl[i]==num){
				return num;
			}
		}
		cout<<"Enter the correct index\n";
		mycoursedetails(cl,cour);
    return 0;
}
void enrollinmatrial(){
    cout<<"Please watch the complete video and ready for Assigniment\n";
    cout<<".\n.\n.\n.\n.\n";
}

int main(){
	    vector<Student> stud;
	    vector<Instructor> inst; 
	    courses.push_back(Course("Amazon",44,3,"Haroon Rana","www.geo.com"));
	    courses.push_back(Course("Meta Ads",44,3,"Dr.Aqeel","www.geo.com"));
	    courses.push_back(Course("shopify",44,3,"WahaasAli","www.geo.com"));
	    courses.push_back(Course("video editing",4,3,"Haroon Rana","www.geo.com"));
		inst.push_back(Instructor("Haroon Rana","m.haroon@gmail.com","BS",2450));
	    inst.push_back(Instructor("Dr.Aqeel","aqel.dr@gmail.com","PHD",3150));
    	inst.push_back(Instructor("WahaasAli","whaasali.45@gmail.com","BS",2340));
    	stud.push_back(Student("Naveed","nw@gmail.com","Amazon",35));
    	stud.push_back(Student("Qadoos","aq@gmail.com","Meta Ads",56));
    	stud.push_back(Student("Waqas","sw@gmail.com","shopify",55));
    	int num;
    	system("cls");
    	cout<<"Press 1 For going as a Instructor\n";
    	cout<<"Press 2 For going as a Student\n";
    	cout<<"Press 3 For printing collection\n";
    	cin>>num;
    	    
    	if(num==1){
    		cout<<"Enter your id\n";
    		double id;
    		cin>>id;
    		cin.ignore();
    		int i=checkforRight(id,inst);
    		if(id==inst[i-1].getid()){
    	    	cout<<"Press 1 for Changing in Course\nPress 2 for upload new course\nPress 3 for Check the Course Progress\nPress 4 for the check result of student\n";
      	    	int num;
      	    	cin>>num;
    	    	if(num==1){	
    	    	system("cls");
    	    	vector<int> change=inst[i-1].mycourse(courses,inst,i-1);
    	    	int index=mycoursedetails(change,courses);
    	    	courses[index].changeCourse();
			}
			if(num==2){
				system("cls");
				inst[i-1].createCourse(courses,inst[i-1].getName());
				
			}
			else if(num==3){
			    vector<int> change=inst[i-1].mycourse(courses,inst,i-1);
			    system("cls");
    	    	totalstudentenroll(change,stud,courses);
    	    	int nu;
    	    	cout<<"Enter 1 for main manu\n0 for exit\n";
    	    	cin>>nu;
    	    	if(nu==1){
    	    		system("cls");
    	    		main();
				}
				else if(nu==0){
					return 0;
				}
				
			}
		       else if(num==4){
                if(progress){
                cout<<"number of student enroll in course "<<courseenrol<<endl<<progress<<"Number of student enroll in assigniment And gain 9.5 marks each\n";
                cout<<"Enter 1 for main\n0 for exit\n";
                int n;
                cin>>n;
                if(n==1){
                    main();
                } 
                if(n==0){
                    return 0;
                }       
                   }
                else{
                cout<<"number of student enroll in course "<<courseenrol<<endl<<progress<<" number of student enroll in assigniment\n";
                cout<<"Enter 1 for main\n0 for exit\n";
                int n;
                cin>>n;
                if(n==1){
                    main();
                } 
                if(n==0){
                    return 0;
                }       
                   }        
		    }
            
            }  
			
		else{
				cout<<"Account Information is incorrect\n";
				int ch;
				cout<<"1 for main Manu\n0 for Exit...";
				cin>>ch;
				if(ch==1){
					main();
				}
				if(ch==0){
					return 0;
				}
			}
	}
		else if(num==2){
			int k;
			cout<<"If you already enroll in course than press 1\nAnd 2 for enroll new Course\n";
			cin>>k;
			     if(k==1){
			     	int id;
			     	cout<<"Enter your id for access course matrials\n";
			     	cin>>id;
			     	vector <int> indexofcourse;
					Student::nameofenrollcourse(stud,id,indexofcourse);
			     	int indexofchange=Student::printdetais(stud,indexofcourse);
			     	int num =Course::coursecontent(courses,indexofchange);
                    if(num==1){
                        enrollinassigniment();
                        int j;
                        cout<<"0- for main\n";
                        cin>>j;
                        if(j==0){
                            main();
                        }
                    }
                    else if(num==2){
                    enrollinmatrial();
                    int j;
                        cout<<"1- for enroll in assigniment \n0- for main\n";
                        cin>>j;
                        if(j==1){
                            enrollinassigniment();
                        }
                        if(j==0){
                            main();
                        }
                }
                                                               
			}
				 if(k==2){
				    int index=Course::printManu(courses);
		        	Student::EnrollCourse(courses,stud,++index);
                    int num =Course::coursecontent(courses,index);
                    if(num==1){
                        enrollinassigniment();
                        int j;
                        cout<<"0- for main\n";
                        cin>>j;
                        if(j==0){
                            main();
                        }
                    }
                    else if(num==2){
                       enrollinmatrial();
                        int j;
                        cout<<"1- for enroll in assigniment \n0- for main\n";
                        cin>>j;
                        if(j==1){
                            enrollinassigniment();
                            int j;
                            cout<<"0- for main\n";
                            cin>>j;
                            if(j==0){
                            main();
                        }
                        }
                        if(j==0){
                            main();
                        }                                           
				 }	
		}
}
		else if(num==3){
			system("cls");
			int nu;
			cout<<"1- for printing the collection of courses\n2- for print the collection of instructor\n";
			cin>>nu;
			if(nu==1){
				Course::printdetails(courses);
				int c;
				cout<<"Press any key for main\n";
				cin>>c;
				if(c){
					main();
				}
				
			}
			if(nu==2){
			  int c;
			  Instructor::printDetalis(inst);
				cout<<"Press any key for main\n";
				cin>>c;
				if(c){
					main();
				}	
			}
				
		}
    	
		}

