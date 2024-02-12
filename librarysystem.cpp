#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/// global data
const int size = 1000;
int add =0;
int add2 =0;
/// structur book
struct book
{
    string bk_name;
    int bk_id;
    int bk_quntity;
    int bk_borrow;
    string bk_who_borrow[size];
    int c =0 ;


};
/// structur user
struct user
{
    string user_name;
    int user_id;
    int ids_book_which_borrowed[size];
    string id_book_which_borrowed[size];
    int cc= 0 ;
};
user arr_user[size];

/// compare by id
bool compare_id(book &b1, book&b2)
{
    return b1.bk_id < b2.bk_id ;
}
/// compare by name
bool compare_name(book &b1, book&b2)
{
    return b1.bk_name < b2.bk_name ;
}
/// compare by quntity
bool compare_quntity(book &b1, book&b2)
{
    return b1.bk_quntity < b2.bk_quntity ;
}
book arr_book[size];
/// structur library
struct library
{
    /// add book for library
    void add_book(book & b)
    {
        //cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "Adding Book for Library ."<<endl;
        cout<< "Enter Book [ Name & Id & Quntity ] : " <<endl;
        printf("you can write Full Name for Book .\n");
        cout<< "Name : ";
       // cin>> b.bk_name ;
        cin.ignore();
        getline(cin , b.bk_name);
        cout<< "Id : ";
        cin>> b.bk_id ;
        cout<< "Quntity : ";
        cin>> b.bk_quntity ;
        /// add++; look at under
    }
    /// 1- sort by id
    void sort_by_id()
    {
        sort(arr_book, arr_book + add, compare_id);/// sort array  in each i call function sort
    }
    /// 2- sort by name
    void sort_by_name()
    {
        sort(arr_book, arr_book + add, compare_name);/// sort array  in each i call function sort
    }
    /// 3- sort by quntity
    void sort_by_quntity()
    {
        sort(arr_book, arr_book + add, compare_quntity);/// sort array  in each i call function sort
    }
    /// print array after sort by id
    void pirnt_sort_by_id()
    {
        cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "List of Books sorted by IDs . \n";
        sort_by_id();
        cout<< endl;
        for(int i=0; i<add; ++i)
        {
            book b = arr_book[i];
            cout<<  "ID : [ "<< b.bk_id
                <<" ] "<<"Name : [ "<< b.bk_name
                <<" ] "<< "Quntity : [ "<<b.bk_quntity
                <<" ] "<<"Total borrowed : [ "<< b.bk_borrow<<" ] "<<"User_Who_Borrow : ";
            for(int j=0 ; j<arr_book[i].c; j++)
            {
                cout<< b.bk_who_borrow[j] <<" , ";
            }
            cout<< endl;
        }
        //cout<<"____________________________________________________________________________________________________________"<<endl;
    }
    /// print array after sort by quntity
    void pirnt_sort_by_quntity()
    {
        cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "List of Books sorted by Quntity . \n";
        sort_by_quntity();
        cout<< endl;
        for(int i=0; i<add; ++i)
        {
            book b = arr_book[i];
            cout<< "Quntity : [ "<<b.bk_quntity
                <<" ] "<<"Name : [ "<< b.bk_name
                <<" ] "<< "ID : [ "<< b.bk_id
                <<" ] "<<"Total borrowed : [ "<< b.bk_borrow<<" ] "<<"User_Who_Borrow : ";
            for(int i=0 ; i<arr_book[i].c; i++)
            {
                cout<< b.bk_who_borrow[i] <<" , ";
            }
            cout<< endl;
        }
        // cout<<"____________________________________________________________________________________________________________"<<endl;
    }
    /// print array after sort by name
    void pirnt_sort_by_name()
    {
        cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "List of Books sorted by Names . \n";
        sort_by_name();
        cout<< endl;
        for(int i=0; i<add; ++i)
        {
            book b = arr_book[i];
            cout<< "Name : [ " << b.bk_name
                <<" ] "<< "ID : [ "<< b.bk_id
                <<" ] "<< "Quntity : [ "<<b.bk_quntity
                <<" ] "<<"Total borrowed : [ "<< b.bk_borrow<<" ] "<<"User_Who_Borrow : ";
            for(int i=0 ; i<arr_book[i].c; i++)
            {
                cout<< b.bk_who_borrow[i] <<" , ";
            }
            cout<< endl;
        }
        //cout<<"____________________________________________________________________________________________________________"<<endl;
    }
    /// find the books it's begin by prifix
    void search_by_prifix()
    {
        cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "To find Books which start specific string [ Search by Prefix ] . \n";
        cout<< endl;
        string s;
        cout<< "Write here : " ;
        cin>> s ;
        bool flag = 0;
        for(int i=0; i<add; ++i)
        {
            book b = arr_book[i];
            if(s[0] == b.bk_name[0])
            {
                cout<< b.bk_name<<endl;
                flag = 1 ;
            }

            else continue ;
        }
        if(flag == 0) cout<< "There is no Books start of this string !!";
    }

    /// show the users who borrowing book
    void who_borrow_book()
    {
        cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "The Users borrowed this book . \n";
        printf("Note ! write the same name which in library ...\n");
        cout<< "Enter - Book name - :  ";
        string bok_name;
        cin.ignore();
        getline(cin , bok_name);
        int flage = 0;
        bool f = 0;
        for(int i=0; i<add; i++)
        {
            if(bok_name == arr_book[i].bk_name)
            {
                flage = i ;
                f = 1;
            }


        }
        if(f==1)
        {
            for(int i=0; i<arr_book[i].c; i++)
            {
                cout<<arr_book[flage].bk_who_borrow[i]<<endl;
                f =0;
            }
            f =0;
            //  cout<<"______________________________________________________________________________________"<<endl;
        }
        else
            cout<< "There is no Users borrowed this book ....."<<endl;

    }
    /******************************************************************************************************************/
    /// add user for library
    void add_user(user &u)
    {
        cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "Adding New User for Library ." <<endl;
        cout<< "Enter data of User [ Username & ID ]: "<<endl;
        printf("you can write [ Full name ] or [ First name only ] : \n");
        cout<< "Name : " ;
        cin.ignore();
        getline(cin,u.user_name);
        cout<< "ID : ";
        cin>> u.user_id;
    }
    /// user want to borrow book
    void user_borrow_book()
    {
        cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "Borrowing Book From library . \n";
        string s_book,s_user;
        cout<< "enter - User name & Book name - :"<<endl;
        printf("Note ! write the same names which in Library ...\n");
        cout<< "User name : " ;
        cin.ignore();
        getline(cin,s_user);
        cout<< "Book name : " ;
       // cin.ignore();
        getline(cin,s_book);
        bool there_user = 0;
        bool there_book = 0;
        for(int i=0; i<add2; i++)
        {
            if(s_user == arr_user[i].user_name)
            {
                there_user = 1;
                break;
            }
        }

        for(int i=0; i<add; i++)
        {
            if(s_book == arr_book[i].bk_name)
            {
                there_book = 1;
                break;
            }
        }
        if(there_book == 1 && there_user ==1)
        {
            int help_id_book;
            int number_user = 0;
            int number_book = 0;
            string help_name_user;
            bool f1 = false , f2 = false;
            for(int i=0;i<max(add,add2);++i) /// 2
            {
                if(f1 == false)
                {
                  if(s_user == arr_user[i].user_name) /// ali kmal*  , math1* math2
                    {
                        help_name_user = arr_user[i].user_name; /// help = kmal i = 1 ;
                        number_user = i ; /// 1
                        f1 = true;
                    }
                }
                if(f2 == false)
                {
                   if(s_book == arr_book[i].bk_name) /// i = 0 ;
                    {
                        help_id_book = arr_book[i].bk_id; /// help = 101 ;
                        number_book = i; /// 0
                        ++arr_book[i].bk_borrow;
                        f2 = true;
                    }
                }

                arr_user[number_user].ids_book_which_borrowed[arr_user[number_user].cc] = help_id_book;
                arr_book[number_book].bk_who_borrow[arr_book[number_book].c] = help_name_user ;
                arr_user[number_user].cc++;
                arr_book[number_book].c++;
            }

        }
        else if(there_book == 0 && there_user ==0) {cout<< "this user and this book are not found !!"<<endl;}
        else if(there_book == 0) {cout<< "this book is not found !! "<<endl;}
        else if(there_user == 0) {cout<< "this user is not found !! "<<endl;}
    }
    /// user information
    void user_information()
    {
        cout<<"____________________________________________________________________________________________________________"<<endl;
        cout<< "User Informations : "<<endl;
        for(int i=0; i<add2; ++i) /// numbers of users 3
        {
            cout<<"Username : " <<arr_user[i].user_name<<endl;
            cout<<"ID : " <<arr_user[i].user_id<<endl;
            cout<<"Book borrowed ID : ";
            for(int j=0; j<arr_user[i].cc; j++) /// each book have numbers of user
            {
               // if(arr_user[i].ids_book_which_borrowed[j] > 0)
                    cout<<arr_user[i].ids_book_which_borrowed[j] <<" ";///
               // else continue;
            }
            cout<<"\n"<<endl;
        }
        //cout<<"____________________________________________________________________________________________________________"<<endl;
    }
    void menu(string n)
    {
        book b1;
        user u1;
        if(n=="0")
        {
            cout<<"  (0) print menu again ."<<endl;
            cout<<"  (1) adding book ."<<endl;
            cout<<"  (2) adding user ."<<endl;
            cout<<"  (3) print user information ."<<endl;
            cout<<"  (4) search by prifix ."<<endl;
            cout<<"  (5) print users who borrowed book ."<<endl;
            cout<<"  (6) print books sorted by names ."<<endl;
            cout<<"  (7) print books sorted by ids ."<<endl;
            cout<<"  (8) print books sorted by quntity ."<<endl;
            cout<<"  (9) user wants to borrowing book ."<<endl;
            cout<<"  (10) EXITE " <<endl;
        }
        else if(n=="1") add_book(arr_book[add++]);
        else if(n=="2") add_user(arr_user[add2++]);
        else if(n=="3") user_information();
        else if(n=="4") search_by_prifix();
        else if(n=="5") who_borrow_book();
        else if(n=="6") pirnt_sort_by_name();
        else if(n=="7") pirnt_sort_by_id();
        else if(n=="8") pirnt_sort_by_quntity();
        else if(n=="9") user_borrow_book();
        else if(n=="10")
        {
            cout<< "THANK YOU ^_^"<<endl;
            exit(0);
        }
        else cout<<"INVALID .... try again !!"<<endl;
    }
    void ran()
    {
        string n;
        cin>> n;
        menu(n);
    }
};
/// main function
int main()
{

    cout<< " WELCOME TO YOU IN LIBRARY SYSTEM\n"<<endl;
    cout<< " Enter for choice ."<<endl;
    cout<<"   (0) print menu again ."<<endl;
    cout<<"   (1) adding book ."<<endl;
    cout<<"   (2) adding user ."<<endl;
    cout<<"   (3) print user information ."<<endl;
    cout<<"   (4) search by prifix ."<<endl;
    cout<<"   (5) print users who borrowed book ."<<endl;
    cout<<"   (6) print books sorted by names ."<<endl;
    cout<<"   (7) print books sorted by ids ."<<endl;
    cout<<"   (8) print books sorted by quntity ."<<endl;
    cout<<"   (9) user wants to borrowing book ."<<endl;
    cout<<"   (10) EXITE " <<endl;
    while(1)
    {
        cout<< endl;
        cout<< "Enter [0] for print menu again , else enter from [1] to [10]"<<endl;
        library l;
        l.ran();

    }


    /**library l;


    l.add_book(arr_book[add++]);
    l.add_book(arr_book[add++]);
    //l.add_book(arr_book[add++]);
    l.add_user(arr_user[add2++]);
    l.add_user(arr_user[add2++]);
    l.user_borrow_book();
    l.user_borrow_book();
    l.user_borrow_book();
    l.user_borrow_book();
    //l.who_borrow_book();
    //l.who_borrow_book();
    //l.who_borrow_book();
    //l.pirnt_sort_by_id();
    //l.pirnt_sort_by_name();
    //l.search_by_prifix();
    l.user_information();
    **/

    //return 0;
}
