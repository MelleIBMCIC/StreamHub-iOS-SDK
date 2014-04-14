//
//  LFSStreamClient.h
//  LFSClient
//
//  Created by Eugene Scherba on 9/3/13.
//  Copyright (c) 2013 Livefyre. All rights reserved.
//

#import "LFSBaseClient.h"

@interface LFSStreamClient : LFSBaseClient

/**
 @abstract eventId Current streaming URL
 */
@property (nonatomic, readonly) NSURL *collectionStreamURL;

/**
 @abstract eventId current collection Id
 */
@property (nonatomic, strong) NSString *collectionId;

/**
 @abstract eventId last seen event id
 */
@property (nonatomic, strong) NSNumber *eventId;

/*!
 @abstract Set result, success, and failure handlers
 @discussion Set result, success, and failure handlers
 @param handler   Callback to handle response data
 @param success   Success callback (if provided, invalidates handler)
 @param failure   Failure callback
 */

- (void)setResultHandler:(LFHandleBlock)handler
                 success:(LFSSuccessBlock)success
                 failure:(LFSFailureBlock)failure;

/** Start streaming */

/**
 * Start stream reusing the stored event Id
 */

- (void)startStream;

/** Start streaming */

/**
 * Start stream with event Id
 *
 * @param eventId event Id (only events with event Ids larger than the given one
 * will be streamed)
 */

- (void)startStreamWithEventId:(NSNumber*)eventId;

/** Pause streaming */

/**
 * Pause streaming
 */

- (void)pauseStream;

/** Resume streaming */

/**
 * Resume streaming
 */

- (void)resumeStream;

/** Stop streaming */

/**
 * stop streaming
 */
- (void)stopStream;


@end
