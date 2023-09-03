  #include<iostream>
  #include<string>
  #include<fstream>
  #include<sstream>
  using namespace std;

  int main(){
    int a, i=0;
    string txt, old, pswd0, pswd1, pswd2, pass, name, age, user, word, word1;
    string cred[2], cp[2];

    cout<<"\t\t\t\t\t\t\tSECURITY SYSTEM ";

     cout<<"\n\t___________________________________________\n";
     cout<<"\t|           1. Register                    |\n";
     cout<<"\t|           2. Login                       |\n";
     cout<<"\t|           3. Change Password             |\n";
     cout<<"\t|___________4. End Program_________________|\n\n";

    do{
        cout<<"\n\n\tEnter Your Choice : ";
        cin>>a;

        switch(a){
            case 1:{
                    cout<<"\t___________________________________________\n";
                    cout<<"\t|- - - - - Register - - - - - - - - - - - -|\n";
                    cout<<"\t|__________________________________________|\n";
                    cout<<"\tPlease Enter username : ";
                    cin>>name;
                    cout<<"\tPlease Enter the Password : ";
                    cin>>pswd0;
                    cout<<"\tPlease Enter Your Age : ";
                    cin>>age;

                ofstream  of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<pswd0;
                    cout<<"\tSuccessfully Registered \n";
                }  
                break;
            }

            case 2:{
                i=0;
                cout<<"\t___________________________________________\n\n";
                cout<<"\t|- - - - - Login - - - - - - - - - - - - - | \n";
                cout<<"\t|__________________________________________|\n\n";

                ifstream of2;
                of2.open("file.txt");
                cout<<"\tPlease Enter the username  : ";
                cin>>user;
                cout<<"\tPlease Enter the Password : ";
                cin>>pass;

                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2, txt)){
                            istringstream iss(txt);
                            iss>>word;
                            cred[i]=word;
                            i++;
                        }

                        if(user==cred[0]&&pass==cred[1]){
                            cout<<"\t___________________________________________\n";
                            cout<<"\t|- - - - - Log in successfull- - - - - - - | \n";
                            cout<<"\t|__________________________________________|\n\n";
                            cout<<"\n\n";

                            cout<<"\tDetail :\n";

                            cout<<"\tUsername : "+ name<<endl;
                            cout<<"\tPassword : "+ pass<<endl;
                            cout<<"\tAge :"+ age<<endl;
                        }

                        else{
                            cout<<"\n\n";
                            cout<<"\tIncorrect Credentials\n";
                            cout<<"\t          1. Press 2 to Login               \n";
                            cout<<"\t          2. Press 3 to Change password     \n";
                            break;
                        }

                    }
                }
                break;
            }

            case 3:{
                i=0;
                cout<<"\t          Change Password                   \n";

                ifstream of0;
                of0.open("file.txt");
                cout<<"\tEnter the old password : ";
                cin>>old;

                if(of0.is_open()){
                    while(of0.eof()){
                        while(getline(of0, txt)){
                            istringstream iss(txt);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }

                        if(old==cp[1]){
                            of0.close();
                            ofstream of1;
                            if(of1.is_open())
                            {
                                cout<<"\tEnter New password : ";
                                cin>>pswd1;
                                cout<<"\tEnter your password again : ";
                                cin>>pswd2;

                                if(pswd1 == pswd2){
                                    of1<<cp[0]<<endl;
                                    of1<<pswd1;
                                    cout<<"\tPassword changed successfully \n";
                                }

                                else{
                                    of1<<cp[0]<<endl;
                                    of1<<old;
                                    cout<<"\tPassword do not match\n";
                                }
                            }
                        }
                        else{
                            cout<<"\tPlease enter a valid password\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 4:{
                cout<<"          Thankyou!                             \n";
                cout<<"\t___________________________________________\n\n";
                cout<<"\t      ********************************     ";
               break;
            }

            default:
             cout<<"\tEnter a valid choice";

        }
    }
    while(a!=4);
    return 0;
  }