/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#include <aidl/android/hardware/gnss/IGnssAntennaInfoCallback.h>
#include "GnssAntennaInfo.h"

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

void gnssAntennaInfoServiceDied(void* cookie) {
    GnssAntennaInfo* iface = static_cast<GnssAntennaInfo*>(cookie);
    if (iface != nullptr) {
        iface->close();
        iface = nullptr;
    }
}
GnssAntennaInfo::GnssAntennaInfo()
    : mDeathRecipient(AIBinder_DeathRecipient_new(&gnssAntennaInfoServiceDied)) {}

ScopedAStatus GnssAntennaInfo::setCallback(
        const shared_ptr<IGnssAntennaInfoCallback>& callback) {
    return ScopedAStatus::ok();
}
ScopedAStatus GnssAntennaInfo::close() {
    mGnssAntennaInfoCbIface = nullptr;
    return ScopedAStatus::ok();
}

}
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
