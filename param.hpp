#pragma once
namespace gdc {
    namespace param {
        struct character {
            int hp;
            int attack;
            int em;
            bool sngw;

            double skill_mul;
            double critical_mul;
            double elemental_damage_mul;
        };
    }
}