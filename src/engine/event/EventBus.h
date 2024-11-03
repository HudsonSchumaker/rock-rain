/**
* @file EventBus.h
* @author Hudson Schumaker
* @brief Defines the EventBus class.
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
#include "Event.h"
#include "MouseClickEvent.h"
#include "MouseHoverEvent.h"
#include "MouseWheelEvent.h"
#include "../../Pch.h"

/**
 * @class IEventCallback
 * @brief The IEventCallback class is an interface that defines the call method for an event.
 */
class IEventCallback {
private:
    virtual void call(Event& e) = 0;

public:
    virtual ~IEventCallback() = default;

    void execute(Event& e) {
        call(e);
    }
};

/**
 * @class EventCallback
 * @brief The EventCallback class is a template class that is used to create a callback for an event.
 */
template <typename TOwner, typename TEvent>
class EventCallback final : public IEventCallback {
private:
    typedef void (TOwner::* CallbackFunction)(TEvent&);

    TOwner* ownerInstance;
    CallbackFunction callbackFunction;

    virtual void call(Event& e) override {
        std::invoke(callbackFunction, ownerInstance, static_cast<TEvent&>(e));
    }

public:
    EventCallback(TOwner* ownerInstance, CallbackFunction callbackFunction) {
        this->ownerInstance = ownerInstance;
        this->callbackFunction = callbackFunction;
    }

    virtual ~EventCallback() override = default;
};

typedef std::list<std::unique_ptr<IEventCallback>> HandlerList;
/**
 * @class EventBus
 * @brief The EventBus class is a singleton that manages the events of the game.
 */
class EventBus final {
private:
    inline static EventBus* instance = nullptr;
    std::map<std::type_index, std::unique_ptr<HandlerList>> subscribers;

    EventBus() = default;
    ~EventBus() = default;

public:
    static EventBus* getInstance() {
        if (instance == nullptr) {
            instance = new EventBus();
        }

        return instance;
    }

    void reset() {
        subscribers.clear();
    }

    template <typename TEvent, typename TOwner>
    void subscribeToEvent(TOwner* ownerInstance, void (TOwner::* callbackFunction)(TEvent&)) {
        if (!subscribers[typeid(TEvent)].get()) {
            subscribers[typeid(TEvent)] = std::make_unique<HandlerList>();
        }
        auto subscriber = std::make_unique<EventCallback<TOwner, TEvent>>(ownerInstance, callbackFunction);
        subscribers[typeid(TEvent)]->push_back(std::move(subscriber));
    }

    template <typename TEvent, typename ...TArgs>
    void emitEvent(TArgs&& ...args) {
        auto handlers = subscribers[typeid(TEvent)].get();
        if (handlers) {
            for (auto it = handlers->begin(); it != handlers->end(); it++) {
                auto handler = it->get();
                TEvent event(std::forward<TArgs>(args)...);
                handler->execute(event);
            }
        }
    }

    template <typename TEvent, typename ...TArgs>
    std::future<void> emitEventAsync(TArgs&& ...args) {
        return std::async(std::launch::async, [this](auto&&... args) {
            this->emitEvent<TEvent>(std::forward<TArgs>(args)...);
            }, std::forward<TArgs>(args)...);
    }
};
