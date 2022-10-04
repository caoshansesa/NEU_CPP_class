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
        cout << "difficulty stuff";
        break;
      case 2:
        cout << "difficulty stuff";
        break;
      case 3:
        cout << "difficulty stuff";
        break;
      case 4:
        cout << "difficulty stuff";
        break;
      case 5:
        cout << "difficulty stuff";
        break;
      case 6:
        cout << "difficulty stuff";
        break;
      case 7:
        cout << "difficulty stuff";
        break;
      case 8:
        cout << "quite The program \n";
        break;
      default:
        break;
    }
  } while (choice != 8);
}

void print_2_passager_manifest() {}

void print_2_seat_map() {}

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
        cout << "difficulty stuff";
        break;
      case 2:
        cout << "sound stuff";
        break;
      case 3:
        break;
      default:
        break;
    }
  } while (choice != 3);
}

void load_3_passager_manifest() {
  // Show Blank and show the main screen
}

void save_4_passager_manifest() {
  // Show Blank and show the main screen
}

void print_menu_5()
{

}

void option_for_menu_5()
{
    
}

void choose_seats_5() {
   // Type define 1, First class, Bu..clas? ecnoy class?
   /*
        * Which_class_the_user_input()
    {
        FirstClass()
        BusinessClass()
        Economy()
    }
   */
   //
   // Assign a random seats 
   //   RandomNumGenerator()
//	    int = num_generator()
//	            if(int not seen before)                             
  // Check_Whether_this_seat_is_available()
  // Downgrade_compatiple test
  //
}


void Option_Cancel_seat_assignment_6()
{
   
    //print current seat alignment?
    // save the seat info?
}


void print_boarding_pass_7(int seatNumber, string name){}




int main(int argc, char *argv[]) {
  int choice = 0;
  do {
    system("clear");
    ShowMainMenu();
    choice = GetInput();
    switch (choice) {
      case 1:
        cout << "Pew pew!\n";
        break;
      case 2:
        break;
      case 3:
        cout << "Goodbye!";
        break;

      default:
        break;
    }
  } while (choice != 3);
  return EXIT_SUCCESS;
}
