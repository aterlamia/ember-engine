#include <game/Game.h>

int main() {

  Game *game = new Game(1024, 768);

  game->init();

  game->run();
}
