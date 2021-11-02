//
//  ServiceApi.h
//  BoomMeeting-BoomMeeting
//
//  Created by zhaozhidan on 2021/2/6.
//

#import <Foundation/Foundation.h>


typedef void (^SuccessCallback)(NSDictionary *_Nonnull dict);
typedef void (^FailCallback)(NSError *_Nonnull error);

typedef void (^Success)(id object);

NS_ASSUME_NONNULL_BEGIN

@interface ServiceApi : NSObject

/// 获取预约会议号信息
+ (void)getMeetingInfo:(NSString *)roomId success:(SuccessCallback)success fail:(FailCallback)fail;

/// 获取 分享url hash 值.
+ (void)apiShareHash:(NSDictionary *)param success:(SuccessCallback)success fail:(FailCallback)fail;
///直播间和会议内分享获取分享信息
+ (void)conferenceApiShareHash:(NSString *)roomId isConference:(BOOL)isConference success:(SuccessCallback)success fail:(FailCallback)fail;

/// 分享的接口
+ (void)apiUserShare:(NSDictionary *)param success:(SuccessCallback)success fail:(FailCallback)fail;

//TODO 短链接获取观众列表
/// 短链接获取观众列表
+(void)apiUserHandsWithRoomId:(NSDictionary *)param Success:(SuccessCallback)success fail:(FailCallback)fail;

/// 结束混流, 在releaseRoom 之前调用
/// @param roomId 房间号
/// @param action 事件    start doing end
/// @param streams 房间号
+ (void)stopMixer:(NSString *)roomId action:(NSString *)action streams:(NSString *)streams success:(SuccessCallback)success;

///获取更多观众方法
///@param 请求参数：{room:xxx,page:xxx,pagesize:xxx} pagesize默认50
///获取分页观众的数据
+(void)apiGetViewerUserWithToken:(NSString *)token roomID:(NSString *)roomId withPage:(NSString *)page  success:(SuccessCallback)success;

+(void)apiGetHandViewerUserWithToken:(NSString *)token roomID:(NSString *)roomId success:(SuccessCallback)success;

///获取主持人昵称和房间主题
+ (void)apiGetMasterAndRoomNameWithRoomId:(NSString *)roomId withSucess:(SuccessCallback)success withFail:(FailCallback)fail;

@end

NS_ASSUME_NONNULL_END
