#include <iostream>
#include <vector>
#include <list>
using namespace std;

enum class ItemType
{
    None,
    Armor,
    Weapon,
    Jewelry
};

enum class Rarity
{
    Common,
    Rare,
    Unique
};

class Item
{
public:
    Item() {}
    Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type) 
    {

    }
public:
    int _itemId = 0;
    Rarity _rarity = Rarity::Common;
    ItemType _type = ItemType::None;
};

int main()
{
    // lambda
    // 함수 객체를 빠르게 만드는 문법
    vector<Item> v;
    v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
    v.push_back(Item(2, Rarity::Common, ItemType::Armor));
    v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
    v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

    // 람다 자체로 C++에 새로운 기능이 들어간 것은 아님
    {
        struct IsUniqueItem
        {
            bool operator()(Item& item)
            {
                return item._rarity == Rarity::Unique;
            }
        };

        // 클로저 = 람다에 의해 만들어진 실행시점 객체
        auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique; };
        
        // auto findIt = std::find_if(v.begin(), v.end(), IsUniqueItem());
        auto findIt = std::find_if(v.begin(), v.end(), isUniqueLambda);
        if (findIt != v.end())
            cout << "찾음!" << endl;
    }

    {
        struct FindItemById
        {

            FindItemById(int itemId) : _itemId(itemId)
            {

            }

            bool operator()(Item& item)
            {
                return item._itemId == _itemId;
            }

            int _itemId;
        };

        int itemId = 4;
        Rarity rarity = Rarity::Unique;
        ItemType type = ItemType::Weapon;

        // [] 캡쳐 = 함수 객체 내부에 변수를 저장하는 개념과 유사
        // 사진을 캡쳐하듯 일종의 스냅샷을 찍는다고 이해
        // 기본 캡쳐 모드 : 값 방식(=) 참조 방식(&)
        auto findByItemByLambda = [=](Item& item) { return item._itemId == itemId; };

        auto findIt = std::find_if(v.begin(), v.end(), FindItemById(itemId));
        if (findIt != v.end())
            cout << "찾음!" << endl;

        // 캡쳐할 변수를 하나 하나 지정해서 사용해주는 것이 좋음
        // - 어떤 변수를 건드릴지 모르기 때문
        // - 복사를 해도 예측하지 못하는 경우가 있음
        // -- 객체 내부에서 this를 캡쳐해서 사용하는데,
        auto FindByItem = [&itemId, &type](Item& item) { return itemId == item._itemId; };

        class Knight
        {
        public:
            auto ResetHpJob()
            {
                auto f = [this]()
                {
                    this->_hp = 200;
                };

                return f;
            }
        private:
            int _hp = 100;
        };

        Knight* k = new Knight();
        auto job = k->ResetHpJob();
        delete k;
        job(); // 에러가 남 this->_hp에서 이미 해제된 this를 참조하기 때문
    }

    return 0;
}