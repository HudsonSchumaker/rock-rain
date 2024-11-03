#pragma once

/**
* @enum Tag
* @brief Defines the tags that can be assigned to entities in the game.
*
* Tags are used to categorize entities and perform operations on a specific category of entities.
*/
enum class Tag {
    STANDARD,
    KILLBYTIME,
    BACKGROUND,
    TILE,
    ENEMY,
    PLAYER,
    SHIELD,
    BULLET,
    BLADE,
    COIN,
    UI
};

/**
* @enum Layer
* @brief Defines the layers that can be assigned to entities in the game.
*
* Layers are used to control the rendering order of entities. Entities in lower layers are rendered before entities in higher layers.
*/
enum class Layer {
    BACKGROUND,
    MIDDLEGROUND,
    FOREGROUND
};

/**
* @enum Group
* @brief Defines the groups that can be assigned to entities in the game.
*
* Groups are used to categorize entities and perform operations on a specific group of entities.
*/
enum class Group {
    PRIMITIVES,
    CLICKABLE,
    COLLIDER,
    RENDERABLE,
};
