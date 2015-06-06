#include<iostream>
#include<new>
#include<cstdlib>
#include<cstring>
#define MAXPATIENTS 200
#define MAXROOMS 200

using namespace std;
 int deluxe=0,semi=0,normal=0;
 int numOfPatients=0,numOfRooms=0;  



// the structure containing the node... info and a link *next to point to the next node
  struct nod{    
        string name;
        string dob;
        string bloodgroup;
        string doc;
        string sex;
        string wardt;
        long long int  contact;
        int age,ward;

        struct nod *next;
         };
    typedef struct nod node;
 
     class hospital{                        //the hospital class(list class) 
             node *f;                         //node that points to null
         public:       
             hospital(){f=NULL;}           //initialize f to null in constructor
    
 //function to admit the patien
     void PatientAdmit(char *n,int a,char *db,char *b,char *s,long long int c,int w,char *wrd,char *d){    
           node *h=new node;  //allocate memory for new node
              {h->name=n;
               h->age=a;
	       h->dob=db;
               h->bloodgroup=b;
               h->sex=s;
               h->contact=c;        
               h->ward=w;
               h->wardt=wrd;
               h->doc=d;}              
            
               h->next=f;         //after assigning info.. point to next node (null)
               f=h;             
             }     
//Function to Discharge Desired patient
     int PatientDischarge(int num){
               node *temp, *prev;
               temp=f;
               if(f==NULL)
                  cout<<"List Is Empty\n";
                while(temp!=NULL)
                    {
                      if(temp->ward==num)
		       {
   		        if(temp==f)
       		         	 {
              { /*cout<<"\n\nThe Patient with the following Details has been discharged Succesfully:\n";
                  cout<<"Name: "<<f->name<<"\n";
                  cout<<"Date Of Birth: "<<f->dob<<"\n";
                  cout<<"Blood Group: "<<f->bloodgroup<<"\n";
                  cout<<"Sex: "<<f->sex<<"\n";
                  cout<<"Age: "<<f->age<<"\n";
                  cout<<"Contact Number: "<<f->contact<<"\n";
                  cout<<"Ward Type: "<<f->wardt<<"\n";
                  cout<<"Ward Number: "<<f->ward<<"\n";}
                  cout<<"Doctor assigned: "<<f->doc<<"\n";*/
                f=temp->next;
	        free(temp);
   	        return 1;
	           }   }
	        else
	          { 
                       prev->next=temp->next;
                         free(temp);
	            return 1;
	     	        }
	              }
                  else
	   	    {
	 	        prev=temp;
		        temp= temp->next;
			    }
		    }
                  cout<<"Patient Does Not Exist \n";
	          return 0;
         }
 
//function to display the list of admitted patients
       void display(){
              int i=1;
              node *temp=f;
              if(f==NULL)
                   cout<<"List Is Empty\n";
              else{
                   cout<<"The Patients in the list are:\n";
              while(temp!=NULL){
                   {   cout<<"Details of Patient:"<<i<<"\n"; 
                    cout<<"Name:"<<temp->name<<"\n";
                    cout<<"Date Of Birth:"<<temp->dob<<"\n";
                    cout<<"Blood Group:"<<temp->bloodgroup<<"\n";
                    cout<<"Sex:"<<temp->sex<<"\n";
                    cout<<"Age:"<<temp->age<<"\n";
                    cout<<"Contact Number:"<<temp->contact<<"\n";
                    cout<<"Ward Type:"<<temp->wardt<<"\n";
                    cout<<"Ward Number: "<<temp->ward<<"\n";
                    cout<<"Doctor: "<<temp->doc<<"\n";
			cout<<"\n\n";}
                  temp=temp->next;
                  i++;
                     }
                }
           }

//seperate function to check if list is empty or not.. to be called in main      
 int list_empty() 
                   {
                  if(f==NULL)
                   {
               
                  return 0;
                   }
                  else
                   {
                          return 1;
                   }
                       }


 
  };

 // LINKED LIST 2 TO PERFORM LINEAR SEARCH TO PREVENT ADDITION OF SAME WARD NUMBER
            struct nod2{
              int wardno;
              struct nod2 *next;
               };
           
            typedef struct nod2 w_node;

       class list:public nod2{
              w_node *f;
              public:
             list(){f=NULL;}
            //insert ward number 
             void ins(int num){
                  w_node *p=new w_node;
                  p->wardno=num;
                  p->next=f;
                  f=p;
                        }
            //delete ward number 
              int del(int num){
                 w_node *temp, *prev;
                      temp=f;
                      if(f==NULL)
                        cout<<"List Is Empty\n";

                      while(temp!=NULL)
                        {
                            if(temp->wardno==num)
                            {
                            
                              if(temp==f)                       
                                 {
                               f=temp->next;
                                free(temp);
                             return 1;
                                }
                                else
                                {
                                prev->next=temp->next;
                                free(temp);
                                return 1;
                                }
                            }
                            else
                            {
                                prev=temp;
                                temp= temp->next;
                            }
                            }
                            cout<<"Patient Does Not Exist \n";
                            return 0;

                  }

        
//checking if ward exists or not using linear search
		int checkWard(int item)
		{
			int loc=0,i;
			i=0;
			w_node *ptr=f;
			while(ptr!=NULL)
			{
			      if((ptr->wardno)==item)
			      {
					return 0;
					break;
			      }
			      ptr=ptr->next;
			      i++;
			}
			return 1;
			}


           
              
//for developers use only
                  void display_ward(){
                   w_node *temp=f;
                  if(f==NULL)
                   cout<<"Empty\n";
                     else{
                     cout<<"The Occupied Ward Numbers are:\n";
                     while(temp!=NULL){
                          cout<<" "<<temp->wardno;
                          temp=temp->next;
                      }
                    }
                 }

//function to check if list is empty or not 
             int list_empty()
	         {
		if(f==NULL)
		{
		cout<<"\nLinked List is empty";
		return 0;
		}
		else
		{
			return 1;
		}
       		     }


        

        };
//beginning of main program
     int main(){
         char nme[20],db[10],bg[5],da[20],sx[20];        
          char ward[20];
          long long int cn;
         int ag,l,wrd,suc,suc1,ch2,item,loc,ch1;
         int choice,patientCount=MAXPATIENTS,roomCount=MAXROOMS;
         hospital ob;
         list wd;
         cout<<".......................HOSPITAL MANAGEMENT MENU........................\n\n";
         while(patientCount!=0){
         cout<<"1.Patient Admission          2.Patient Discharge     3.Display   4.Exit\n\n";
         cout<<"Enter your choice: ";
         cin>>choice;
         cout<<"\n";
                  switch(choice){
           case 1:
                     //accept info of patients.. no need of getdetails() 
                             cout<<"ENTER THE DETAILS OF PATIENT BELOW\n";
                             
                             cout<<"\nEnter name of patient:";
                              cin>>nme;
                              cout<<"\nEnter the age of person:";
                              cin>>ag;
                              cout<<"\nEnter the Date Of Birth:";
                              cin>>db;
				cout<<"\nEnter the Blood Group:";
                              cin>>bg;
                              cout<<"\nSex:";
                              cin>>sx;
                              cout<<"\nEnter the contact number:";
                              cin>>cn;
                              cout<<"Enter Type Of Ward Patient Requires:1.Normal  2.Semi   3.Deluxe\n";
                              cin>>ch1;
                                 switch(ch1){
         
                                           case 1:strcpy(ward,"Normal");
                                                  break;
 
                                            case 2:strcpy(ward,"Semi");
                                                   break;
                                            case 3:strcpy(ward,"Deluxe");
                                                   break;
 
                                            default:cout<<"wrong choice entered\n";


                                                      }
                                            
                        label:     cout<<"\nEnter the Ward Number For The Patient:";
                                   cin>>wrd;
                                   if((wrd<=0)||(wrd>MAXROOMS)){
                                      cout<<"Enter a valid ward number\n";
                                      goto label;
                                      }
                                   loc=wd.checkWard(wrd);
                                   if(loc==1)
                                     {
                                       cout<<" Room allocated Succesfully\n";
                                         wd.ins(wrd); 
                                             }
                                   else{
                                     cout<<"Ward already Allocated, Please Enter a different ward\n";    
                                     goto label;
                                     }
                            --roomCount;
                             cout<<"Total Number Of rooms available:"<<roomCount<<"\n";
                
                                                                      
                          cout<<"\nDoctor Assigned:";
                           cin>>da;
                           cout<<"Admission Succesfull \n";
                            //pass above info as parameters to admit function
                             ob.PatientAdmit(nme,ag,db,bg,sx,cn,wrd,ward,da);
                             patientCount--;//decrement count when patient admitted
                             cout<<"vacancy left: "<<patientCount<<" Patients \n";
                           //Display Vacancy   
                             break;
 
              case 2:
                                      if(ob.list_empty()==0)
                                                cout<<"List Empty\n";
                          else{
                             cout<<"Enter Ward Number of person to be discharged\n";
                             cin>>l;
                           
                            suc=ob.PatientDischarge(l);
                          if(suc==1){
                            if(patientCount<MAXPATIENTS) patientCount++;
                             cout<<"vacancy left: "<<patientCount<<" Patients \n";
                           if(roomCount<MAXROOMS) roomCount++;
                             cout<<"Room Vacany left: "<<roomCount<<" Rooms\n";
                           
                               }

                         else{
                               cout<<"Invalid entry\n";
                            }
                          }
                             break;
                                                 
                
                             
                             

                      case 3: ob.display();
                         break;
                 



                      case 4:exit(0);                //easiest part of program
                             break; 
                             default: cout<<"Invalid Choice Entered... Please Try Again\n";
                      
                           }
              }
return 0;
}
            
 
         
           

          

    
