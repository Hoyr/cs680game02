#ifndef ARENA_ACTOR_COMPONENT_HPP
#define ARENA_ACTOR_COMPONENT_HPP

#include <gamelib_actor_component.hpp>

namespace GameLib {
	class ArenaActorComponent : public ActorComponent {
	public:
		virtual ~ArenaActorComponent() {}

		void update(Actor& actor, World& world) override;
		void beginPlay(Actor& actor) override;
		void handleCollisionStatic(Actor& a, Actor& b) override;
		void handleCollisionDynamic(Actor& a, Actor& b) override;
		void handleCollisionWorld(Actor& actor, World& world) override;
		void beginOverlap(Actor& a, Actor& b) override;
		void endOverlap(Actor& a, Actor& b) override;
		void beginTriggerOverlap(Actor& a, Actor& b) override;
		void endTriggerOverlap(Actor& a, Actor& b) override;

	private:
		struct STATICINFO {
			bool horizontal{false};
			float movement{2.0f};
			glm::vec3 position;
			float t{0.0f};
		} staticInfo;

		struct TRIGGERINFO {
			glm::vec3 position;
			float t{0.0f};
		} triggerInfo;
	};
} // namespace GameLib
#endif
