/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSCONFIGURATION_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSCONFIGURATION_H
#include <aidl/android/hardware/gnss/BnGnssConfiguration.h>
#include <aidl/android/hardware/gnss/GnssConstellationType.h>
#include <aidl/android/hardware/gnss/BlocklistedSource.h>
#include <vector>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

using ::aidl::android::hardware::gnss::GnssConstellationType;
using ::aidl::android::hardware::gnss::BlocklistedSource;
using ::aidl::android::hardware::gnss::BnGnssConfiguration;
using ::ndk::ScopedAStatus;

using std::vector;

struct GnssConfiguration : public BnGnssConfiguration {
public:
    GnssConfiguration();
    ScopedAStatus setSuplVersion(int) override;

    ScopedAStatus setSuplMode(int) override;

    ScopedAStatus setLppProfile(int) override;

    ScopedAStatus setGlonassPositioningProtocol(int) override;

    ScopedAStatus setEmergencySuplPdn(bool) override;

    ScopedAStatus setEsExtensionSec(int) override;

    ScopedAStatus setBlocklist(const vector<BlocklistedSource>& blocklist) override;
};

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSCONFIGURATION_H
