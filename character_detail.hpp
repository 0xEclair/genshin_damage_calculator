#pragma once

struct ElementalMastery {
    constexpr auto bonus_multiplier() const {
        return (278.0 * value) / (value + 1400);
    }

    constexpr auto compare(auto value) const {
        return (1 + bonus_multiplier(value) / 100) / (1 + bonus_multiplier(value) / 100);
    }

    int value;
};

constexpr auto level_multiplier = [](auto u, auto monster) {
    return (0.0 + u + 100) / (u + monster + 200);
};

class CharacterDetail {
public:
    constexpr CharacterDetail(int hp, int attack, int em, bool sngw, double skill_mul, double critical_mul, double elemental_damage_mul)
        :hp_max_(hp), attack_(attack), em_{ em },
         shimenawa_(sngw),
         skill_damage_multiplier_(skill_mul),
         critical_damage_(critical_mul),
         elemental_damage_bonus_(elemental_damage_mul) {
        
    }

    constexpr auto damage() const {
        auto v =
            attack_ * (skill_damage_multiplier_ / 100) *
            (1 + critical_damage_ / 100) *
            1.5 * (1 + em_.bonus_multiplier() / 100) *
            ((shimenawa_ ? 1.5 : 1) + elemental_damage_bonus_ / 100) *
            0.9 * level_multiplier(90, 90);
        return v;
    }

    constexpr auto damage(auto EM) const {
        auto v =
            attack_ * (skill_damage_multiplier_ / 100) *
            (1 + critical_damage_ / 100) *
            1.5 * (1 + em_.bonus_multiplier() / 100) *
            ((shimenawa_ ? 1.5 : 1) + elemental_damage_bonus_ / 100) *
            0.9 * 0.5;
        return v;
    }

    constexpr auto elemental_damage_diff() {
        auto base = 107;
        auto x = 1 + ElementalMastery{ base }.bonus_multiplier() / 100;
        auto y = 1 + ElementalMastery{ base + 125 + 120 }.bonus_multiplier() / 100;
        return y / x;
    }
private:
    int hp_max_ = 0;

    int attack_ = 0;
    ElementalMastery em_ = ElementalMastery{ 0 };
    bool shimenawa_ = false;

    double skill_damage_multiplier_ = 0.0;
    double critical_damage_ = 0.0;
    double elemental_damage_bonus_ = 0.0;
};