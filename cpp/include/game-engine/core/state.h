#ifndef GAMEENGINE_CORE_STATE_H_
#define GAMEENGINE_CORE_STATE_H_

namespace GameEngine {
struct InputState {
  struct MouseButton {
    unsigned char state;
    unsigned char clicks;
  };

  unsigned char keys[282];

  struct {
    MouseButton left, middle, right;
    int x, y;
  } mouse;

  struct {
    unsigned time;
    int amount;
  } scroll;
};

struct State {
  InputState input;
  void *object;
};
}

#endif
