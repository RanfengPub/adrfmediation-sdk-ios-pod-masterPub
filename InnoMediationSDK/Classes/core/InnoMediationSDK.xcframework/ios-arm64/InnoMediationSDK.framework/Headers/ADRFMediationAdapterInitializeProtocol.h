//
//  ADRFMediationAdapterInitializeProtocol.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/3/20.
//

#import <Foundation/Foundation.h>
#import <InnoMediationSDK/ADRFMediationAdapterInitializeRequestContext.h>
#import "ADRFMediationAdapterCommonDefine.h"

NS_ASSUME_NONNULL_BEGIN

#ifndef ADRFMediationAdapterInitializeProtocol
#define ADRFMediationAdapterInitializeProtocol ADRFMediationAdapterInitializeProtocol
@protocol ADRFMediationAdapterInitializeProtocol <NSObject>

@required
+ (void)initializePlatformSDKWithParams:(ADRFMediationAdapterInitializeRequestContext *)params;

+ (NSString *)platformSDKVersion;

+ (ADRFMediationAdapterPlatform)platformSDKName;

@end
#endif

NS_ASSUME_NONNULL_END
