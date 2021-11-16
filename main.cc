
auto elemental_mastery_increase_damage = []() {
    
};
class ElementalMastery {
public:
    ElementalMastery(int val)
        :elemental_mastery_(val){
        
    }

private:
    int elemental_mastery_;
};

constexpr auto EMbonus_multiplier = [](auto elemental_mastery) {
    auto vaporize_melt = (278.0 * elemental_mastery) / (elemental_mastery + 1400);
    return vaporize_melt;
};

constexpr auto level_multiplier = [](auto u, auto monster) {
    return (0.0 + u + 100) / (u + monster + 200);
};

// demo for Hu Tao
struct CharacterDetail {
    int hp_max = 33000;
    // 3507
    // 精通沙漏 187精通 目前期望 36911
    // 生命值沙漏 攻击力 3507+167 目前期望 34421
    int attack = 4157;
    int elemental_mastery = 159;
    bool shimenawa = true;

    double skill_damage_multiplier = 228.7;
    double critical_damage = 208.2;
    double pyro_damage_bonus = 79.6;

    constexpr auto damage() const {
        auto v = 
            attack * (skill_damage_multiplier / 100) *
            (1 + critical_damage / 100) *
            1.5 * (1 + EMbonus_multiplier(elemental_mastery) / 100) *
            ((shimenawa ? 1.5 : 1) + pyro_damage_bonus / 100) *
            0.9 * level_multiplier(90,90);
        return v;
    }

    constexpr auto damage(auto EM) const {
        auto v =
            attack * (skill_damage_multiplier / 100) *
            (1 + critical_damage / 100) *
            1.5 * (1 + EMbonus_multiplier(EM) / 100) *
            ((shimenawa ? 1.5 : 1) + pyro_damage_bonus / 100) *
            0.9 * 0.5;
        return v;
    }

    constexpr auto elemental_damage_diff() {
        auto base = 107;
        auto x = 1 + EMbonus_multiplier(base) / 100;
        auto y = 1 + EMbonus_multiplier(base + 125 + 120) / 100;
        return y / x;
    }
};

constexpr auto elemental_mastery_diff = [](auto x, auto y) {
    return (1 + EMbonus_multiplier(y)/100) / (1 + EMbonus_multiplier(x)/100);
};

auto main() -> int {
    auto hutao = CharacterDetail{};
    return hutao.damage();
}

