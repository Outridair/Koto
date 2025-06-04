//
// Created by David Rynearson on 04.06.25.
//

#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP

#include "Scene.hpp"
#include "../Player.hpp"
#include  "../Level.hpp"
#include  "../Camera.hpp"

class PlayScene : public Scene{
public:
    PlayScene(SDL_Renderer* renderer);
    void handleEvent(const SDL_Event& e) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;

private:
    Player player;
    Level level;
    Camera camera;
};



#endif //PLAYSCENE_HPP
