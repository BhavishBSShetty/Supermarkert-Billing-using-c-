#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shopping :: menu()
{
    int choice;
    string email;
    string password;
    mnu:
    cout<<"\n\n\t\t_______________________________________________________\n";
    cout<<"\t\t                                                        \n";
    cout<<"\t\t                      Main Menu                         \n";
    cout<<"\t\t                                                        \n";
    cout<<"\t\t_______________________________________________________\n";
    cout<<"\t\t\t\t                                                        \n";
    cout<<"\t\t\t\t|        1)Administrator         |\n";
    cout<<"\t\t\t\t|                                |\n";
    cout<<"\t\t\t\t|        2)Buyer                 |\n";
    cout<<"\t\t\t\t|                                |\n";
    cout<<"\t\t\t\t|        3}Exit                  |\n";
    cout<<"\t\t\t\t|                                |\n\n";
    cout<<"\t\t Please enter your choice :";
    cin>>choice;
    cout<<"\n\n";
    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t Enter Email :";
            cin>>email;
            cout<<"\t\t Enter Password :";
            cin>>password;

            if(email=="abc@gmail.com" && password=="abc@123"){
                administrator();
            }
            else{
                cout<<"Invalid email/password";
            }
            break;
        
        case 2:
            {
                buyer();
            }
        
        case 3:{
            exit(0);
        }

        default:
            cout<<"\nPlease enter a valid choice\n";
    }

    goto mnu;
}

void shopping::administrator(){
    mnu:
    int choice;
    cout<<"\n\n\n\t\t\t\t Administrator menu\n";
    cout<<"\n\t\t\t|______1)Add the product______|";
    cout<<"\n\t\t\t|                             |";
    cout<<"\n\t\t\t|______2)Modify the product___|";
    cout<<"\n\t\t\t|                             |";
    cout<<"\n\t\t\t|______3)Delete the product___|";
    cout<<"\n\t\t\t|                             |";
    cout<<"\n\t\t\t|______4)Back to menu_________|";

    cout<<"\n\t\t Please enter your choice :";
    cin>>choice;

  
    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Invalid choice!";
    }
    goto mnu;

}


void shopping :: buyer(){
    mnu:
    int choice;
    cout<<"\t\t\t Buyer \n";
    cout<<"\t\t\t________\n";
    cout<<"                      \n";
    cout<<"\t\t\t 1)Buy Product \n";
    cout<<"                      \n";
    cout<<"\t\t\t 2)Go Back \n";
    cout<<"                      \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
        
        default:
            cout<<"Invalid Choice\n";

    }

    goto mnu;
}


void shopping :: add(){
    mnu:
    fstream data;
    int c;
    int token=0;
    float p;float d;
    string n;

    cout<<"\n\n\t\t\t Add new Products" ;
    cout<<"\n\n\t Product code of the product : ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product :";
    cin>>pname;
    cout<<"\n\n\t Price of the product : ";
    cin>>price;
    cout<<"\n\n\t Discount on the product : ";
    cin>>dis;
    

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    

    if(token==1){
        cout<<"\t\t\t This product code already exists\n";
        goto mnu;
    }
    else{
         data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }

   } 
    cout<<"\n\n\t\t\t Record inserted !";

}

void shopping :: edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\tModify the Products " ;
    cout<<"\n\n\t Product code of the product :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n File doesn't exist!";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\n\t New Product code of the product : ";
                cin>>c;
                cout<<"\n\n\t Name of the product : ";
                cin>>n;
                cout<<"\n\n\t Price of the product : ";
                cin>>p;
                cout<<"\n\n\t Discount on the product : ";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t\tRecord Edited!";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found !";
        }
    }
}

void shopping :: rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Code of product to be deleted : ";
    cin>>pkey;
    data.open("database.txt",ios::in);

    if(!data){
        cout<<"File doesnot exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
         data>>pcode>>pname>>price>>dis;

         while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted !";
                token++;
            }
            else{
                 data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
             data>>pcode>>pname>>price>>dis;
         }
         data.close();
         data1.close();
         remove("database.txt");
         rename("database1.txt","database.txt");

         if(token==0){
            cout<<"\n\nRecord not found";
         }
    }
}


void shopping:: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_________________________________________________";
    cout<<"Product No\t\tName\t\tPrice\n";
    cout<<"\n_________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
         cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
         data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float total=0;
    float dis=0;

    cout<<"\n\n\t\t\t\t RECEIPT";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n File doesn't exist!";
    }
    else{

        data.close();
        list();
        cout<<"\n_________________________________________________\n";
        cout<<"\n            Please place the order               \n";
        cout<<"\n_________________________________________________\n";
        
        do{
            m:
            cout<<"\n\nEnter product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter product quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\nDuplicate product code.Please try again!";
                    goto m;
                }
            }
                c++;
                cout<<"\n\n Do you want to buy another product? If YES the type 'y' else 'n'";
                cin>>choice;
            
        }while(choice == 'y');

        cout<<"\n\n______________________________________RECEIPT____________________________________________\n\n";
        cout<<"Product No\tProduct Name\tQuantity\tPrice\tAmount\tDiscount\n";
        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
            }
            
        }
        cout<<"\n\n_________________________________________________________________________";
        cout<<"\n Total Amount : "<<total<<"\n\n";
    
}

int main(){
    shopping s;
    s.menu();
}

