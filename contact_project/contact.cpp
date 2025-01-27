#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include "DataStructueWithArray.h"
using namespace std;

class address {
private:
    string street_num;
    string street_name;
    string town;
    string state;
    size_t is_fav;

public:
    address() : street_num(""), street_name(""), town(""), state(""), is_fav() {}

    address(string street_num, string street_name, string town, string state, size_t fav)
        : street_num(street_num), street_name(street_name), town(town), state(state), is_fav(fav) {}

    void set_street_num(string s)  { street_num = s; }
    string get_street_num()  { return street_num; }

    void set_street_name(string str)  { street_name = str; }
    string get_street_name()  { return street_name; }

    void set_town(string t)  { town = t; }
    string get_town()  { return town; }

    void set_state(string st)  { state = st; }
    string get_state()  { return state; }

    void set_fav(size_t f)  { is_fav = f; }
    size_t get_fav()  { return is_fav; }
    bool is_f() { return is_fav == 1; }

    string print()
    {
        return street_num + "," + street_name + "," + town + "," + state;
    }

    void Update(string s_num, string s_name, string to, string st, size_t fav)
    {
        set_street_num(s_num);
        set_street_name(s_name);
        set_town(to);
        set_state(st);
        set_fav(fav);
    }
};

class person
{
private:
    size_t id;
    string first_name;
    string last_name;
    Array<string> phone_nums; 
    Array<string> email_nums;  
    string classification;
    size_t favorite;
    address ad;

public:
    person()
    : id(0), first_name(""), last_name(""), classification(""), favorite(0), ad() {}

    person(size_t id, string f_n, string l_n, Array<string> p_nums, Array<string> e_nums, string cla, size_t fav, address a)
        : id(id), first_name(f_n), last_name(l_n), phone_nums(p_nums), email_nums(e_nums), classification(cla), favorite(fav), ad(a) {}

    address get_address() const
    {
        return ad;
    }

    void print()
    {
        cout << setw(20) << left << id
             << setw(20) << first_name
             << setw(20) << last_name
             << setw(20) << classification
             << setw(20) << favorite
             << setw(20) << ad.print();

        cout << setw(20) << "[";
        for (size_t i = 0; i < phone_nums.getSize(); ++i) {
            cout << phone_nums.get(i) << (i < phone_nums.getSize() - 1 ? ", " : "");
        }
        cout << "]";

        cout << setw(20) << "[";
        for (size_t i = 0; i < email_nums.getSize(); ++i) {
            cout << email_nums.get(i) << (i < email_nums.getSize() - 1 ? ", " : "");
        }
        cout << "]" << endl;

        cout << "----------------------------------------------------------------------------------------------------------------------------------------------\n";
    }

    bool is_fav() { return favorite == 1; }

    void Update(string f_n, string l_n, Array<string> p_nums, Array<string> e_nums, string cla, size_t fav, string s_num, string s_name, string to, string st)
    {
        first_name = f_n;
        last_name = l_n;
        phone_nums = p_nums;
        email_nums = e_nums;
        classification = cla;
        favorite = fav;
        ad.Update(s_num, s_name, to, st, fav);
    }

    string get_f_n()    { return first_name; }
    string get_p_n()    { return phone_nums.get(0); }  
    string get_e_n()    { return email_nums.get(0); }  
    string get_l_n()    { return last_name; }
    string get_classify() { return classification; }
};

class contact
{
private:
    Array<person> per1;
    size_t next_id = 1;

public:
    void get_data(string f_n, string l_n, Array<string> phones, Array<string> emails, string cla, size_t fav, string str_num, string str_name, string to, string st)
    {
        address a(str_num, str_name, to, st, fav);
        person p(next_id++, f_n, l_n, phones, emails, cla, fav, a);
        per1.append(p);
    }

    void print_all()
    {
        cout << setw(20) << left << "ID" << setw(20) << "FName" << setw(20) << "LName" << setw(20) << "Classification" << setw(20) << "Fav" << setw(20) << "Address" << setw(20) << "Phone Num" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------\n";
        for (size_t i = 0; i < per1.getSize(); i++)
        {
            per1.get(i).print();
        }
    }

    size_t get_contact_size() const
    {
        return per1.getSize();
    }

    person& get_person(size_t index)
    {
        return per1[index];
    }

    void Delete_()
    {
        size_t index;
        cout << "Enter index to delete: ";
        cin >> index;
        if (index < per1.getSize())
        {
            per1.Delete(index);
            cout << "Contact deleted successfully." << endl;
        }
        else
        {
            cout << "Invalid index." << endl;
        }
    }

    void reverse()
    {
        per1.Reverse();
    }
};

string toLower(string str)
{
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(), [](unsigned char c){ return tolower(c); });
    return lower_str;
}

void print_info()
{
    cout << "============================================================\n";
    cout << "Contacts Book Menu: \n";
    cout << "-------------------------------\n";
    cout << "1. Add a new Contact \n";
    cout << "2. Search by Last Name\n";
    cout << "3. Search by Classification\n";
    cout << "4. Print All Contacts\n";
    cout << "5. Print Fav Contacts\n";
    cout << "6. Save Data To File\n";
    cout << "7. Load Data From File\n";
    cout << "8. Delete Contact\n";
    cout << "9. Update Contact Information\n";
    cout << "10. Share Data With Others\n";
    cout << "11. Reverse Contacts book\n";
    cout << "12. Exit\n";
    cout << "============================================================\n";
}

void add_contact(contact &c1)
{
    string fn, ln, cla, str_name, to, sta, str_num;
    size_t fav, phone_count, email_count;

    cout << "FN: "; cin >> fn;
    cout << "LN: "; cin >> ln;
    cout << "Class (Friend, Work, Family, Other): "; cin >> cla;
    cout << "Set As Fav (1 for Yes, 0 for No): "; cin >> fav;

    cout << "How Many Phone Numbers: "; cin >> phone_count;
    Array<string> phones;
    for (size_t i = 1; i <= phone_count; i++)
    {
        string p;
        cout << "Phone #" << i << ": ";
        cin >> p;
        phones.append(p);
    }

    cout << "How Many Emails: "; cin >> email_count;
    Array<string> emails;
    for (size_t i = 1; i <= email_count; i++)
    {
        string e;
        cout << "Email #" << i << ": ";
        cin >> e;
        emails.append(e);
    }

    cout << "Enter Address: ";
    cout << "Street Number: "; cin >> str_num;
    cout << "Street Name: "; cin >> str_name;
    cout << "Town: "; cin >> to;
    cout << "State: "; cin >> sta;

    c1.get_data(fn, ln, phones, emails, cla, fav, str_num, str_name, to, sta);
}

void search_by_last_name(contact &c1)
{
    string ln;
    cout << "Enter Last Name: ";
    cin >> ln;
    ln = toLower(ln);
    for (size_t i = 0; i < c1.get_contact_size(); i++)
    {
        if (ln == toLower(c1.get_person(i).get_l_n()))
        {
            c1.get_person(i).print();
        }
    }
}

void search_by_classification(contact &c1)
{
    string cla;
    cout << "Enter Classification: ";
    cin >> cla;
    cla = toLower(cla);
    for (size_t i = 0; i < c1.get_contact_size(); i++)
    {
        if (cla == toLower(c1.get_person(i).get_classify()))
        {
            c1.get_person(i).print();
        }
    }
}

void print_all_contacts(contact &c1)
{
    c1.print_all();
}

void print_favorite_contacts(contact &c1)
{
    for (size_t i = 0; i < c1.get_contact_size(); i++)
    {
        if (c1.get_person(i).is_fav())
        {
            c1.get_person(i).print();
        }
    }
}

void delete_contact(contact &c1)
{
    c1.Delete_();
}

void reverse_contacts(contact &c1)
{
    c1.reverse();
    cout << "Contacts reversed successfully.\n";
}

void update_contact(contact &c1)
{
    size_t index;
    cout << "Enter Index: "; cin >> index;
    string fn, ln, cla, str_name, to, sta, str_num;
    size_t fav, phone_count, email_count;

    cout << "FN: "; cin >> fn;
    cout << "LN: "; cin >> ln;
    cout << "Class (Friend, Work, Family, Other): "; cin >> cla;
    cout << "Set As Fav (1 for Yes, 0 for No): "; cin >> fav;

    cout << "How Many Phone Numbers: "; cin >> phone_count;
    Array<string> phones;
    for (size_t i = 1; i <= phone_count; i++)
    {
        string p;
        cout << "Phone #" << i << ": ";
        cin >> p;
        phones.append(p);
    }

    cout << "How Many Emails: "; cin >> email_count;
    Array<string> emails;
    for (size_t i = 1; i <= email_count; i++)
    {
        string e;
        cout << "Email #" << i << ": ";
        cin >> e;
        emails.append(e);
    }

    cout << "Enter Address: ";
    cout << "Street Number: "; cin >> str_num;
    cout << "Street Name: "; cin >> str_name;
    cout << "Town: "; cin >> to;
    cout << "State: "; cin >> sta;


    if (index < c1.get_contact_size())
    {
        c1.get_person(index).Update(fn,ln,phones,emails,cla,fav,str_num,str_name,to,sta);
    }
    else
    {
        cout << "Invalid index." << endl;
    }
}


void save_data_to_file(contact &c1)
{
    ofstream outfile("data.txt");
    if (outfile.is_open())
    {
        outfile << setw(20) << left << "First Name"
                << setw(20) << "Last Name"
                << setw(20) << "Classification"
                << setw(20) << "Is Favourite"
                << setw(20) << "Phone Numbers"
                << setw(20) << "Emails"
                << setw(20) << "Address"
                << endl;
        for (size_t i = 0; i < c1.get_contact_size(); i++)
        {
            person p = c1.get_person(i);
            outfile << setw(20) << left << p.get_f_n()
                    << setw(20) << p.get_l_n()
                    << setw(20) << p.get_classify()
                    << setw(20) << p.is_fav()
                    << setw(20) << p.get_p_n()  
                    << setw(20) << p.get_e_n()  
                    << setw(20) << p.get_address().print() 
                    << endl;
        }
        outfile.close();
        cout << "Data Saved To File Successfully.\n";
    }
    else
    {
        cout << "Failed to open file for saving.\n";
    }
}


void load_data_from_file(contact &c1)
{
    ifstream infile("data.txt");
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            stringstream ss(line);
            string fn, ln, cla, s_num, s_name, to, sta, mobiles, mails;
            size_t fav;

            getline(ss, fn, ',');
            getline(ss, ln, ',');
            getline(ss, cla, ',');
            ss >> fav;
            getline(ss, s_num, ',');
            getline(ss, s_name, ',');
            getline(ss, to, ',');
            getline(ss, sta, ',');
            getline(ss, mobiles, ',');
            getline(ss, mails, ',');

            // Parsing phone numbers and emails
            Array<string> phones;
            stringstream phone_stream(mobiles);
            string phone;
            while (getline(phone_stream, phone, ';')) {
                phones.append(phone);
            }

            Array<string> emails;
            stringstream email_stream(mails);
            string email;
            while (getline(email_stream, email, ';')) {
                emails.append(email);
            }

            c1.get_data(fn, ln, phones, emails, cla, fav, s_num, s_name, to, sta);
        }
        infile.close();
        cout << "Data Loaded From File Successfully.\n";
    }
    else
    {
        cout << "Failed to open file for loading.\n";
    }
}


void share(contact &c1)
{
    cout << "Sharing Contact Details:\n";
    for (size_t i = 0; i < c1.get_contact_size(); i++)
    {
        person p = c1.get_person(i);
        cout << "-------------------------------\n";
        cout << "First Name: " << p.get_f_n() << endl;
        cout << "Last Name: " << p.get_l_n() << endl;
        cout << "Classification: " << p.get_classify() << endl;
        cout << "Is Favourite: " << (p.is_fav() ? "Yes" : "No") << endl;

        cout << "Phone Numbers: ";
        for (size_t j = 0; j < p.get_p_n().size(); j++)  
        {
            cout << p.get_p_n()[j];  
            if (j < p.get_p_n().size() - 1) cout << ", ";
        }
        cout << endl;

        cout << "Emails: ";
        for (size_t j = 0; j < p.get_e_n().size(); j++)  
        {
            cout << p.get_e_n()[j];  
            if (j < p.get_e_n().size() - 1) cout << ", ";
        }
        cout << endl;

        cout << "Address: " << p.get_address().print() << endl;
        cout << "-------------------------------\n";
    }
}



int main()
{
    contact c1;
    while (true)
    {
        print_info();
        int num;
        cout << "Enter Your Choice: ";
        cin >> num;

        if (num == 1)
        {
            add_contact(c1);
        }
        else if (num == 2)
        {
            search_by_last_name(c1);
        }
        else if (num == 3)
        {
            search_by_classification(c1);
        }
        else if (num == 4)
        {
            print_all_contacts(c1);
        }
        else if (num == 5)
        {
            print_favorite_contacts(c1);
        }
        else if (num == 6)
        {
            save_data_to_file(c1);
        }
        else if (num == 7)
        {
            load_data_from_file(c1);
        }
        else if (num == 8)
        {
            delete_contact(c1);
        }
        else if (num == 9)
        {
            update_contact(c1);
        }
        else if (num == 10)
        {
            share(c1);
        }
        else if (num == 11)
        {
            reverse_contacts(c1);
        }
        else if (num == 12)
        {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid option. Please try again.\n"; break;
        }
    }
    return 0;
}
