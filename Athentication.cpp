#include <iostream>
#include <fstream>
using namespace std;
struct pass
{
    double pas;
    char user_id[10];
};
void main_menu();
class Athentication
{
public:
    void sign_up()
    {
        pass p;
        ofstream Fileout("pass.txt", ios::app | ios::binary);
        cout << "\n\n\tuser id : ";
        cin >> p.user_id;
        cout << "\n\tPassword :";
        cin >> p.pas;
        Fileout.write((char *)(&p), sizeof(pass));
        Fileout.close();
        cout << "\n\n\tuser nuterlized " << endl;
        cin.get();
        cin.ignore();
        system("cls");
        sign_in();
    }
    void sign_in()
    {
        char id[20];
        int c = 1, n;
        pass p;
        cout << "\n\n\tuser id :";
        cin >> id;
        cout << "\n\tPassword :";
        cin >> n;
        ifstream inFile("pass.txt", ios::binary);
        while (!inFile.eof())
        {
            inFile.read((char *)(&p), sizeof(pass));
            if (p.pas == n)
            {
                c = 0;
            }
        }
        inFile.close();
        if (c == 0)
        {
            cin.get();
            system("cls");
            main_menu();
        }
        else
        {
            cout << "\n\twrong pssword";
            cout << "\n\tpress enter to try again";
            cin.get();
            cin.ignore();
            system("cls");
            sign_in();
        }
    }
    void pas_main()
    {
        char d;
        cout << "\n\n\t01. new user :";
        cout << "\n\t02. already exist :";
        cout << "\n\tPlease Select Your Option (1-2) ";
        cin >> d;
        system("cls");
        switch (d)
        {
        case '1':
            sign_up();
            break;
        case '2':
            sign_in();
            break;
        case '/':
            main_menu();
            break;
        default:
            cout << "\n\n\t invalid choice\n";
            cin.get();
            pas_main();
        }
    }
};
main()
{
    Athentication athu;
    athu.pas_main();
    return 0;
}