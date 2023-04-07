/// in this project i will make a phone book directory which will have all general feature of a contact list in smartphone 
// refernce for this is on github -> https://github.com/PRITI24/Phonebook-management-using-doubly-linked-list/blob/master/main.cpp
// date -> 7 jan 2023

                // phone book project using concpet of D.L.L
#include<bits/stdc++.h>
using namespace std;

class dnode{
    public:
        char number[20];
        char gmail[20];
        char name[30];
        dnode *prev, *next;
        // constructoor 
        dnode(char n[],char r[], char g[]){
            strcpy(name,n);
            strcpy(number,r);
            strcpy(gmail,g);
            next = NULL;
            prev =NULL;
        }
    friend class dlist; // new concept of freiend classs came for very first time
};

class dlist{
    dnode *head,*temp,*ptr;
    dnode *ptr1,*ptr2,*duplicate;
    public:

    // now we define the function which will make our phone book 
    void insert();
    void sort();
    void display();
    void accept();
    void update(char ch[10]);
    void deletecontact(char n[20]);
    void deletesamename();
    void deletesamenumber();
    void deletesamegmail();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);

    // constructor for this dlist class
    dlist(){
        head =NULL;
        temp =NULL;
        ptr= NULL;
        ptr1 =NULL;
        ptr2 =NULL;
        duplicate =NULL;
    }
};

// now we write the body of all above functions 

void dlist::accept(){ // by this function we wil enter new contacts in phone book
    // so firstly take inpuut of the details from user and then pass them to make a node of dnode type 
    char number[50];
    char gmail[40];
    char name[30];
    char ans;
    // now ek contact toh hoga hi so once we need to atleast run the loop so use do-while loop
    do{
        cout <<"ENTER NAME : ";
        cin >> name;
        cout <<"ENTER NUMBER : ";
        cin >> number;
        while(strlen(number)!=10){
            cout<<"ENTER A VALID 10 DIGIT NUMBER ONLY";
            cin >> number;
        }
        cout<<"ENTER EMAIL : ";
        cin >> gmail;

        temp =new dnode(name,number,gmail);
        //check if its the first node / conatct of pphone book
        if(head ==NULL){
            head =temp;
        }
        else{
            ptr=head;
            while(ptr->next !=NULL){
                ptr = ptr->next;
            }
            ptr->next =temp;
            temp->prev =ptr;
        }
        cout <<" DO YOU WANT TO CONTINUE ENETRING NEW CONTACTS ?????????? PRESS 'y' TO DO SO ";
        cin >> ans;
    }while(ans =='y');
}
//end of accept function body

void dlist::display(){ // traversing the D.L.L
    ptr = head;
    while(ptr!=NULL){
        cout <<"\n NAME : " << ptr->name<<endl;
        cout <<"\n NUMBER : " << ptr->number<<endl;
        cout <<"\n G-MAIL : " << ptr->gmail<<endl;
        ptr = ptr->next;
    }
}

void dlist::insert(){
    accept();
}


//THIS SORT FUNCTION I NEED TO CHANGE SOME AS HERE ONLY NAMES ARE GETING SORTED AND SO OTHER DETAILS ARE GETTIG MIXED UP 
void dlist::sort(){
    dnode *i,*j;
    int temp;
    char n[20];
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            temp = strcmp(i->name,j->name);
            if(temp>0){
                strcpy(n,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,n);
            }
        }
    }
}


void dlist::deletecontact(char s[20]){
    //here possibility are there that node is at the head, taiil or middle or not presnt so we need cases;
    ptr= head;
    int c=0;
    while(ptr!=NULL){
        if(strcmp(s,ptr->name)==0){
            c=1;
            break;  //as i found the node to delete
        }
        else{
            c=2;
        }
        ptr=ptr->next;
    }

    //now check for cases
    if(c==1 && ptr!=head && ptr->next!=NULL){ // measn we want to delte a middle node of a D.L.L
        ptr->prev->next=ptr->next;
        ptr->next->prev = ptr->prev;
        delete(ptr);
        cout <<" THE SELECTED CONTACT IS SUCCESSFULLY DELETED!!"<<endl;
    }
    if(ptr==head){
        head =head->next;
        head->prev=NULL;
        delete(ptr);
        cout <<" THE SELECTED CONTACT IS SUCCESSFULLY DELETED!!"<<endl;
    }
    if(ptr->next == NULL){
        ptr->prev->next =NULL;
        ptr->prev=NULL;
        delete(ptr);
        cout <<" THE SELECTED CONTACT IS SUCCESSFULLY DELETED!!"<<endl;
    }
    if(c==2){
        cout <<" THE SELECTED CONTACT IS NOT PRESENT IN THE PHONE-BOOK!!"<<endl;
    }
}

// here i will need two pointer to chekc 
void dlist::deletesamename(){
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr2= ptr1; // initilze second pointer alwasy with first one then we increment late in while loop
        while(ptr2->next!=NULL){
            if(strcmp(ptr1->name,ptr2->next->name)==0){
                duplicate =ptr2->next;
                ptr2->next = ptr->next->next;
                //this line is not there in github code i guess it should also come 
                //ptr2->next->next->prev = ptr2;
                delete(duplicate);
            }
            else{
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void dlist::deletesamenumber(){
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr2= ptr1; // initilze second pointer alwasy with first one then we increment late in while loop
        while(ptr2->next!=NULL){
            if(strcmp(ptr1->number,ptr2->next->number)==0){
                duplicate =ptr2->next;
                ptr2->next = ptr->next->next;
                //this line is not there in github code i guess it should also come 
                //ptr2->next->next->prev = ptr2;
                delete(duplicate);
            }
            else{
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void dlist::deletesamegmail(){
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr2= ptr1; // initilze second pointer alwasy with first one then we increment late in while loop
        while(ptr2->next!=NULL){
            if(strcmp(ptr1->gmail,ptr2->next->gmail)==0){
                duplicate =ptr2->next;
                ptr2->next = ptr->next->next;
                //this line is not there in github code i guess it should also come 
                //ptr2->next->next->prev = ptr2;
                delete(duplicate);
            }
            else{
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void dlist::searchbyname(char na[20]){
    ptr = head;
    while(ptr!=NULL){
        if(strcmp(na,ptr->name)==0){
            cout <<"NAME FOUND : "<<endl;
            cout<<"CONTACT DETAILS"<<endl;
            cout <<"PHONE NUMEBER"<<ptr->number<<endl;
            cout<<"GMAIL ADDRESS"<<ptr->gmail<<endl;
        }
        ptr=ptr->next;
    }
}

void dlist::searchbynumber(char na[20]){
    ptr = head;
    while(ptr!=NULL){
        if(strcmp(na,ptr->number)==0){
            cout <<"NUMBER FOUND : "<<endl;
            cout<<"CONTACT DETAILS"<<endl;
            cout<<"NAME : "<<ptr->name<<endl;
            cout <<"PHONE NUMEBER"<<ptr->number<<endl;
            cout<<"GMAIL ADDRESS"<<ptr->gmail<<endl;
        }
        ptr=ptr->next;
    }
}

void dlist::searchbygmail(char na[20]){
    ptr = head;
    while(ptr!=NULL){
        if(strcmp(na,ptr->gmail)==0){
            cout <<"NAME FOUND : "<<endl;
            cout<<"CONTACT DETAILS"<<endl;
            cout <<"PHONE NUMEBER"<<ptr->number<<endl;
            cout<<"GMAIL ADDRESS"<<ptr->gmail<<endl;
        }
        ptr=ptr->next;
    }
}

void dlist::update(char n[20]){
    int c;
    char ans;
    ptr= head;
    while(ptr!=NULL){
        if(strcmp(n,ptr->name)==0){
            do{ // one time atleast we need to run the looop for sure 
                cout<<"\n WHAT DO YOU WANT TO UPPDATE?? \n 1. NAME \n 2.NUMBER \n 3.GMAIL \n";
                cin>>c;
                switch(c){
                    case 1:
                    cout<<"ENTER NEW-NAME = ";
                    cin >> ptr->name;
                    break;
                    case 2:
                    cout<<"ENTER NEW NUMBER = ";
                    cin >> ptr->number;
                    while(strlen(ptr->number)!=10){
                        cout<<"PLEASE ENTER A VALID 10 DIGIT NUMBER : ";
                        cin >> ptr->number;
                    }
                    break;
                    case 3:
                    cout<<"ENTER NEW GMAIL ADDRESS = ";
                    cin >> ptr->gmail;
                    break;
                }
            cout<<"DO YOU WANT TO CONTINUE UPDATING?";
            cin >> ans;
            }while(ans == 'y');
        }
        ptr= ptr->next;
    }
}


int main(){
    char n[20];
    char nam[20];
    char name[20];
    char number[10];
    char gmail[20];
    dlist d1;
    char ans;
    int ch,a;
    cout<<"**************                                PHONE BOOK                          ********************";
    cout<<"\n\nWHAT IS YOUR NAME?\n";
    cin.getline(name,20);
    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME "<<name<<"   !!!!!!!!!!!!!!!!!!!!!";
    cout<<"\n\n\nLET'S CREATE OUR PHONEBOOK "<<name<<"  \n\n";

    // now we will have atleast one contact in phone book so 
    d1.accept();
    d1.sort();
    do{
        cout<<"\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN PHONEBOOK\n6) DELETE SAME NUMBERS IN PHONEBOOK\n7) SEARCH\n";
        cin>>ch;
        switch(ch){
            case 1:
            d1.display();
            break;

            case 2:
            d1.insert();
            d1.sort();
            break;

            case 3:
            cout<<"\n ENTER THE NAME OF PERSON WHOSE CONTACT YOU WANT TO UPDATE....\n\n";
            cin >>n;
            d1.update(n);
            d1.sort();
            break;

            case 4:
            cout<<"\n ENTER THE NAME YOU WANT TO DELTE FROM PHONE BOOK....\n\n";
            cin >>nam;
            d1.deletecontact(nam);
            break;

            case 5:
            d1.deletesamename();
            d1.display();
            break;

            case  6:
            d1.deletesamenumber();
            d1.display();
            break;

            case 7:
            do{
                cout<<"1.SEARCH BY NAME\n 2.SEARCH BY NUMBER\n 3.SEARCH BY GMAIL\n ";
                cin>>a;
                switch(a){
                    case 1:
                    cout<<"ENTER THE NAME TO BE SEARCHED..";
                    cin>> name;
                    d1.searchbyname(name);
                    break;

                    case 2:
                    cout<<"ENTER THE NUMBER TO BE SEARCHED..";
                    cin>> number;
                    d1.searchbyname(number);
                    break;

                    case 3:
                    cout<<"ENTER THE GMAIL TO BE SEARCHED..";
                    cin>> gmail;
                    d1.searchbyname(gmail);
                    break;
                }
                cout<<"DO YOU WANT TO CONTINUE SEARCHING FOR THE OTHER CONTACT??"<<endl;
                cin >>ans;
            }while (ans == 'y');
            break;
        }
        cout<<"\n DO YOU WANT TO CONTINUE OPERATION?????";
        cin>>ans;
    }while(ans == 'y');

    return 0;
}   