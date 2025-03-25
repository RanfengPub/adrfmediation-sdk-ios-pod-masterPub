//
//  ADRFMediationAdapterDrawvodAdView.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/4/22.
//

#import <UIKit/UIKit.h>
#import <ADRFMediationSDK/ADRFMediationAdViewInfoProtocol.h>
#import <ADRFMediationSDK/ADRFMediationAdapterNativeAdData.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationAdapterDrawvodAdView : UIView <ADRFMediationAdViewInfoProtocol>

- (void)render;

- (void)registView;

- (void)unRegist;

// 记录当前渲染是否完成，如果已经完成渲染，则不要重复回掉
// 因为穿山甲有重复回掉渲染成功的问题
@property (nonatomic, assign) BOOL renderSucced;

/**
 渲染类型
 */
- (ADRFMediationAdapterRenderType)renderType;

/**
 自渲染广告数据，模版类型等其他类型为空
 */
@property (nonatomic, strong, nullable, readonly) ADRFMediationAdapterNativeAdData *data;

/**
 获取视频视图，如果是模版广告则为nil
 */
- (nullable UIView *)adrf_mediaViewForWidth:(CGFloat)width;

/**
 平台logo
 */
- (void)adrf_platformLogoImageDarkMode:(BOOL)darkMode loadImageBlock:(void(^)(UIImage * _Nullable))block;

@end

NS_ASSUME_NONNULL_END
