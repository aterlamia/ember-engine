#include <game/Game.h>

int main() {

  Game *game = new Game(1024, 1024);

  game->init();

  game->run();
}
