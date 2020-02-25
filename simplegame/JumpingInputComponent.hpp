#ifndef GAMELIB_JUMPING_INPUT_COMPONENT_HPP
#define GAMELIB_JUMPING_INPUT_COMPONENT_HPP

#include <gamelib_actor.hpp>

namespace GameLib {
    class JumpingInputComponent : public SimpleInputComponent {
    public:
        virtual ~JumpingInputComponent() {}
        void update(Actor& actor) override;
    };
}

#endif