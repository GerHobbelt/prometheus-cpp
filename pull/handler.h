#pragma once

#include <CivetServer.h>

#include <memory>
#include <mutex>
#include <vector>

#include "prometheus/core/collectable.h"
#include "prometheus/core/counter.h"
#include "prometheus/core/family.h"
#include "prometheus/core/registry.h"
#include "prometheus/core/summary.h"

namespace prometheus {
namespace detail {
class MetricsHandler : public CivetHandler {
 public:
  explicit MetricsHandler(Registry& registry);

  void RegisterCollectable(const std::weak_ptr<Collectable>& collectable);
  void RemoveCollectable(const std::weak_ptr<Collectable>& collectable);

  bool handleGet(CivetServer* server, struct mg_connection* conn) override;

 private:
  static void CleanupStalePointers(
      std::vector<std::weak_ptr<Collectable>>& collectables);

  std::mutex collectables_mutex_;
  std::vector<std::weak_ptr<Collectable>> collectables_;
  Family<Counter>& bytes_transferred_family_;
  Counter& bytes_transferred_;
  Family<Counter>& num_scrapes_family_;
  Counter& num_scrapes_;
  Family<Summary>& request_latencies_family_;
  Summary& request_latencies_;
};
}  // namespace detail
}  // namespace prometheus
