#include<iostream>
#include<vector>
#include<map>
using namespace std;

class ride{
    public:
    int taxi;
    int booking_id;
    int customer_id;
    char pickup_point;
    char drop_point;
    int pickup_time;
    int drop_time;
    int amount;
};

class taxi{
    public:
    int id;
    int earnings;
    char current_spot;
    int free_time;
    vector<ride> rides;

    taxi(char current_spot, int free_time,int id){
        this->current_spot=current_spot;
        this->free_time=free_time;
        this->earnings=0;
        this->id=id;
    }
    taxi() {
        this->id=1;
        this->earnings = 0;
        this->current_spot = 'A'; // default spot
        this->free_time = 9; // default free time
    }
};

class book{
public:
void show_choices(){
    cout<<"Choose Your Choice(With the keys)"<<endl;
    cout<<"KEY"<<"    "<<"CHOICE"<<endl;
    cout<<" "<<"1."<<"    "<<"Book Taxi"<<endl;
    cout<<" "<<"2."<<"    "<<"Print taxi details"<<endl;
    cout<<" "<<"0."<<"    "<<"Exit"<<endl;
}

void distance_finder(ride &temp){
    int dis=abs(temp.pickup_point-temp.drop_point);
    int kms=dis*15-15;//as we calculated already for first 15 kms i.e 200
    int travel_time=dis*1;
    temp.drop_time=temp.pickup_time+travel_time;
    temp.amount=200+kms*10;

}

int allot_taxi(ride temp,map<int,taxi> taxi_map){
    int lowest_dist=INT_MAX;
    int low_taxi_id=-1;
    for(int i=1;i<=taxi_map.size();i++){
            if(taxi_map[i].free_time>temp.pickup_time)continue;
       // lowest_dist=min(lowest_dist,abs(temp.pickup_point-taxi_map[i].current_spot);
        if(lowest_dist>(abs(temp.pickup_point-taxi_map[i].current_spot))){
            lowest_dist=abs(temp.pickup_point-taxi_map[i].current_spot);
           low_taxi_id=taxi_map[i].id;
            }
        else if(lowest_dist==(abs(temp.pickup_point-taxi_map[i].current_spot))){
            low_taxi_id= taxi_map[low_taxi_id].earnings > taxi_map[i].earnings ?  taxi_map[i].id : low_taxi_id;
                }
        else{
            continue;
        }

    }
    return low_taxi_id;
}

void book_taxi(int &id_tracker,vector<ride> &rides_vector,map<int,taxi> &taxi_map){

    char pickup_point;
    char drop_point;
    int pickup_time;
    cout<<"Enter pickup point: ";
    cin>>pickup_point;
    cout<<"Enter dropping point: ";
    cin>>drop_point;
    cout<<"Enter pickup time: ";
    cin>>pickup_time;
    if(pickup_point==drop_point){
        cout<<"Drop location cannot be the pickup location"<<endl;
        return;
    }
    ride temp;
    temp.booking_id=id_tracker;
    temp.customer_id=id_tracker++;
    temp.pickup_point=pickup_point;
    temp.drop_point=drop_point;
    temp.pickup_time=pickup_time;

    distance_finder(temp);
    int taxi_id=allot_taxi(temp,taxi_map);
    if(taxi_id==-1){
        cout<<"No taxi is available at the moment"<<endl;
        return;
    }
    cout<<"Taxi "<<taxi_id<<" is booked";
    taxi_map[taxi_id].free_time=temp.drop_time;
    taxi_map[taxi_id].current_spot=temp.drop_point;
    taxi_map[taxi_id].earnings+=temp.amount;
    temp.taxi=taxi_id;
    taxi_map[taxi_id].rides.push_back(temp);
    rides_vector.push_back(temp);
}
void taxi_details(map<int,taxi> taxi_map,vector<ride> rides_vector){
    for(int i=1;i<=taxi_map.size();i++){
        cout<<"Taxi "<<taxi_map[i].id<<"  "<<"Total Earnings - "<<taxi_map[i].earnings<<"    "<<"Current spot - "<<taxi_map[i].current_spot<<"   "<<"Free time - "<<taxi_map[i].free_time<<endl;
    }
    cout<<"RIDE DETAILS:"<<endl;
    for(auto taxi_s : taxi_map){
        cout<<"Taxi "<<taxi_s.second.id<<":"<<endl;
        cout<<"Taxi Id"<<"      "<<"Booking Id"<<"      "<<"Customer Id"<<"          "<<"From"<<"          "<<"To"<<"      "<<"PickupTime"<<"      "<<"DropTime"<<"        "<<"Amount"<<endl;
        for(auto taxi_ride : taxi_s.second.rides){
            cout<<"     "<<taxi_ride.taxi<<"             "<<taxi_ride.booking_id<<"               "<<taxi_ride.customer_id<<"              "<<taxi_ride.pickup_point<<"             "<<taxi_ride.drop_point<<"           "<<taxi_ride.pickup_time<<"             "<<taxi_ride.drop_time<<"            "<<taxi_ride.amount<<endl;
        }
    }
}
};
int main(){
    book taxis;
    int id_tracker=1;
    vector<ride> rides_vector;
    map<int,taxi> taxi_map;
    taxi taxi_1('A',9,1);
    taxi taxi_2('A',9,2);
    taxi taxi_3('A',9,3);
    taxi taxi_4('A',9,4);
    taxi_map[1]=(taxi_1);
    taxi_map[2]=(taxi_2);
    taxi_map[3]=(taxi_3);
    taxi_map[4]=(taxi_4);
    cout << "---------------------------------------------" << endl;
    cout << "     WELCOME TO BLACK TAXI BOOKING PORTAL    " << endl;
    cout << "---------------------------------------------" << endl;
    while(1){
        taxis.show_choices();
        int choice;
        cin>>choice;
        if(choice==1){
            taxis.book_taxi(id_tracker,rides_vector,taxi_map);
        }//book taxi
        else if(choice==2){
            taxis.taxi_details(taxi_map,rides_vector);
        }//Print taxi details
        else if(choice==0){
            break;
        }
        cout << "---------------------------------------------" << endl;
    }
}
