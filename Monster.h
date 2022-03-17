#ifndef UALR___P2___S22___POWER_PLAY_9_MONSTER_H
#define UALR___P2___S22___POWER_PLAY_9_MONSTER_H

    #include "Object.h"

    class Player;
    class Monster: public Object
    {
    public:
        Monster() {};
        Monster(const Player& player);

        void update(Player& player, std::vector<Monster>& monsters) override;

        int attack() const override;
        void defend(int damage) override;
        void print(std::ostream& o) const override;

    private:
        int AC{ 0 };

    };

#endif //UALR___P2___S22___POWER_PLAY_9_MONSTER_H
