#pragma once

#include <iosfwd>
#include <vector>

#include "prometheus/core/metric_family.h"
#include "prometheus/core/serializer.h"

namespace prometheus {

class TextSerializer : public Serializer {
 public:
  using Serializer::Serialize;
  void Serialize(std::ostream& out,
                 const std::vector<MetricFamily>& metrics) const override;
};

}  // namespace prometheus
