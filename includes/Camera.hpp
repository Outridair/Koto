//
// Created by David Rynearson on 04.06.25.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "SDL.h"

class Camera {
public:
    Camera(int screenWidth, int screenHeight, int levelWidth, int levelHeight);

    void update(int playerX, int playerY);
    const SDL_Rect& getView() const;

private:
    SDL_Rect view{};
    int levelWidth;
    int levelHeight;
};



#endif //CAMERA_HPP
