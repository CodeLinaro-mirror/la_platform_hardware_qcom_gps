/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSBATCHING_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSBATCHING_H
#include <aidl/android/hardware/gnss/BnGnssBatching.h>
#include <aidl/android/hardware/gnss/IGnssBatchingCallback.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;
using ::aidl::android::hardware::gnss::IGnssBatching;
using ::aidl::android::hardware::gnss::BnGnssBatching;
using ::aidl::android::hardware::gnss::IGnssBatchingCallback;

class GnssBatching : public BnGnssBatching {
public:
  GnssBatching();
  virtual ~GnssBatching();

  virtual ScopedAStatus init(const shared_ptr<IGnssBatchingCallback>& callback) override;
  virtual ScopedAStatus getBatchSize(int32_t* _aidl_return) override;
  virtual ScopedAStatus start(const IGnssBatching::Options& options) override;
  virtual ScopedAStatus flush() override;
  virtual ScopedAStatus stop() override;
  virtual ScopedAStatus cleanup() override;
private:
  shared_ptr<IGnssBatchingCallback> mGnssBatchingCbIface = nullptr;
  AIBinder_DeathRecipient *mDeathRecipient = nullptr;
  int mBatchSize;
};
}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSBATCHING_H
