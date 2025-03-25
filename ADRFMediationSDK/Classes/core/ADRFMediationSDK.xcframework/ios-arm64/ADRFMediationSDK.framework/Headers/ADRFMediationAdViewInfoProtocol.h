//
//  ADRFMediationAdViewInfoProtocol.h
//  ADRFMediationSDK
//
//  Created by 陶冶明 on 2020/7/22.
//

#import <ADRFMediationSDK/ADRFMediationAdapterCommonDefine.h>
#import <ADRFMediationSDK/ADRFMediationSDKExtInfo.h>

@protocol ADRFMediationAdViewInfoProtocol <NSObject>

/**
 获取广告对象的平台
    如banner、插屏、激励视频、开屏等，则需要在加载成功之后才可以获取当前平台
    信息流可以直接获取
 */
@required
- (nullable ADRFMediationAdapterPlatform)adrf_platform;
- (nullable ADRFMediationSDKExtInfo *)adrf_extInfo;

@end
