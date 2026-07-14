#include<iostream>
using namespace std;
struct SNode{
	int seatNo;
	SNode* Snext;
};
struct CNode{
	int CNo;
	CNode* Cnext;
	SNode* stdList;
};
	CNode* Chead=NULL;
//Insert course
void insertCourse(int CNo){
	CNode* newNode= new CNode;
	newNode->CNo=CNo;
	newNode->Cnext=NULL;
	newNode->stdList=NULL;
	if(Chead==NULL){
		Chead=newNode;
		return;
	}
	CNode* Ctemp=Chead;
	while(Ctemp->Cnext!=NULL){
		Ctemp=Ctemp->Cnext;
	}
	Ctemp->Cnext=newNode;	
}
//INSERT STUDENT
void insert_Std(int seatNo,int CourseNo){
	//phly courseNo ki availability check
	CNode* Ctemp=Chead;
	while(Ctemp!=NULL){
		if(Ctemp->CNo==CourseNo){
			SNode* newNode=new SNode;
			newNode->seatNo=seatNo;
			newNode->Snext=NULL;
			if(Ctemp->stdList==NULL){
				Ctemp->stdList=newNode;
			}
			else{
			SNode* Stemp=Ctemp->stdList;
			while(Stemp->Snext!=NULL){
				Stemp=Stemp->Snext;
			}
			Stemp->Snext=newNode;		
		}
				return;
	}	
	Ctemp = Ctemp->Cnext;
	}
	
}
//SEARCH A COURSE
void searchCourse(int courseNo){
	if(Chead==NULL){
		cout << "List is Null";
		return;
}
	CNode* Ctemp=Chead;
	while(Ctemp!=NULL){
		if(Ctemp->CNo==courseNo){
			cout << "Course Found :" << courseNo << endl;
		}
		Ctemp=Ctemp->Cnext;
	}
}
//Delete a student from Course
void delStd_Course(int courseNo,int seatNo){
	CNode* Ctemp = Chead;
	if(Ctemp==NULL){
		cout << "List is Null";
		return;
}
	Ctemp=Ctemp->Cnext;
	if(Ctemp->CNo==courseNo){
		SNode* Stemp=Ctemp->stdList;
		//if we want to delete head std
		if(Stemp->seatNo==seatNo){
			Stemp=Stemp->Snext;
			delete Stemp;
			return;
		}
		//otherwise
		SNode* Scurr= Ctemp->stdList->Snext;
		SNode* Sprev=Ctemp->stdList;
		while(Scurr!=NULL){
			if(Scurr->seatNo==seatNo){
				Scurr->	Snext=Sprev->Snext;
				delete Scurr;
				return;
	}
		Sprev=Scurr;
		Scurr=Scurr->Snext;
	}
}
}
//Delete a course (phly std list poori dlt then course)
void del_Course(int CourseNo){
	if(Chead==NULL){
		cout<<" Course list is empty" << endl;
		return;
	}
	//head course delete
	if(Chead->CNo==CourseNo){
		//First delete list of stds
		SNode* Stemp=Chead->stdList;
		while(Stemp!=NULL){
			SNode* Sdel=Stemp;
			Stemp=Stemp->Snext;
			delete Sdel;
		}
		CNode* Cprev=Chead;
		Chead=Chead->Cnext;
		delete Cprev;
		return;	
	}
	 // MIDDLE / LAST COURSE DELETE
	CNode* Cprev=Chead;
	CNode* Ccurr=Chead->Cnext;
	while(Ccurr!=NULL){
		if(Ccurr->CNo==CourseNo){
			SNode* Stemp=Ccurr->stdList;
			while(Stemp!=NULL){
			SNode* Sdel=Stemp;
			Stemp=Stemp->Snext;
			delete Sdel;
		}
		Cprev->Cnext = Ccurr->Cnext;
            delete Ccurr;
            return;
	}
		Cprev=Ccurr;
		Ccurr=Ccurr->Cnext;
	}
	    cout << "Course not found" << endl;
	
}
//Search Std in a course
void searchStd_course(int courseNo,int seatNo){
	if(Chead==NULL){
		cout <<"Course list is empty" << endl;
		return;
	}
	CNode* Ctemp=Chead;
	if(Ctemp->CNo==courseNo){
		SNode* Stemp=Ctemp->stdList;
		while(Stemp!=NULL){
		if(Stemp->seatNo==seatNo){
			cout << "Student Found : "<< endl<< "Seat No:" << Stemp->seatNo << "Course No:" << Ctemp->CNo <<  endl;	
			return;
			}
			Stemp=Stemp->Snext;
		}
		Ctemp=Ctemp->Cnext;
	}
}
//Delete a student
void delStd(int seatNo){
	if(Chead==NULL){
		cout << "Course list is empty";
		return;
	}
	CNode* Ctemp=Chead;
	while(Ctemp!=NULL){
		SNode* Stemp=Ctemp->stdList;		//Ctemp->stdList this is head of std list
		//null check
		if(Stemp == NULL){
            Ctemp = Ctemp->Cnext; 		//skip that course
            continue;
        }

		//Head Case
		if(Stemp->seatNo==seatNo){
			Ctemp->stdList=Stemp->Snext;	// head ka next=head hojyee
			delete Stemp;
			return;
		}
		SNode* Scurr=Stemp->Snext;
		SNode* Sprev=Stemp;
		while(Scurr!=NULL){
			if(Scurr->seatNo==seatNo){
				Sprev->Snext=Scurr->Snext;
				delete Scurr;
				return;
		}
		Sprev=Scurr;
		Scurr=Scurr->Snext;
}
	Ctemp=Ctemp->Cnext;
}
}
//Search a student
void SearchBySeat(int seatNo){
	if(Chead==NULL){
		cout<< "Course list is empty";
		return;
	}
	CNode* Ctemp=Chead;
	while(Ctemp!=NULL){
		SNode* Stemp=Ctemp->stdList;
		if(Stemp->seatNo==seatNo){
			cout << "Student Found: " << "Seat No: " << Stemp->seatNo << ", Course No: " << Ctemp->CNo << endl;
			return;
		}
		Stemp=Stemp->Snext;
		Ctemp=Ctemp->Cnext;
	}
}
//Display CourseList
void displayCourseList(){
	if(Chead==NULL){
		cout << "List is Null" ;
		return;
	}
	CNode* Ctemp=Chead;
	cout << "List of Course:" << endl;
	while(Ctemp!=NULL){
		cout<< Ctemp->CNo << "  " << endl;
		Ctemp=Ctemp->Cnext;
	}
}
//Display Student List from Course
void display_StdList(int courseNo){
	if(Chead==NULL){
		cout << "Course List is empty" << endl;
		return;
	}
	CNode* Ctemp=Chead;
	while(Ctemp!=NULL){
		if(Ctemp->CNo==courseNo){
			cout << "Student List:" ;
			SNode* Stemp=Ctemp->stdList;
			while(Stemp!=NULL){
				cout << Stemp->seatNo << ",";
				Stemp=Stemp->Snext;
			}	
		}
		Ctemp=Ctemp->Cnext;
	}
}
//Display all
void display(){
	if(Chead==NULL){
		cout<< "List is Null";
		return;
	}
	CNode* Ctemp=Chead;
	while(Ctemp!=NULL)
	{
		cout<< Ctemp->CNo << " -> "  ;
		
		SNode* Stemp=Ctemp->stdList;
		
		if(Stemp==NULL){
			cout<< "No Students exist in the list" << endl;
		}
		else{
		    while(Stemp!=NULL){
			cout<< Stemp->seatNo << " " <<endl;
			Stemp=Stemp->Snext;
	    	}
		}
		Ctemp=Ctemp->Cnext;
	}
}
int main(){
	int chooseNum;
	while (true) { 
    cout << "Enter option:\n";
cout << "1: Insert Course\n";
cout << "2: Delete a course\n";
cout << "3: Search a Course\n";
cout << "4: Display list of course\n";
cout << "5: Add student to specific course\n";
cout << "6: Delete student from specific course\n";
cout << "7: Delete a student\n";
cout << "8: Search student in specific course\n";
cout << "9: Search a student\n";
cout << "10: Display list of student of specific course\n";
cout << "11: Display All\n";
cout << "Your choice: ";
    cin >> chooseNum;
    switch(chooseNum){
    	case 1:
    		int CNo;
                cout << "Enter Course Number: ";
                cin >> CNo;
    			insertCourse(CNo);
    			break;
    		case 2:
    			int C_No;
                cout << "Enter Course Number to delete: ";
                cin >> C_No;
    			del_Course(C_No);
    			break;
    				case 3:
    				int cNo;
                	cout << "Enter Course Number to search: ";
                	cin >>cNo;
    				searchCourse(cNo);
    				break;
    					case 4:
    					displayCourseList();
    					break;
    						case 5:
    							int seatNo, courseNo;
                				cout << "Enter Course Number: ";
                				cin >>courseNo;
                				cout << "Enter Student Seat Number: ";
                				cin >> seatNo;
    							insert_Std(seatNo, courseNo);
    							break;
    								case 6:
    								int CourseNo,SeatNo;
    								cout << "Enter Course Number: ";
                					cin >> CourseNo;
                					cout << "Enter Student Seat Number to delete: ";
                					cin >> SeatNo;
    								delStd_Course(CourseNo,SeatNo);
    								break;
    									case 7:
    									int seaTNo;
                						cout << "Enter Student Seat Number to delete: ";
                						cin >> seaTNo;
    									delStd(seaTNo);
    									break;
    										case 8:
    											int SEatNo, COURSENo;
                								cout << "Enter Course Number: ";
                								cin >> COURSENo;
                								cout << "Enter Student Seat Number to search: ";
                								cin >> SEatNo;
    											searchStd_course(SEatNo, COURSENo);
    											break;
    												case 9:
    													int SEATNo;
                										cout << "Enter Student Seat Number to search: ";
                										cin >> SEATNo;
    													SearchBySeat(SEATNo);
    													break;
    														case 10:
    															int CoursENo;
                												cout << "Enter Course Number: ";
                												cin >> CoursENo;
    															display_StdList(CoursENo);
    															break;
    																case 11:  	
                													display();
                													break;
            															case 12:  // Exit
                														return 0;
           																	 default:
                																cout << "Wrong choice! Try again." << endl;		
	}
}
return 0;
}
//	insert(401);
//	insert(403);
//	insert(405);
//	insert(407);
//	insert_Std(32,401);
//	insert_Std(33,403);
//	insert_Std(34,405);
//	insert_Std(41,405);
//	insert_Std(43,405);
//	insert_Std(35,407);
//	display();
////	searchCourse(405);
////	delStd(403);
//	//del_Course(403);
//	//searchStd(401,32);
//	//display_StdList(405);
//	//delStd(41);
//	//SearchBySeat(35);
//	//display();
////	displayCourseList();
//}
