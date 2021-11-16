#pragma once

namespace gdc {
    namespace param {
        struct character {
            int hp;
            int attack;
            int em;
            bool shimenawa;

            double skill_multiplier;
            double critical_multiplier;
            double elemental_damage_multiplier;
        };
    }
}
