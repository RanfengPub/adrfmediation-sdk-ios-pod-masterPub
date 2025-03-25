//
//  ADRFMediationAdapterErrorDefine.h
//  ADRFMediationSDK
//
//  Created by 陈坤 on 2020/3/27.
//

#import <Foundation/Foundation.h>
#import <ADRFMediationSDK/ADRFMediationAdapterCommonDefine.h>

typedef NSInteger ADRFMediationAdapterErrorCode NS_EXTENSIBLE_STRING_ENUM;
// 错误码长度为6位 abcdef, 类型为NSInteger
// ab为平台，主SDK为10，其他平台SDK以20开始，每次进1
// | platform  | code |
// | --------- | ---- |
// | sdk       | 10   | // 主SDK
// | gdt       | 21   |
// | bu        | 22   |
// | baidu     | 27   |
// | ks        | 28   |
// | gromore   | 32   |
// | TM        | 36   |
// | RF        | 37   |

// cd为广告类型，以01开始，每次增1
// | adType        | code |
// | ------------- | ---- |
// | init          | 01   | // 初始化相关，包括但不限于appid、posid错误、没有导入对应的类、SDK初始化失败
// | splash        | 02   |
// | banner        | 03   |
// | flow          | 04   |
// | rewardVod     | 05   |
// | interstitial  | 06   |
// ef为错误代码，以01开始，每次增1
// | info          | code |
// | ------------- | ---- |
// | bidding       | 01   |

// 申明必须以上述platform和adtype为准，全大写，info必须为英语单词，不要出现冗余信息
//      LOADTIMEOUT 需要改为 TIMEOUT
//      EMPEYERROR 需要改为 EMPTY
//      PRESENT 需改为 PRESENTFAILED
// 格式如下:
//      ADRF_#{platform}_#{adType}_#{info}

//splash广告获取超时
extern const ADRFMediationAdapterErrorCode ADRF_SDK_SPLASH_TIMEOUT;
// 横屏不加载开屏广告
extern const ADRFMediationAdapterErrorCode ADRF_SDK_SPLASH_HORIZONTAL;
// banner广告获取超时
extern const ADRFMediationAdapterErrorCode ADRF_SDK_BANNER_TIMEOUT;
// appId为空
extern const ADRFMediationAdapterErrorCode ADRF_SDK_INIT_APPIDEMPTY;
// 包名和appId不对应
extern const ADRFMediationAdapterErrorCode ADRF_SDK_INIT_BUNDLE;
// 请求配置为空
extern const ADRFMediationAdapterErrorCode ADRF_SDK_INIT_CONFIGEMPTY;
// 未获取到加载广告的平台，可能一下原因 1、第一次启动未获取到配置信息；2、运营未配置广告
extern const ADRFMediationAdapterErrorCode ADRF_SDK_INIT_PLATFORMEMPTY;
// 未导入需要加载的广告类型对应的类
extern const ADRFMediationAdapterErrorCode ADRF_SDK_INIT_CLASSEMPTY;
// 未导入天目
extern const ADRFMediationAdapterErrorCode ADRF_SDK_INIT_TMNOTIMPORTED;
// 未导入ADRanFeng
extern const ADRFMediationAdapterErrorCode ADRF_SDK_INIT_RFADSNOTIMPORTED;


#define ADRFMediationAdapterErrorDomain @"com.adrfad.error"

FOUNDATION_EXPORT NSError *ADRFMediationAdapterError(NSErrorDomain domain, NSInteger code, NSString *localizedDescription);

FOUNDATION_EXPORT NSError *ADRFMediationAdapterErrorDefaultDomain(NSInteger code, NSString *localizedDescription);

@interface ADRFMediationAdapterErrorDefine : NSObject

@property (nonatomic, copy, readonly) NSString *posId;

@property (nonatomic, copy, readonly) ADRFMediationAdapterAdType adType;

@property (nonatomic, assign, readonly) ADRFMediationAdapterErrorCode code;

@property (nonatomic, copy, readonly) NSString *errorDescription;

@property (nonatomic, strong, readonly) NSDictionary<ADRFMediationAdapterPlatform,NSError *> *errorDetailDict;

@property (nonatomic, copy, readonly) NSString *message;

- (NSString *)allPlatformErrorDetail;

@end
