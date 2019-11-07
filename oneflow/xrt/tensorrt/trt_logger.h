#ifndef ONEFLOW_XRT_TENSORRT_TRT_LOGGER_H_
#define ONEFLOW_XRT_TENSORRT_TRT_LOGGER_H_

#include "NvInfer.h"

namespace oneflow {
namespace xrt {
namespace tensorrt {

namespace nv {

class Logger : public nvinfer1::ILogger {
 public:
  Logger(const std::string &name) : name_(name) {}

  void log(nvinfer1::ILogger::Severity severity, const char* msg) override;

 private:
  std::string name_ = "TensorRT Logger";
};

}  // namespace nv

}  // namespace tensorrt
}  // namespace xrt
}  // namespace oneflow

#endif  // ONEFLOW_XRT_TENSORRT_TRT_LOGGER_H_
