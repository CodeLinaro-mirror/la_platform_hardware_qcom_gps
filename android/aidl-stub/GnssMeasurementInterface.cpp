/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/

#define LOG_TAG "GnssMeasurementInterfaceAidl"

#include "GnssMeasurementInterface.h"
#include <android/binder_auto_utils.h>
#include <aidl/android/hardware/gnss/BnGnss.h>
#include <inttypes.h>

using aidl::android::hardware::gnss::ElapsedRealtime;
using aidl::android::hardware::gnss::GnssClock;
using aidl::android::hardware::gnss::GnssData;
using aidl::android::hardware::gnss::GnssMeasurement;
using aidl::android::hardware::gnss::GnssSignalType;
using aidl::android::hardware::gnss::GnssConstellationType;
using aidl::android::hardware::gnss::GnssMultipathIndicator;
using aidl::android::hardware::gnss::SatellitePvt;

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

GnssMeasurementInterface::GnssMeasurementInterface() :
    mDeathRecipient(AIBinder_DeathRecipient_new(GnssMeasurementInterface::gnssMeasurementDied)) {
}

ScopedAStatus GnssMeasurementInterface::setCallback(
        const shared_ptr<IGnssMeasurementCallback>& callback,
        bool enableFullTracking, bool enableCorrVecOutputs) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssMeasurementInterface::setCallbackWithOptions(
        const shared_ptr<IGnssMeasurementCallback>& callback,
        const IGnssMeasurementInterface::Options& options) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssMeasurementInterface::close()  {
    return ScopedAStatus::ok();
}

void GnssMeasurementInterface::gnssMeasurementDied(void* cookie) {
    GnssMeasurementInterface* iface = static_cast<GnssMeasurementInterface*>(cookie);
    //clean up, i.e.  iface->close();
    if (iface != nullptr) {
        iface->close();
    }
}

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
