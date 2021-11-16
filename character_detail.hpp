#pragma once
#include "param.hpp"

namespace gdc {
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

    class Character {
    public:
        constexpr Character(param::character param)
            :param_(param) {

        }

        constexpr auto damage() const {
            auto v =
                param_.attack * (param_.skill_multiplier / 100) *
                (1 + param_.critical_multiplier / 100) *
                1.5 * (1 + ElementalMastery{ param_.em }.bonus_multiplier() / 100) *
                ((param_.shimenawa ? 1.5 : 1) + param_.elemental_damage_multiplier / 100) *
                0.9 * level_multiplier(90, 90);
            return v;
        }

        constexpr auto elemental_damage_diff() {
            auto base = 107;
            auto x = 1 + ElementalMastery{ base }.bonus_multiplier() / 100;
            auto y = 1 + ElementalMastery{ base + 125 + 120 }.bonus_multiplier() / 100;
            return y / x;
        }
    private:
        param::character param_;
    };
}
