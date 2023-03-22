#include <iostream>
using namespace std;

struct Player
{
    int hp;
    int damage;
};

Player CreatePlayer();
void CreatePlayer(Player* player);
void CreatePlayer(Player& player);
void PrintPlayer(Player player);

int main()
{
    Player player1;
    player1 = CreatePlayer();

    Player player2;
    CreatePlayer(&player2);

    Player player3;
    PrintPlayer(player3);
    CreatePlayer(player3);
    PrintPlayer(player3);
}

Player CreatePlayer()
{
    Player ret;
    ret.hp = 120;
    ret.damage = 20;

    return ret;
}

void CreatePlayer(Player* player)
{
    player->hp = 140;
    player->damage = 40;
}

void CreatePlayer(Player& player)
{
    player.hp = 150;
    player.damage = 50;
}

void PrintPlayer(Player player)
{
    cout << player.hp << endl;
    cout << player.damage << endl;
}