#include "NewtonPhysicsComponent.hpp"

namespace GameLib {
	bool touching(Actor& a, World& w) {
		glm::vec3 pcenter = a.position + a.size * 0.5f;
		pcenter.y = a.position.y + a.size.y;
		int x = (int)pcenter.x;
		int aboveHead = (int)(a.position.y - 0.01f);
		int topOfHead = (int)(a.position.y);
		int aboveFoot = (int)(pcenter.y);
		int belowFoot = (int)(pcenter.y + 0.01f);
		// collision?
		auto tileAboveHead = w.getTile(x, aboveHead);
		auto tileBelowHead = w.getTile(x, topOfHead);
		auto tilePlayer = w.getTile(x, aboveFoot);
		auto tileBelow = w.getTile(x, belowFoot);
		//if (tileAboveHead.solid())
		//	return true;
		if (tileBelow.solid()) {
			return true;
		}
		return false;
	}

	void NewtonPhysicsComponent::update(Actor& a, World& w) {
		glm::vec3 pdiff = a.position - a.lastPosition;
		float plength = std::abs(pdiff.y);
		if (touching(a, w) && plength < 0.0001f) {
			a.physicsInfo.v.y = 0.0f;
		}

		// update acceleration
		glm::vec3 acceleration=a.physicsInfo.a;
		acceleration.x+=a.physicsInfo.v.x*-5;
		if (a.physicsInfo.v.y > 0.0f)
			acceleration += 5.0f * w.worldPhysicsInfo.g;
		else
			acceleration += 3.0f * w.worldPhysicsInfo.g;

		glm::vec3 vold = a.physicsInfo.v;
		glm::vec3 vnew = vold + a.dt * acceleration;
		a.physicsInfo.v = vnew;
		a.position += 0.5f * (vold + vnew) * a.dt;

		if (a.clipToWorld) {
			a.position.x = clamp<float>(a.position.x, 1, (float)w.worldSizeX - a.size.x);
			a.position.y = clamp<float>(a.position.y, 1, (float)w.worldSizeY - a.size.y - 1);
		}
	}

	void debugDrawSDF(Actor& a, Actor& b);

	bool NewtonPhysicsComponent::collideDynamic(Actor& a, Actor& b) {
		//debugDrawSDF(a, b);
		return SimplePhysicsComponent::collideDynamic(a, b);
	}

	bool NewtonPhysicsComponent::collideStatic(Actor& a, Actor& b) {
		//debugDrawSDF(a, b);
		return SimplePhysicsComponent::collideStatic(a, b);
	}


} // namespace GameLib
