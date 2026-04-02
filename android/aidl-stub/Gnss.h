/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/

#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSS_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSS_H

#include <android/binder_auto_utils.h>
#include <aidl/android/hardware/gnss/BnGnss.h>
namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

using ::aidl::android::hardware::gnss::GnssConstellationType;
using ::aidl::android::hardware::gnss::BnGnss;
using ::aidl::android::hardware::gnss::IGnssCallback;
using ::aidl::android::hardware::gnss::IGnssPowerIndication;
using ::aidl::android::hardware::gnss::IGnssMeasurementInterface;
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;
using ::aidl::android::hardware::gnss::GnssLocation;
using ::aidl::android::hardware::gnss::IGnssPsds;
using ::aidl::android::hardware::gnss::IGnssConfiguration;
using ::aidl::android::hardware::gnss::IGnssBatching;
using ::aidl::android::hardware::gnss::IGnssGeofence;
using ::aidl::android::hardware::gnss::IGnssNavigationMessageInterface;
using ::aidl::android::hardware::gnss::IAGnss;
using ::aidl::android::hardware::gnss::IAGnssRil;
using ::aidl::android::hardware::gnss::IGnssDebug;
using ::aidl::android::hardware::gnss::IGnssAntennaInfo;
using ::aidl::android::hardware::gnss::visibility_control::IGnssVisibilityControl;
using ::aidl::android::hardware::gnss::measurement_corrections::IMeasurementCorrectionsInterface;
struct Gnss : public BnGnss {
    Gnss();
    ~Gnss();

    ScopedAStatus setCallback(const shared_ptr<IGnssCallback>& callback) override;
    ScopedAStatus close() override;
    ScopedAStatus getExtensionPsds(shared_ptr<IGnssPsds>* _aidl_return) {
        return ScopedAStatus(AStatus_fromExceptionCode(EX_UNSUPPORTED_OPERATION));
    }
    ScopedAStatus getExtensionGnssConfiguration(
            shared_ptr<IGnssConfiguration>* _aidl_return) override;
    ScopedAStatus getExtensionGnssPowerIndication(
            shared_ptr<IGnssPowerIndication>* _aidl_return) override;
    ScopedAStatus getExtensionGnssMeasurement(
            shared_ptr<IGnssMeasurementInterface>* _aidl_return) override;

    ScopedAStatus getExtensionGnssBatching(shared_ptr<IGnssBatching>* _aidl_return) override;
    ScopedAStatus getExtensionGnssGeofence(shared_ptr<IGnssGeofence>* _aidl_return) override;
    ScopedAStatus getExtensionGnssNavigationMessage(
            shared_ptr<IGnssNavigationMessageInterface>* _aidl_return) {
        return ScopedAStatus(AStatus_fromExceptionCode(EX_UNSUPPORTED_OPERATION));
    }
    ScopedAStatus getExtensionAGnss(shared_ptr<IAGnss>* _aidl_return) override;
    ScopedAStatus getExtensionAGnssRil(shared_ptr<IAGnssRil>* _aidl_return) override;
    ScopedAStatus getExtensionGnssDebug(shared_ptr<IGnssDebug>* _aidl_return) override;
    ScopedAStatus getExtensionGnssVisibilityControl(
            shared_ptr<IGnssVisibilityControl>* _aidl_return) override;
    ScopedAStatus start() override;
    ScopedAStatus stop() override;
    ScopedAStatus injectTime(int64_t timeMs, int64_t timeReferenceMs,
            int32_t uncertaintyMs) override;
    ScopedAStatus injectLocation(const GnssLocation& location) override;
    ScopedAStatus injectBestLocation(const GnssLocation& gnssLocation) override;
    ScopedAStatus deleteAidingData(IGnss::GnssAidingData aidingDataFlags) override;
    ScopedAStatus setPositionMode(const IGnss::PositionModeOptions& options) override;
    ScopedAStatus getExtensionGnssAntennaInfo(shared_ptr<IGnssAntennaInfo>* _aidl_return) override;
    ScopedAStatus getExtensionMeasurementCorrections(
            shared_ptr<IMeasurementCorrectionsInterface>* _aidl_return) override;
    ScopedAStatus startSvStatus() override;
    ScopedAStatus stopSvStatus() override;
    ScopedAStatus startNmea() override;
    ScopedAStatus stopNmea() override;

    // These methods are not part of the IGnss base class.
    void handleAidlClientSsr();
private:
    shared_ptr<IGnssConfiguration> mGnssConfiguration = nullptr;
    shared_ptr<IGnssPowerIndication> mGnssPowerIndication = nullptr;
    shared_ptr<IGnssMeasurementInterface> mGnssMeasurementInterface = nullptr;
    shared_ptr<IGnssBatching> mGnssBatching = nullptr;
    shared_ptr<IGnssGeofence> mGnssGeofence = nullptr;
    shared_ptr<IAGnss> mAGnss = nullptr;
    shared_ptr<IAGnssRil> mAGnssRil = nullptr;
    shared_ptr<IGnssDebug> mGnssDebug = nullptr;
    shared_ptr<IGnssVisibilityControl> mGnssVisibCtrl = nullptr;
    shared_ptr<IGnssAntennaInfo> mGnssAntennaInfo = nullptr;
    shared_ptr<IMeasurementCorrectionsInterface> mGnssMeasCorr = nullptr;

    shared_ptr<IGnssCallback> mGnssCallback = nullptr;
    AIBinder_DeathRecipient *mDeathRecipient = nullptr;
};

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_GNSS_AIDL_GNSS_H
