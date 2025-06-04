//
// Created by David Rynearson on 04.06.25.
//

#ifndef SCENE_HPP
#define SCENE_HPP
#include <SDL.h>


class Scene {
public:
    virtual void handleEvent(const SDL_Event& e) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual ~Scene() = default;
};



#endif //SCENE_HPP
