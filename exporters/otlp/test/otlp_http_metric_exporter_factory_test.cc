// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#ifndef ENABLE_METRICS_PREVIEW

#  include <gtest/gtest.h>

#  include "opentelemetry/exporters/otlp/otlp_http_metric_exporter_factory.h"
#  include "opentelemetry/exporters/otlp/otlp_http_metric_exporter_options.h"

/*
  Make sure OtlpHttpExporterFactory does not require,
  even indirectly, nlohmann/json headers.
*/
#  ifdef NLOHMANN_JSON_VERSION_MAJOR
#    error "nlohmann/json should not be included"
#  endif /* NLOHMANN_JSON_VERSION_MAJOR */

/*
  Make sure OtlpHttpExporterFactory does not require,
  even indirectly, protobuf headers.
*/
#  ifdef GOOGLE_PROTOBUF_VERSION
#    error "protobuf should not be included"
#  endif

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace otlp
{

TEST(OtlpHttpMetricExporterFactory, BuildTest)
{
  OtlpHttpMetricExporterOptions opts;
  opts.url = "localhost:45454";

  std::unique_ptr<opentelemetry::sdk::metrics::PushMetricExporter> exporter =
      OtlpHttpMetricExporterFactory::Create(opts);

  EXPECT_TRUE(exporter != nullptr);
}

}  // namespace otlp
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE

#endif  // ENABLE_METRICS_PREVIEW