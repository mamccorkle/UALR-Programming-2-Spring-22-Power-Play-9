#ifndef UALR___P2___S22___POWER_PLAY_9_ITEM_H
#define UALR___P2___S22___POWER_PLAY_9_ITEM_H

    #include <iostream>

    class Item
    {
    public:
        Item() {};
        enum class Type { sword, armor, shield, numTypes };
        Item(Type classification, int bonusValue);

        Type getClassification() const;
        int getBonusValue() const;

    private:
        Type classification{ Type::numTypes };
        int bonusValue{ 0 };

    };

    std::ostream& operator<< (std::ostream& o, const Item& src);
    bool operator< (const Item& srcL, const Item& srcR);
    int& operator+=(int& srcL, const Item& srcR);

#endif //UALR___P2___S22___POWER_PLAY_9_ITEM_H
