// Railway.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream out;
ifstream in;

int first_level_menu();
bool log_in(string old_log, string old_password);
bool log_in(int choise);

class Voyage
{
    private: 
        int id;
        string bus_type;
        
        string destination; //пункт назначения
        int departure_day; //день отъезда
        int departure_month;//день приезда
        int arrival_day; //день приезда
        int arrival_month;
        
        int departure_hour;
        int arrival_hour;
        int departure_min;
        int arrival_min;
public:
        Voyage(int id, string bus_type, string destination, int departure_day, int departure_month,
            int arrival_day, int arrival_month, int departure_hour, int arrival_hour, int departure_min, int arrival_min)
        {
            setId(id);
            setBusType(bus_type);
            setDestination(destination);
            setDepartureDay(departure_day);
            setDepartureMonth( departure_month);
            setDepartureMin(departure_min);
            setDepartureHour(departure_hour);
            setArrivalDay(arrival_day);
            setArrivalMonth(arrival_month);
            setArrivalMin(arrival_min);
            setArrivalHour(arrival_hour);
        }

        void show()
        {
            cout << "Id:\t" << id << "\tBus type:\t" << bus_type << "\tDestination:\t" << destination << "\tDeparture date\t" << departure_day<<"."
                << departure_month<<"Depature time:"<<departure_hour<<":"<<departure_min<<"\tArrival date:\t"<<arrival_day<<"."<<arrival_month<<
                "Arrival time:"<<arrival_hour<<":"<<arrival_min<<endl;
       
        }

        void setId(int id)
        {
            if (id < 0 || id >= 1000)
                return;
            this->id = id;
        }
        void setDepartureDay(int departure_day)
        {
            if (departure_day < 0 || departure_day > 30)
                return;
            this->departure_day = departure_day;
        }
        void setDepartureMonth(int departure_month)
        {
            if (departure_month < 0 || departure_month >12)
                return;
            this->departure_month = departure_month;
        }
        void setDepartureHour(int departure_hour)
        {
            if (departure_hour < 0 || departure_hour > 23)
                return;
            this->departure_hour = departure_hour;
        }
        void setDepartureMin(int departure_min)
        {
            if (departure_min < 0 || departure_min >59)
                return;
            this->departure_min = departure_min;
        }
        void setArrivalDay(int arrival_day)
        {
            if (arrival_day < 0 || arrival_day > 30)
                return;
            this->arrival_day = arrival_day;
        }
        void setArrivalMonth(int arrival_month)
        {
            if (arrival_month < 0 || arrival_month >12)
                return;
            this->arrival_month = arrival_month;
        }
        void setArrivalHour(int arrival_hour)
        {
            if (arrival_hour < 0 || arrival_hour > 23)
                return;
            this->arrival_hour = arrival_hour;
        }
        void setArrivalMin(int arrival_min)
        {
            if (arrival_min < 0 || arrival_min >59)
                return;
            this->arrival_min = arrival_min;
        }
        void setBusType(string bus_type)
        {
           /* if ((bus_type != "small" || bus_type != "Small")||(bus_type != "standart" || bus_type != "Standart") || (bus_type != "comfortable" || bus_type != "comfortable"))
                return;*/
            this->bus_type = bus_type;
        }
        void setDestination(string destination)
        {
            this->destination = destination;
        }




        string getBusType()
        {
            return bus_type;
        }
        string getDestination()
        {
            return destination;
        }
        int getId()
        {
            return id;
        }
        int getDepartureDay()
        {
            return departure_day;
        }
        int getDepartureMonth()
        {
            return departure_month;
        }
        int getDepartureHour()
        {
            return departure_hour;
        }
        int getDepartureMin()
        {
            return departure_min;
        }
        int getArrivalDay()
        {
           return arrival_day;
        }
        int getArrivalMonth()
        {
            return arrival_month;
        }
        int getArrivalHour()
        {
            return arrival_hour;
        }
        int getArrivalMin()
        {
            return arrival_min;
        }


        
        


};

void user_management()
{
    string admin_log = "Sasha";
    string admin_password = "0405Yh";
    string user_log = "Sokol";
    string user_password = "1111";
    string temp_log;
    string temp_password;
    ifstream in("C:\\Users\\DELL\\source\\repos\\Kyrsovay_ief\\Railway\\Password.txt");
    if (in.is_open())
    {

        in >> user_log >> user_password;
        
    }
    in.close();

    cout << "To change password enter old login and password "<<endl;
    


    if (log_in(user_log, user_password))
    {
        cout << "Enter new login and password"<<endl;
        cin >> user_log >> user_password;
    }
    out.open("C:\\Users\\DELL\\source\\repos\\Kyrsovay_ief\\Railway\\Password.txt");
    if (out.is_open())
    {
        out<< user_log << user_password;
    }
    out.close();

}

void route_search(vector <Voyage> arr)
{
    int arrival_minutes, arrival_hours, arrival_days, arrival_months;
    char a;
    string destination;
    bool is_finded = false;
    bool input_sucsses = false;
    do
    {
        cout << "Enter time of arrival(hour : minutes)";
        cin >> arrival_hours >>a>> arrival_minutes;
        if (arrival_hours > 0 && arrival_hours <= 23 && arrival_minutes > 0 && arrival_minutes <= 59)
        {
            cout << "Enter date of arrival(day . month)";
            cin >> arrival_days >> a >> arrival_months;
            if (arrival_days > 0 && arrival_days <= 30 && arrival_months > 0 && arrival_months <= 12)
                input_sucsses = true;
        }
    } while (input_sucsses == false);

    cout << "Enter destination"<<endl;
    cin>> destination;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (arr[i].getDestination() == destination)
        {
            {


                if ((arrival_months < arr[i].getArrivalMonth()))
                {
                arr[i].show();
                is_finded = true;
                }

                if ((arrival_months == arr[i].getArrivalMonth()) && (arrival_days < arr[i].getArrivalDay()))
                {
                    arr[i].show();
                    is_finded = true;
                }

                if ((arrival_months == arr[i].getArrivalMonth()) && (arrival_days == arr[i].getArrivalDay()) && (arrival_hours < arr[i].getArrivalHour()))
                {
                    arr[i].show();
                    is_finded = true;
                }

                if ((arrival_months == arr[i].getArrivalMonth()) && (arrival_days == arr[i].getArrivalDay()) && (arrival_hours == arr[i].getArrivalHour()) && (arrival_minutes < arr[i].getArrivalMin()))
                {
                    arr[i].show();
                    is_finded = true;
                }
            }
        }
    }
    if (is_finded == true)
        cout << "You can use this routes"<<endl;
    else cout << "Sorry we haven't buses to this destination"<<endl;
}

vector<Voyage> read_file()
{
    int  id, departure_day, departure_month, arrival_day, arrival_month, departure_hour, arrival_hour, departure_min, arrival_min;
    string bus_type, destination;
    vector<Voyage> arr;
    in.open("C:\\Users\\DELL\\source\\repos\\Kyrsovay_ief\\Railway\\Save.txt");

    if (in.is_open())
    {
        while (in >> id >> bus_type >> destination >> departure_day >> departure_month >> arrival_day >> arrival_month >> departure_hour >> arrival_hour >> departure_min >> arrival_min)
        {
            arr.push_back(Voyage(id, bus_type, destination, departure_day, departure_month, arrival_day, arrival_month, departure_hour, arrival_hour, departure_min, arrival_min));
        }
    }
    in.close();
    return arr;
}


bool log_in(int choise)
{
    string admin_log = "Sasha";
    string admin_password = "0405Yh";
    string user_log = "Sokol";
    string user_password = "1111";
    string temp_log;
    string temp_password;
    bool result;

    cout << "Enter login and password";
    cin >> temp_log;
    cin >> temp_password;
    if (((choise == 1) && (admin_log == temp_log) && (admin_password == temp_password)) || ((choise == 2) && (user_log == temp_log) && (user_password == temp_password)))
    {
        result = true;
    }
    else result= false;
    return result;
}

bool log_in(string old_log, string old_password )
{   
    string log, password;
    cin >> log >> password;
    if (log == old_log && password == old_password)
        return true;
    else return false;
}
vector <Voyage> add_voyge(vector <Voyage> arr)
{
    int  id, departure_day, departure_month, arrival_day, arrival_month, departure_hour, arrival_hour, departure_min, arrival_min;
    string bus_type, destination;
    char a;
    cout << "Enter id, bus_type, destination, departure_day, departure_month, arrival_day, arrival_month, departure_hour, arrival_hour, departure_min, arrival_min "<<endl;
    cin >> id >> bus_type >> destination >> departure_day >> departure_month >> arrival_day >> arrival_month >> departure_hour >> arrival_hour >> departure_min >> arrival_min;
    arr.push_back(Voyage(id, bus_type, destination, departure_day, departure_month, arrival_day, arrival_month, departure_hour, arrival_hour, departure_min, arrival_min));
    return arr;
}


vector <Voyage> edit(vector <Voyage> arr)
{
    int id=-1;
    bool edited=false;
    cout << "Enter id of voyage to edition";
    while (edited == false)
    {
        while (id < 0)
        {
            cout << "Enter id of voyage to edition";
            cin >> id;
        }
        for (int i = 0; i < (int)arr.size() && edited != true; i++)
        {
            if (arr[i].getId() == id)
            {
                int  id, departure_day, departure_month, arrival_day, arrival_month, departure_hour, arrival_hour, departure_min, arrival_min;
                string bus_type, destination;
                cout << "Enter id, bus_type, destination, departure_day, departure_month, arrival_day, arrival_month, departure_hour, arrival_hour, departure_min, arrival_min ";
                cin >> id >> bus_type >> destination >> departure_day >> departure_month >> arrival_day >> arrival_month >> departure_hour >> arrival_hour >> departure_min >> arrival_min;
                arr.emplace(arr.cbegin() + i-1, Voyage(id, bus_type, destination, departure_day, departure_month, arrival_day, arrival_month, departure_hour, arrival_hour, departure_min, arrival_min));
                edited = true;
            }
            else cout << "Can't find voyage with that id";
        }
    }
    return arr;
}

vector <Voyage> input()
{
    vector <Voyage> arr;
    while (true)
    {
        arr = add_voyge(arr);

        cout << "\n\"1\" - continue, \"0\" - exit: ";
        int g; cin >> g;
        if (g == 0) break;

    }
    return arr;
}

void showing(vector <Voyage> arr)
{
    for (int i = 0; i < (int)arr.size(); i++)
    {
        arr[i].show();
    }
}


vector <Voyage> removing(vector <Voyage> arr)
{
    int id=-1;
    bool removed = false;
    while (removed == false)
    {
        while (id < 0)
        {
            cout << "Enter id of voyage to remove"<<endl;
            cin >> id;
        }
        for (int i = 0; i < (int)arr.size() || removed != true; i++)
        {
            if (arr[i].getId() == id&&i!=(int)arr.size())
            {
                arr.erase(arr.begin() + i);
            }
            if (arr[i].getId() == id && i == (int)arr.size())
            {
                arr.pop_back();
            }
        }
    }
    return arr;
}
void second_level_menu(int choise)
{
    vector <Voyage> arr;
    char choose;
    bool result;
    if (choise == 1)// administrator
    {
        result = log_in(1);
        if (result == true)
        {
            while(true)
            {
                cout << "Enter 'a' to open file\n Enter 'b' to add voyage\n Enter 'c' to edit voyages\nEnter 'd' to remove voyage\nEnter 'e' to show data\nEnter 'f' to search voyage\nEnter'g' to change password of user\nEnter 'e' to return to first menu\n";
                cin >> choose;
                switch (choose)
                {
                case 'a': arr=read_file(); break;
                case 'b': arr=add_voyge(arr); break;
                case 'c': arr=edit(arr); break;
                case 'd': arr=removing(arr); break;
                case 'e': showing(arr); break;
                case 'f': route_search(arr); break;
                case 'g': user_management(); break;
                case 'h': first_level_menu(); break;
                default: cout << "Input error, try again";
                    break;
                }
            }
        }
    }
    else if (choise == 2)//user
    {
        result = log_in(2);
        if (result == true)
        {
            while (true) 
            {
                cout << "Enter 'a' to open file\n Enter 'b' to show data\nEnter 'c' to search voyage\nEnter'd'  to return to first menu"<<endl;
                cin >> choose;

                switch (choose)
                {
                case 'a': arr = read_file(); break;
                case 'b': showing(arr); break;
                case 'c': route_search(arr); break;
                case 'd': first_level_menu(); break;
                default: cout << "Input error, try again"<<endl;
                    break;
                }
            }
        }
    }
}

int first_level_menu()
{
    int choise;
    cout << "Press 1 to administration enterance, 2 - to user enterance or 3 to exit"<<endl;
    cin >> choise;
    
        if (choise != 1 && choise != 2 && choise != 3)
        {
            cout << "Input error, Please press\n 1 - to administration enterance,\n 2 - to user enterance or\n 3 to exit"<<endl;
            cin >> choise;
        }
    
        if (choise != 3)
        second_level_menu(choise);

    return 0;
}

int main()
{
    //cout << "Hello World!\n";
    first_level_menu();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
