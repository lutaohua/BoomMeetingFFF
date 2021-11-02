//
//  NetworkUtil.h
//  BRTC-iDemo
//
//  Created by zhaozhidan on 2020/8/21.
//  Copyright © 2020 boommeeting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BJLiveBase/BJLNetworking.h>
NS_ASSUME_NONNULL_BEGIN

@interface NetworkUtil : NSObject

@property (nonatomic, strong) BJLNetworking *manager;

+ (void)addToken:(NSString *)token;

+ (void)requestGet:(NSString *)requestUrl callback:(void (^)(NSDictionary *dict))callback failcallback:(void (^)(NSError *error))failcallback;

+ (void)requestPost:(NSString *)requestUrl param:(NSDictionary * _Nullable)dict callback:(void (^)(NSDictionary *dict))callback failcallback:(nonnull void (^)(NSError *error))failcallback;

@end

NS_ASSUME_NONNULL_END
