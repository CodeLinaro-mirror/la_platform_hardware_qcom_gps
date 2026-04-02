/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_AGNSSRIL_H
#define ANDROID_HARDWARE_GNSS_AIDL_AGNSSRIL_H
#include <aidl/android/hardware/gnss/IAGnssRil.h>
#include <aidl/android/hardware/gnss/IAGnssRilCallback.h>
#include <aidl/android/hardware/gnss/BnAGnssRil.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
using ::aidl::android::hardware::gnss::BnAGnssRil;
using ::aidl::android::hardware::gnss::IAGnssRilCallback;
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;
class AGnssRil : public BnAGnssRil {
public:
  AGnssRil();
  virtual ~AGnssRil();

  ScopedAStatus setCallback(const shared_ptr<IAGnssRilCallback>& callback) override {
      return ScopedAStatus::ok();
  }
  ScopedAStatus setRefLocation(const IAGnssRil::AGnssRefLocation& agnssReflocation) override {
      return ScopedAStatus::ok();
  }
  ScopedAStatus setSetId(IAGnssRil::SetIdType type, const std::string& setid) override {
      return ScopedAStatus::ok();
  }
  ScopedAStatus updateNetworkState(const IAGnssRil::NetworkAttributes& attributes) override;
  ScopedAStatus injectNiSuplMessageData(
            const std::vector<uint8_t>& in_msgData, int32_t in_slotIndex) override {
      return ScopedAStatus(AStatus_fromServiceSpecificError(STATUS_UNKNOWN_ERROR));
  }
};
}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_AGNSSRIL_H
