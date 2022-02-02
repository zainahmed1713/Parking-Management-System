#include <iostream>
#include <conio.h>
using namespace std;

class Parking_lot
{
protected:
    // static var
    static int vehicle_count;
    int car_rev = 0, bike_rev = 0, auto_rev = 0, van_rev = 0, total_revenue = 0;
    int calc_revenue();

public:
    virtual void take_data() = 0;
    void show_revenue();
};

class Vehicles : public Parking_lot
{
private:
    int choice;
    char usr_input;
    void car();
    void bike();
    void auto_rickshaw();
    void van();

public:
    void take_data();
    void show_count();
};

class Reciept
{
private:
    int vehicle_num = 0, vehicle_type = 0;
    string Fname, Lname;
    double time_parked = 0, charges = 0;

public:
    friend void generate_reciept(Reciept r);
};

int main()
{
    Vehicles v_obj;
    Reciept rec_obj;
    //Main Menu
    int choice;
    while (choice != 5)
    {
        cout << "\t\t\t\t\tParking Management System\n";
        cout << "Menu:\n1. Park Vehicle\n2. Total Vehicles\n3. Generate Reciept\n4. Total Revenue\n5. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            v_obj.take_data();
            break;
        }
        case 2:
        {
            v_obj.show_count();
            break;
        }
        case 3:
        {
            generate_reciept(rec_obj);
            break;
        }
        case 4:
        {
            v_obj.show_revenue();
            break;
        }
        case 5:
        {
            cout << "Program exited\n";
            break;
        }
        default:
        {
            cout << "Invalid Input\n";
            break;
        }
        }
    }

    system("pause");
    return 0;
}
// Static Variable Initialization
int Parking_lot ::vehicle_count = 0;

int Parking_lot ::calc_revenue()
{
    total_revenue = car_rev + bike_rev + auto_rev + van_rev;
    return total_revenue;
}

void Parking_lot ::show_revenue()
{
    system("cls");
    int total_rev = calc_revenue();

    cout << "Revenue of Cars = " << car_rev << "\n";
    cout << "Revenue of Bikes = " << bike_rev << "\n";
    cout << "Revenue of Auto RickShaws = " << auto_rev << "\n";
    cout << "Revenue of Vans = " << van_rev << "\n";
    cout << "Total Revenue of " << vehicle_count << " vehicles is = " << total_rev << "\n";
    cout << "Press any key to continue\n";
    getch();
    system("cls");
}

void Vehicles ::take_data()
{
    system("cls");
    do
    {
        cout << "Vehicle Menu:\n";
        cout << "1. Car\n2. Bike\n3. Auto Rickshaw\n4. Van\n5. Back to Menu\n";
        cout << "Enter Vehicle Type\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            car();
            break;
        }
        case 2:
        {
            bike();
            break;
        }
        case 3:
        {
            auto_rickshaw();
            break;
        }
        case 4:
        {
            van();
            break;
        }
        default:
            cout << "Invalid Input!!!\n";
            break;
        }

    } while (choice != 5);

    system("cls");
}

// Calculating individual vehicle count and revenue of parking lot
void Vehicles ::car()
{
    vehicle_count++;
    car_rev += 200;
    cout << "Car has been added\nPress any key to continue\n";
    getch();
    system("cls");
}
void Vehicles ::bike()
{
    vehicle_count++;
    bike_rev += 50;
    cout << "Bike has been added\nPress any key to continue\n";
    getch();
    system("cls");
}
void Vehicles ::auto_rickshaw()
{
    vehicle_count++;
    auto_rev += 100;
    cout << "Auto Rickshaw has been added\nPress any key to continue\n";
    getch();
    system("cls");
}
void Vehicles ::van()
{
    vehicle_count++;
    van_rev += 300;
    cout << "Van has been added\nPress any key to continue\n";
    getch();
    system("cls");
}
void Vehicles ::show_count()
{
    system("cls");
    cout << "Currently there are " << vehicle_count << " vehicles in the Parking Lot\n";
    cout << "Press any key to continue\n";
    getch();
    system("cls");
}

void generate_reciept(Reciept r)
{
    system("cls");
    while (r.vehicle_type != 5)
    {
        cout << "Select vehicle type:\n1. Car\n2. Bike\n3. Auto-rickshaw\n4. Van\n5. Back to Menu\n";
        cin >> r.vehicle_type;
        if (r.vehicle_type == 1)
        {
            system("cls");

            cout << "Enter your Full Name\n";
            cin >> r.Fname >> r.Lname;
            cout << "Enter Vehicle Num\n";
            cin >> r.vehicle_num;
            cout << "How much hours have you parked your car\n";
            cin >> r.time_parked;
            cout << "Your charges are " << r.time_parked * 200 << "\n";
            cout << "Press any to exit\n";
            getch();
            system("cls");
        }

        else if (r.vehicle_type == 2)
        {
            system("cls");

            cout << "Enter your Full Name\n";
            cin >> r.Fname >> r.Lname;
            cout << "Enter Vehicle Num\n";
            cin >> r.vehicle_num;
            cout << "How much hours have you parked your bike\n";
            cin >> r.time_parked;
            cout << "Your charges are " << r.time_parked * 50 << "\n";
            cout << "Press any key to exit\n";
            getch();
            system("cls");
        }

        else if (r.vehicle_type == 3)
        {
            system("cls");

            cout << "Enter your Full Name\n";
            cin >> r.Fname >> r.Lname;
            cout << "Enter Vehicle Num\n";
            cin >> r.vehicle_num;
            cout << "How much hours have you parked your Auto Rickshaw\n";
            cin >> r.time_parked;
            cout << "Your charges are " << r.time_parked * 100 << "\n";
            cout << "Press any key to exit\n";
            getch();
            system("cls");
        }

        else if (r.vehicle_type == 4)
        {
            system("cls");

            cout << "Enter your Full Name\n";
            cin >> r.Fname >> r.Lname;
            cout << "Enter Vehicle Num\n";
            cin >> r.vehicle_num;
            cout << "How much hours have you parked your van\n";
            cin >> r.time_parked;
            cout << "Your charges are " << r.time_parked * 300 << "\n";
            cout << "Press any key to exit\n";
            getch();
            system("cls");
        }
        else
        {
            system("cls");
            break;
        }
    }
}