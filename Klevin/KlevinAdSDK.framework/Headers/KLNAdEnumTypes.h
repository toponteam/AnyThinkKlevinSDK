//
//  KLNAdEnumTypes.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>

/// 广告样式
typedef NS_ENUM(NSInteger, KLNAdFormat) {
    KLNAdFormatSplash = 1,                ///< 开屏广告（Splash）
    KLNAdFormatInterstitial,              ///< 插屏广告（Interstitial）
    KLNAdFormatRewarded,                  ///< 激励广告（Rewarded）
};

/// 广告创意模版
typedef NS_ENUM(NSInteger, KLNAdTemplateType) {
    /// 未知模版
    KLNAdTemplateTypeNone = 0,
    /// 开屏大图
    KLNAdTemplateTypeSplashImage = 100,
    /// 开屏视频
    KLNAdTemplateTypeSplashVideo = 101,
    /// 激励竖版
    KLNAdTemplateTypeVerticalRewarded = 102,
    /// 激励横版
    KLNAdTemplateTypeHorizontalRewarded = 103,
    /// 插屏1：1
    KLNAdTemplateTypeInterstitial11 = 104,
    /// 插屏9：16
    KLNAdTemplateTypeInterstitial916 = 105
};
