#pragma once

#include <string>
#include <vector>

#include "prometheus/core/client_metric.h"
#include "prometheus/core/metric_type.h"

namespace prometheus {

struct MetricFamily {
  std::string name;
  std::string help;
  MetricType type = MetricType::Untyped;
  std::vector<ClientMetric> metric;
};
}  // namespace prometheus
