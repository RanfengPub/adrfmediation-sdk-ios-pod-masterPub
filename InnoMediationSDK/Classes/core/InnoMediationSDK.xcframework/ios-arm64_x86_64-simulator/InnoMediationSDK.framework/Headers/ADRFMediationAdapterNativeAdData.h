//
//  ADRFMediationAdapterNativeAdView.h
//  ADRFMediationSDK
//
//  Created by 陶冶明 on 2020/4/16.
//

#import <UIKit/UIKit.h>
#import <InnoMediationSDK/ADRFMediationAdViewInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class ADRFMediationAdapterNativeAdData;

@protocol ADRFMediationAdapterNativeAdViewDelegate <ADRFMediationAdViewInfoProtocol>
/**
 注册广告视图
 */
- (void)adrf_registViews:(NSArray<UIView *> *)clickViews;

/**
 取消注册
    如果renderType为ExpressView，可以不调用
    如果renderType为UnifiedNative，必须调用，否则会有内存泄漏
 */
- (void)adrf_unRegistView;

/**
 广告关闭事件，手动调用
 */
- (void)adrf_close;

/**
 广告关闭按钮是否存在
 */
- (BOOL)adrf_closeButtonExist;

/**
 渲染类型
 */
- (ADRFMediationAdapterRenderType)renderType;

/**
 自渲染广告数据，模版类型为空
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


@interface ADRFMediationAdapterNativeAdData : NSObject

/**
 标题
 */
@property (nonatomic, copy, nullable, readonly) NSString *title;

/**
 描述
 */
@property (nonatomic, copy, nullable, readonly) NSString *desc;

/**
 封面大图
 */
@property (nonatomic, copy, nullable, readonly) NSString *imageUrl;

/**
 图片列表
 */
@property (nonatomic, copy, nullable, readonly) NSArray<NSString *> *imageUrlAry;

/**
 icon图片
 */
@property (nonatomic, strong, nullable, readonly) NSString *iconImageUrl;

/**
 获取icon图片
 */
- (void)loadIconImage:(void(^)(UIImage * _Nullable))block;

/**
 是否需要显示多媒体View（当素材为视频素材时，或者没有图片素材，需要调用获取广告视图方法）
 */
@property (nonatomic, assign, readonly) BOOL shouldShowMediaView;

@end

NS_ASSUME_NONNULL_END
