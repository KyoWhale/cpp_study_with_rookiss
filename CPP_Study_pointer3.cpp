#include <iostream>
using namespace std;

struct Player
{
    int hp;
    int damage;
};

Player CreatePlayer();
void CreatePlayer(Player* player);

int main()
{
    Player player1;
    player1 = CreatePlayer();

    Player player2;
    CreatePlayer(&player2);
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