//
//  ADRFMediationCustomAdapterClassLoader.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/8/25.
//  Updated by Suancai on 2023/03/01 19:44.

#import <Foundation/Foundation.h>
#import <ADRFMediationSDK/ADRFMediationCustomAdapterRequestContext.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRFMediationCustomAdapterInitialize : NSObject

/// 注册初始化类 需要在load方法中调用
/// @param klass 初始化自定义平台的管理类
/// @param sdkName 平台名称，需与后台配置管理类名一致且不能与现有平台名称冲突。Eg:gdt,bu,ks等
+ (void)registPlatformInitializeClass:(id)klass forSdkName:(NSString *)sdkName;

/// 初始化方法，子类需在此方法实现中初始化平台SDK
/// @param config 初始化参数
+ (void)initAdSDKWithConfigInfo:(ADRFMediationCustomAdapterRequestContext *)config;

/// 平台版本号
+ (NSString *)platformSDKVersion;

@end

NS_ASSUME_NONNULL_END
