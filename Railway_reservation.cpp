#include<iostream>
#include<map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class ticket{
    public:
    int id;
    string name;
    int age;
    string status;
    ticket(string name,int age,int id){
    this->name=name;
    this->age=age;
    this->id=id;
    }
};




class Booking{
public:
    map<char,int> available_map;
    void tickets(vector<int> admin_panel_tickets){
     available_map['L']=admin_panel_tickets[0];//LOWER
     available_map['M']=admin_panel_tickets[1];//UPPER
     available_map['U']=admin_panel_tickets[2];//MIDDLE
     available_map['R']=admin_panel_tickets[3];//RAC
     available_map['W']=admin_panel_tickets[4];//WAITING LIST
    }
    void show_available_tickets(){
    cout<<" AVAILABLE TICKETS"<<endl;
    cout<<"Available lower births"<<"       "<<available_map['L']<<endl;
    cout<<"Available upper births"<<"       "<<available_map['U']<<endl;
    cout<<"Available middle births"<<"       "<<available_map['M']<<endl;
    cout<<"Available RAC Tickets"<<"       "<<available_map['R']<<endl;
    cout<<"Available waiting limit"<<"       "<<available_map['W']<<endl;

    }

    void book_ticket(vector<ticket> &booked_tickets,vector<ticket> &RAC,vector<ticket> &Waiting_list,int &id_tracker,vector<int>admin_panel_tickets){
        if(available_map['L']+available_map['U']+available_map['M']+available_map['R']+available_map['W']==0){
            cout<<"No tickets available for this train"<<endl;
            return;
        }
        int id=++id_tracker;
        string name;
        int age;
        char preference;
        cout<<"Enter Passenger name: ";
        cin>>name;
        cout<<"Enter passenger age: ";
        cin>>age;
        while(1){
        cout<<"Enter Birth Preference (L/M/U): ";
        cin>>preference;
        if(preference=='L' || preference=='M' || preference=='U'){
            break;
        }
        else{
            cout<<"Please enter a valid preference"<<endl;
        }
        }


    ticket temp(name,age,id);


        if(available_map['U'] + available_map['M'] + available_map['L']>0){
            string status=asign_berth(preference,admin_panel_tickets);
            temp.status=status;
            booked_tickets.push_back(temp);
        }
        else{
            string status=asign_berth(preference,admin_panel_tickets);
            temp.status=status;
            if(status[0]=='R'){
                RAC.push_back(temp);
            }
            else{
                Waiting_list.push_back(temp);
            }
        }
        cout << "---------------------------------------------" << endl;
        cout<<"TICKET BOOKED SUCCESSFULLY"<<endl;
        cout<<"Your Ticket Id: "<<temp.id<<endl;
        cout<<"Your booking status: "<<temp.status<<endl;
        cout << "---------------------------------------------" << endl;

    }


    string asign_berth(char preference,vector<int> admin_panel_tickets){
        if(available_map['U'] + available_map['M'] + available_map['L']<=0){
            if(available_map['R']>0){
                available_map['R']--;
                return "RAC"+to_string(admin_panel_tickets[3]-available_map['R']);
            }
            else if(available_map['R']<=0){
                available_map['W']--;
                return "WL"+to_string(admin_panel_tickets[4]-available_map['W']);
            }
        }
        else{
            if(available_map[preference]>0){
            available_map[preference]--;
            if(preference=='U'){
                return preference+to_string(admin_panel_tickets[2]-available_map[preference]);
            }
            else if(preference=='M'){
                return preference+to_string(admin_panel_tickets[1]-available_map[preference]);
            }
            else if(preference=='L'){
                return preference+to_string(admin_panel_tickets[0]-available_map[preference]);
            }

            }
            else if(preference=='L'){
                if(available_map['M']>0){
                available_map['M']--;
                return 'M'+to_string(admin_panel_tickets[1]-available_map['M']);
                }
                else if(available_map['U']>0){
                available_map['U']--;
                return 'U'+to_string(admin_panel_tickets[2]-available_map['U']);
                }
            }
            else if(preference=='M'){
                if(available_map['L']>0){
                available_map['L']--;
                return 'L'+to_string(admin_panel_tickets[0]-available_map['L']);
                }
                else if(available_map['U']>0){
                available_map['U']--;
                return 'U'+to_string(admin_panel_tickets[2]-available_map['U']);
                }
            }
            else if((preference=='U')){
                if(available_map['M']>0){
                available_map['M']--;
                return 'M'+to_string(admin_panel_tickets[1]-available_map['M']);
                }
                else if(available_map['L']>0){
                available_map['L']--;
                return 'L'+to_string(admin_panel_tickets[0]-available_map['L']);
                }
            }
        }

    }

    void show_booked_tickets(vector<ticket> &booked_tickets){
        for(auto TICKET:booked_tickets){
            cout<<"Passenger ID:"<<TICKET.id<<endl;
            cout<<"Passenger: "<<TICKET.name<<endl;
            cout<<"Age: " <<TICKET.age<<endl;
            cout<<"Birth status: "<<TICKET.status<<endl;

        }
    }

        void show_RAC_tickets(vector<ticket> &RAC){
        for(auto TICKET:RAC){
            cout<<"Passenger ID:"<<TICKET.id<<endl;
            cout<<"Passenger: "<<TICKET.name<<endl;
            cout<<"Age: " <<TICKET.age<<endl;
            cout<<"Birth status: "<<TICKET.status<<endl;

        }
    }

        void show_Waiting_list(vector<ticket> &Waiting_list){
        for(auto TICKET:Waiting_list){
            cout<<"Passenger ID:"<<TICKET.id<<endl;
            cout<<"Passenger: "<<TICKET.name<<endl;
            cout<<"Age: " <<TICKET.age<<endl;
            cout<<"Birth status: "<<TICKET.status<<endl;

        }
    }

    bool comp(const ticket& TICKET, int target_id) {
    return TICKET.id == target_id;
}



void push_waitlist(int index,vector<ticket> &booked_tickets,vector<ticket> &RAC,vector<ticket> &Waiting_list,vector<int> admin_panel_tickets){
    if(RAC.size()>0){
            string stts=booked_tickets[index].status;
        RAC[0].status=stts;
        booked_tickets.erase(booked_tickets.begin() + index);
        booked_tickets.push_back(RAC[0]);
        RAC.erase(RAC.begin());
        if(Waiting_list.size()>0){
            RAC.push_back(Waiting_list[0]);
            Waiting_list.erase(Waiting_list.begin());
        }
        int counter=1;
        for(auto &Rac: RAC){
            Rac.status="RAC"+to_string(counter++);
        }
        counter=1;
        for(auto &Wl : Waiting_list){
            Wl.status="WL" +to_string(counter++);
        }
    }
    else{
        if(booked_tickets[index].status[0]=='L'){
            available_map['L']++;
        }
        else if(booked_tickets[index].status[0]=='M'){
            available_map['M']++;
        }
        else if(booked_tickets[index].status[0]=='U'){
            available_map['U']++;
        }
        booked_tickets.erase(booked_tickets.begin() + index);
    }
    available_map['R']=admin_panel_tickets[3]-RAC.size();
    available_map['W']=admin_panel_tickets[4]-Waiting_list.size();
}
void cancel_ticket(int id,vector<ticket> &booked_tickets,vector<ticket> &RAC,vector<ticket> &Waiting_list,vector<int> admin_panel_tickets){
    auto index=find_if(booked_tickets.begin(),booked_tickets.end(),[&](const ticket& TICKET){return comp(TICKET, id);});
    if(index!=booked_tickets.end()){
            int idx=distance(booked_tickets.begin(),index);
        push_waitlist(idx,booked_tickets,RAC,Waiting_list,admin_panel_tickets);
        cout<<"Ticket cancelled successfully"<<endl;

    }
    else{
        cout<<"Id does not exist"<<endl;
    }
}


void admin_panel(vector<int> &admin_panel_tickets){

    cout << "---------------------------------------------" << endl;
    cout << "         WELCOME TO IRCTC ADMIN PANEL        " << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Enter the number of tickets to be made available for booking:"<<endl;
    cout << "Lower berth: ";
    int temp;
    cin >>temp;
    admin_panel_tickets.push_back(temp);
    cout << "Middle berth: ";
    cin >>temp;
    admin_panel_tickets.push_back(temp);
    cout << "Upper berth: ";
    cin >>temp;
    admin_panel_tickets.push_back(temp);
    cout << "RAC: ";
    cin >>temp;
    admin_panel_tickets.push_back(temp);
    cout << "Waiting List: ";
    cin >>temp;
    admin_panel_tickets.push_back(temp);

}
};




void show_choices(){
    cout<<"Choose Your Choice(With the keys)"<<endl;
    cout<<"KEY"<<"    "<<"CHOICE"<<endl;
    cout<<" "<<"1."<<"    "<<"Book Ticket"<<endl;
    cout<<" "<<"2."<<"    "<<"Cancel Ticket"<<endl;
    cout<<" "<<"3."<<"    "<<"Available Tickets"<<endl;
    cout<<" "<<"4."<<"    "<<"Booked Ticket"<<endl;
    cout<<" "<<"5."<<"    "<<"Exit"<<endl;
}

int choices(){
show_choices();
int choice;
cin>>choice;
if(choice>0 && choice <6){
return choice;
}

cout<<"Please Enter a valid Choice"<<endl;
choices();

}





int main(){
    Booking booking;
    vector<ticket> booked_tickets;
    vector<ticket> RAC;
    vector<ticket> Waiting_list;
    vector<int> admin_panel_tickets;
    booking.admin_panel(admin_panel_tickets);

    int id_tracker=0;
    cout << "---------------------------------------------" << endl;
    cout << "    WELCOME TO IRCTC ONLINE BOOKING PORTAL   " << endl;
    cout << "---------------------------------------------" << endl;
    booking.tickets(admin_panel_tickets);
    while(1){
        int choice=choices();
        if(choice==5){
            cout<<"THANK YOU FOR REACHING OUT TO US"<<endl;
            break;
        }
        else if(choice==3){
            booking.show_available_tickets();
            cout<<"Do you wish to continue(Y/N):";
            char c;//choice;
            cin>>c;
            if(c=='N'){
                break;
            }
            else if(c=='Y'){
                continue;
            }
            else{
                cout<<endl<<"You entered an invalid choice. Navigating to main menu..."<<endl;
            }
        }
        else if(choice==1){
            booking.book_ticket(booked_tickets,RAC,Waiting_list,id_tracker,admin_panel_tickets);
            cout<<"Do you wish to continue(Y/N):";
            char c;//choice;
            cin>>c;
            if(c=='N'){
                break;
            }
            else if(c=='Y'){
                continue;
            }
            else{
                cout<<endl<<"You entered an invalid choice. Navigating to main menu..."<<endl;
            }
        }
        else if (choice==2){
            cout<<"Enter your ticket Id: "<<endl;
            int id;
            cin>>id;
            booking.cancel_ticket(id,booked_tickets,RAC,Waiting_list,admin_panel_tickets);
        }
        else if(choice==4){
                if(booked_tickets.size()+RAC.size()+Waiting_list.size()==0){
                    cout<<"There is no tickets booked yet!"<<endl;
                }
            booking.show_booked_tickets(booked_tickets);
            booking.show_RAC_tickets(RAC);
            booking.show_Waiting_list(Waiting_list);

        }
            cout << "---------------------------------------------" << endl;

    }

}
