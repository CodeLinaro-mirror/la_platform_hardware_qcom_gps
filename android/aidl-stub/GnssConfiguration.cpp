/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/


#define LOG_TAG "GnssConfigurationAidl"

#include "GnssConfiguration.h"

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

GnssConfiguration::GnssConfiguration() {
}

ScopedAStatus GnssConfiguration::setSuplVersion(int version) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssConfiguration::setSuplMode(int mode) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssConfiguration::setLppProfile(int lppProfileMask) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssConfiguration::setGlonassPositioningProtocol(int protocol) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssConfiguration::setEmergencySuplPdn(bool enabled) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssConfiguration::setEsExtensionSec(int emergencyExtensionSeconds) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssConfiguration::setBlocklist(const vector<BlocklistedSource>& sourceList) {
    return ScopedAStatus::ok();
}

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
