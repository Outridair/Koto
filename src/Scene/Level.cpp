#include "../../includes/Scene/Level.hpp"
#include "../../includes/Scene/Overworld.hpp"  // for scene transition
#include <SDL_log.h>

// Constants for tile size, level width, etc.
static constexpr int kTileSize   = 40;
static constexpr int kLevelWidth = 3200;
static constexpr int kTileCount  = kLevelWidth / kTileSize;

Level::Level(SDL_Renderer* renderer,
             SceneManager* sceneManager,
             int levelId)
  : renderer(renderer),
    sceneManager(sceneManager),
    levelId(levelId),
    camera(800, 600, kLevelWidth, 600)
{
    SDL_Log("Level ctor (levelId=%d) starting", levelId);

    if (!renderer) {
        SDL_Log("ERROR: Level ctor got null renderer!");
        return;
    }
    if (!sceneManager) {
        SDL_Log("ERROR: Level ctor got null sceneManager!");
        return;
    }

    // Build a very simple floor, one test enemy, and a goal
    buildSimpleFloor();

    // Place the player somewhere above the floor
    player.init(renderer, 100, 500);

    SDL_Log("Level ctor complete: %zu tiles, %zu enemies, goal=%s",
            tiles.size(), enemies.size(),
            (goal ? "present" : "NONE"));
}

Level::~Level() {
    SDL_Log("Level destructor (levelId=%d) called", levelId);
    // unique_ptr<Goal>, vector<unique_ptr<Tile>>, vector<unique_ptr<Enemy>> auto-clean
}

void Level::handleEvent(const SDL_Event &e) {
    player.handleInput(e);
}

void Level::update(float deltaTime) {
    // Update player physics/collision (passing our tiles/enemies)
    player.update(deltaTime, tiles, enemies);

    // Scroll camera to follow player
    camera.update(player.getX(), player.getY());

    // Check if player reached the goal
    SDL_Rect playerRect = {
        player.getX(),
        player.getY(),
        player.getWidth(),
        player.getHeight()
    };

    if (goal) {
        SDL_Rect goalRect = goal->getRect();  // copy
        if (SDL_HasIntersection(&playerRect, &goalRect)) {
            SDL_Log("Player reached the goal! Switching to Overworld.");
            sceneManager->setScene(
                std::make_unique<Overworld>(renderer, sceneManager)
            );
        }
    }
}

void Level::render(SDL_Renderer *renderer) {
    SDL_Rect camView = camera.getView();

    // Draw all tiles
    for (const auto& t : tiles) {
        t->render(renderer, camView);
    }
    // Draw all enemies
    for (const auto& e : enemies) {
        e->render(renderer, camView);
    }
    // Draw goal if present
    if (goal) {
        goal->render(renderer, camView);
    }
    // Draw the player last (so player overlaps tiles/enemies)
    player.render(renderer, camView);
}

void Level::buildSimpleFloor() {
    // Clear any existing data (in case this is ever re-used)
    tiles.clear();
    enemies.clear();
    goal.reset();

    // 1) Build a full row of ground tiles across the bottom of the level
    const int floorY = 560;  // e.g. if screen height=600 and tileSize=40
    for (int i = 0; i < kTileCount; ++i) {
        int px = i * kTileSize;
        tiles.push_back(std::make_unique<Tile>(px, floorY, kTileSize, kTileSize));
    }

    // 2) Add one simple enemy on top of the floor
    //    For example: at world X=400, Y just above floor
    const int enemyX = 400;
    const int enemyY = floorY - 32; // 32px tall enemy
    enemies.push_back(std::make_unique<Enemy>(enemyX, enemyY, 32, 32));

    // 3) Place the goal a bit further to the right on top of the floor
    const int goalX = 3000;
    const int goalY = floorY - 128; // 128px tall goal pole
    goal = std::make_unique<Goal>(goalX, goalY);
}
