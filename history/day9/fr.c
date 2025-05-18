#include <stdio.h>

struct Heli {
  int id;
};

struct Heli create_heli()
{
  struct Heli heli;
  heli.id = 3;
  return heli;
}

int main() {
  printf("%d", create_heli().id);
  return 0;
}
