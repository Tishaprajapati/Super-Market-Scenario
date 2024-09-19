#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h> 
using namespace std;
long INVENTORY_DATASET[100][4] = {
{111100000001,1,100,20},{111100000002,2,110,20},{111100000003,3,120,20},{111100000004,4,130,20},{111100000005,5,140,20},{111100000006,6,150,20},{111100000007,7,160,20},{111100000008,8,170,20},{111100000009,9,180,20},{111100000010,10,190,20},
{111100000011,11,200,20},{111100000012,12,210,20},{111100000013,13,220,20},{111100000014,14,230,20},{111100000015,15,240,20},{111100000016,16,250,20},{111100000017,17,260,20},{111100000018,18,270,20},{111100000019,19,280,20},{111100000020,20,290,20},
{111100000021,21,300,20},{111100000022,22,310,20},{111100000023,23,320,20},{111100000024,24,330,20},{111100000025,25,340,20},{111100000026,26,350,20},{111100000027,27,360,20},{111100000028,28,370,20},{111100000029,29,380,20},{111100000030,30,390,20},
{111100000031,31,400,20},{111100000032,32,410,20},{111100000033,33,420,20},{111100000034,34,430,20},{111100000035,35,440,20},{111100000036,36,450,20},{111100000037,37,460,20},{111100000038,38,470,20},{111100000039,39,480,20},{111100000040,40,490,20},
{111100000041,41,500,20},{111100000042,42,510,20},{111100000043,43,520,20},{111100000044,44,530,20},{111100000045,45,540,20},{111100000046,46,550,20},{111100000047,47,560,20},{111100000048,48,570,20},{111100000049,49,580,20},{222200001111,50,590,20},
{222200001114,51,600,20},{222200001117,52,610,20},{222200001120,53,620,20},{222200001123,54,630,20},{222200001126,55,640,20},{222200001129,56,650,20},{222200001132,57,660,20},{222200001135,58,670,20},{222200001138,59,680,20},{222200001141,60,690,20},
{222200001144,61,700,20},{222200001147,62,710,20},{222200001150,63,720,20},{222200001153,64,730,20},{222200001156,65,740,20},{222200001159,66,750,20},{222200001162,67,760,20},{222200001165,68,770,20},{222200001168,69,780,20},{222200001171,70,790,20},
{222200001174,71,800,20},{222200001177,72,810,20},{222200001180,73,820,20},{222200001183,74,830,20},{222200001186,75,840,20},{222200001189,76,850,20},{222200001192,77,860,20},{222200001195,78,870,20},{222200001198,79,880,20},{222200001201,80,890,20},
{222200001204,81,900,20},{222200001207,82,910,20},{222200001210,83,920,20},{222200001213,84,930,20},{222200001216,85,940,20},{222200001219,86,950,20},{222200001222,87,960,20},{222200001225,88,970,20},{222200001228,89,980,20},{222200001231,90,990,20},
{222200001234,91,1000,20},{222200001237,92,1010,20},{222200001240,93,1020,20},{222200001243,94,1030,20},{222200001246,95,1040,20},{222200001249,96,1050,20},{222200001252,97,1060,20},{222200001255,98,1070,20},{222200001258,99,1080,20},{222200001261,100,1090,20},
};
long CUSTOMER_DATASET[100][3] = {
{9400000001,1,0},{9400000002,2,0},{9400000003,3,0},{9400000004,4,0},{9400000005,5,0},{9400000006,6,0},{9400000007,7,0},{9400000008,8,0},{9400000009,9,0},{9400000010,10,0},
{9400000011,11,0},{9400000012,12,0},{9400000013,13,0},{9400000014,14,0},{9400000015,15,0},{9400000016,16,0},{9400000017,17,0},{9400000018,18,0},{9400000019,19,0},{9400000020,20,0},
{9400000021,21,0},{9400000022,22,0},{9400000023,23,0},{9400000024,24,0},{9400000025,25,0},{9400000026,26,0},{9400000027,27,0},{9400000028,28,0},{9400000029,29,0},{9400000030,30,0},
{9400000031,31,0},{9400000032,32,0},{9400000033,33,0},{9400000034,34,0},{9400000035,35,0},{9400000036,36,0},{9400000037,37,0},{9400000038,38,0},{9400000039,39,0},{9400000040,40,0},
{9400000041,41,0},{9400000042,42,0},{9400000043,43,0},{9400000044,44,0},{9400000045,45,0},{9400000046,46,0},{9400000047,47,0},{9400000048,48,0},{9400000049,49,0},{9400000050,50,0},
{9400000051,51,0},{9400000052,52,0},{9400000053,53,0},{9400000054,54,0},{9400000055,55,0},{9400000056,56,0},{9400000057,57,0},{9400000058,58,0},{9400000059,59,0},{9400000060,60,0},
{9400000061,61,0},{9400000062,62,0},{9400000063,63,0},{9400000064,64,0},{9400000065,65,0},{9400000066,66,0},{9400000067,67,0},{9400000068,68,0},{9400000069,69,0},{9400000070,70,0},
{9400000071,71,0},{9400000072,72,0},{9400000073,73,0},{9400000074,74,0},{9400000075,75,0},{9400000076,76,0},{9400000077,77,0},{9400000078,78,0},{9400000079,79,0},{9400000080,80,0},
{9400000081,81,0},{9400000082,82,0},{9400000083,83,0},{9400000084,84,0},{9400000085,85,0},{9400000086,86,0},{9400000087,87,0},{9400000088,88,0},{9400000089,89,0},{9400000090,90,0},
{9400000091,91,0},{9400000092,92,0},{9400000093,93,0},{9400000094,94,0},{9400000095,95,0},{9400000096,96,0},{9400000097,97,0},{9400000098,98,0},{9400000099,99,0},{9400000100,100,0},
};
struct item
{
    long item_id;
    string name;
    float rate;
    short quantity;
    item *next=NULL;
}; item* hash_item[13];

struct item_1
{
    long item_1_id;
    string name_1;
    float rate_1;
    int quantity_1;
    float amount;
    item_1 *next=NULL;
}*head = NULL,*curt = NULL;

struct custm
{
    long customer_id;
    string cust_name;
    float points;
    custm *next=NULL;
}; custm* hash_cust[13]={NULL};

//*********************************************************************//
//*********************************************************************//

class Inventory
{
private:
    item* newitem = new item;
public:
    
    void Add_item(long item_id,string name,float rate,short quantity)
    {
        int index=0;
        item* newitem=new item;
        newitem->item_id=item_id;
        newitem->name=name;
        newitem->rate=rate;
        newitem->quantity=quantity;
        item *prev, *current, *ptr;
        index=item_id%13;
        if(hash_item[index] == NULL)
        {
            hash_item[index] = newitem;
            newitem->next = NULL;
            current = newitem;
        }
        else
        {
            prev = hash_item[index];
            if(prev->item_id > item_id && prev == hash_item[index])
            {
                ptr = hash_item[index];
                hash_item[index] = newitem;
                newitem->next = ptr;
            }
            else
            {

                while(prev->next != NULL)
                {
                   current = prev->next;
                    if(prev->item_id < item_id && current->item_id > item_id)
                    {
                        prev->next = newitem;
                        newitem->next = current;
                        break;
                    }
                    prev = prev->next;
                }
                if(prev->next == NULL && prev->item_id < item_id)
                {
                    prev->next = newitem;
                    newitem->next = NULL;
                }
            }
        }
    }

    void Delete_item(long item_id)
    {
        int index=item_id%13;
        item *ptr;
        int flag=0;
        ptr=hash_item[index];
        if(ptr->item_id == item_id)
        {
            hash_item[index]= ptr->next;
            flag = 1;
            delete(ptr);
        }
        else
        {
            item *prev;
            prev =hash_item[index];
            ptr = ptr->next;
            while(ptr->next != NULL)
            {
                if(ptr->item_id == item_id)
                {
                    prev->next = ptr->next;
                    flag = 1;
                    delete(ptr);
                    cout<<"Item deletion complete"<<endl;
                }
                ptr = ptr->next;
                prev= prev->next;
            }
       }
        if(flag==0)
        cout<<"Not Found"<<endl;
    }
    
    void Update_item(long item_id)
    {
        int index=item_id%13;
        item *ptr;
        int flag=0;
        short quantity;
        float rate;
        for(ptr = hash_item[index];ptr != NULL;ptr = ptr->next)
        {
            if(ptr->item_id == item_id)
            {
                cout<<"Enter Quantity"<<endl;
                cin>>quantity;
                ptr->quantity = quantity;
                cout<<"Enter rate"<<endl;
                cin>>rate;
                ptr->rate = rate;
                flag = 1;
                cout<<"Item update complete.."<<endl;
                break;
            }
        }
        if(flag==0)
            cout<<"Not Found"<<endl; 
    }
    
    void update_stock(long item_id,short quantity)
    {
        int index=item_id%13;
        item *ptr;
        int flag=0;
        for(ptr = hash_item[index];ptr != NULL;ptr = ptr->next)
        {
            if(ptr->item_id == item_id)
            {
                ptr->quantity = ptr->quantity - quantity;
                flag = 1;
                break;
            }
        }
        if(flag==0)
            cout<<"Not Found"<<endl;
        }
    
    void Get_Product_Info(long item_id)
    {
        cout<<"Inventory Data: "<<endl;
        int index=item_id%13;
        item* ptr=new item;
        int flag = 0;
    for(ptr = hash_item[index];ptr != NULL;ptr = ptr->next)
    {
        if(ptr->item_id == item_id)
        {
            cout<<"ID         :  "<<ptr->item_id<<endl;
            cout<<"name       :  "<<ptr->name<<endl;
            cout<<"Quantity   :  "<<ptr->quantity<<endl;
            cout<<"Rate       :  "<<ptr->rate<<endl<<endl;
            flag = 1;
            break;
        }
    }
    if(flag==0)
        cout<<"Not Found"<<endl<<endl;
    }

};

//*********************************************************************//
//*********************************************************************//

class Customer
{
public:
    void add_customer(long customer_id,string cust_name,float points)
    {
        int index=0;
        custm* newcust=new custm;
        newcust->customer_id=customer_id;
        newcust->cust_name=cust_name;
        newcust->points=points;
        custm *prev, *current, *ptr;
        index = customer_id%13;
        
        if(hash_cust[index] == NULL)
        {
            hash_cust[index] = newcust;
            newcust->next = NULL;
            current = newcust;
        }
        else
        {
            prev = hash_cust[index];
            if(prev->customer_id > customer_id && prev == hash_cust[index])
            {
                ptr = hash_cust[index];
                hash_cust[index] = newcust;
                newcust->next = ptr;
            }
            else
            {
                while(prev->next != NULL)
                {
                    current = prev->next;
                    if(prev->customer_id < customer_id && current->customer_id > customer_id)
                    {
                        prev->next = newcust;
                        newcust->next = current;
                        break;
                    }
                    prev = prev->next;
                }
                
                if(prev->next == NULL && prev->customer_id < customer_id)
                {
                    prev->next = newcust;
                    newcust->next = NULL;
                }
           }
        }
    }
    
    void Customer_Info(long customer_id)
    {
        custm *ptr;
        int index=customer_id%13;
        int flag = 0;
        cout<<"Customer Information: "<<endl;
        for(ptr = hash_cust[index];ptr != NULL;ptr = ptr->next)
        {
        if(ptr->customer_id == customer_id){
            cout<<"Customer ID  : "<<ptr->customer_id<<endl;
            cout<<"Name         : "<<ptr->cust_name<<endl;
            cout<<"Points       : "<<ptr->points<<endl;
            flag = 1;
            break;
        }
    }
    if(flag==0)
        cout<<"Customer Not Found.."<<endl;
    }
    
    void update_points(long customer_id,float amount)
    {
        int index=customer_id%13;
        custm *ptr;
        int flag=0;
        for(ptr = hash_cust[index];ptr != NULL;ptr = ptr->next)
        {
            if(ptr->customer_id == customer_id)
            {
                ptr->points = amount;
                flag = 1;
                break;
            }
        }
        if(flag==0)
            cout<<"Not Found"<<endl;
        }
};

//*********************************************************************//
//*********************************************************************//

class Billing:public Customer
{
private:
    long transaction_id;
    long customer_id=0;
    
    float total_amount;
public:
Billing()
{
    for(int i=0;i<13;i++)
    hash_cust[i]=NULL;
}
int transacNoGenerator(int limit) 
{ 
    // uniformly-distributed integer random number 
    // generator that produces non-deterministic 
    // random numbers. 
    random_device rd; 

    // A Mersenne Twister pseudo-random generator 
    // of 32-bit numbers with a state size of 
    // 19937 bits. 
    mt19937 gen(rd()); 

    // Uniform distribution 
    uniform_int_distribution<> dis(1, limit); 
    return dis(gen); 
} 
    //Billing b1;
    
//friend void Inventory:: update_stock();
//friend void Inventory::Get_Product_Info(long item_id);

void Cancel_item(Inventory *ii3,long item_id)
{
    item_1 *ptr = head;
    int flag = 0;
    if(ptr->item_1_id == item_id)
    {
        head = ptr->next;
        flag = 1;
        ii3->update_stock(item_id, -ptr->quantity_1);
    }
    else
    {
    item_1 *prev;
    prev = head;
    ptr = ptr->next;
    while(ptr->next != NULL)
    {
        if(ptr->item_1_id == item_id)
        {
            prev->next = ptr->next;
            flag = 1;
            ii3->update_stock(item_id, -ptr->quantity_1);
             cout<<"Item Canceled"<<endl;
        }
        ptr = ptr->next;
        prev = prev->next;
    }
    }
    if(flag==0)
        cout<<"Not Found"<<endl;
}

void assign_customer_Id(long cust_id)
{
    customer_id=cust_id;
}

void make_item_list(Inventory *ii2, long item_id, short quantity)
    {
        int index=0;
        item_1 *newitm_1 = new item_1;
        item *tmp;
        int flag = 0;
        index=item_id%13;
        for(tmp = hash_item[index];tmp != NULL; tmp = tmp->next)
        {
            if(tmp->item_id == item_id)
            {
                newitm_1->item_1_id = tmp->item_id;
                newitm_1->name_1 = tmp->name;
                newitm_1->quantity_1 = quantity;
                newitm_1->rate_1 = tmp->rate;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout<<"Not found"<<endl;
        if(head == NULL)
        {
            head = newitm_1;
            newitm_1->next = NULL;
            curt = newitm_1;
        }
        else
        {
            curt->next = newitm_1;
            newitm_1->next = NULL;
            curt = newitm_1;
        }
    }
    
void Buy_item(Inventory *ii1, long item_id, short quantity)
{
   ii1->update_stock(item_id,quantity);
   make_item_list(ii1,item_id,quantity);
}
    
void make_payment(long customer_id)
{
    float total_amount=0;
    cout<<"Transaction ID : "<<transacNoGenerator(100000000)<<endl;                  
        cout<<"Customer ID    : "<<customer_id<<endl<<endl;
        cout<<"Product ID"<<"\t"<<"Name" <<"\t"<<"Rate"<<"\t"<<"Quantity"<<"\t"<<"Amount"<<endl;
        item_1 *ptr;
        for(ptr = head;ptr!= NULL;ptr = ptr->next)
        {
        cout<<ptr->item_1_id<<"\t"<<ptr->name_1<<"\t"<<ptr->rate_1<<"\t"<<" "<<ptr->quantity_1<<"\t"<<"\t"<<ptr->rate_1 * ptr->quantity_1<<endl;
        total_amount = total_amount + (ptr->rate_1 * ptr->quantity_1);
        }
        cout<<"                                        Total:  "<<total_amount<<endl;
        update_points(customer_id,total_amount);
}
};

//*********************************************************************//
//*********************************************************************//

class Manager:public Inventory
{
public:
    long Id;
    string mname;
    Manager()
    {
        Id = 201901118;      
        mname = "anjali";      
            for(int i=0;i<13;i++)
            {
               hash_item[i]=NULL;
            }
        
    }
};

//*********************************************************************//
//*********************************************************************//

int main() {

    Manager m;
for(int i=0;i<100;i++)
{
    long item_id=INVENTORY_DATASET[i][0];
    string name;
    stringstream ss;
    ss << INVENTORY_DATASET[i][1];
    ss >> name;
    float rate=INVENTORY_DATASET[i][2];
    short quantity=INVENTORY_DATASET[i][3];
    m.Add_item(item_id,name,rate,quantity);
}

    Billing b;
    for(int j=0;j<100;j++)
    {
        long customer_id=CUSTOMER_DATASET[j][0];
        string cust_name;
        stringstream ssc;
        ssc << CUSTOMER_DATASET[j][1];
        ssc >> cust_name;
        float points=CUSTOMER_DATASET[j][2];
        b.add_customer(customer_id,cust_name,points);
    }
    Inventory i1;
   
    b.assign_customer_Id(9400000011);
    b.Buy_item(&i1,111100000011,3);           
    b.Buy_item(&i1,111100000046, 5);           
    b.Buy_item(&i1,222200001225, 1);           
    //b.Cancel_item(&i1,111100000011);        
    b.make_payment(9400000011);                  
    cout<<endl;
    m.Get_Product_Info(111100000011);             
    m.Get_Product_Info(111100000046);             
    m.Get_Product_Info(222200001225);            
    b.Customer_Info(9400000011);  
    
    return 0;
}
