
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
//#include <execution>

class FreightTrainRoute {
private:
  std::vector<float> weightPerWagon;

public:
  FreightTrainRoute() = default;
  virtual ~FreightTrainRoute() = default;

  void set_weightPerWagon(std::vector<float> trucks) {
    weightPerWagon = trucks;
  }

  int totalWeight() const {
    auto total = std::accumulate(weightPerWagon.begin(), weightPerWagon.end(), 0.0F, std::plus<>());
    return static_cast<int>(total);
  }

  int totalWeightFE() const {
    float total(0.0F);
    std::for_each(weightPerWagon.begin(), weightPerWagon.end(), [&total](auto v_) {
      total += v_;
    });
    return static_cast<int>(total);
  }

  int totalWeightRBL() const {
    float total(0.0F);
    for (auto v_ : weightPerWagon) {
      total += v_;
    }
    return static_cast<int>(total);
  }

//  int totalWeightR() const {
//    auto total = std::reduce(std::execution::par, weightPerWagon.begin(), weightPerWagon.end(), 0.0F, std::plus<>());
//    return static_cast<int>(total);
//  }
};

int main() {
  std::cout << __cplusplus << std::endl;

  FreightTrainRoute troublesome;

  troublesome.set_weightPerWagon(std::vector<float> { 100.0f, 250.0f, 110.0f, });

  std::cout << "Total weight  (std::accumulate):" << std::setw(5) << troublesome.totalWeight() << std::endl;
  std::cout << "Total weight    (std::for_each):" << std::setw(5) << troublesome.totalWeightFE() << std::endl;
  std::cout << "Total weight (range based loop):" << std::setw(5) << troublesome.totalWeightRBL() << std::endl;
//  std::cout << "Total weight      (std::reduce):" << std::setw(5) << troublesome.totalWeightR() << std::endl;

  return 0;
}
