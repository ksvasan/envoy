#pragma once

#include <chrono>
#include <cstdint>
#include <string>

#include "envoy/server/options.h"

#include "spdlog/spdlog.h"

namespace Envoy {
/**
 * Implementation of Server::Options.
 */
class OptionsImpl : public Server::Options {
public:
  typedef std::function<std::string(uint64_t, uint64_t)> HotRestartVersionCb;

  OptionsImpl(int argc, char** argv, const HotRestartVersionCb& hot_restart_version_cb,
              spdlog::level::level_enum default_log_level);

  // Server::Options
  uint64_t baseId() override { return base_id_; }
  uint32_t concurrency() override { return concurrency_; }
  const std::string& configPath() override { return config_path_; }
  bool v2ConfigOnly() override { return v2_config_only_; }
  const std::string& adminAddressPath() override { return admin_address_path_; }
  Network::Address::IpVersion localAddressIpVersion() override { return local_address_ip_version_; }
  std::chrono::seconds drainTime() override { return drain_time_; }
  spdlog::level::level_enum logLevel() override { return log_level_; }
  const std::string& logPath() override { return log_path_; }
  std::chrono::seconds parentShutdownTime() override { return parent_shutdown_time_; }
  uint64_t restartEpoch() override { return restart_epoch_; }
  Server::Mode mode() const override { return mode_; }
  std::chrono::milliseconds fileFlushIntervalMsec() override { return file_flush_interval_msec_; }
  const std::string& serviceClusterName() override { return service_cluster_; }
  const std::string& serviceNodeName() override { return service_node_; }
  const std::string& serviceZone() override { return service_zone_; }
  uint64_t maxStats() override { return max_stats_; }
  uint64_t maxObjNameLength() override { return max_obj_name_length_; }

private:
  uint64_t base_id_;
  uint32_t concurrency_;
  std::string config_path_;
  bool v2_config_only_;
  std::string admin_address_path_;
  Network::Address::IpVersion local_address_ip_version_;
  spdlog::level::level_enum log_level_;
  std::string log_path_;
  uint64_t restart_epoch_;
  std::string service_cluster_;
  std::string service_node_;
  std::string service_zone_;
  std::chrono::milliseconds file_flush_interval_msec_;
  std::chrono::seconds drain_time_;
  std::chrono::seconds parent_shutdown_time_;
  Server::Mode mode_;
  uint64_t max_stats_;
  uint64_t max_obj_name_length_;
};
} // namespace Envoy
