/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/


#define LOG_TAG "GnssAidl"
#define LOG_NDEBUG 0

#include "Gnss.h"
#include "GnssConfiguration.h"
#include "AGnssRil.h"
#include "AGnss.h"
#include "GnssGeofence.h"
#include "GnssDebug.h"
#include "GnssAntennaInfo.h"
#include "GnssVisibilityControl.h"
#include "GnssBatching.h"
#include "GnssPowerIndication.h"
#include "GnssMeasurementInterface.h"
#include "MeasurementCorrectionsInterface.h"

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
using measurement_corrections::aidl::implementation::MeasurementCorrectionsInterface;
using ::android::hardware::gnss::visibility_control::aidl::implementation::GnssVisibilityControl;

void gnssServiceDied(void* cookie) {
    Gnss* iface = static_cast<Gnss*>(cookie);
    if (iface != nullptr) {
        iface->handleAidlClientSsr();
    }
}
ScopedAStatus Gnss::setCallback(const shared_ptr<IGnssCallback>& callback) {
    return ScopedAStatus::ok();
}

ScopedAStatus Gnss::close() {
    return ScopedAStatus::ok();
}

Gnss::Gnss(): mDeathRecipient(AIBinder_DeathRecipient_new(&gnssServiceDied)) {
}

Gnss::~Gnss() {
    handleAidlClientSsr();
}

void Gnss::handleAidlClientSsr() {
    if (mGnssCallback != nullptr) {
        AIBinder_unlinkToDeath(mGnssCallback->asBinder().get(), mDeathRecipient, this);
        mGnssCallback = nullptr;
    }
}
ScopedAStatus Gnss::getExtensionGnssBatching(shared_ptr<IGnssBatching>* _aidl_return) {
    if (mGnssBatching == nullptr) {
        mGnssBatching = SharedRefBase::make<GnssBatching>();
    }
    *_aidl_return = mGnssBatching;
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionGnssGeofence(shared_ptr<IGnssGeofence>* _aidl_return) {
    if (mGnssGeofence == nullptr) {
        mGnssGeofence = SharedRefBase::make<GnssGeofence>();
    }
    *_aidl_return = mGnssGeofence;
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionAGnss(shared_ptr<IAGnss>* _aidl_return) {
    if (mAGnss == nullptr) {
        mAGnss = SharedRefBase::make<AGnss>();
    }
    *_aidl_return = mAGnss;
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionAGnssRil(shared_ptr<IAGnssRil>* _aidl_return) {
    if (mAGnssRil == nullptr) {
        mAGnssRil = SharedRefBase::make<AGnssRil>();
    }
    *_aidl_return = mAGnssRil;
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionGnssDebug(shared_ptr<IGnssDebug>* _aidl_return) {
    if (mGnssDebug == nullptr) {
        mGnssDebug = SharedRefBase::make<GnssDebug>();
    }
    *_aidl_return = mGnssDebug;
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionGnssVisibilityControl(
        shared_ptr<IGnssVisibilityControl>* _aidl_return) {
    if (mGnssVisibCtrl == nullptr) {
        mGnssVisibCtrl = SharedRefBase::make<GnssVisibilityControl>();
    }
    *_aidl_return = mGnssVisibCtrl;
    return ScopedAStatus::ok();
}

ScopedAStatus Gnss::start() {
    return ScopedAStatus::ok();
}

ScopedAStatus Gnss::stop()  {
    return ScopedAStatus::ok();
 }
ScopedAStatus Gnss::startSvStatus() {
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::stopSvStatus() {
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::startNmea() {
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::stopNmea() {
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::injectTime(int64_t timeMs, int64_t timeReferenceMs,
            int32_t uncertaintyMs) {
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::injectLocation(const GnssLocation& location) {
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::injectBestLocation(const GnssLocation& gnssLocation) {
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::deleteAidingData(IGnss::GnssAidingData aidingDataFlags) {
    return ScopedAStatus::ok();
}

ScopedAStatus Gnss::setPositionMode(const IGnss::PositionModeOptions& options) {
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionGnssAntennaInfo(shared_ptr<IGnssAntennaInfo>* _aidl_return) {
    if (mGnssAntennaInfo == nullptr) {
        mGnssAntennaInfo = SharedRefBase::make<GnssAntennaInfo>();
    }
    *_aidl_return = mGnssAntennaInfo;
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionMeasurementCorrections(
        shared_ptr<IMeasurementCorrectionsInterface>* _aidl_return) {
    if (mGnssMeasCorr == nullptr) {
        mGnssMeasCorr = SharedRefBase::make<MeasurementCorrectionsInterface>();
    }
    *_aidl_return = mGnssMeasCorr;
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionGnssConfiguration(
        shared_ptr<IGnssConfiguration>* _aidl_return) {
    if (mGnssConfiguration == nullptr) {
        mGnssConfiguration = SharedRefBase::make<GnssConfiguration>();
    }
    *_aidl_return = mGnssConfiguration;
    return ScopedAStatus::ok();
}

ScopedAStatus Gnss::getExtensionGnssPowerIndication(
        shared_ptr<IGnssPowerIndication>* _aidl_return) {
    if (mGnssPowerIndication == nullptr) {
        mGnssPowerIndication = SharedRefBase::make<GnssPowerIndication>();
    }
    *_aidl_return = mGnssPowerIndication;
    return ScopedAStatus::ok();
}
ScopedAStatus Gnss::getExtensionGnssMeasurement(
        shared_ptr<IGnssMeasurementInterface>* _aidl_return) {
    if (mGnssMeasurementInterface == nullptr) {
        mGnssMeasurementInterface = SharedRefBase::make<GnssMeasurementInterface>();
    }
    *_aidl_return = mGnssMeasurementInterface;
    return ScopedAStatus::ok();
}

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
