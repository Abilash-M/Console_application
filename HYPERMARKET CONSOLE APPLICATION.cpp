#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
/*USER PROGRAM STARTS HERE*/
class user
{
    public:
    string name;
    string password;
    user * next;
        user(string Name,string pass)
        {
            name=Name;
            password=pass;
            next=NULL;
        }

};

class linked
{

public:
    user * head=NULL;
    void Createuser(user * givnode)
    {
        user *tptr;
        if(head==NULL)
            {
            head=givnode;
            }
        else
        {
            for(tptr=head;tptr->next!=NULL;tptr=tptr->next);
            tptr->next=givnode;
        }
    }

    void disp()
    {
        user * tptr;
        for(tptr=head;tptr!=NULL;tptr=tptr->next)
        {
            cout<<tptr->name<<"\t\t"<<tptr->password<<endl;
        }
    }

    void inv()
    {
    user * givnode = new user("Suba","989");
    Createuser(givnode);
    user * givnode2 = new user("Abi","956");
    Createuser(givnode2);
    user * givnode3 = new user("Harish","900");
    Createuser(givnode3);
    user * givnode4 = new user("Yash","911");
    Createuser(givnode4);
    }

    void userverify()
    {
    int check=5;//any num except 0 and 1
    cout<<"If You are a existing User ENTER '1' , else ENTER '0':";
    int userexist;
    cin>>userexist;
    string UN,pass;
    if(userexist)
    {
        user * dptr;
    cout<<"Enter Your username: ";
    while(1)
    {
    if(check==3)
        cout<<"Enter a valid username: ";
    if(check==2)
        cout<<"Enter Your username: ";
    cin>>UN;
    cout<<"Enter Your password: ";
    cin>>pass;

    for(dptr=head;dptr->next!=NULL;dptr=dptr->next)
    {
        if(UN==dptr->name)
        {

            if(pass==dptr->password)
            {
                check =1;
                break;
            }
            else{
                check=2;
                break;

            }
        }
        else
            check=3;
            break;
    }
    if(check==1)
        break;
    else if(check==2)
        cout<<"password is incorrect"<<endl;
    else if(check==3)
        cout<<"Username is invalid"<<endl;
    }
    if(check==1)
    {
        cout << "-------------------------------------" << endl;
        cout<<"\t   "<<"Welcome "<<dptr->name<<"!"<<endl;
    }




    }
    else{
        cout<<"To sign up, contact Store Manager. To continue as guest ENTER 1:";
        int temp;
        cin>>temp;
        if(temp==1)
        {
        cout << "-------------------------------------" << endl;

            cout<<"\t   "<<"Welcome Guest"<<endl;
        }
        else
        {
            cout<<"Thank You!";
            exit(5);
        }
        }

        }
    };

    /*USER PROGRAM ENDS HERE*/

/* Inventory NODE STARTS HERE */
class Node
{
public:
 string prod;
 float price;
 int productcode;
 Node * next;
    Node(string givennode,float rate,int code)
    {
        prod=givennode;
        price=rate;
        productcode = code;
        next=NULL;
    }
};
/* Inventory NODE ENDS HERE */

/* SELECTED ITSMS NODE STARTS HERE */

class SN
{
public:
 string item;
 int nos;
 float subtotal;
 SN * snext;
    SN(string Items,int quantity)
    {
        item=Items;
        nos=quantity;
        snext=NULL;
        subtotal=NULL;
    }
};
/* SELECTED ITEMS NODE ENDS HERE */

/* SELECTED ITEMS LINKEDLIST STARTS HERE */
class SelectedItems
{
        SN* shead = NULL;

public:

    void createSlinkedlist(SN * gn)
    {
        SN *dptr;
        int flag=0;
        if(shead==NULL)
            shead=gn;
        else
        {
            for( dptr=shead;dptr->snext!=NULL;dptr=dptr->snext)
            {if(gn->item==dptr->item)
                {
                flag=1;
                break;
                }
            }
            if(flag)
                dptr->nos=dptr->nos+gn->nos;
            else
            dptr->snext=gn;
        }
    }

    void displays()
    {
        int Total=0;
        SN * dptr;
        Node * tr;
        cout << "-------------------------------------" << endl;
        cout << "                Bill                 " << endl;
        cout << "-------------------------------------" << endl;
        cout << "Product   Quantity   Rate   Subtotal " << endl;
        cout << "-------------------------------------" << endl;
       for(dptr=shead;dptr!=NULL;)
       {
            cout<<dptr->item<<setw(5)<<"\t"<<dptr->nos<<setw(5)<<"\t"<<dptr->subtotal<<setw(5)<<"\t"<<dptr->subtotal*dptr->nos<<endl;
            Total+=dptr->subtotal*dptr->nos;
            dptr=dptr->snext;
        }
        cout << "-------------------------------------" << endl;
        cout << "                TOTAL =         "<<Total << endl;
        cout << "-------------------------------------" << endl;

        cout << "---THANK YOU FOR SHOPPING WITH US!---" << endl;
        cout << "-------------------------------------" << endl;

    }
};
/* SELECTED ITEMS LINKEDLIST ENDS HERE */

/* INVENTORY LINKEDLIST STARTS HERE */
class linkedlist
{
    public:
    Node * head= NULL;
    void createlinkedlist(Node * givennode)
    {
        Node * tptr;
        if(head==NULL)
            head=givennode;
        else{
            for( tptr=head;tptr->next!=NULL;tptr=tptr->next);
            tptr->next=givennode;
        }
    }
    void display()
    {
        Node * tptr;
        for(tptr=head;tptr!=NULL;tptr=tptr->next)
        {
            if(tptr->productcode==1)
                cout<<"Fruits(Price per Kilograms):"<<endl;
            else if(tptr->productcode==4)
                cout<<endl<<"Vegetables(Price per Kilograms):"<<endl;
            else if(tptr->productcode==7)
                cout<<endl<<"Other food Items(nos/kg):"<<endl;
            else if(tptr->productcode==9)
                cout<<endl<<"Baverages:"<<endl;
            else if(tptr->productcode==13)
                cout<<endl<<"Dog Foods and Snacks:"<<endl;
            else if(tptr->productcode==15)
                cout<<endl<<"Sanitary Items:"<<endl;
            cout<<tptr->prod<<"\t\t"<<tptr->price<<"\t"<<tptr->productcode<<"\n";
        }
    }
  /*  void dispitems(string Items,int quantity)
    {
    for(Node * tptr=head;tptr!=NULL;tptr=tptr->next)
        if(Items==tptr->prod)
        {
            cout<<tptr->prod<<"\t"<<tptr->price*quantity<<"\n";
        }
    }*/

    void inventory()
    {
    Node * newnode = new Node("Apple",150.0,1);
    createlinkedlist(newnode);
    Node * newnode2 = new Node("Orange",80.0,2);
    createlinkedlist(newnode2);
    Node * newnode3 = new Node("Kiwi",26,3);
    createlinkedlist(newnode3);
    Node * newnode4 = new Node("potato",50,4);
    createlinkedlist(newnode4);
    Node * newnode5 = new Node("Tomoto",120,5);
    createlinkedlist(newnode5);
    Node * newnode6 = new Node("Chilli",10,6);
    createlinkedlist(newnode6);
    Node * newnode7 = new Node("Eggs",8,7);
    createlinkedlist(newnode7);
    Node * newnode8 = new Node("Meat",500,8);
    createlinkedlist(newnode8);
    Node * newnode9 = new Node("Frooti",40,9);
    createlinkedlist(newnode9);
    Node * newnode10 = new Node("Redbull",40,10);
    createlinkedlist(newnode10);
    Node * newnode11 = new Node("Monster",40,11);
    createlinkedlist(newnode11);
    Node * newnode12 = new Node("Appyfiz",40,12);
    createlinkedlist(newnode12);
    Node * newnode13 = new Node("Pedegre",120,13);
    createlinkedlist(newnode13);
    Node * newnode14 = new Node("Candy",10,14);
    createlinkedlist(newnode14);
    Node * newnode15 = new Node("Soap",20,15);
    createlinkedlist(newnode15);
    Node * newnode16 = new Node("Shampoo",40,16);
    createlinkedlist(newnode16);
    Node * newnode17 = new Node("Wipes",30,17);
    createlinkedlist(newnode17);
    Node * newnode18 = new Node("Napkins",80,18);
    createlinkedlist(newnode18);
    }
};
/* INVENTORY LINKEDLIST ENDS HERE */



int main()
{
   linkedlist ll;
   SelectedItems s1;
        cout << "-------------------------------------" << endl;
        cout << "        Welcome To Techno Mart       " << endl;
        cout << "-------------------------------------" << endl;
    /*  cout << "       Please Enter Your Name        " << endl;
        string Name;
        cin  >> Name;
        cout << "Welcome "<<Name<<"!"<<endl;*/
        linked Usr;
        Usr.inv();
        Usr.userverify();
        cout << "-------------------------------------" << endl;
        cout << "Please Find the list of Items Below"<< "\n"<<endl;
       // cout << "-------------------------------------" << endl;
        cout << "-----------Available Items-----------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Product"<<"\t\t"<<"Price" <<"\t"<< "Product code"<< endl;
        cout << "-------------------------------------" << endl;
        ll.inventory();
        ll.display();
        cout << "-------------------------------------" << endl;
cout<<"Do you wish to continue"<<"\n"<<"(Enter Y for Yes/N for No)";
char choice;
while(choice!='Y' && choice!='N')
{
    cin>> choice;
    if(choice!='Y' && choice!='N')
    cout<<"Enter a valid choice"<<endl;
}

if(choice=='Y')
{
    cout << "-------------------------------------" << endl;
    cout<<"Enter the Product Code one at a time:"<< endl;
    int Items;
    int quantity;
    while(1)
    {
        int flag=0;
        cin>>Items;
        if(Items==0)
            break;
        Node *tr;
        for(tr=ll.head;tr!=NULL;tr=tr->next)
           {
               if(tr->productcode==Items)
               {
                   flag=1;
                   break;
               }
           }
        if(flag==1)
        {
        cout<<"Enter the Quantity required:"<< endl;
        cin>>quantity;
        cout<<"To add more, Enter the next Product's code or Enter 0 to checkout"<<endl;
        SN * gnn = new SN(tr->prod,quantity);
        gnn->subtotal=tr->price;
        s1.createSlinkedlist(gnn);
        }
        else
        {
            cout<<"Please Enter A Valid Product code"<<"\n";
            cout<<"To add more, Enter the next Item or press END"<<endl;
        }
    }
        s1.displays();
}

else if(choice=='N')
{
    cout << "-------------------------------------" << endl;
    cout<<"\tThank You For Visiting!!"<<endl;
    cout<<"\t  Hope You Come Again!!"<<endl;
    cout << "-------------------------------------" << endl;
}
else
    cout<<"The Choice Is Invalid";
}
