//
//  ADRFMediationSDKExtInfo.h
//  ADRFMediationSDK
//
//  Created by xingming on 2024/6/13.
//

#import <Foundation/Foundation.h>
#import <ADRFMediationSDK/ADRFMediationAdapterCommonDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationSDKExtInfo : NSObject

/**
 价格 （单位分）
 */
@property (nonatomic, copy) NSString *ecpm;

/**
 价格精度
 */
@property (nonatomic, assign) ADRFMediationAdapterECPMType ecpmType;

@end

NS_ASSUME_NONNULL_END
