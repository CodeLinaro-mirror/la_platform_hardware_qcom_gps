/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#include <aidl/android/hardware/gnss/measurement_corrections/IMeasurementCorrectionsCallback.h>
#include <aidl/android/hardware/gnss/measurement_corrections/MeasurementCorrections.h>
#include "MeasurementCorrectionsInterface.h"

namespace android {
namespace hardware {
namespace gnss {
namespace measurement_corrections {
namespace aidl {
namespace implementation {
using ::aidl::android::hardware::gnss::GnssConstellationType;

void measurementCorrectionsInterfaceDied(void* cookie) {
    MeasurementCorrectionsInterface* iface = static_cast<MeasurementCorrectionsInterface*>(cookie);
    if (iface != nullptr) {
        iface->setCallback(nullptr);
        iface = nullptr;
    }
}
MeasurementCorrectionsInterface::MeasurementCorrectionsInterface() :
    mDeathRecipient(AIBinder_DeathRecipient_new(&measurementCorrectionsInterfaceDied)) {
}

MeasurementCorrectionsInterface::~MeasurementCorrectionsInterface() {
}


ScopedAStatus MeasurementCorrectionsInterface::setCorrections(
        const MeasurementCorrections& corrections) {
   return ScopedAStatus::ok();
}

ScopedAStatus MeasurementCorrectionsInterface::setCallback(
    const shared_ptr<IMeasurementCorrectionsCallback>& callback) {
    return ScopedAStatus::ok();
}
}
}  // namespace aidl
}  // namespace measurement_corrections
}  // namespace gnss
}  // namespace hardware
}  // namespace android
