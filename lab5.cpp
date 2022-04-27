#include <bits/stdc++.h>
#include <stdlib.h>
#include <cctype>
using namespace std;

void FIFO(vector<int>requests,int headPosition){

    float counter=0;
    float sum=0;
    float average;
    int currentTrack;
    int distance;
    int head=headPosition;
    for(int i=0;i<requests.size();i++){
            counter++;
            currentTrack=requests[i];
            //calculate distance
            distance=abs(currentTrack-headPosition);
            //increase sum
            sum=sum+distance;
            //current track is now the head
            headPosition=currentTrack;

    }
    cout<<"FIFO\n";
    cout<<"----\n";
    requests.insert(requests.begin(),head);
    for(int i=0;i<requests.size();i++){
        cout<<requests[i];
        if(i == requests.size()-1){
        }else{
             cout<<"->";
        }
    }
    average=sum/counter;
    cout<<"\n";
    cout<<"Total Head Movement : "<<sum;
    cout<<"\n";
    cout<<"Average Head Movement : "<<average;
    cout<<"\n";
    cout<<"----------------------------------\n";

 }

void SCAN_CSCAN(vector<int>requests,int headPosition,int headDirection,int type){
    float counter=0;
    float sum=0;
    float average;
    int currentTrack;
    int distance;
    int head=headPosition;
    vector<int>left,right;
    vector<int>r;
    //divide the request vector to two vectors
    for(int i=0;i<requests.size();i++){
        if(requests[i]<headPosition){
            left.push_back(requests[i]);
        }
        if(requests[i]>headPosition){
            right.push_back(requests[i]);
        }
    }
    //sort the two vectors
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    //if SCAN so reverse left
    if(type==2){
      reverse(left.begin(),left.end());
    }
    //if CSCAN reverse left and right cause CSCAN is circular
    if(type==3 && headDirection==0){
        reverse(left.begin(),left.end());
        reverse(right.begin(),right.end());
    }



    int loop=2;
    while(loop--){
        //0 means decreasing so move left
        if(headDirection==0){
            for(int i=0;i<left.size();i++){
                counter++;
                currentTrack=left[i];
                r.push_back(currentTrack);
                distance=abs(currentTrack-headPosition);
                sum=sum+distance;
                headPosition=currentTrack;

            }
            headDirection=1;
        }
        //1 means increasing so move right
        else if(headDirection==1){
             for(int i=0;i<right.size();i++){
                counter++;
                currentTrack=right[i];
                r.push_back(currentTrack);
                distance=abs(currentTrack-headPosition);
                sum=sum+distance;
                headPosition=currentTrack;

            }
            headDirection=0;
        }
    }
    if(type==2){
    cout<<"SCAN\n";
    cout<<"----\n";
    r.insert(r.begin(),head);
    for(int i=0;i<r.size();i++){
        cout<<r[i];
        if(i == r.size()-1){
        }else{
             cout<<"->";
        }
    }
    }
    if(type==3){
    cout<<"C-SCAN\n";
    cout<<"----\n";
    r.insert(r.begin(),head);
    for(int i=0;i<r.size();i++){
        cout<<r[i];
        if(i == r.size()-1){
        }else{
             cout<<"->";
        }
    }
    }

    average=sum/counter;
    cout<<"\n";
    cout<<"Total Head Movement : "<<sum;
    cout<<"\n";
    cout<<"Average Head Movement : "<<average;
    cout<<"\n";
    cout<<"----------------------------------\n";
}


 int main() {
        int requestNumber;
        int request;
        int headPosition;
        int headDirection;
        int diskSize;
        int type;
        vector<int>requests;
        vector<int>values;
        cout<<"Please Choose Algorithm\n";
        cout<<"1)FIFO\n2)SCAN\n3)C-SCAN\n";
        cin>>type;
        cout<<"Please Enter Size Of Disk :\n";
        cin>>diskSize;
        cout<<"Please Enter Number Of Requests :\n";
        cin>>requestNumber;
        cout<<"Please Enter Requests :\n";

        for(int i=0;i<requestNumber;i++){
              cin>>request;
              requests.push_back(request);
        }

        cout<<"Please Enter Head Position :\n";
        cin>>headPosition;

        //check that the headposition within range of disk size
        if(headPosition>diskSize){
                cout<<"Head Position Exeded Disk Size";
                return 0;
        }
        //check that the requests within range of disk size
        for(int i=0;i<requests.size();i++){
                if(requests[i]>diskSize){
                        cout<<"Request: " <<requests[i] <<" Exeded Disk Size So Removed From Requests\n";
                        values.push_back(requests[i]);
                }
        }
        if(values.size()!=0){
                for(int i=0;i<values.size();i++){
                requests.erase(remove(requests.begin(),requests.end(),values[i]),requests.end());
                }
        }
        if(type==1){
        FIFO(requests,headPosition);
        }
        else if(type==2){
        cout<<"Please Enter Head Direction :\n";
        cin>>headDirection;
        SCAN_CSCAN(requests,headPosition,headDirection,type);
        }
        else if(type==3){
        cout<<"Please Enter Head Direction :\n";
        cin>>headDirection;
        SCAN_CSCAN(requests,headPosition,headDirection,type);
        }
        else{
            cout<<"Please Enter Valid Choise For Algorithm Type ";
        }


        return 0;
}
