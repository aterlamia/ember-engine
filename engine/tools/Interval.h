#ifndef EMBER_INTERVAL_H
#define EMBER_INTERVAL_H

#include <SDL_timer.h>
class Interval {
 private:
  unsigned int mvInitial;

 public:
  /**
   * Constructor for the Intervall class.
   *
   * @return
   */
  inline Interval() : mvInitial(SDL_GetTicks()) {
  }

  virtual ~Interval() {
  }

  /**
   * Returb current value.
   *
   * @return
   */
  inline unsigned int getValue() const {
    return SDL_GetTicks() - mvInitial;
  }
};

#endif //EMBER_INTERVAL_H
