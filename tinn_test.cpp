#include "tinn.hpp"
#include <cstdio>

#define len(a) ((int)(sizeof(a) / sizeof(*a)))

int main() {
  float in[] = {0.05, 0.10};
  float tg[] = {0.01, 0.99};
  /* Two hidden neurons */
  const Tinn::Tinn tinn = Tinn::xtbuild(len(in), 2, len(tg));
  for (int i = 0; i < 1000; i++) {
    float error = Tinn::xttrain(tinn, in, tg, 0.5);
    printf("%.12f\n", error);
  }
  xtfree(tinn);
  return 0;
}
