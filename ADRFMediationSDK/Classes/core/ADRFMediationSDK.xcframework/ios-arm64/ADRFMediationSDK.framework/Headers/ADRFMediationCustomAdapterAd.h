//
//  ADRFMediationCustomAdapterAd.h
//  ADRFMediationCustomPlatform
//
//  Created by Erik on 2021/8/25.
//

#import <Foundation/Foundation.h>
#import <ADRFMediationSDK/ADRFMediationAdapterCommonDefine.h>
#import <ADRFMediationSDK/ADRFMediationCustomAdapterRequestContext.h>

NS_ASSUME_NONNULL_BEGIN



@interface ADRFMediationCustomAdapterAd : NSObject

/// 注册自定义广告平台广告加载类，需load方法调用（每个广告类型的适配，都需要调用该方法加载注册）
/// @param klass 广告加载类
/// @param sdkName 自定义平台名称，需与后台配置管理类名一致且不能与现有平台名称冲突 。Eg:gdt,toutiao,ks等
+ (void)registPlatformAdLoaderClass:(id)klass forSdkName:(NSString *)sdkName;

/// 注册自定义广告平台广告加载类，需load方法调用（每个广告类型的适配，都需要调用该方法加载注册）
/// @param klass 广告加载类
/// @param sdkName 自定义平台名称，需与后台配置管理类名一致且不能与现有平台名称冲突 。Eg:gdt,bu,ks等
/// @param renderType 广告类型，如果自定义平台广告不区分类型，使用+ (void)registPlatformAdLoaderClass:(id)klass forSdkName:(NSString *)sdkName注册方法即可。
+ (void)registPlatformAdLoaderClass:(id)klass forSdkName:(NSString *)sdkName renderType:(ADRFMediationAdapterRenderType)renderType;

@end

NS_ASSUME_NONNULL_END
