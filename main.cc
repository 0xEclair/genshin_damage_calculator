#include "character_detail.hpp"

auto main() -> int {
    using namespace gdc;
    constexpr auto hutao = Character(
        param::character{
            33000, 4157, 159, true,
            228.7, 208.2, 79.6
        }
    );
    return hutao.damage();
}