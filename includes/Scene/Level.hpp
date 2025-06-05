#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP

#include "SceneBase.hpp"
#include "../SceneManager.hpp"
#include "../Player.hpp"
#include "../Camera.hpp"
#include "../Goal.hpp"
#include "../Tile.hpp"
#include "../Enemy.hpp"

#include <vector>
#include <memory>

class Level : public SceneBase {
public:
    Level(SDL_Renderer* renderer, SceneManager* sceneManager, int levelId);
    void handleEvent(const SDL_Event& e) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    ~Level() override;

    // Expose tiles/enemies so Player can collide
    [[nodiscard]] const std::vector<std::unique_ptr<Tile>>& getTiles() const { return tiles; }
    [[nodiscard]] const std::vector<std::unique_ptr<Enemy>>& getEnemies() const { return enemies; }
    [[nodiscard]] Goal* getGoal() const { return goal.get(); }

private:
    SDL_Renderer*              renderer;
    SceneManager*              sceneManager;
    int                        levelId;
    Camera                     camera;
    Player                     player;

    // Owned by this scene now, not by a separate LevelRender
    std::vector<std::unique_ptr<Tile>>   tiles;
    std::vector<std::unique_ptr<Enemy>>  enemies;
    std::unique_ptr<Goal>                goal;

    void buildSimpleFloor();    // helper to populate tiles/enemies/goal
};

#endif // PLAYSCENE_HPP
