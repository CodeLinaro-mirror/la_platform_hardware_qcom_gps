/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSDEBUG_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSDEBUG_H
#include <aidl/android/hardware/gnss/GnssConstellationType.h>
#include <aidl/android/hardware/gnss/BnGnssDebug.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
using ::aidl::android::hardware::gnss::BnGnssDebug;
using ::ndk::ScopedAStatus;
class GnssDebug : public BnGnssDebug {
public:
    GnssDebug();
  virtual ~GnssDebug();

  virtual ScopedAStatus getDebugData(IGnssDebug::DebugData* _aidl_return) override;
private:
};
}
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSDEBUG_H
