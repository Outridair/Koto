//
// Created by David Rynearson on 04.06.25.
//

#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "Scene.hpp"
#include "PlayScene.hpp"
#include "SceneManager.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>


class StartScene : public Scene {
public:
    StartScene(SDL_Renderer* renderer, SceneManager* sceneManager);
    void handleEvent(const SDL_Event& e) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    ~StartScene() override;

private:
    SDL_Renderer* renderer;
    SceneManager* sceneManager;
    TTF_Font* font = nullptr;
    SDL_Texture* messageTexture = nullptr;
    SDL_Rect messageRect{};

};



#endif //STARTSCENE_HPP
