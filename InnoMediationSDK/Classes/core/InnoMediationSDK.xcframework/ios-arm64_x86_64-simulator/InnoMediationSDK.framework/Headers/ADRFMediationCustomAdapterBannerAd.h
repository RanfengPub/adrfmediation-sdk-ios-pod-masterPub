//
//  ADRFMediationCustomAdapterBannerAd.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/8/30.
//

#import <InnoMediationSDK/ADRFMediationCustomAdapterAd.h>
#import <InnoMediationSDK/ADRFMediationCustomAdapterBannerRequestContext.h>
#import <InnoMediationSDK/ADRFMediationSDKSourceBiddingResult.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterBannerAd : ADRFMediationCustomAdapterAd

// MARK: - 需要在子类实现的方法

/// 在子类实现该方法用于请求平台banner广告
/// @param context 请求参数模型
- (UIView *)requestBannerViewWithContext:(ADRFMediationCustomAdapterBannerRequestContext *)context;

/// 竞价询价请求
- (void)biddingRequestBannerViewWithContext:(ADRFMediationCustomAdapterBannerRequestContext *)context;

/// 竞价结果，该方法内实现仅处理三方竞价结果上报即可
/// - Parameters:
///   - result: 竞价结果
///   - allPrices: 所有竞价价格
- (void)biddingResult:(ADRFMediationSDKSourceBiddingResult)result
             AllPrice:(NSArray *)allPrices;

// MARK: - 以下方法无需在子类中实现，已在父类中实现，只需子类中调用即可

/// 三方平台广告请求成功时，子类适配器中调用方法
/// - Parameter eCPM: 若为竞价广告，则传递价格（元）
- (void)trackBannerAdDidReceived:(double)eCPM;
- (void)trackBannerAdDidReceived;

/// 三方平台广告请求失败时，子类适配器中调用方法
- (void)trackBannerAdFailToReceivedWithError:(nullable NSError *)error;

/// 三方平台广告点击时，子类适配器中调用方法
- (void)trackBannerAdClicked;

/// 三方平台广告曝光时，子类适配器调用方法
- (void)trackBannerAdExposure;

/// 三方平台广告关闭时，子类适配器中调用方法
- (void)trackBannerAdClosed;

/// 三方平台广告落地页关闭时，子类适配器中调用方法
- (void)trackBannerAdLandingPageClosed;


@end

NS_ASSUME_NONNULL_END
