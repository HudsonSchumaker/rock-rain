/**
* @file Entity.h
* @author Hudson Schumaker
* @brief Defines the Entity class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#pragma once
#include "../../Pch.h"
#include "TLG.h"
#include "component/Component.h"
#include "component/Transform.h"

/**
* @class Entity
* @brief The GameObject of the engine.
*/
class Entity final {
private:
	std::unordered_map<const std::type_info*, Component*> components;

public:
	short zIndex = 0;
	unsigned long id = 0;
	Layer layer = Layer::MIDDLEGROUND;
	std::pair<Tag, Tag> tags = { 
		Tag::STANDARD,
		Tag::STANDARD
	};

	Entity(unsigned long id, float x, float y) : id(id) {
		addComponent(new Transform(x, y));
	}

	~Entity() {
		deleteComponents();
	}

	template<typename T>
	T* getComponent() {
		auto it = components.find(&typeid(T));
		if (it != components.end()) {
			return static_cast<T*>(it->second);
		}
		return nullptr;
	}

	template<typename T1, typename T2>
	std::pair<T1*, T2*> getComponents() {
		T1* comp1 = getComponent<T1>();
		T2* comp2 = getComponent<T2>();
		return std::make_pair(comp1, comp2);
	}

	template<typename T1, typename T2, typename T3>
	std::tuple<T1*, T2*, T3*> getComponents() {
		T1* comp1 = getComponent<T1>();
		T2* comp2 = getComponent<T2>();
		T3* comp3 = getComponent<T3>();
		return std::make_tuple(comp1, comp2, comp3);
	}

	template<typename T>
	T* addComponent(T* component) {
		components[&typeid(T)] = component;
		component->parentId = id;
		return component;
	}

	void deleteComponents() {
		for (const auto& entry : components) {
			delete entry.second;
		}
		components.clear();
	}
};
