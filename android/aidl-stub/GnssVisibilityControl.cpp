/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#include <aidl/android/hardware/gnss/visibility_control/BnGnssVisibilityControl.h>
#include "GnssVisibilityControl.h"

namespace android {
namespace hardware {
namespace gnss {
namespace visibility_control {
namespace aidl {
namespace implementation {

void gnssVisibilityControlServiceDied(void* cookie) {
    GnssVisibilityControl* iface = static_cast<GnssVisibilityControl*>(cookie);
    if (iface != nullptr) {
        iface->setCallback(nullptr);
        iface = nullptr;
    }
}

GnssVisibilityControl::GnssVisibilityControl() :
    mDeathRecipient(AIBinder_DeathRecipient_new(&gnssVisibilityControlServiceDied)) {
}

ScopedAStatus GnssVisibilityControl::enableNfwLocationAccess(
        const std::vector<std::string>& proxyApps) {
    return ScopedAStatus::ok();
}

/**
 * Registers the callback for HAL implementation to use.
 *
 * @param callback Handle to IGnssVisibilityControlCallback interface.
 */
ScopedAStatus GnssVisibilityControl::setCallback(
        const shared_ptr<IGnssVisibilityControlCallback>& callback) {
    return ScopedAStatus::ok();
}
}  // namespace implementation
}  // namespace aidl
}  // namespace visibility_control
}  // namespace gnss
}  // namespace hardware
}  // namespace android
