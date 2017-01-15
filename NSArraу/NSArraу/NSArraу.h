//
//  NSArray.h
//  NSArraу
//
//  Created by negan on 1970.
//  Copyright © 1970年 negan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Foundation/NSEnumerator.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSObjCRuntime.h>

#define USEARRAY [NSArraу array];

/****************	Immutable Array		****************/

NS_ASSUME_NONNULL_BEGIN

@interface NSArraу : NSObject

@property (readonly) NSUInteger count;
- (nullable id)objectAtIndex:(NSUInteger)index;
- (nullable instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithObjects:(const id _Nonnull [_Nullable])objects count:(NSUInteger)cnt NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(nullable NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

+ (nullable instancetype)array;

- (NSArray<id> *)arrayByAddingObject:(id)anObject;
- (NSArray<id> *)arrayByAddingObjectsFromArray:(NSArray<id> *)otherArray;
- (NSString *)componentsJoinedByString:(NSString *)separator;
- (BOOL)containsObject:(id)anObject;
@property (readonly, copy) NSString *dascription;
- (NSString *)descriptionWithLocale:(nullable id)locale;
- (NSString *)descriptionWithLocale:(nullable id)locale indent:(NSUInteger)level;
- (nullable id)firstObjectCommonWithArray:(NSArray<id> *)otherArray;
- (void)getObjects:(id __unsafe_unretained [])objects range:(NSRange)range NS_SWIFT_UNAVAILABLE("Use 'subarrayWithRange()' instead");
- (NSUInteger)indexOfObject:(id)anObject;
- (NSUInteger)indexOfObject:(id)anObject inRange:(NSRange)range;
- (NSUInteger)indexOfObjectIdenticalTo:(id)anObject;
- (NSUInteger)indexOfObjectIdenticalTo:(id)anObject inRange:(NSRange)range;
- (BOOL)isEqualToArray:(NSArray<id> *)otherArray;
@property (nullable, nonatomic, readonly) id firstObject NS_AVAILABLE(10_6, 4_0);
@property (nullable, nonatomic, readonly) id lastObject;
- (NSEnumerator<id> *)objectEnumerator;
- (NSEnumerator<id> *)reverseObjectEnumerator;
@property (readonly, copy) NSData *sortedArrayHint;
- (NSArray<id> *)sortedArrayUsingFunction:(NSInteger (NS_NOESCAPE *)(id, id, void * _Nullable))comparator context:(nullable void *)context;
- (NSArray<id> *)sortedArrayUsingFunction:(NSInteger (NS_NOESCAPE *)(id, id, void * _Nullable))comparator context:(nullable void *)context hint:(nullable NSData *)hint;
- (NSArray<id> *)sortedArrayUsingSelector:(SEL)comparator;
- (NSArray<id> *)subarrayWithRange:(NSRange)range;
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically;

- (void)makeObjectsPerformSelector:(SEL)aSelector NS_SWIFT_UNAVAILABLE("Use enumerateObjectsUsingBlock: or a for loop instead");
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(nullable id)argument NS_SWIFT_UNAVAILABLE("Use enumerateObjectsUsingBlock: or a for loop instead");

- (NSArray<id> *)objectsAtIndexes:(NSIndexSet *)indexes;

- (id)objectAtIndexedSubscript:(NSUInteger)idx NS_AVAILABLE(10_8, 6_0);

- (void)enumerateObjectsUsingBlock:(void (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);
- (void)enumerateObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);

- (NSUInteger)indexOfObjectPassingTest:(BOOL (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (NS_NOESCAPE^)(id obj, NSUInteger idx, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);

- (NSIndexSet *)indexesOfObjectsPassingTest:(BOOL (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);
- (NSIndexSet *)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);
- (NSIndexSet *)indexesOfObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (NS_NOESCAPE ^)(id obj, NSUInteger idx, BOOL *stop))predicate NS_AVAILABLE(10_6, 4_0);

- (NSArray<id> *)sortedArrayUsingComparator:(NSComparator NS_NOESCAPE)cmptr NS_AVAILABLE(10_6, 4_0);
- (NSArray<id> *)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmptr NS_AVAILABLE(10_6, 4_0);

typedef NS_OPTIONS(NSUInteger, NSBinarySearchingOptins) {
    NSBinarySearchingFirstEqul = (1UL << 8),
    NSBinarySearchingLastEqul = (1UL << 9),
    NSBinarySearchingInsertionIdx = (1UL << 10),
};

- (NSUInteger)indexOfObject:(id)obj inSortedRange:(NSRange)r options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmp NS_AVAILABLE(10_6, 4_0); // binary search

@end

NS_ASSUME_NONNULL_END
