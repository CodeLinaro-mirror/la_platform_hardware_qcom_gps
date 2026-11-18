/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#include <aidl/android/hardware/gnss/GnssConstellationType.h>
#include <aidl/android/hardware/gnss/IGnssDebug.h>
#include "GnssDebug.h"

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

GnssDebug::GnssDebug() {}
GnssDebug::~GnssDebug() {}

ScopedAStatus GnssDebug::getDebugData(IGnssDebug::DebugData* _aidl_return) {
    return ScopedAStatus::ok();
}
}
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
