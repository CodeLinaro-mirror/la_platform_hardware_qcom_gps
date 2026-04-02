/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#include <aidl/android/hardware/gnss/IGnssGeofenceCallback.h>
#include "GnssGeofence.h"

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
void gnssGeofenceDied(void* cookie) {
}
GnssGeofence::GnssGeofence() : mDeathRecipient(AIBinder_DeathRecipient_new(&gnssGeofenceDied)) {}
GnssGeofence::~GnssGeofence() {}

ScopedAStatus GnssGeofence::setCallback(const shared_ptr<IGnssGeofenceCallback>& callback) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssGeofence::addGeofence(int32_t geofenceId, double latitudeDegrees,
        double longitudeDegrees, double radiusMeters, int32_t lastTransition,
        int32_t monitorTransitions, int32_t notificationResponsivenessMs, int32_t unknownTimerMs) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssGeofence::pauseGeofence(int32_t geofenceId) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssGeofence::resumeGeofence(int32_t geofenceId, int32_t monitorTransitions) {
    return ScopedAStatus::ok();
}

ScopedAStatus GnssGeofence::removeGeofence(int32_t geofenceId) {
    return ScopedAStatus::ok();
}

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
