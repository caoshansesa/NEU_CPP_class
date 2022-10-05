#include "../inc/hw2.hpp"
int GetInput() {
    int choice;
    cin >> choice;
    return choice;
}

void ShowMainMenu() {
    cout << "Main Menu\n";
    cout << "1 - Display the seating map/chart showing all seats.\n";
    cout << "2 - Print a passenger manifest. \n";
    cout << "3 - Load the saved seat. \n";
    cout << "4 - Save the current seat. \n";
    cout << "5 - Choose a Seat. \n";
    cout << "6 - Cancel Seat Assignment. \n";
    cout << "7 - Print Your Boarding PASS \n";
    cout << "8 - Quit the system \n";
}

void option_for_main_menu() {
    int choice = 0;
    do {
        system("clear");
        ShowMainMenu();
        choice = GetInput();
        switch (choice) {
            case 1:
                print_2_seat_map();
                break;
            case 2:
                // 2 - Print a passenger manifest.
                option_for_2_print_passager_manifest();
                break;
            case 3:
                load_3_passager_manifest();
                break;
            case 4:
                save_4_passager_manifest();
                break;
            case 5:
                option_for_menu_5();
                break;
            case 6:
                Option_Cancel_seat_assignment_6();
                break;
            case 7:
                Option_Print_boardingPass_7();
                break;
            case 8:
                cout << "quite The program \n";
                break;
            default:
                break;
        }
    } while (choice != 8);
}

void Display_2_1_passager_manifest()
{
    cout << " 1 - Seat Number Assending" << endl;
    cout << " 2 - Seat Number Desending" << endl;
    cout << " 3 - Name Alphbacal Assending A~Z" << endl;
    cout << " 4 - Name Alphbacal Desending A~Z" << endl;

}

bool comparator(string a,string b)
{
    return a<b;
}

bool comparator2(string a,string b)
{
    return a>b;
}

void name_assending()
{
    string Local_passager[72];
    for (int i = 0; i < 72; ++i) {
        Local_passager[i] = name_of_passager[i];
    }

    sort(Local_passager,Local_passager+72,comparator);
    for(int i=0;i<72;i++)
    {
        if (Local_passager[i].compare("Available") != 0) {
            cout << Local_passager[i]  << endl;
        }
    }
    cout << " 3 - Name Alphbacal Assending A~Z" << endl;
    system("read -n 1 -s -p \"Press any key to continue...\"");
}

void name_desending()
{
    string Local_passager[72];
    for (int i = 0; i < 72; ++i) {
        Local_passager[i] = name_of_passager[i];
    }

    sort(Local_passager,Local_passager+72,comparator2);
    for(int i=0;i<72;i++)
    {
        if (Local_passager[i].compare("Available") != 0) {
            cout << Local_passager[i]  << endl;
        }
    }
    cout << " 4 - Name Alphbacal Desending A~Z" << endl;
    system("read -n 1 -s -p \"Press any key to continue...\"");
}

void seat_assending()
{
    string Local_passager[72];
    for (int i = 0; i < 72; ++i) {
        Local_passager[i] = name_of_passager[i];
    }

    for(int i=0;i<72;i++)
    {
        if (Local_passager[i].compare("Available") != 0) {
            cout << Local_passager[i]  << endl;
        }
    }
    cout << " 1 - Seat Number Assending" << endl;
    system("read -n 1 -s -p \"Press any key to continue...\"");
}

void seat_desending()
{
    string Local_passager[72];
    for (int i = 0; i < 72; ++i) {
        Local_passager[i] = name_of_passager[72-i];
    }

    for(int i=0;i<72;i++)
    {
        if (Local_passager[i].compare("Available") != 0) {
            cout << Local_passager[i]  << endl;
        }
    }
    cout << " 2 - Seat Number Desending" << endl;
    system("read -n 1 -s -p \"Press any key to continue...\"");
}
void option_2_1_passager_manifest()
{
    int choice = 0;
    do {
        system("clear");
        Display_2_1_passager_manifest();
        choice = GetInput();
        switch (choice) {
            case 1:
                seat_assending();
                choice = 5;  // Manually Exit
                break;
            case 2:
                seat_desending();
                choice = 5;  // Manually Exit
                break;
            case 3:
                name_assending();
                choice = 5;  // Manually Exit
                break;
            case 4:
                name_desending();
                choice = 5;  // Manually Exit
                break;
        }
    } while (choice != 5);

};

void print_2_seat_map() {
    cout << "A means the seats are availabe, X means the seat has been taken"
         << endl;
    cout << "A" << "  "<< "B" << "  "<< "D" << "  "<< "E" <<"  "<< "F"<< "  "<<"G" << "  "<<"I"<< "  "<< "J" << "  "<< "K" << endl;
    for (int i = 0; i < 72; ++i) {
        if (i % 9 == 0) {
            cout << endl;
        }
        if (name_of_passager[i].compare("Available")== 0) {
            cout << "A"
                 << " ";
        } else {
            cout << "X"
                 << " ";
        }
        cout << " ";
    }
    cout << endl;
    system("read -n 1 -s -p \"Press any key to continue...\"");
}

void Display_2_Print_passager_manifest() {
    cout << " 1 - Print Passager Manifest" << endl;
    cout << " 2 - Print seat Map" << endl;
}

void option_for_2_print_passager_manifest() {
    int choice = 0;
    do {
        system("clear");
        Display_2_Print_passager_manifest();
        choice = GetInput();
        switch (choice) {
            case 1:
                option_2_1_passager_manifest();
                choice = 3;  // Manually Exit
                break;
            case 2:
                print_2_seat_map();
                choice = 3;  // Manually Exit
                break;
        }
    } while (choice != 3);
}

void seperate_strings(string line, string* a, string* b, string* op) {
    int coma_counter(0);
    for (char cc : line) {
        if ((cc != ',') && (coma_counter == 0)) {
            a->push_back(cc);
        }

        if ((cc != ',') && (coma_counter == 1)) {
            b->push_back(cc);
        }

        if ((cc != ',') && (coma_counter == 2)) {
            op->push_back(cc);
        }
        if (cc == ',') {
            coma_counter++;
        }
    }
}

int seat_info_2_index(string x, string y)
{
    int y1 = stoi(y);
    int index = 0;
    if ( x == "A") index = 0;
    if ( x == "B") index = 1;
    if ( x == "D") index = 2;
    if ( x == "E") index = 3;
    if ( x == "F") index = 4;
    if ( x == "G") index = 5;
    if ( x == "I") index = 6;
    if ( x == "J") index = 7;
    if ( x == "K") index = 8;

    return (y1-1)*9 + index;

}

void load_3_passager_manifest() {
        ifstream infile("input.txt");
        string line;
        signed int x = 0, y = 0;

        while (getline(infile, line)) {
            string str_x, str_y, str_z;
            seperate_strings(line, &str_x, &str_y, &str_z);
            int index = seat_info_2_index(str_z, str_y);
            name_of_passager[index]= str_x;
        }
    system("read -n 1 -s -p \"Press any key to continue...\"");
}

string index_2_seat_info(int i)
{
    int Row(0);
    int column;
    Row = (i / 9) + 1;
    column = i % 9;
    switch (column) {
        case 0:
            return "A";
            break;
        case 1:
            return "B";
            break;
        case 2:
            return "D";
            break;
        case 3:
            return "E";
            break;
        case 4:
            return "F";
            break;
        case 5:
            return "G";
            break;
        case 6:
            return "I";
            break;
        case 7:
            return "J";
            break;
        case 8:
            return "K";
            break;
    }
}

void save_4_passager_manifest() {
    ofstream outfile("output.txt");
    string line;
    signed int x = 0, y = 0;


    for (int i = 0; i < 72; ++i) {
        int j = i/9 +1;
        outfile << name_of_passager[i] << "," <<to_string(j) << ","<< index_2_seat_info(i) << endl;
    }
    system("read -n 1 -s -p \"Press any key to continue...\"");
}

void Display_menu_5() {
    cout << "1. Choose your seat, input your name, Format: FirstName_LastName " << endl;
}

void choose_seats_5() {
    string name_input;
    cin >> name_input;

    srand(time(nullptr));
    int index = 0;
   do {
       // :TODO
       index = rand() % 71;  // generate number between 0 ~71
       if((index > 8) &&(index < 26))
       {
           cout << "There is seat in first class, upgrade to First class? "<< endl;
           system("read -n 1 -s -p \"Press any key to continue...\""); //pause
       }
       if((index > 26))
       {
           cout << "There is seat in Business class upgrade to Business class? "<< endl;
           system("read -n 1 -s -p \"Press any key to continue...\""); //pause
       }
   }while (name_of_passager[index].compare("Available"));

   name_of_passager[index] = name_input; // if the seat is available, reserve the seat.
   save_4_passager_manifest(); // save right away
   system("read -n 1 -s -p \"Press any key to continue...\"");
}

void option_for_menu_5() {

    int choice = 0;
    do {
        system("clear");
        Display_menu_5();
        choice = GetInput();
        switch (choice) {
            case 1:
                choose_seats_5();
                choice = 2;  // Manually Exit
                break;
        }
    } while (choice != 2);
}

void display_6_cancel_seat()
{
    cout << "1. Cancel your seat, input your name, Format: FirstName_LastName " << endl;

}
void cancel_seat()
{
    vector<string> data_temp;
    string name_input;
    cin >> name_input;
    for (int i = 0; i < 71; ++i) {
        if (name_of_passager[i].compare(name_input))
        {
            name_of_passager[i] = "Available";
        }
    }

}

void Option_Cancel_seat_assignment_6() {
    int choice = 0;
    do {
        system("clear");
        display_6_cancel_seat();
        choice = GetInput();
        switch (choice) {
            case 1:
                cancel_seat();
                choice = 2;  // Manually Exit
                break;
        }
    } while (choice != 2);
}

void display_7_boardingpass()
{
    cout << "1. Print Your boarding pass, input your name, Format: FirstName_LastName " << endl;
}

void print_boarding_pass_7() {
    string name_input;
    cin >> name_input;
    int counter=0;
    for (int i = 0; i < 71; ++i) {
        if (name_of_passager[i].compare(name_input))
        {
            int j = i/9 +1;
            cout << "NAME:" << name_input << ","<<to_string(j) << ","<< index_2_seat_info(i) << endl;
            counter++;
        }
        if (counter == 0)
        {
            cout << "Seat Unassigned - No Boarding pass available. Try Again" <<endl;
        }
    }

}

int try_counter = 0;
void Option_Print_boardingPass_7() {
    int choice = 0;

    do {
        system("clear");
        display_7_boardingpass();
        choice = GetInput();
        switch (choice) {
            case 1:
                try_counter++;
                if(try_counter < 3)
                {
                    print_boarding_pass_7();
                }
                else
                {
                    cout << "Boarding pass is not available at this time. Try Again later!”" << endl;
                }
                choice = 2;  // Manually Exit
                break;
        }
    } while (choice != 2);
}


int main(int argc, char* argv[]) {
    system("clear");
    option_for_main_menu();
}
