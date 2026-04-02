/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#include <aidl/android/hardware/gnss/IAGnssRil.h>
#include <aidl/android/hardware/gnss/IAGnssRilCallback.h>
#include <aidl/android/hardware/gnss/BnAGnssRil.h>
#include "AGnssRil.h"

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
AGnssRil::AGnssRil() {}

AGnssRil::~AGnssRil() {}

ScopedAStatus AGnssRil::updateNetworkState(const IAGnssRil::NetworkAttributes& attributes) {
    return ScopedAStatus::ok();
}
}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
