//
//  ADRFMediationSDKSourceBiddingResult.h
//  ADRFMediationSDK
//
//  Created by 白粿 on 2021/12/29.
//

typedef NS_ENUM(NSInteger, ADRFMediationSDKSourceBiddingResult) {
    ADRFMediationSDKSourceBiddingResult_Failed = 0, // 竞价失败
    ADRFMediationSDKSourceBiddingResult_Timeout,    // 竞价超时
    ADRFMediationSDKSourceBiddingResult_Sucess,     // 竞价成功
};


typedef NS_ENUM(NSInteger, ADRFMediationSDKSourcePreLoadResult) {
    ADRFMediationSDKSourcePreLoadResult_NULL = 0,    // 未开始预加 & 非预加载
    ADRFMediationSDKSourcePreLoadResult_Loading,     // 预加载中
    ADRFMediationSDKSourcePreLoadResult_LoadingAndNeedJugle,// 预加载中，并且结果需要与竞价比较
    ADRFMediationSDKSourcePreLoadResult_Failed,      // 预加载，广告获取失败
    ADRFMediationSDKSourcePreLoadResult_Success,     // 预加载，广告获取成功
    
    ADRFMediationSDKSourcePreLoadResult_Reward_ReadyToPlay,        // 激励视频，播放准备完成
    ADRFMediationSDKSourcePreLoadResult_Reward_VideoLoadSuccess,   // 激励视频，视频加载完成
    ADRFMediationSDKSourcePreLoadResult_Reward_VideoFailToPlay,    // 激励视频，视频加载失败
    
};

