#include <vector>

std::vector<int> create_vector()
{
  std::vector<int> v(1'000'000);  // 1M elements
  return v;
}

int main()
{
  std::vector<int> v1 = {1, 2, 3};

  // Copy
  std::vector<int> v2 = v1;

  // Move
  std::vector<int> v3 = std::move(v1);
  // v3 is now {1, 2, 3}
  // v1 is now empty

  v3 = create_vector();
}
