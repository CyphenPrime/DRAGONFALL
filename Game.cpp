#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

//Global Variables
char name[20];
int select;
int player[7]={100,10,10,1,0,0,0};
int fightmob = 1;
int rngp;
int rngm;
int z=1;

//Mobs
int skeleton[4]={30,5,5};
int zombie[4]={40,6,6};
int centaur[4]={100,10,15};
int ghoul[4]={150,15,15};
int dragon[4]={300,20,20};

//Functions

//Talk to Edwin
void Edwintalk()
{
    cout << "\033[2J\033[H";
    do
    {
    cout<<"Edwin: Hey! What can i help you with?\n\n";
    cout<<"System: Ask about:";
    cout<<"\n1.What is the dungeon like?\n2.How do i get to the Boss room?\n3.How are the villagers?\n4.Nevermind.";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n\nEdwin: The dungeon is mostly straight and easy to understand but has some traps and undead to be wary of.\n\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    else if(select==2)
    {
        cout<<"\n\nEdwin: you have to defeat the 3 guardians, although i dont know what they look like, they all possess a key which is needed to open the door to the Dragons Den.\n\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    else if(select==3)
    {
        cout<<"\n\nEdwin: Well, The villagers and I have been struglling a lot but we have been sleeping sound now that you are here.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\n"<<name<<": Sure...";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\nEdwin: Hahaha! Im sure about it as well.\n\n";
    }
    }
    while(select!=4);
}

//Talk to Old man
void oldMan()
{
   cout << "\033[2J\033[H";
   cout<<"Old Man: Hello....\n\n";
   this_thread::sleep_for(chrono::seconds(2));
    do
    {
    cout << "\033[2J\033[H";
    cout<<"System: Ask about:";
    cout<<"\n1.Who are you?\n2.How long have you been here?\n3.Have you tried fighting the dragon?\n4.I should take my leave now.";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n\nMerlin: My name is Merlin, i used to be an adventurer when i was about your age.\n\n";
        this_thread::sleep_for(chrono::seconds(3));
    }
    else if(select==2)
    {
        cout<<"\n\nMerlin: Ive been here far too long to count.\n\n";
        this_thread::sleep_for(chrono::seconds(3));
    }
    else if(select==3)
    {
        cout<<"\n\nMerlin: Well, Me and my friends used to be so naive...\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"\n"<<name<<": Sure...";
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"\nMerlin: Its alright..\n\n";
        this_thread::sleep_for(chrono::seconds(2));
    }
    }
    while(select!=4);
}



//Check Inventory
void Inventory()
{
    cout << "\033[2J\033[H";
    cout<<"--Inventory--\n\n";
    cout<<"Level: "<<player[3]<<endl;
    cout<<"Health: "<<player[0]<<endl;
    cout<<"Attack: "<<player[1]<<endl;
    cout<<"Defense:"<<player[2]<<endl;
    cout<<"Green Key: "<<player[4]<<endl;
    cout<<"Red Key: "<<player[5]<<endl;
    cout<<"Grey Key:"<<player[6]<<endl<<endl;
}

//Heal
void Inn()
{
cout<<"\nDo you want to heal?\n\n1.Heal";
cout<<"\n"<<name<<": ";
cin>>select;
if(select==1)
{
    if(player[3]==1)
    {
        player[0]=100;
    }
    else if(player[3]==2)
    {
        player[0]=150;
    }
    else if(player[3]==3)
    {
        player[0]=200;
    }
    else if(player[3]==4)
    {
        player[0]=250;
    }
    else if(player[3]==5)
    {
        player[0]=300;
    }
}
}

//Fight Mobs
void Fight()
{
    //Skeleton Fight
    if(z==1)
    {
      while (skeleton[0] > 0) 
     {
        cout << "\033[2J\033[H";
        cout << "--FIGHT--\n\n";
        cout << "--SKELETON--\n";
        cout << "HP: " << skeleton[0] << endl;
        cout << "Attack: " << skeleton[1] << endl;
        cout << "Defense: " << skeleton[2] << "\n\n";
        cout << "--" << name << "--\n";
        cout << "HP: " << player[0] << endl;
        cout << "Attack: " << player[1] << "\n";
        cout << "Defense: " << player[2] << "\n\n";
        cout << "What do you want to do?\n";
        cout << "1. Attack\n";
        cout << "2. Dodge\n\n";
        cout << name << ": ";
        cin >> select;

        // Validate input
        if (select != 1 && select != 2) {
            cout << "Invalid choice! Try again.\n";
            this_thread::sleep_for(chrono::seconds(2));
            continue;
        }

        // Player's turn
        if (select == 1)
        // Attack 
            { 
                rngp = (rand() % 10) + 1;
                if (rngp > 8) {
                    cout << "\nCritical Strike! Double damage dealt.\n";
                    skeleton[0] -= player[1] * 2;
                } else if (rngp <= 2) {
                    cout << "Attack Missed.\n";
                } else {
                    cout << "Attacked for " << player[1] << " damage.\n";
                    skeleton[0] -= player[1];
                }
            } 
        else if (select == 2)
        // Dodge
            {
                rngp = (rand() % 100) + 1;
                if (rngp <= player[2]) {
                    cout << "Dodged the attack successfully!\n";
                    this_thread::sleep_for(chrono::seconds(3));
                    continue;
                } else {
                    cout << "Failed to dodge the attack.\n";
                }
            }

        // Check if skeleton is defeated
        if (skeleton[0] <= 0) {
            cout << "You defeated the Skeleton!\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }

        // Skeleton's turn
        cout << "--Skeleton's turn--\n";
        this_thread::sleep_for(chrono::seconds(2));
        rngm = (rand() % 10) + 1;
        if (rngm > 8) {
            cout << "Critical Strike! You take double damage.\n";
            player[0] -= skeleton[1] * 2;
        } else if (rngm <= 2) {
            cout << "Skeleton's attack missed.\n";
        } else {
            cout << "Skeleton attacked for " << skeleton[1] << " damage.\n";
            player[0] -= skeleton[1];
        }

        // Check if player is defeated
        if (player[0] <= 0) {
            cout << "You died. Restart the game.\n";
            break;
        }

        this_thread::sleep_for(chrono::seconds(1));
     }
    }

    //Zombie Fight
    else if(z==2)
    {
      while (zombie[0] > 0) 
     {
        cout << "\033[2J\033[H";
        cout << "--FIGHT--\n\n";
        cout << "--ZOMBIE--\n";
        cout << "HP: " << zombie[0] << endl;
        cout << "Attack: " << zombie[1] << endl;
        cout << "Defense: " << zombie[2] << "\n\n";
        cout << "--" << name << "--\n";
        cout << "HP: " << player[0] << endl;
        cout << "Attack: " << player[1] << "\n";
        cout << "Defense: " << player[2] << "\n\n";
        cout << "What do you want to do?\n";
        cout << "1. Attack\n";
        cout << "2. Dodge\n\n";
        cout << name << ": ";
        cin >> select;

        // Validate input
        if (select != 1 && select != 2) {
            cout << "Invalid choice! Try again.\n";
            this_thread::sleep_for(chrono::seconds(2));
            continue;
        }

        // Player's turn
        if (select == 1)
        // Attack 
            { 
                rngp = (rand() % 10) + 1;
                if (rngp > 8) {
                    cout << "\nCritical Strike! Double damage dealt.\n";
                    zombie[0] -= player[1] * 2;
                } else if (rngp <= 2) {
                    cout << "Attack Missed.\n";
                } else {
                    cout << "Attacked for " << player[1] << " damage.\n";
                    zombie[0] -= player[1];
                }
            } 
        else if (select == 2)
        // Dodge
            {
                rngp = (rand() % 100) + 1;
                if (rngp <= player[2]) {
                    cout << "Dodged the attack successfully!\n";
                    this_thread::sleep_for(chrono::seconds(3));
                    continue;
                } else {
                    cout << "Failed to dodge the attack.\n";
                }
            }

        // Check if zombie is defeated
        if (zombie[0] <= 0) {
            cout << "You defeated the Zombie!\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }

        //Zombie's turn
        cout << "--Zombie's turn--\n";
        this_thread::sleep_for(chrono::seconds(2));
        rngm = (rand() % 10) + 1;
        if (rngm > 8) {
            cout << "Critical Strike! You take double damage.\n";
            player[0] -= zombie[1] * 2;
        } else if (rngm <= 2) {
            cout << "Zombie's attack missed.\n";
        } else {
            cout << "Zombie attacked for " << zombie[1] << " damage.\n";
            player[0] -= zombie[1];
        }

        // Check if player is defeated
        if (player[0] <= 0) {
            cout << "You died. Restart the game.\n";
            break;
        }

        this_thread::sleep_for(chrono::seconds(1));
     }
    }

    //Centaur Fight
    else if(z==3)
    {
      while (centaur[0] > 0) 
     {
        cout << "\033[2J\033[H";
        cout << "--FIGHT--\n\n";
        cout << "--CENTAUR--\n";
        cout << "HP: " << centaur[0] << endl;
        cout << "Attack: " << centaur[1] << endl;
        cout << "Defense: " << centaur[2] << "\n\n";
        cout << "--" << name << "--\n";
        cout << "HP: " << player[0] << endl;
        cout << "Attack: " << player[1] << "\n";
        cout << "Defense: " << player[2] << "\n\n";
        cout << "What do you want to do?\n";
        cout << "1. Attack\n";
        cout << "2. Dodge\n\n";
        cout << name << ": ";
        cin >> select;

        // Validate input
        if (select != 1 && select != 2) {
            cout << "Invalid choice! Try again.\n";
            this_thread::sleep_for(chrono::seconds(2));
            continue;
        }

        // Player's turn
        if (select == 1)
        // Attack 
            { 
                rngp = (rand() % 10) + 1;
                if (rngp > 8) {
                    cout << "\nCritical Strike! Double damage dealt.\n";
                    centaur[0] -= player[1] * 2;
                } else if (rngp <= 2) {
                    cout << "Attack Missed.\n";
                } else {
                    cout << "Attacked for " << player[1] << " damage.\n";
                    centaur[0] -= player[1];
                }
            } 
        else if (select == 2)
        // Dodge
            {
                rngp = (rand() % 100) + 1;
                if (rngp <= player[2]) {
                    cout << "Dodged the attack successfully!\n";
                    this_thread::sleep_for(chrono::seconds(3));
                    continue;
                } else {
                    cout << "Failed to dodge the attack.\n";
                }
            }

        // Check if centaur is defeated
        if (centaur[0] <= 0) {
            cout << "You defeated the Centaur!\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }

        //Centaur's turn
        cout << "--Centaur's turn--\n";
        this_thread::sleep_for(chrono::seconds(2));
        rngm = (rand() % 10) + 1;
        if (rngm > 8) {
            cout << "Critical Strike! You take double damage.\n";
            player[0] -= centaur[1] * 2;
        } else if (rngm <= 2) {
            cout << "Centaur's attack missed.\n";
        } else {
            cout << "Centaur attacked for " << centaur[1] << " damage.\n";
            player[0] -= centaur[1];
        }

        // Check if player is defeated
        if (player[0] <= 0) {
            cout << "You died. Restart the game.\n";
            break;
        }

        this_thread::sleep_for(chrono::seconds(1));
     }
    }

     //Ghoul Fight
    else if(z==4)
    {
      while (ghoul[0] > 0) 
     {
        cout << "\033[2J\033[H";
        cout << "--FIGHT--\n\n";
        cout << "--GHOUL--\n";
        cout << "HP: " << ghoul[0] << endl;
        cout << "Attack: " << ghoul[1] << endl;
        cout << "Defense: " << ghoul[2] << "\n\n";
        cout << "--" << name << "--\n";
        cout << "HP: " << player[0] << endl;
        cout << "Attack: " << player[1] << "\n";
        cout << "Defense: " << player[2] << "\n\n";
        cout << "What do you want to do?\n";
        cout << "1. Attack\n";
        cout << "2. Dodge\n\n";
        cout << name << ": ";
        cin >> select;

        // Validate input
        if (select != 1 && select != 2) {
            cout << "Invalid choice! Try again.\n";
            this_thread::sleep_for(chrono::seconds(2));
            continue;
        }

        // Player's turn
        if (select == 1)
        // Attack 
            { 
                rngp = (rand() % 10) + 1;
                if (rngp > 8) {
                    cout << "\nCritical Strike! Double damage dealt.\n";
                    ghoul[0] -= player[1] * 2;
                } else if (rngp <= 2) {
                    cout << "Attack Missed.\n";
                } else {
                    cout << "Attacked for " << player[1] << " damage.\n";
                    ghoul[0] -= player[1];
                }
            } 
        else if (select == 2)
        // Dodge
            {
                rngp = (rand() % 100) + 1;
                if (rngp <= player[2]) {
                    cout << "Dodged the attack successfully!\n";
                    this_thread::sleep_for(chrono::seconds(3));
                    continue;
                } else {
                    cout << "Failed to dodge the attack.\n";
                }
            }

        // Check if ghoul is defeated
        if (ghoul[0] <= 0) {
            cout << "You defeated the Ghoul!\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }

        //Ghoul's turn
        cout << "--Ghoul's turn--\n";
        this_thread::sleep_for(chrono::seconds(2));
        rngm = (rand() % 10) + 1;
        if (rngm > 8) {
            cout << "Critical Strike! You take double damage.\n";
            player[0] -= ghoul[1] * 2;
        } else if (rngm <= 2) {
            cout << "Ghoul's attack missed.\n";
        } else {
            cout << "Ghoul attacked for " << ghoul[1] << " damage.\n";
            player[0] -= ghoul[1];
        }

        // Check if player is defeated
        if (player[0] <= 0) {
            cout << "You died. Restart the game.\n";
            break;
        }

        this_thread::sleep_for(chrono::seconds(1));
     }
    }

    //Dragon Fight
    else if(z==5)
    {
      while (dragon[0] > 0) 
     {
        cout << "\033[2J\033[H";
        cout << "--FIGHT--\n\n";
        cout << "--DRAGON--\n";
        cout << "HP: " << dragon[0] << endl;
        cout << "Attack: " << dragon[1] << endl;
        cout << "Defense: " << dragon[2] << "\n\n";
        cout << "--" << name << "--\n";
        cout << "HP: " << player[0] << endl;
        cout << "Attack: " << player[1] << "\n";
        cout << "Defense: " << player[2] << "\n\n";
        cout << "What do you want to do?\n";
        cout << "1. Attack\n";
        cout << "2. Dodge\n\n";
        cout << name << ": ";
        cin >> select;

        // Validate input
        if (select != 1 && select != 2) {
            cout << "Invalid choice! Try again.\n";
            this_thread::sleep_for(chrono::seconds(2));
            continue;
        }

        // Player's turn
        if (select == 1)
        // Attack 
            { 
                rngp = (rand() % 10) + 1;
                if (rngp > 8) {
                    cout << "\nCritical Strike! Double damage dealt.\n";
                    dragon[0] -= player[1] * 2;
                } else if (rngp <= 2) {
                    cout << "Attack Missed.\n";
                } else {
                    cout << "Attacked for " << player[1] << " damage.\n";
                    dragon[0] -= player[1];
                }
            } 
        else if (select == 2)
        // Dodge
            {
                rngp = (rand() % 100) + 1;
                if (rngp <= player[2]) {
                    cout << "Dodged the attack successfully!\n";
                    this_thread::sleep_for(chrono::seconds(3));
                    continue;
                } else {
                    cout << "Failed to dodge the attack.\n";
                }
            }

        // Check if dragon is defeated
        if (dragon[0] <= 0) {
            cout << "You defeated the Dragon!\n";
            this_thread::sleep_for(chrono::seconds(2));
            break;
        }

        //Dragon's turn
        cout << "--Dragon's turn--\n";
        this_thread::sleep_for(chrono::seconds(2));
        rngm = (rand() % 10) + 1;
        if (rngm > 8) {
            cout << "Critical Strike! You take double damage.\n";
            player[0] -= dragon[1] * 2;
        } else if (rngm <= 2) {
            cout << "Dragon's attack missed.\n";
        } else {
            cout << "Dragon attacked for " << dragon[1] << " damage.\n";
            player[0] -= dragon[1];
        }

        // Check if player is defeated
        if (player[0] <= 0) {
            cout << "You died. Restart the game.\n";
            break;
        }

        this_thread::sleep_for(chrono::seconds(1));
     }
    }
}



int main()
{
srand(time(0)); 
main:
    cout << "\033[2J\033[H";
    cout<<"--DRAGONFALL--"<<endl;
    cout<<"MAIN MENU"<<endl;
    cout<<"1.Start \n2.Info \n3.Exit game\n";
    cout<<"\n\nEnter option : ";
    cin>>select;
    switch (select)
    {
        case 1:
            goto intro;
            break;
        case 2:
            goto info;
            break;
        case 3:
            goto exit;
            break;
    }


info:
    cout<<"\nINFO"<<endl;
    cout<<"DragonFall is a Text-Based RPG made for the Num-pad where you are a knight who is prophesized to slay the Dragon."<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"Controls:\nuse number keys to input and select from the choices provided by the system"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"Credits:\nMade by Muhammad Usman"<<endl<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"1.Main Menu\n2.Exit Game\n\n";
    cout<<"System: ";
    cin>>select;
    if(select==1)
    {
        goto main; 
    }
    else if(select==2)
    {
        goto exit;
    }


intro:
    cout<<"What is your name?: ";
    cin>>name;
    cout<<"Do you want to skip intro?\n\n1.Play intro\n2.Skip intro"<<endl;
    cout<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\nLong ago Aurendor, a world filled with swords and sorcery and mythical creatures fell ill to the darkness. The Undead started to appear and waged wars against the humans. After suffering a huge loss, the undead resorted to underhanded tactics and started secretly enslacing humans."<<endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"Wanting revenge, the undead started sacrificing the slaves to fuel the birth of the evil incarnate, The Great Dragon.\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"When the humans noticed due to the sheer amount of missing reports, it was already too late. The sky turned red and with a loud screech the dragon had alerted the world of its presence.\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"Grindell, humanities mightiest mage had an intense battle with the dragon. Both sides suffered heavy damage, enough to make the dragon go into hiding in its dungeon.\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"Many centuries passed and you the 'Golden Child', a person prophesized to slay the dragon and end the undead completely was born.\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"Since birth you had been training as a knight and after 20 years you are finally ready to slay the dragon and you set off for StoneHaven a small village on the outskirts of the Dragons Dungeon.\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\nSystem: Start?\n\n1.Yes\n2.Exit Game";
        cout<<"\n\n"<<name<<": ";
        cin>>select;
        if(select==1)
        {
            goto game;
        }
        else if(select==2)
        {
            goto exit;
        }

    }
   

game:
    cout << "\033[2J\033[H";
    cout<<"Edwin: Hello "<<name<<"! Welcome to StoneHaven."<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"My name is Edwin, the owner of the Keepers Inn right outside of the Dragons Dungeon."<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"As you can imagine business hasnt been boomin, the dragon has been striking fear in the hearts of all of StoneHaven but the villagers can have a bit of peace of mind now that you are here."<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"Oh, and dont be shy to ask me anything!"<<endl<<endl;
    this_thread::sleep_for(chrono::seconds(3));


Stone:
    cout << "\033[2J\033[H";
    cout<<"--StoneHaven--\n\n";


StoneS:
    cout<<"What do you want to do?\n\n1.Talk to Edwin\n2.Go to Inn\n3.Go to Dungeon\n4.Inventory\n\n";
    cout<<name<<": ";
    cin>>select;
    if(select==1)
    {
        Edwintalk();
        goto Stone;
    }
    else if(select==2)
    {
        goto Inn;
    }
    else if(select==3)
    {
        goto DE;
    }
    else if(select==4)
    {
        Inventory();
        goto StoneS;
    }


Inn:
    cout << "\033[2J\033[H";
    cout<<"--KEEPERS INN--";
    cout<<"\n\nWelcome to the Keepers Inn!.";
    Inn();
    this_thread::sleep_for(chrono::seconds(3));
    cout<<"\n\nHEALTH RESTORED";
    this_thread::sleep_for(chrono::seconds(2));
    goto Stone;

//Dungeon Entrance
DE:
    cout << "\033[2J\033[H";
    cout<<"--DUNGEON ENTRANCE--\n\n";
    cout<<"Welcome to the Dungeon Entrance"<<endl;
    cout<<"Do you want to Enter?"<<endl<<endl;
    cout<<"NOTE: Once you enter you cannot exit.";
    cout<<"\n1.Enter\n2.Exit";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
        {
            goto D1;
        }
    else if(select==2)
        {
            goto Stone;
        }

//First Dungeon Room
D1:
    cout<< "\033[2J\033[H";
d11:   
    cout<<"--DUNGEON ROOM 1--\n\n";
    cout<<"1.Move Forward\n2.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        cout<<"You encounter a skeleton.";
        this_thread::sleep_for(chrono::seconds(2));
        Fight();
        z++;
        if(player[0]<=0)
        {
            goto exit;
        }
    }
    else if(select==2)
    {
        Inventory();
        goto d11;
    }
    cout<< "\033[2J\033[H";
    cout<<"--DUNGEON ROOM 1--\n\n";
    cout<<"Level Up!\nHP increased\nAttack increased\nDefense increased\n\n";
    player[1]=15;
    player[2]=15;
    player[3]=2;
d12:
    cout<<"What do you want to do?\n";
    cout<<"1.Move Forward\n2.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        goto D2;
    }
    else if(select==2)
    {
        Inventory();
        goto d12;
    }

//Second Room   
D2:
    cout<< "\033[2J\033[H";
d21:   
    cout<<"--DUNGEON ROOM 2--\n\n";
    cout<<"You see a lantern.\n";
    cout<<"1.Light Lantern\n2.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        cout<<"You encounter a zombie.";
        this_thread::sleep_for(chrono::seconds(2));
        Fight();
        z++;
        if(player[0]<=0)
        {
            goto exit;
        }
    }
    else if(select==2)
    {
        Inventory();
        goto d21;
    }
    cout<< "\033[2J\033[H";
    cout<<"--DUNGEON ROOM 2--\n\n";
    cout<<"Level Up!\nHP increased\nAttack increased\nDefense increased\n\n";
    player[1]=20;
    player[2]=20;
    player[3]++;
d22:
    cout<<"What do you want to do?\n";
    cout<<"1.Move Forward\n2.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        goto D3;
    }
    else if(select==2)
    {
        Inventory();
        goto d22;
    }


//Third Dungeon Room
D3:
cout<< "\033[2J\033[H";
d31:
cout<<"--DUNGEON ROOM 3--\n\n";
cout<<"What do you want to do?\n";
cout<<"1.Look around\n2.Check Inventory\n\n";
cout<<name<<": ";
cin>>select;
if(select==1)
{
 cout<<"you found a campfire.\n";
 cout<<"you sat down to rest.\n";
 Inn();
 cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
 cout<<"\n\nHEALTH RESTORED";
 this_thread::sleep_for(chrono::seconds(1));
 cout<< "\033[2J\033[H";
 goto d32;
 

}
else if(select==2)
{
    Inventory();
    goto d31;
}
d32:
cout<<"--DUNGEON ROOM 3--\n\n";
cout<<"What do you want to do?\n";
cout<<"1.Move Forward\n2.Check Inventory\n\n";
cout<<name<<": ";
cin>>select;
if(select==1)
{
    cout<<"Next room has Centaur(miniboss).\n\n";
    cout<<"Do you want to continue?\n";
    cout<<"1.yes\n2.no\n\n";
    cout<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        goto D4;
    }
    else if(select==2)
    {
        goto d32;
    }
    
}
else if(select==2)
{
    Inventory();
    goto d32;
}


//Fourth Room (centaur):
D4:
    cout<< "\033[2J\033[H";
d41:   
    cout<<"--DUNGEON ROOM 4--\n\n";
    cout<<"You see a Centaur resting in the middle of the room.\n";
    cout<<"1.Fight\n2.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        Fight();
        z++;
        if(player[0]<=0)
        {
            goto exit;
        }
    }
    else if(select==2)
    {
        Inventory();
        goto d41;
    }
    cout<< "\033[2J\033[H";
    cout<<"--DUNGEON ROOM 4--\n\n";
    cout<<"You Obtained Green Key.\n\n";
    player[4]=1;
    cout<<"Level Up!\nHP increased\nAttack increased\nDefense increased\n\n";
    player[1]=25;
    player[2]=25;
    player[3]++;
d42:
    cout<<"What do you want to do?\n";
    cout<<"1.Move Forward\n2.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        goto D5;
    }
    else if(select==2)
    {
        Inventory();
        goto d42;
    }


//Fifth Room
D5:
    cout<< "\033[2J\033[H";
d51:   
    cout<<"--DUNGEON ROOM 5--\n\n";
    cout<<"You see two paths.\n";
    cout<<"1.Go Left\n2.Go Right\n3.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        cout<<"You reach the next room.";
        this_thread::sleep_for(chrono::seconds(2));
        goto D6;
    }
    else if(select==2)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        cout<<"You fell in a pitfall.\n-10 Health";
        player[0]-10;
        this_thread::sleep_for(chrono::seconds(2));
        goto D6;
    }
    else if(select==3)
    {
        Inventory();
        goto d51;
    }


//Sixth Dungeon Room
D6:
cout<< "\033[2J\033[H";
d61:   
    cout<<"--DUNGEON ROOM 6--\n\n";
    cout<<"You see an old man in the corner.\n";
    cout<<"1.Aproach him\n2.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        oldMan();
        cout<< "\033[2J\033[H";
        cout<<"--DUNGEON ROOM 6--\n\n";
        cout<<"Merlin: Hey before you leave let me give you something and enchant you.";
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        cout<<"YOU HAVE BEEN ENCHANTED AND GAINED EXPERIENCE.\n";
        cout<<"YOU GAIN RED KEY.\n\n";
        player[5]=1;
        cout<<"Level Up!\nHP increased\nAttack increased\nDefense increased\n\n";
        player[1]=30;
        player[2]=30;
        player[3]++;
        this_thread::sleep_for(chrono::seconds(3));
        cout<<"You move forward.";
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        cout<<"You reach the next room.";
        this_thread::sleep_for(chrono::seconds(2));
        goto D7; 
    

    }
    else if(select==2)
    {
       Inventory();
        goto d61; 
    }

//Seventh Dungeon Room
D7:
    cout<< "\033[2J\033[H";
d71:   
    cout<<"--DUNGEON ROOM 7--\n\n";
    cout<<"You see a Ghoul charging towards you.\n";
    cout<<"\n.";
    this_thread::sleep_for(chrono::seconds(1));
    cout<<".";
    this_thread::sleep_for(chrono::seconds(1));
    cout<<".\n\n";
    Fight();
    z++;
    if(player[0]<=0)
    {
    goto exit;
    }
    cout<< "\033[2J\033[H";
    cout<<"--DUNGEON ROOM 7--\n\n";
    cout<<"You Obtained Grey Key.\n\n";
    player[6]=1;
    cout<<"Level Up!\nHP increased\nAttack increased\nDefense increased\n\n";
    player[1]=30;
    player[2]=30;
    player[3]++;
    this_thread::sleep_for(chrono::seconds(3));
d72:
    cout<< "\033[2J\033[H";
    cout<<"What do you want to do?\n";
    cout<<"1.Move Forward\n2.Check Inventory";
    cout<<"\n\n"<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        goto D8;
    }
    else if(select==2)
    {
        Inventory();
        goto d72;
    }


//Eight Dungeon Room
D8:
cout<< "\033[2J\033[H";
d81:
cout<<"--DUNGEON ROOM 8--\n\n";
cout<<"What do you want to do?\n";
cout<<"1.Look around\n2.Check Inventory\n\n";
cout<<name<<": ";
cin>>select;
if(select==1)
{
 cout<<"you found a campfire.\n";
 cout<<"you sat down to rest.\n";
 player[0]=300;
 cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
 cout<<"\n\nHEALTH RESTORED";
 this_thread::sleep_for(chrono::seconds(1));
 cout<< "\033[2J\033[H";
 goto d82;
 

}
else if(select==2)
{
    Inventory();
    goto d31;
}
d82:
cout<<"--DUNGEON ROOM 8--\n\n";
cout<<"What do you want to do?\n";
cout<<"1.Move Forward\n2.Check Inventory\n\n";
cout<<name<<": ";
cin>>select;
if(select==1)
{
    cout<<"Up next is the Dragons den.\n\n";
    cout<<"Do you want to continue?\n";
    cout<<"1.yes\n2.no\n\n";
    cout<<name<<": ";
    cin>>select;
    if(select==1)
    {
        cout<<"\n.";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<".\n\n";
        cout<<"You have all three keys.";
        this_thread::sleep_for(chrono::seconds(2));
        goto DD;
    }
    else if(select==2)
    {
        goto d82;
    }
    
}
else if(select==2)
{
    Inventory();
    goto d82;
}

DD:
cout<< "\033[2J\033[H";
dd1:
cout<<"--DRAGONS DEN--\n\n";
cout<<"The dragon is waiting for you patiently.\n";
cout<<"what do you want to do?\n\n";
cout<<"1.Check inventory\n2.Talk to Dragon\n\n";
cout<<name<<": ";
cin>>select;
if(select==1)
{
    Inventory();
    goto dd1;
}
else if(select==2)
{
    goto dd2;
}
dd2:
this_thread::sleep_for(chrono::seconds(2));
cout<<"Dragon: At last! I have been dreaming about this day. Grindell promised me a worthy challenger\n";
this_thread::sleep_for(chrono::seconds(2));
cout<<name<<": Is that why you have been hiding here?\n";
cout<<"Dragon: HIDING? what kind of blasphemy is this?. I have simply had been holding my end of the bargain.\n";
cout<<name<<": Yeah right, as if you would keep a promise.\n";
cout<<"Dragon: You are soon going to regret this.\n";
this_thread::sleep_for(chrono::seconds(3));
cout<<"\n.";
this_thread::sleep_for(chrono::seconds(1));
cout<<".";
this_thread::sleep_for(chrono::seconds(1));
cout<<".\n\n";
Fight();
cout<< "\033[2J\033[H";
cout<<"CONGRAGULATIONS ON COMPLETING THE GAME.\n\n";
exit:
cout<<"Thanks for playing DRAGONFALL!!";
return 0;
}   