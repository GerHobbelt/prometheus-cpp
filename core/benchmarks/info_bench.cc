#include <benchmark/benchmark.h>

#include "prometheus/core/family.h"
#include "prometheus/core/info.h"
#include "prometheus/core/registry.h"

static void BM_Info_Collect(benchmark::State& state) {
  using prometheus::BuildInfo;
  using prometheus::Info;
  using prometheus::Registry;
  Registry registry;
  auto& info_family =
      BuildInfo().Name("benchmark_info").Help("").Register(registry);
  auto& info = info_family.Add({});

  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(info.Collect());
  };
}
BENCHMARK(BM_Info_Collect);
