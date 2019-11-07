#ifndef ONEFLOW_XRT_TENSORRT_TRT_GRAPH_COMPILER_H_
#define ONEFLOW_XRT_TENSORRT_TRT_GRAPH_COMPILER_H_

#include "NvInfer.h"

#include "oneflow/xrt/graph_compiler.h"
#include "oneflow/xrt/tensorrt/trt_executable.h"

namespace oneflow {
namespace xrt {
namespace tensorrt {

class TrtGraphCompiler : public GraphCompiler::Impl {
 public:
  explicit TrtGraphCompiler(const std::string &name)
      : GraphCompiler::Impl(name) {
    builder_ = std::make_shared<XrtBuilder>(name);
  }

  virtual ~TrtGraphCompiler() = default;

  std::shared_ptr<Executable> Compile(
      const XrtGraph *graph, const std::vector<Parameter> &entry_params,
      const std::vector<Parameter> &return_params,
      const std::vector<InputOutputAlias> &aliases) override;

 private:
  void SetupKernelContextParam(
      const XrtNode *node, OpKernelContext::Param *context_param);

 private:
  std::shared_ptr<TrtBuilder> builder_;

  util::Map<std::string, Argument> arguments_;
  util::Map<Argument, TrtValue> operands_;
};

}  // namespace tensorrt
}  // namespace xrt
}  // namespace oneflow

#endif  // ONEFLOW_XRT_TENSORRT_TRT_GRAPH_COMPILER_H_
