//
//  ADRFMediationCustomRewardVodAd.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/8/28.
//

#import <InnoMediationSDK/ADRFMediationCustomAdapterAd.h>
#import <InnoMediationSDK/ADRFMediationCustomAdapterRewardRequestContext.h>
#import <InnoMediationSDK/ADRFMediationSDKSourceBiddingResult.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADRFMediationCustomAdapterRewardVodAdProtocol <NSObject>

@required
// MARK: - 需要在子类实现的方法

/// 激励视频广告是否准备好
- (bool)isReady;

/// 激励视频广告物料是否有效
- (bool)isValid;

/// 请求广告方法，必须于子类中实现
/// @param context 主SDK端传入的请求相关参数
- (void)requestAdWithContext:(ADRFMediationCustomAdapterRewardRequestContext *)context;

/// 展示激励视频方法方法，在该方法实现中调用平台展示方法
- (void)showRewardVodAdFromViewController:(UIViewController * _Nullable)viewController;


@optional

/// 激励视频广告是否支持服务端验证
- (bool)canServerVerrify;

// MARK: 需支持竞价时实现

/// 竞价询价请求
- (void)biddingRequestWithContext:(ADRFMediationCustomAdapterRewardRequestContext *)context;

/// 竞价结果，该方法内实现仅处理三方竞价结果上报即可
/// - Parameters:
///   - result: 竞价结果
///   - allPrices: 所有竞价价格
- (void)biddingResult:(ADRFMediationSDKSourceBiddingResult)result
             AllPrice:(NSArray *)allPrices;

@end


@interface ADRFMediationCustomAdapterRewardVodAd : ADRFMediationCustomAdapterAd<ADRFMediationCustomAdapterRewardVodAdProtocol>

// MARK: - 以下方法无需在子类中实现，已在父类中实现，只需子类中调用即可

/// 三方平台请求成功时，子类适配器中调用方法
/// - Parameter eCPM: 若为竞价广告，则传递价格（元）
- (void)trackRwardvodAdLoadSuccess:(double)eCPM;
- (void)trackRwardvodAdLoadSuccess;

/// 三方平台视频准备播放时，子类适配器中调用方法
- (void)trackRewardvodAdReadyToPlay;

/// 三方平台视频准备完成时，子类适配器中调用方法
- (void)trackRewardvodAdVideoLoadSuccess;

/// 三方平台视频即将展示时，子类适配器中调用方法
- (void)trackRewardvodAdWillVisible;

/// 三方平台视频展示时，子类适配器中调用方法
- (void)trackRewardvodAdDidVisible;

/// 三方平台视频关闭时，子类适配器中调用方法
- (void)trackRewardvodAdDidClose;

/// 三方平台视频点击时，子类适配器中调用方法
- (void)trackRewardvodAdDidClick;

/// 三方平台视频播放完成时，子类适配器中调用方法
- (void)trackRewardvodAdDidPlayFinish;

/// 三方平台视频播放达到激励条件时，子类适配器中调用方法
- (void)trackRewardVodAdDidRewardEffective;

/// 三方平台请求失败时，子类适配器中调用方法
- (void)trackRewardvodAdFailToLoadError:(NSError *)error;

/// 三方平台展示失败时，子类适配器中调用方法
- (void)trackRewardvodAdFailToPresentError:(NSError *)error;

/// 三方平台视频播放错误时，子类适配器中调用方法
- (void)trackRewardvodAdVideoFailToPlayError:(NSError *)error;

/// 三方平台关闭落地页时，子类适配器中调用方法
- (void)trackRewardvodAdLandingPageClosed;

/// 三方平台广告服务器验证成功(不携带激励验证相关参数)，子类适配器中调用方法
- (void)trackRewardvodAdVideoAdServerRewardDidSucceed;

/// 三方平台广告服务器验证成功(携带激励验证相关参数)，子类适配器中调用方法
- (void)trackRewardvodAdVideoAdServerRewardDidSucceedWithInfo:(nullable NSDictionary *)info;

/// 广告服务器验证失败
- (void)trackRewardvodAdVideoAdServerRewardDidFailed:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
