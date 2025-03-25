//
//  ADRFMediationSDKBannerAdView.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/4/9.
//

#import <UIKit/UIKit.h>
#import <ADRFMediationSDK/ADRFMediationAdapterErrorDefine.h>
#import <ADRFMediationSDK/ADRFMediationAdViewInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADRFMediationSDKBannerAdViewDelegate;

@interface ADRFMediationSDKBannerAdView : UIView <ADRFMediationAdViewInfoProtocol>

/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<ADRFMediationSDKBannerAdViewDelegate> delegate;

/**
 广告位id
*/
@property (nonatomic, copy) NSString *posId;

/**
 场景id
 */
@property (nonatomic, copy, nullable) NSString *scenesId;

/**
 请求超时时间,默认为4s,需要设置3s及以上
*/
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

/*
 初始化bannerView
 @param frame 期望的banner视图尺寸
*/
- (instancetype)initWithFrame:(CGRect)frame;

/**
 拉取并展示广告
 
 @param controller 用来弹出目标页的ViewController，一般为当前ViewController
*/
- (void)loadAndShow:(UIViewController *)controller;

@end

@protocol ADRFMediationSDKBannerAdViewDelegate <NSObject>

/**
 广告获取成功
 
 @param bannerView banner实例
 */
- (void)adrf_bannerViewDidReceived:(ADRFMediationSDKBannerAdView *)bannerView;

/**
 广告拉取失败
 
 @param bannerView banner实例
 @param errorModel 错误描述
 */
- (void)adrf_bannerViewFailToReceived:(ADRFMediationSDKBannerAdView *)bannerView errorModel:(ADRFMediationAdapterErrorDefine *)errorModel;

/**
 广告点击
 
 @param bannerView 广告实例
 */
- (void)adrf_bannerViewClicked:(ADRFMediationSDKBannerAdView *)bannerView;

/**
 广告关闭
 
 @param bannerView 广告实例
 */
- (void)adrf_bannerViewClose:(ADRFMediationSDKBannerAdView *)bannerView;

/**
 广告展示
 
 @param bannerView 广告实例
 */
- (void)adrf_bannerViewDidPresent:(ADRFMediationSDKBannerAdView *)bannerView;

/**
 广告曝光
 
 @param bannerView 广告实例
 */
- (void)adrf_bannerViewExposure:(ADRFMediationSDKBannerAdView *)bannerView;

/**
 关闭落地页
 
 @param bannerView 广告实例
 */
- (void)adrf_bannerAdCloseLandingPage:(ADRFMediationSDKBannerAdView *)bannerView;

@end


NS_ASSUME_NONNULL_END
