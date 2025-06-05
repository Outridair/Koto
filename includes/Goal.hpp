//
// Created by David Rynearson on 04.06.25.
//

#ifndef GOAL_HPP
#define GOAL_HPP
#include "GameObject.hpp"


class Goal : public GameObject {
public:
    Goal(int x, int y);
    void render(SDL_Renderer* renderer, const SDL_Rect& camera) override;
    void update(float deltaTime) override {} // Static goal
    [[nodiscard]] SDL_Rect getRect() const;

private:
    SDL_Rect rect{};
};



#endif //GOAL_HPP
