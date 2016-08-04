////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>

#import "RLMSyncUtil.h"

@class RLMCredential, RLMSessionInfo;

/**
 A `RLMUser` instance represents a single Realm Sync user account (or just user).

 A user may have one or more credentials associated with it. These credentials uniquely identify the user to a
 third-party auth provider, and are used to sign into a Realm Sync user account.
 */
@interface RLMUser : NSObject

NS_ASSUME_NONNULL_BEGIN

@property (nonatomic, readonly) NSDictionary<RLMSyncPath, RLMSessionInfo *> *realms;
@property (nonatomic, readonly) BOOL isAnonymous;

@property (nonatomic, readonly) BOOL isLoggedIn;

+ (instancetype)defaultUser;

+ (instancetype)userForAnonymousAccount;

- (void)loginWithCredential:(RLMCredential *)credential
                 completion:(nullable RLMErrorReportingBlock)completion;

- (void)refresh;

- (void)logout:(BOOL)allDevices completion:(nullable RLMErrorReportingBlock)completion;

- (void)addCredential:(RLMCredential *)credential
           completion:(nullable RLMErrorReportingBlock)completion;

- (void)removeCredential:(RLMCredential *)credential
              completion:(nullable RLMErrorReportingBlock)completion;

NS_ASSUME_NONNULL_END

@end
