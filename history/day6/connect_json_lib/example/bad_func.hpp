
int add_impl(int a, int b);

static int add(int a, int b) {
  return add_impl(a, b);
}
