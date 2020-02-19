#ifndef ONEFLOW_CORE_VM_CONTROL_VPU_H_
#define ONEFLOW_CORE_VM_CONTROL_VPU_H_

#include "oneflow/core/vm/vpu.h"
#include "oneflow/core/common/util.h"

namespace oneflow {

class InvalidVpu final : public Vpu {
 public:
  InvalidVpu() : Vpu() {}
  ~InvalidVpu() override = default;

  void Run(VpuScheduler* scheduler, VmInstructionMsg* vm_instr_msg) const;

  // UNIMPLEMENTED methods
  const VmInstruction* GetVmInstruction(VmInstructionOpcode vm_instr_opcode) const override {
    UNIMPLEMENTED();
    return nullptr;
  }
  VmInstructionStatusQuerier* NewStatusQuerier(ObjectMsgAllocator* allocator, int* allocated_size,
                                               const VmStream* vm_stram) const override {
    UNIMPLEMENTED();
    return nullptr;
  }
  void Run(VmStream* vm_stram, RunningVmInstructionPackage* vm_instr_pkg) const override {
    UNIMPLEMENTED();
  }
};

}  // namespace oneflow

#endif  // ONEFLOW_CORE_VM_CONTROL_VPU_H_