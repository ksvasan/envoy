#pragma once

#include "envoy/server/filter_config.h"

#include "common/config/well_known_names.h"

#include "api/filter/network/tcp_proxy.pb.h"

namespace Envoy {
namespace Server {
namespace Configuration {

/**
 * Config registration for the tcp proxy filter. @see NamedNetworkFilterConfigFactory.
 */
class TcpProxyConfigFactory : public NamedNetworkFilterConfigFactory {
public:
  // NamedNetworkFilterConfigFactory
  NetworkFilterFactoryCb createFilterFactoryFromProto(const Protobuf::Message& config,
                                                      FactoryContext& context) override;
  NetworkFilterFactoryCb createFilterFactory(const Json::Object& json_config,
                                             FactoryContext& context) override;
  ProtobufTypes::MessagePtr createEmptyConfigProto() override;
  std::string name() override { return Config::NetworkFilterNames::get().TCP_PROXY; }

private:
  NetworkFilterFactoryCb createFactory(const envoy::api::v2::filter::network::TcpProxy& config,
                                       FactoryContext& context);
};

} // namespace Configuration
} // namespace Server
} // namespace Envoy
