//
//  ADRFMediationSDKSplashAd.h
//  ADRFMediationSDK
//
//  Created by 陶冶明 on 2020/4/8.
//

#import <UIKit/UIKit.h>
#import <InnoMediationSDK/ADRFMediationAdapterErrorDefine.h>
#import <InnoMediationSDK/ADRFMediationAdapterSplashSkipViewProtocol.h>
#import <InnoMediationSDK/ADRFMediationAdViewInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ADRFMediationSplashRenderType) {
    ADRFMediationSplashRenderTypeExpress = 1,//模版开屏
    ADRFMediationSplashRenderTypeNative = 2,//原生开屏
    ADRFMediationSplashRenderTypeExpressPro = 3, //开屏模版2.0
};

@protocol ADRFMediationSDKSplashAdDelegate;

@interface ADRFMediationSDKSplashAd : NSObject <ADRFMediationAdViewInfoProtocol>

/**
开屏的默认背景色,或者启动页,为nil则代表透明
*/
@property (nonatomic, copy, nullable) UIColor *backgroundColor;

/*
viewControllerForPresentingModalView
详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
*/
@property (nonatomic, weak) UIViewController *controller;

/**
 广告位id
*/
@property (nonatomic, copy, nullable) NSString *posId;

/**
 场景id
 */
@property (nonatomic, copy, nullable) NSString *scenesId;

/**
 代理回调
*/
@property (nonatomic, weak) id<ADRFMediationSDKSplashAdDelegate> delegate;

/**
 开屏请求总超时时间:所有平台轮询的请求等待总时长（不包括图片渲染时间），单位秒，推荐设置为4s，最小值为3s
 开屏各平台分配逻辑:(目前只有开屏需要分配时间，并且理论上分配给到各平台的超时时间不会完全耗尽)
 1、3<=tolerateTimeout<=4:轮询首位平台的超时时间为(tolerateTimeout-1)s，次位为2s，如果后续还有平台统一为1s;
 2、tolerateTimeout>=5:轮询首位平台的超时时间为(tolerateTimeout-2)s，次位为3s，如果后续还有平台统一为2s;
 */
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

/**
 屏蔽摇一摇、扭转手机
 默认NO：不屏蔽，YES：屏蔽
 支持平台：天目、易量跃动ads、优量汇(仅支持屏蔽摇一摇)、快手
 */
@property (nonatomic, assign) BOOL disableMotion;

/**
设置保底开屏 （可选）
（App初次启动及ADRFMediationSDK未初始化状态保证开屏填充）
 支持平台：穿山甲、优量汇、快手、百度
 @param rfId rf平台广告源id
@param platformListId 后台配置查看networkAdPosListID
@param appId 广告平台AppId，非rfAPPid
@param appKey 广告平台AppKey,没有可不传
@param platformPosid 广告平台广告位id
@param renderType 平台广告类型，如：原生，模板。
*/
- (void)setBottomSplashWithRfPosid:(NSString * )rfId platformListId:(NSString *)platformListId platform:(NSString *)platform appId:(NSString *)appId appKey:(nullable NSString *)appKey platformPosid:(NSString *)platformPosid renderType:(ADRFMediationSplashRenderType)renderType;

/**
加载开屏广告

@param window 开屏广告展示的window
@param bottomView 底部logo视图, 高度不能超过屏幕的25%
*/
- (void)loadAndShowInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

/**
加载开屏广告

@param window 开屏广告展示的window
*/
- (void)loadAndShowInWindow:(UIWindow *)window;

/**
加载开屏广告

@param window 开屏广告展示的window
*/
- (void)loadAdInWindow:(UIWindow *)window;

/**
加载开屏广告

@param window 开屏广告展示的window
@param bottomView 底部logo视图, 高度不能超过屏幕的25%, 建议: 开屏的广告图片默认640 / 960比例, 可以用 MIN(screenHeight - screenWidth * (960 / 640.0), screenHeight * 0.25) 得出bottomview的高度
*/
- (void)loadAdInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

/**
展示开屏广告

@param window 开屏广告展示的window
*/
- (void)showAdInWindow:(UIWindow *)window;


@end

@protocol ADRFMediationSDKSplashAdDelegate <NSObject>

@optional
/**
 开屏加载成功
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdSuccessToLoadAd:(ADRFMediationSDKSplashAd *)splashAd;

/**
 开屏展现成功
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdSuccessToPresentScreen:(ADRFMediationSDKSplashAd *)splashAd;

/**
 开屏展现失败
 
 @param splashAd 广告实例
 @param error 具体错误信息
 */
- (void)adrf_splashAdFailToPresentScreen:(ADRFMediationSDKSplashAd *)splashAd failToPresentScreen:(ADRFMediationAdapterErrorDefine *)error;

/**
 开屏广告点击
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdClicked:(ADRFMediationSDKSplashAd *)splashAd;

/**
 开屏被跳过
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdSkip:(ADRFMediationSDKSplashAd *)splashAd;

/**
 开屏被关闭
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdClosed:(ADRFMediationSDKSplashAd *)splashAd;

/**
 开屏展示
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdEffective:(ADRFMediationSDKSplashAd *)splashAd;

/**
 开屏关闭落地页
 
 @param splashAd 广告实例
 */
- (void)adrf_splashAdCloseLandingPage:(ADRFMediationSDKSplashAd *)splashAd;

@end

NS_ASSUME_NONNULL_END
