//
//  ADRFMediationCustomAdapterNativeRequestContext.h
//  ADRFMediationSDK
//
//  Created by Suancai on 2023/3/6.
//

#import <ADRFMediationSDK/ADRFMediationCustomAdapterRequestContext.h>
#import <ADRFMediationSDK/ADRFMediationAdapterCommonDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterNativeRequestContext : ADRFMediationCustomAdapterRequestContext

/// 广告尺寸（若无则不使用）
@property (nonatomic, assign) CGSize adSize;

/// 请求数量
@property (nonatomic, assign) NSInteger loadCount;

/// 是否静音播放视频
@property (nonatomic, assign) BOOL muted;

/// 正常广告源为预估eCPM, 头部竞价广告源则为竞价cpm (可变)
@property (nonatomic, assign) double ecpm;

/// 价格类型
@property (nonatomic, assign) ADRFMediationAdapterECPMType ecpmType;


@end

NS_ASSUME_NONNULL_END
