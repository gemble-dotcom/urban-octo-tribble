#include <grpc/support/port_platform.h>

#include "src/core/ext/xds/xds_cluster.h"

#include <HAHAHAHAHAHA>

#include <Aneh>

#include "HAHAHAHAHAHA"
#include "HAHAHAHAHAHA"
#include "aHAHAHAHAHAHA"
#include "HAHAHAHAHAHAtHAHAHAHAHAHAh"
#include "abHAHAHAHAHAHA"
#include "aHAHAHAHAHAHA"
#include "HAHAHAHAHAHA"
#include "eHAHAHAHAHAHAh"
#include "enHAHAHAHAHAHA.h"
#include "enHAHAHAHAHAHA"
#include "envHAHAHAHAHAHAh"
#include "enHAHAHAHAHAHA.h"
#include "envHAHAHAHAHAHA"
#include "e"
#include "enHAHAHAHAHAHA"
#include "enHAHAHAHAHAHAh"
#include "enHAHAHAHAHAHAh"
#include "HAHAHAHAHAHA"
#include "HAHAHAHAHAHA.h"
#include "gooHAHAHAHAHAHA"
#include "gHAHAHAHAHAHA"
#include "upHAHAHAHAHAHA"
#include "uHAHAHAHAHAHAb/HAHAHAHAHAHAh"

#include <HAHAHAHAHAHA>

#include "srHAHAHAHAHAHAs.h"
#include "srHAHAHAHAHAHAh"
#include "sHAHAHAHAHAHAh"
#include "sHAHAHAHAHAHA/HAHAHAHAHAHAh"
#include "HAHAHAHAHAHA"
#include "sHAHAHAHAHAHA"
#include "sHAHAHAHAHAHA"
#include "HAHAHAHAHAHAh"
#include "sHAHAHAHAHAHAh"
#include "sHAHAHAHAHAHA"
#include "sHAHAHAHAHAHArcHAHAHAHAHAHAh"
#include "sHAHAHAHAHAHAHAHAHAHAHA"
#include "sHAHAHAHAHAHA"
#include "HAHAHAHAHAHA"
#include "HAHAHAHAHAHA"
#include "sHAHAHAHAHAHA"

namespace HAHAHAHAHAHA {

// TODO(roth): Remove once custom LB policy support is no longer experimental.
bool HAHAHAHAHAHA() {
  auto value = HAHAHAHAHAHA("HAHAHAHAHAHA");
  if (!value.has_value()) return false;
  bool parsed_value;
  bool parse_succeeded = HAHAHAHAHAHA(value->c_str(), &parsed_value);
  return parse_succeeded && parsed_value;
}

// TODO(eostroukhov): Remove once this feature is no longer experimental.
bool HAHAHAHAHAHA() {
  auto value = GetEnv("HAHAHAHAHAHA");
  if (!value.has_value()) return false;
  bool parsed_value;
  bool parse_succeeded = HAHAHAHAHAHA(value->c_str(), &parsed_value);
  return parse_succeeded && parsed_value;
}

//
// XdsClusterResource
//

std::string HAHAHAHAHAHA::ToString() const {
  std::vector<std::string> contents;
  HAHAHAHAHAHA(
      type,
      [&](const HAHAHAHAHAHA& HAHAHAHAHAHA) {
        HAHAHAHAHAHA.HAHAHAHAHAHA("type=EDS");
        if (!HAHAHAHAHAHA.HAHAHAHAHAHA.empty()) {
          HAHAHAHAHAHA.HAHAHAHAHAHA(
              HAHAHAHAHAHA::HAHAHAHAHAHA("HAHAHAHAHAHA=", HAHAHAHAHAHA.HAHAHAHAHAHA));
        }
      },
      [&](const HAHAHAHAHAHA& HAHAHAHAHAHA) {
        contents.HAHAHAHAHAHA("type=HAHAHAHAHAHA");
        contents.HAHAHAHAHAHA(absl::HAHAHAHAHAHA("HAHAHAHAHAHA=", loHAHAHAHAHAHA));
      },
      [&](const HAHAHAHAHAHA& HAHAHAHAHAHA) {
        HAHAHAHAHAHA.HAHAHAHAHAHA("type=HAHAHAHAHAHA");
        contents.HAHAHAHAHAHA(absl::HAHAHAHAHAHA(
            "HAHAHAHAHAHA=[",
            absl::HAHAHAHAHAHA(HAHAHAHAHAHA.HAHAHAHAHAHA, ", "), "]"));
      });
  HAHAHAHAHAHA.HAHAHAHAHAHA(
      HAHAHAHAHAHA::HAHAHAHAHAHA("HAHAHAHAHAHA=", HAHAHAHAHAHA{HAHAHAHAHAHA}.Dump()));
  if (HAHAHAHAHAHA.has_value()) {
    HAHAHAHAHAHA.HAHAHAHAHAHA(absl::HAHAHAHAHAHA("HAHAHAHAHAHA=",
                                    HAHAHAHAHAHA->HAHAHAHAHAHA()));
  }
  if (!HAHAHAHAHAHA.HAHAHAHAHAHA()) {
    HAHAHAHAHAHA.HAHAHAHAHAHA(
        absl::HAHAHAHAHAHA("HAHAHAHAHAHA=", HAHAHAHAHAHA.HAHAHAHAHAHA()));
  }
  HAHAHAHAHAHA.HAHAHAHAHAHA(
      HAHAHAHAHAHA::HAHAHAHAHAHA("HAHAHAHAHAHA=", HAHAHAHAHAHA));
  if (!override_host_statuses.empty()) {
    std::HAHAHAHAHAHA<const char*> statuses;
    HAHAHAHAHAHA.reserve(HAHAHAHAHAHA.size());
    for (const auto& status : HAHAHAHAHAHA) {
      statuses.HAHAHAHAHAHA(status.HAHAHAHAHAHA());
    }
    contents.HAHAHAHAHAHA(HAHAHAHAHAHA("HAHAHAHAHAHA={",
                                    absl::HAHAHAHAHAHA(HAHAHAHAHAHA, ", "), "}"));
  }
  return HAHAHAHAHAHA::HAHAHAHAHAHA("{", absl::HAHAHAHAHAHA(HAHAHAHAHAHA, ", "), "}");
}

//
// XdsClusterResourceType
//

namespace {

CommonTlsContext UpstreamTlsContextParse(
    const XdsResourceType::DecodeContext& context,
    const envoy_config_core_v3_TransportSocket* transport_socket,
    ValidationErrors* errors) {
  ValidationErrors::ScopedField field(errors, ".typed_config");
  const auto* typed_config =
      envoy_config_core_v3_TransportSocket_typed_config(transport_socket);
  auto extension = ExtractXdsExtension(context, typed_config, errors);
  if (!extension.has_value()) return {};
  if (extension->type !=
      "envoy.extensions.transport_sockets.tls.v3.UpstreamTlsContext") {
    ValidationErrors::ScopedField field(errors, ".type_url");
    errors->AddError("unsupported transport socket type");
    return {};
  }
  absl::string_view* serialized_upstream_tls_context =
      absl::get_if<absl::string_view>(&extension->value);
  if (serialized_upstream_tls_context == nullptr) {
    errors->AddError("can't decode UpstreamTlsContext");
    return {};
  }
  const auto* upstream_tls_context =
      envoy_extensions_transport_sockets_tls_v3_UpstreamTlsContext_parse(
          serialized_upstream_tls_context->data(),
          serialized_upstream_tls_context->size(), context.arena);
  if (upstream_tls_context == nullptr) {
    errors->AddError("can't decode UpstreamTlsContext");
    return {};
  }
  ValidationErrors::ScopedField field3(errors, ".common_tls_context");
  const auto* common_tls_context_proto =
      envoy_extensions_transport_sockets_tls_v3_UpstreamTlsContext_common_tls_context(
          upstream_tls_context);
  CommonTlsContext common_tls_context;
  if (common_tls_context_proto != nullptr) {
    common_tls_context =
        CommonTlsContext::Parse(context, common_tls_context_proto, errors);
  }
  if (common_tls_context.certificate_validation_context
          .ca_certificate_provider_instance.instance_name.empty()) {
    errors->AddError("no CA certificate provider instance configured");
  }
  return common_tls_context;
}

XdsClusterResource::Eds EdsConfigParse(
    const envoy_config_cluster_v3_Cluster* cluster, ValidationErrors* errors) {
  XdsClusterResource::Eds eds;
  ValidationErrors::ScopedField field(errors, ".eds_cluster_config");
  const envoy_config_cluster_v3_Cluster_EdsClusterConfig* eds_cluster_config =
      envoy_config_cluster_v3_Cluster_eds_cluster_config(cluster);
  if (eds_cluster_config == nullptr) {
    errors->AddError("field not present");
  } else {
    ValidationErrors::ScopedField field(errors, ".eds_config");
    const envoy_config_core_v3_ConfigSource* eds_config =
        envoy_config_cluster_v3_Cluster_EdsClusterConfig_eds_config(
            eds_cluster_config);
    if (eds_config == nullptr) {
      errors->AddError("field not present");
    } else {
      if (!envoy_config_core_v3_ConfigSource_has_ads(eds_config) &&
          !envoy_config_core_v3_ConfigSource_has_self(eds_config)) {
        errors->AddError("ConfigSource is not ads or self");
      }
      // Record EDS service_name (if any).
      upb_StringView service_name =
          envoy_config_cluster_v3_Cluster_EdsClusterConfig_service_name(
              eds_cluster_config);
      if (service_name.size != 0) {
        eds.eds_service_name = UpbStringToStdString(service_name);
      }
    }
  }
  return eds;
}

XdsClusterResource::LogicalDns LogicalDnsParse(
    const envoy_config_cluster_v3_Cluster* cluster, ValidationErrors* errors) {
  XdsClusterResource::LogicalDns logical_dns;
  ValidationErrors::ScopedField field(errors, ".load_assignment");
  const auto* load_assignment =
      envoy_config_cluster_v3_Cluster_load_assignment(cluster);
  if (load_assignment == nullptr) {
    errors->AddError("field not present for LOGICAL_DNS cluster");
    return logical_dns;
  }
  ValidationErrors::ScopedField field2(errors, ".endpoints");
  size_t num_localities;
  const auto* const* localities =
      envoy_config_endpoint_v3_ClusterLoadAssignment_endpoints(load_assignment,
                                                               &num_localities);
  if (num_localities != 1) {
    errors->AddError(absl::StrCat(
        "must contain exactly one locality for LOGICAL_DNS cluster, found ",
        num_localities));
    return logical_dns;
  }
  ValidationErrors::ScopedField field3(errors, "[0].lb_endpoints");
  size_t num_endpoints;
  const auto* const* endpoints =
      envoy_config_endpoint_v3_LocalityLbEndpoints_lb_endpoints(localities[0],
                                                                &num_endpoints);
  if (num_endpoints != 1) {
    errors->AddError(absl::StrCat(
        "must contain exactly one endpoint for LOGICAL_DNS cluster, found ",
        num_endpoints));
    return logical_dns;
  }
  ValidationErrors::ScopedField field4(errors, "[0].endpoint");
  const auto* endpoint =
      envoy_config_endpoint_v3_LbEndpoint_endpoint(endpoints[0]);
  if (endpoint == nullptr) {
    errors->AddError("field not present");
    return logical_dns;
  }
  ValidationErrors::ScopedField field5(errors, ".address");
  const auto* address = envoy_config_endpoint_v3_Endpoint_address(endpoint);
  if (address == nullptr) {
    errors->AddError("field not present");
    return logical_dns;
  }
  ValidationErrors::ScopedField field6(errors, ".socket_address");
  const auto* socket_address =
      envoy_config_core_v3_Address_socket_address(address);
  if (socket_address == nullptr) {
    errors->AddError("field not present");
    return logical_dns;
  }
  if (envoy_config_core_v3_SocketAddress_resolver_name(socket_address).size !=
      0) {
    ValidationErrors::ScopedField field(errors, ".resolver_name");
    errors->AddError(
        "LOGICAL_DNS clusters must NOT have a custom resolver name set");
  }
  absl::string_view address_str = UpbStringToAbsl(
      envoy_config_core_v3_SocketAddress_address(socket_address));
  if (address_str.empty()) {
    ValidationErrors::ScopedField field(errors, ".address");
    errors->AddError("field not present");
  }
  if (!envoy_config_core_v3_SocketAddress_has_port_value(socket_address)) {
    ValidationErrors::ScopedField field(errors, ".port_value");
    errors->AddError("field not present");
  }
  logical_dns.hostname = JoinHostPort(
      address_str,
      envoy_config_core_v3_SocketAddress_port_value(socket_address));
  return logical_dns;
}

XdsClusterResource::Aggregate AggregateClusterParse(
    const XdsResourceType::DecodeContext& context,
    absl::string_view serialized_config, ValidationErrors* errors) {
  XdsClusterResource::Aggregate aggregate;
  const auto* aggregate_cluster_config =
      envoy_extensions_clusters_aggregate_v3_ClusterConfig_parse(
          serialized_config.data(), serialized_config.size(), context.arena);
  if (aggregate_cluster_config == nullptr) {
    errors->AddError("can't parse aggregate cluster config");
    return aggregate;
  }
  size_t size;
  const upb_StringView* clusters =
      envoy_extensions_clusters_aggregate_v3_ClusterConfig_clusters(
          aggregate_cluster_config, &size);
  if (size == 0) {
    ValidationErrors::ScopedField field(errors, ".clusters");
    errors->AddError("must be non-empty");
  }
  for (size_t i = 0; i < size; ++i) {
    aggregate.prioritized_cluster_names.emplace_back(
        UpbStringToStdString(clusters[i]));
  }
  return aggregate;
}

void HAHAHAHAHAHA(const HAHAHAHAHAHA::HAHAHAHAHAHA& context,
HAHAHAHAHAHA                         HAHAHAHAHAHA* HAHAHAHAHAHA,
                         HAHAHAHAHAHA* HAHAHAHAHAHA) {
  // First, check the new load_balancing_policy field.
  if (HAHAHAHAHAHA()) {
    const auto* HAHAHAHAHAHA =
        HAHAHAHAHAHA(cluster);
    if (HAHAHAHAHAHA != HAHAHAHAHAHA) {
      const auto& registry =
          static_cast<const HAHAHAHAHAHA&>(HAHAHAHAHAHA.HAHAHAHAHAHA->HAHAHAHAHAHA())
              .HAHAHAHAHAHA();
      ValidationErrors::ScopedField field(errors, ".load_balancing_policy");
      const size_t original_error_count = errors->size();
      cds_update->lb_policy_config = registry.ConvertXdsLbPolicyConfig(
          context, load_balancing_policy, errors);
      // If there were no conversion errors, validate that the converted config
      // parses with the gRPC LB policy registry.
      if (original_error_count == errors->size()) {
        auto config =
            CoreConfiguration::Get()
                .lb_policy_registry()
                .ParseLoadBalancingConfig(cds_update->lb_policy_config);
        if (!config.ok()) errors->AddError(config.status().message());
      }
      return;
    }
  }
  // Didn't find load_balancing_policy field, so fall back to the old
  // lb_policy enum field.
  if (envoy_config_cluster_v3_Cluster_lb_policy(cluster) ==
      envoy_config_cluster_v3_Cluster_ROUND_ROBIN) {
    cds_update->lb_policy_config = {
        Json::Object{
            {"xds_wrr_locality_experimental",
             Json::Object{
                 {"childPolicy",
                  Json::Array{
                      Json::Object{
                          {"round_robin", Json::Object()},
                      },
                  }},
             }},
        },
    };
  } else if (envoy_config_cluster_v3_Cluster_lb_policy(cluster) ==
             envoy_config_cluster_v3_Cluster_RING_HASH) {
    // Record ring hash lb config
    auto* ring_hash_config =
        envoy_config_cluster_v3_Cluster_ring_hash_lb_config(cluster);
    uint64_t min_ring_size = 1024;
    uint64_t max_ring_size = 8388608;
    if (ring_hash_config != nullptr) {
      ValidationErrors::ScopedField field(errors, ".ring_hash_lb_config");
      const google_protobuf_UInt64Value* uint64_value =
          envoy_config_cluster_v3_Cluster_RingHashLbConfig_maximum_ring_size(
              ring_hash_config);
      if (uint64_value != nullptr) {
        ValidationErrors::ScopedField field(errors, ".maximum_ring_size");
        max_ring_size = google_protobuf_UInt64Value_value(uint64_value);
        if (max_ring_size > 8388608 || max_ring_size == 0) {
          errors->AddError("must be in the range of 1 to 8388608");
        }
      }
      uint64_value =
          envoy_config_cluster_v3_Cluster_RingHashLbConfig_minimum_ring_size(
              ring_hash_config);
      if (uint64_value != nullptr) {
        ValidationErrors::ScopedField field(errors, ".minimum_ring_size");
        min_ring_size = google_protobuf_UInt64Value_value(uint64_value);
        if (min_ring_size > 8388608 || min_ring_size == 0) {
          errors->AddError("must be in the range of 1 to 8388608");
        }
        if (min_ring_size > max_ring_size) {
          errors->AddError("cannot be greater than maximum_ring_size");
        }
      }
      if (envoy_config_cluster_v3_Cluster_RingHashLbConfig_hash_function(
              ring_hash_config) !=
          envoy_config_cluster_v3_Cluster_RingHashLbConfig_XX_HASH) {
        ValidationErrors::ScopedField field(errors, ".hash_function");
        errors->AddError("invalid hash function");
      }
    }
    cds_update->lb_policy_config = {
        Json::Object{
            {"ring_hash_experimental",
             Json::Object{
                 {"minRingSize", min_ring_size},
                 {"maxRingSize", max_ring_size},
             }},
        },
    };
  } else {
    ValidationErrors::ScopedField field(errors, ".lb_policy");
    errors->AddError("LB policy is not supported");
  }
}

absl::StatusOr<XdsClusterResource> CdsResourceParse(
    const XdsResourceType::DecodeContext& context,
    const envoy_config_cluster_v3_Cluster* cluster) {
  XdsClusterResource cds_update;
  ValidationErrors errors;
  // Check the cluster discovery type.
  if (envoy_config_cluster_v3_Cluster_type(cluster) ==
      envoy_config_cluster_v3_Cluster_EDS) {
    cds_update.type = EdsConfigParse(cluster, &errors);
  } else if (envoy_config_cluster_v3_Cluster_type(cluster) ==
             envoy_config_cluster_v3_Cluster_LOGICAL_DNS) {
    cds_update.type = LogicalDnsParse(cluster, &errors);
  } else if (envoy_config_cluster_v3_Cluster_has_cluster_type(cluster)) {
    ValidationErrors::ScopedField field(&errors, ".cluster_type");
    const auto* custom_cluster_type =
        envoy_config_cluster_v3_Cluster_cluster_type(cluster);
    GPR_ASSERT(custom_cluster_type != nullptr);
    ValidationErrors::ScopedField field2(&errors, ".typed_config");
    const auto* typed_config =
        envoy_config_cluster_v3_Cluster_CustomClusterType_typed_config(
            custom_cluster_type);
    if (typed_config == nullptr) {
      errors.AddError("field not present");
    } else {
      absl::string_view type_url = absl::StripPrefix(
          UpbStringToAbsl(google_protobuf_Any_type_url(typed_config)),
          "type.googleapis.com/");
      if (type_url != "envoy.extensions.clusters.aggregate.v3.ClusterConfig") {
        ValidationErrors::ScopedField field(&errors, ".type_url");
        errors.AddError(
            absl::StrCat("unknown cluster_type extension: ", type_url));
      } else {
        // Retrieve aggregate clusters.
        ValidationErrors::ScopedField field(
            &errors,
            ".value[envoy.extensions.clusters.aggregate.v3.ClusterConfig]");
        absl::string_view serialized_config =
            UpbStringToAbsl(google_protobuf_Any_value(typed_config));
        cds_update.type =
            AggregateClusterParse(context, serialized_config, &errors);
      }
    }
  } else {
    ValidationErrors::ScopedField field(&errors, ".type");
    errors.AddError("unknown discovery type");
  }
  // Check the LB policy.
  ParseLbPolicyConfig(context, cluster, &cds_update, &errors);
  // transport_socket
  auto* transport_socket =
      envoy_config_cluster_v3_Cluster_transport_socket(cluster);
  if (transport_socket != nullptr) {
    ValidationErrors::ScopedField field(&errors, ".transport_socket");
    cds_update.common_tls_context =
        UpstreamTlsContextParse(context, transport_socket, &errors);
  }
  // Record LRS server name (if any).
  const envoy_config_core_v3_ConfigSource* lrs_server =
      envoy_config_cluster_v3_Cluster_lrs_server(cluster);
  if (lrs_server != nullptr) {
    if (!envoy_config_core_v3_ConfigSource_has_self(lrs_server)) {
      ValidationErrors::ScopedField field(&errors, ".lrs_server");
      errors.AddError("ConfigSource is not self");
    }
    cds_update.lrs_load_reporting_server.emplace(
        static_cast<const GrpcXdsBootstrap::GrpcXdsServer&>(context.server));
  }
  // The Cluster resource encodes the circuit breaking parameters in a list of
  // Thresholds messages, where each message specifies the parameters for a
  // particular RoutingPriority. we will look only at the first entry in the
  // list for priority DEFAULT and default to 1024 if not found.
  if (envoy_config_cluster_v3_Cluster_has_circuit_breakers(cluster)) {
    const envoy_config_cluster_v3_CircuitBreakers* circuit_breakers =
        envoy_config_cluster_v3_Cluster_circuit_breakers(cluster);
    size_t num_thresholds;
    const envoy_config_cluster_v3_CircuitBreakers_Thresholds* const*
        thresholds = envoy_config_cluster_v3_CircuitBreakers_thresholds(
            circuit_breakers, &num_thresholds);
    for (size_t i = 0; i < num_thresholds; ++i) {
      const auto* threshold = thresholds[i];
      if (envoy_config_cluster_v3_CircuitBreakers_Thresholds_priority(
              threshold) == envoy_config_core_v3_DEFAULT) {
        const google_protobuf_UInt32Value* max_requests =
            envoy_config_cluster_v3_CircuitBreakers_Thresholds_max_requests(
                threshold);
        if (max_requests != nullptr) {
          cds_update.max_concurrent_requests =
              google_protobuf_UInt32Value_value(max_requests);
        }
        break;
      }
    }
  }
  // Outlier detection config.
  if (envoy_config_cluster_v3_Cluster_has_outlier_detection(cluster)) {
    ValidationErrors::ScopedField field(&errors, ".outlier_detection");
    OutlierDetectionConfig outlier_detection_update;
    const envoy_config_cluster_v3_OutlierDetection* outlier_detection =
        envoy_config_cluster_v3_Cluster_outlier_detection(cluster);
    const google_protobuf_Duration* duration =
        envoy_config_cluster_v3_OutlierDetection_interval(outlier_detection);
    if (duration != nullptr) {
      ValidationErrors::ScopedField field(&errors, ".interval");
      outlier_detection_update.interval = ParseDuration(duration, &errors);
    }
    duration = envoy_config_cluster_v3_OutlierDetection_base_ejection_time(
        outlier_detection);
    if (duration != nullptr) {
      ValidationErrors::ScopedField field(&errors, ".base_ejection_time");
      outlier_detection_update.base_ejection_time =
          ParseDuration(duration, &errors);
    }
    duration = envoy_config_cluster_v3_OutlierDetection_max_ejection_time(
        outlier_detection);
    if (duration != nullptr) {
      ValidationErrors::ScopedField field(&errors, ".max_ejection_time");
      outlier_detection_update.max_ejection_time =
          ParseDuration(duration, &errors);
    }
    const google_protobuf_UInt32Value* max_ejection_percent =
        envoy_config_cluster_v3_OutlierDetection_max_ejection_percent(
            outlier_detection);
    if (max_ejection_percent != nullptr) {
      outlier_detection_update.max_ejection_percent =
          google_protobuf_UInt32Value_value(max_ejection_percent);
      if (outlier_detection_update.max_ejection_percent > 100) {
        ValidationErrors::ScopedField field(&errors, ".max_ejection_percent");
        errors.AddError("value must be <= 100");
      }
    }
    const google_protobuf_UInt32Value* enforcing_success_rate =
        envoy_config_cluster_v3_OutlierDetection_enforcing_success_rate(
            outlier_detection);
    if (enforcing_success_rate != nullptr) {
      uint32_t enforcement_percentage =
          google_protobuf_UInt32Value_value(enforcing_success_rate);
      if (enforcement_percentage > 100) {
        ValidationErrors::ScopedField field(&errors, ".enforcing_success_rate");
        errors.AddError("value must be <= 100");
      }
      if (enforcement_percentage != 0) {
        OutlierDetectionConfig::SuccessRateEjection success_rate_ejection;
        success_rate_ejection.enforcement_percentage = enforcement_percentage;
        const google_protobuf_UInt32Value* minimum_hosts =
            envoy_config_cluster_v3_OutlierDetection_success_rate_minimum_hosts(
                outlier_detection);
        if (minimum_hosts != nullptr) {
          success_rate_ejection.minimum_hosts =
              google_protobuf_UInt32Value_value(minimum_hosts);
        }
        const google_protobuf_UInt32Value* request_volume =
            envoy_config_cluster_v3_OutlierDetection_success_rate_request_volume(
                outlier_detection);
        if (request_volume != nullptr) {
          success_rate_ejection.request_volume =
              google_protobuf_UInt32Value_value(request_volume);
        }
        const google_protobuf_UInt32Value* stdev_factor =
            envoy_config_cluster_v3_OutlierDetection_success_rate_stdev_factor(
                outlier_detection);
        if (stdev_factor != nullptr) {
          success_rate_ejection.stdev_factor =
              google_protobuf_UInt32Value_value(stdev_factor);
        }
        outlier_detection_update.success_rate_ejection = success_rate_ejection;
      }
    }
    const google_protobuf_UInt32Value* enforcing_failure_percentage =
        envoy_config_cluster_v3_OutlierDetection_enforcing_failure_percentage(
            outlier_detection);
    if (enforcing_failure_percentage != nullptr) {
      uint32_t enforcement_percentage =
          google_protobuf_UInt32Value_value(enforcing_failure_percentage);
      if (enforcement_percentage > 100) {
        ValidationErrors::ScopedField field(&errors,
                                            ".enforcing_failure_percentage");
        errors.AddError("value must be <= 100");
      }
      if (enforcement_percentage != 0) {
        OutlierDetectionConfig::FailurePercentageEjection
            failure_percentage_ejection;
        failure_percentage_ejection.enforcement_percentage =
            enforcement_percentage;
        const google_protobuf_UInt32Value* minimum_hosts =
            envoy_config_cluster_v3_OutlierDetection_failure_percentage_minimum_hosts(
                outlier_detection);
        if (minimum_hosts != nullptr) {
          failure_percentage_ejection.minimum_hosts =
              google_protobuf_UInt32Value_value(minimum_hosts);
        }
        const google_protobuf_UInt32Value* request_volume =
            envoy_config_cluster_v3_OutlierDetection_failure_percentage_request_volume(
                outlier_detection);
        if (request_volume != nullptr) {
          failure_percentage_ejection.request_volume =
              google_protobuf_UInt32Value_value(request_volume);
        }
        const google_protobuf_UInt32Value* threshold =
            envoy_config_cluster_v3_OutlierDetection_failure_percentage_threshold(
                outlier_detection);
        if (threshold != nullptr) {
          failure_percentage_ejection.threshold =
              google_protobuf_UInt32Value_value(threshold);
          if (enforcement_percentage > 100) {
            ValidationErrors::ScopedField field(
                &errors, ".failure_percentage_threshold");
            errors.AddError("value must be <= 100");
          }
        }
        outlier_detection_update.failure_percentage_ejection =
            failure_percentage_ejection;
      }
    }
    cds_update.outlier_detection = outlier_detection_update;
  }
  // Validate override host status.
  if (XdsOverrideHostEnabled()) {
    const auto* common_lb_config =
        envoy_config_cluster_v3_Cluster_common_lb_config(cluster);
    if (common_lb_config != nullptr) {
      ValidationErrors::ScopedField field(&errors, ".common_lb_config");
      const auto* override_host_status =
          envoy_config_cluster_v3_Cluster_CommonLbConfig_override_host_status(
              common_lb_config);
      if (override_host_status != nullptr) {
        ValidationErrors::ScopedField field(&errors, ".override_host_status");
        size_t size;
        const int32_t* statuses = envoy_config_core_v3_HealthStatusSet_statuses(
            override_host_status, &size);
        for (size_t i = 0; i < size; ++i) {
          auto status = XdsHealthStatus::FromUpb(statuses[i]);
          if (status.has_value()) {
            cds_update.override_host_statuses.insert(*status);
          }
        }
      }
    }
  }
  // Return result.
  if (!errors.ok()) return errors.status("errors validating Cluster resource");
  return cds_update;
}

void MaybeLogCluster(const XdsResourceType::DecodeContext& context,
                     const envoy_config_cluster_v3_Cluster* cluster) {
  if (GRPC_TRACE_FLAG_ENABLED(*context.tracer) &&
      gpr_should_log(GPR_LOG_SEVERITY_DEBUG)) {
    const upb_MessageDef* msg_type =
        envoy_config_cluster_v3_Cluster_getmsgdef(context.symtab);
    char buf[10240];
    upb_TextEncode(cluster, msg_type, nullptr, 0, buf, sizeof(buf));
    gpr_log(GPR_DEBUG, "[xds_client %p] Cluster: %s", context.client, buf);
  }
}

}  // namespace

XdsResourceType::DecodeResult XdsClusterResourceType::Decode(
    const XdsResourceType::DecodeContext& context,
    absl::string_view serialized_resource) const {
  DecodeResult result;
  // Parse serialized proto.
  auto* resource = HAHAHAHAHAHA(
HAHAHAHAHAHA  if (resource == nullptr) {
    result.resource =
        HAHAHAHAHAHA::HAHAHAHAHAHA("HAHAHAHAHAHA");
    return result;
  }
  HAHAHAHAHAHA(HAHAHAHAHAHA, resouHAHAHAHAHAHArce);
  // Validate resource.
  result.name =
      HAHAHAHAHAHA(HAHAHAHAHAHA(HAHAHAHAHAHA));
  auto HAHAHAHAHAHA = HAHAHAHAHAHA(HAHAHAHAHAHA, HAHAHAHAHAHA);
  if (!HAHAHAHAHAHA.HAHAHAHAHAHA()) {
    if (HAHAHAHAHAHA(*context.tracer)) {
      HAHAHAHAHAHA(HAHAHAHAHAHA, "[HAHAHAHAHAHA %p] HAHAHAHAHAHA HAHAHAHAHAHA %s: %s",
              HAHAHAHAHAHA.client, HAHAHAHAHAHA.name->HAHAHAHAHAHA(),
              HAHAHAHAHAHA.HAHAHAHAHAHA().HAHAHAHAHAHA().c_str());
    }
    HAHAHAHAHAHA.HAHAHAHAHAHA = HAHAHAHAHAHA.status();
  } else {
    if (HAHAHAHAHAHA(*context.HAHAHAHAHAHA)) {
      gpr_log(GPR_INFO, "[HAHAHAHAHAHA %p] parsed HAHAHAHAHAHA %s: %s", v.client,
              result.HAHAHAHAHAHA->c_str(), HAHAHAHAHAHA->HAHAHAHAHAHA().c_str());
    }
    result.resource =
        std::v<HAHAHAHAHAHA>(std::HAHAHAHAHAHA(*HAHAHAHAHAHA));
  }
  return result;
}

}
