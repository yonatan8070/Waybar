#pragma once

#include <fmt/format.h>
#include <unistd.h>
#include <cstdint>
#include <fstream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include "ALabel.hpp"
#include "util/sleeper_thread.hpp"

namespace waybar::modules {

class Cpu : public ALabel {
 public:
  Cpu(const std::string&, const Json::Value&);
  ~Cpu() = default;
  auto update(std::string format, fmt::dynamic_format_arg_store<fmt::format_context> &args) -> void override;

 private:
  uint16_t                                getCpuLoad();
  std::tuple<uint16_t, std::string>       getCpuUsage();
  std::vector<std::tuple<size_t, size_t>> parseCpuinfo();

  std::vector<std::tuple<size_t, size_t>> prev_times_;

  util::SleeperThread thread_;
};

}  // namespace waybar::modules
