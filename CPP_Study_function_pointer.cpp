#include <iostream>
using namespace std;

// 언리얼에서는 STL을 사용하지 않음

int Add(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}

class Item
{
public:
    Item() : _itemId(0), _rarity(0), _ownerId(0)
    {

    }
public:
    int _itemId;
    int _rarity;
    int _ownerId;
};

typedef bool(ITEM_SELECTOR)(Item* item, int value);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value) // 함수의 매개변수로 동작을 넣으면 어떨까?
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        if (selector(item, value))
            return item;
    }

    return nullptr;
}

bool IsRareItem(Item* item, int value)
{
    return item->_rarity >= value;
}

bool IsOwnerItem(Item* item, int ownerId)
{
    return item->_ownerId == ownerId;
}

int main()
{
    int a = 10;
    typedef int DATA;
    DATA* pointer = &a;

    typedef int(FUNC_TYPE) (int a, int b);
    FUNC_TYPE* fn; // int를 반환하고, int, int를 매개변수로 받는 함수 포인터 변수
    
    // 원하는 걸 넣어서 사용할 수 있음
    // fn = Add;
    fn = Sub;
    fn = &Sub; // C언어와의 호환성으로 인해 의미는 동일하지만 &를 붙여서 가독성을 주는 걸 추천

    int result = fn(1, 2);
    cout << result << endl;

    result = (*fn)(1,2); // 함수 포인터는 * 붙여도 함수 주소
    cout << result << endl;

    Item items[10] = {};
    items[3]._rarity = 2;
    Item* rareItem = FindItem(items, 10, IsRareItem, 2);
    cout << rareItem->_rarity << endl;

    return 0;
}