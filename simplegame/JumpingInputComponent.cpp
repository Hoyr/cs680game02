#include "JumpingInputComponent.hpp"
#include <gamelib_locator.hpp>
#include <gamelib_random.hpp>

namespace GameLib {
    void JumpingInputComponent::update(Actor& actor) {
            auto axis1 = Locator::getInput()->axis1X;
            if (axis1)
            {
                actor.physicsInfo.a.x = (axis1->getAmount());
            }

            auto buttonA = Locator::getInput()->buttonA;
            if (buttonA->checkClear())
            {
                actor.physicsInfo.a.y = -10;
            }
            else
            {
                actor.physicsInfo.a.y = 0;
            }
            
        }
}