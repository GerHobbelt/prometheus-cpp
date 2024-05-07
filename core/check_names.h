#pragma once

#include <string>

#include "prometheus/metric_type.h"

namespace prometheus {

bool CheckMetricName(const std::string& name);
bool CheckLabelName(const std::string& name, MetricType type);
}  // namespace prometheus
