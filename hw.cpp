  #include <iostream>
  using namespace std;

  int main()
  {
      int side;
      cout << "Enter a number: ";
      cin >> side;

      switch(side) {
        case 281:
          cout << "bigamy";
          break;
        case 321:
        case 322:
          cout << "selling illegal lottery tickets";
          break;
        case 383:
          cout << "selling rancid butter";
          break;
        case 598:
          cout << "wounding a bird in a public cemetery";
          break;
        default:
          cout << "some other crime";
      }

  }
