/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSVISIBILITYCONTROL_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSVISIBILITYCONTROL_H
#include <aidl/android/hardware/gnss/visibility_control/BnGnssVisibilityControl.h>

namespace android {
namespace hardware {
namespace gnss {
namespace visibility_control {
namespace aidl {
namespace implementation {
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;
using ::aidl::android::hardware::gnss::visibility_control::BnGnssVisibilityControl;
using ::aidl::android::hardware::gnss::visibility_control::IGnssVisibilityControlCallback;
class GnssVisibilityControl : public BnGnssVisibilityControl {
public:
  GnssVisibilityControl();
  virtual ~GnssVisibilityControl() = default;

    ScopedAStatus enableNfwLocationAccess(const std::vector<std::string>& proxyApps) override;
    ScopedAStatus setCallback(const shared_ptr<IGnssVisibilityControlCallback>& callback) override;
private:
    shared_ptr<IGnssVisibilityControlCallback> mGnssVisibilityControlCbIface = nullptr;
    AIBinder_DeathRecipient* mDeathRecipient;
};
}  // namespace implementation
}  // namespace aidl
}  // namespace visibility_control
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSVISIBILITYCONTROL_H
