#ifndef UALR___P2___S22___POWER_PLAY_9_PLAYER_H
#define UALR___P2___S22___POWER_PLAY_9_PLAYER_H

    #include "Object.h"
    #include "Item.h"

    class Player: public Object
    {
    public:
        Player();

        void levelUp();
        void update( std::vector<Object*> ) override;

        int getLevel() const;
        int getSP() const;

        int attack() const override;
        void defend(int damage) override;
        void print(std::ostream& o) const override;

        std::map<Item::Type, Item> getInventory() const;

        void heal();

    private:
        std::map<Item::Type, Item> inventory;
        int SP{ 0 };

    };

    std::ostream& operator<< (std::ostream& o, const std::map<Item::Type, Item>& src);

#endif //UALR___P2___S22___POWER_PLAY_9_PLAYER_H
