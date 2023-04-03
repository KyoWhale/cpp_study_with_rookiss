#include <iostream>
using namespace std;

enum ItemType
{
    IT_WEAPON = 1,
    IT_ARMOR = 2,
};

class Knight
{
public:
    int _hp = 10;
};

class Item
{
public:
    Item()
    {
        cout << "Item()" << endl;
    }
    Item(int itemType) : _itemType(itemType)
    {
        cout << "Item(int)" << endl;
    }
    Item(const Item& item)
    {
        cout << "Item(const Item&)" << endl;
    }
    virtual ~Item()
    {
        cout << "~Item()" << endl;
    }
public:
    int _itemType = 0;
    int _itemDbId = 0;

    char _dummy[4096] = {};
};

class Weapon : public Item
{
public:
    Weapon() : Item(IT_WEAPON)
    {
        cout << "Weapon()" << endl;
        _damage = rand() % 100;
    }
    ~Weapon()
    {
        cout << "~Weapon()" << endl;
    }
public:
    int _damage = 0;
};

class Armor : public Item
{
public:
    Armor() : Item(IT_ARMOR)
    {
        cout << "Armor()" << endl;
    }
    ~Armor()
    {
        cout << "~Armor()" << endl;
    }
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* itemPtr)
{

}

int main() 
{
    {
        Item item;
        Item* itemPtr = new Item();

        TestItem(item);
        TestItem(*itemPtr);

        TestItemPtr(&item);
        TestItemPtr(itemPtr);

        cout << " ---------------------------------- " << endl;

        Item item2[5];
        Item* itemPtr2[5];

        for (int i = 0; i < 5; i++)
            itemPtr2[i] = new Item();

        for (int i = 0; i < 5; i++)
            delete itemPtr2[i];

        cout << " 복습 끝 " << endl;
    }

    {
        // Stack [ 주소 ] -> Heap [ _hp(4) ]
        Knight* knight = new Knight();

        // 암시적으로 NO
        // 명시적으로 OK
        // Stack [ 주소 ] -> Heap [ _hp(4) ] ??
        Item* item = (Item*)knight;
    }        

    // 부모 -> 자식 변환 테스트
    {
        Item* item = new Item();
        Weapon* weapon = (Weapon*)item;
        // 할당된 메모리를 넘어서 접근하기에 위험
        weapon->_damage = 10;

        delete item;
    }
    
    // 자식 -> 부모 변환 테스트
    {
        Weapon* weapon = new Weapon();
        // 암시적으로도 됨
        Item* item = weapon;

        delete weapon;
    }

    // 명시적으로 타입 변환할 때는 항상 조심해야한다
    // 암시적으로 될 때는 안전하다?
    // -> 평생 명시적으로 타입 변환은 안 하면 되는거 아닌가?
    srand((unsigned int)time(nullptr));
    Item* inventory[20] = {};
    {

        for (int i = 0; i < 20; i++)
        {
            int randValue = rand() % 2;
            switch (randValue)
            {
            case 0:
                inventory[i] = new Weapon();
                break;
            case 1:
                inventory[i] = new Armor();
                break;
            }
        }

        for (int i = 0; i < 20; i++)
        {
            Item* item = inventory[i];
            if (item == nullptr)
                continue;

            if (item->_itemType == IT_WEAPON)
            {
                Weapon* weapon = (Weapon*)item; // 위험함
                cout << "Weapon Damage : " << weapon->_damage << endl;
            }
        }
    }

    // --------------------------매우 중요--------------------------
    {
        for (int i = 0; i < 20; i++)
        {
            Item* item = inventory[i];
            if (item == nullptr)
                continue;

            delete item; // item의 소멸자만 호출함
            // Item 클래스의 소멸자를 virtual로 구현하게 되면 알아서 자식 소멸자도 버추얼이 되므로 제대로 동작함
        }
    }

    // 결론
    // - 포인터 vs 일반 타입 : 차이를 이해하자
    // - 포인터 사이의 타입 변환(캐스팅)을 할 때는 매우 매우 조심해야 한다!!
    // - 부모 -자식 관계에서 부모 클래스의 소멸자에는 virutal을 붙이자

    return 0;
}