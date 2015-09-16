//
//  PLCollectionViewWaterfallLayout.h
//  Example
//
//  Created by Plan on 15/9/16.
//  Copyright (c) 2015年 PLAN. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  Enumerated structure to define direction in which items can be rendered.
 */
typedef NS_ENUM (NSUInteger, PLCollectionViewWaterfallLayoutItemRenderDirection) {
    PLCollectionViewWaterfallLayoutItemRenderDirectionShortestFirst,
    PLCollectionViewWaterfallLayoutItemRenderDirectionLeftToRight,
    PLCollectionViewWaterfallLayoutItemRenderDirectionRightToLeft
};

/**
 *  Constants that specify the types of supplementary views that can be presented using a waterfall layout.
 */

/// A supplementary view that identifies the header for a given section.
extern NSString *const PLCollectionElementKindSectionHeader;
/// A supplementary view that identifies the footer for a given section.
extern NSString *const PLCollectionElementKindSectionFooter;

#pragma mark - PLCollectionViewDelegateWaterfallLayout

@class PLCollectionViewWaterfallLayout;

/**
 *  The PLCollectionViewDelegateWaterfallLayout protocol defines methods that let you coordinate with a
 *  PLCollectionViewWaterfallLayout object to implement a waterfall-based layout.
 *  The methods of this protocol define the size of items.
 *
 *  The waterfall layout object expects the collection view’s delegate object to adopt this protocol.
 *  Therefore, implement this protocol on object assigned to your collection view’s delegate property.
 */
@protocol PLCollectionViewDelegateWaterfallLayout <UICollectionViewDelegate>
@required
/**
 *  Asks the delegate for the size of the specified item’s cell.
 *
 *  @param collectionView
 *    The collection view object displaying the waterfall layout.
 *  @param collectionViewLayout
 *    The layout object requesting the information.
 *  @param indexPath
 *    The index path of the item.
 *
 *  @return
 *    The original size of the specified item. Both width and height must be greater than 0.
 */
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional
/**
 *  Asks the delegate for the row count in a section
 *
 *  @param collectionView
 *    The collection view object displaying the waterfall layout.
 *  @param collectionViewLayout
 *    The layout object requesting the information.
 *  @param section
 *    The section.
 *
 *  @return
 *    The original row count for that section. Must be greater than 0.
 */
- (NSInteger)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout rowCountForSection:(NSInteger)section;

/**
 *  Asks the delegate for the height of the header view in the specified section.
 *
 *  @param collectionView
 *    The collection view object displaying the waterfall layout.
 *  @param collectionViewLayout
 *    The layout object requesting the information.
 *  @param section
 *    The index of the section whose header size is being requested.
 *
 *  @return
 *    The height of the header. If you return 0, no header is added.
 *
 *  @discussion
 *    If you do not implement this method, the waterfall layout uses the value in its headerHeight property to set the size of the header.
 *
 *  @see
 *    headerHeight
 */
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout heightForHeaderInSection:(NSInteger)section;

/**
 *  Asks the delegate for the height of the footer view in the specified section.
 *
 *  @param collectionView
 *    The collection view object displaying the waterfall layout.
 *  @param collectionViewLayout
 *    The layout object requesting the information.
 *  @param section
 *    The index of the section whose header size is being requested.
 *
 *  @return
 *    The height of the footer. If you return 0, no footer is added.
 *
 *  @discussion
 *    If you do not implement this method, the waterfall layout uses the value in its footerHeight property to set the size of the footer.
 *
 *  @see
 *    footerHeight
 */
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout heightForFooterInSection:(NSInteger)section;

/**
 * Asks the delegate for the insets in the specified section.
 *
 * @param collectionView
 *   The collection view object displaying the waterfall layout.
 * @param collectionViewLayout
 *   The layout object requesting the information.
 * @param section
 *   The index of the section whose insets are being requested.
 *
 * @discussion
 *   If you do not implement this method, the waterfall layout uses the value in its sectionInset property.
 *
 * @return
 *   The insets for the section.
 */
- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section;

/**
 * Asks the delegate for the header insets in the specified section.
 *
 * @param collectionView
 *   The collection view object displaying the waterfall layout.
 * @param collectionViewLayout
 *   The layout object requesting the information.
 * @param section
 *   The index of the section whose header insets are being requested.
 *
 * @discussion
 *   If you do not implement this method, the waterfall layout uses the value in its headerInset property.
 *
 * @return
 *   The headerInsets for the section.
 */
- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForHeaderInSection:(NSInteger)section;

/**
 * Asks the delegate for the footer insets in the specified section.
 *
 * @param collectionView
 *   The collection view object displaying the waterfall layout.
 * @param collectionViewLayout
 *   The layout object requesting the information.
 * @param section
 *   The index of the section whose footer insets are being requested.
 *
 * @discussion
 *   If you do not implement this method, the waterfall layout uses the value in its footerInset property.
 *
 * @return
 *   The footerInsets for the section.
 */
- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForFooterInSection:(NSInteger)section;

/**
 * Asks the delegate for the minimum spacing between two items in the same row
 * in the specified section. If this method is not implemented, the
 * minimumInteritemSpacing property is used for all sections.
 *
 * @param collectionView
 *   The collection view object displaying the waterfall layout.
 * @param collectionViewLayout
 *   The layout object requesting the information.
 * @param section
 *   The index of the section whose minimum interitem spacing is being requested.
 *
 * @discussion
 *   If you do not implement this method, the waterfall layout uses the value in its minimumInteritemSpacing property to determine the amount of space between items in the same row.
 *
 * @return
 *   The minimum interitem spacing.
 */
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;

/**
 * Asks the delegate for the minimum spacing between colums in a secified section. If this method is not implemented, the
 * minimumrowSpacing property is used for all sections.
 *
 * @param collectionView
 *   The collection view object displaying the waterfall layout.
 * @param collectionViewLayout
 *   The layout object requesting the information.
 * @param section
 *   The index of the section whose minimum interitem spacing is being requested.
 *
 * @discussion
 *   If you do not implement this method, the waterfall layout uses the value in its minimumrowSpacing property to determine the amount of space between rows in each section.
 *
 * @return
 *   The minimum spacing between each row.
 */
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout minimumrowSpacingForSectionAtIndex:(NSInteger)section;

@end

#pragma mark - PLCollectionViewWaterfallLayout

/**
 *  The PLCollectionViewWaterfallLayout class is a concrete layout object that organizes items into waterfall-based grids
 *  with optional header and footer views for each section.
 *
 *  A waterfall layout works with the collection view’s delegate object to determine the size of items, headers, and footers
 *  in each section. That delegate object must conform to the `PLCollectionViewDelegateWaterfallLayout` protocol.
 *
 *  Each section in a waterfall layout can have its own custom header and footer. To configure the header or footer for a view,
 *  you must configure the height of the header or footer to be non zero. You can do this by implementing the appropriate delegate
 *  methods or by assigning appropriate values to the `headerHeight` and `footerHeight` properties.
 *  If the header or footer height is 0, the corresponding view is not added to the collection view.
 *
 *  @note PLCollectionViewWaterfallLayout doesn't support decoration view, and it supports vertical scrolling direction only.
 */
@interface PLCollectionViewWaterfallLayout : UICollectionViewLayout

/**
 *  @brief How many rows for this layout.
 *  @discussion Default: 2
 */
@property (nonatomic, assign) NSInteger rowCount;

/**
 *  @brief The minimum spacing to use between successive rows.
 *  @discussion Default: 10.0
 */
@property (nonatomic, assign) CGFloat minimumRowSpacing;

/**
 *  @brief The minimum spacing to use between items in the same row.
 *  @discussion Default: 10.0
 *  @note This spacing is not applied to the space between header and rows or between rows and footer.
 */
@property (nonatomic, assign) CGFloat minimumInteritemSpacing;

/**
 *  @brief Height for section header
 *  @discussion
 *    If your collectionView's delegate doesn't implement `collectionView:layout:heightForHeaderInSection:`,
 *    then this value will be used.
 *
 *    Default: 0
 */
@property (nonatomic, assign) CGFloat headerHeight;

/**
 *  @brief Height for section footer
 *  @discussion
 *    If your collectionView's delegate doesn't implement `collectionView:layout:heightForFooterInSection:`,
 *    then this value will be used.
 *
 *    Default: 0
 */
@property (nonatomic, assign) CGFloat footerHeight;

/**
 *  @brief The margins that are used to lay out the header for each section.
 *  @discussion
 *    These insets are applied to the headers in each section.
 *    They represent the distance between the top of the collection view and the top of the content items
 *    They also indicate the spacing on either side of the header. They do not affect the size of the headers or footers themselves.
 *
 *    Default: UIEdgeInsetsZero
 */
@property (nonatomic, assign) UIEdgeInsets headerInset;

/**
 *  @brief The margins that are used to lay out the footer for each section.
 *  @discussion
 *    These insets are applied to the footers in each section.
 *    They represent the distance between the top of the collection view and the top of the content items
 *    They also indicate the spacing on either side of the footer. They do not affect the size of the headers or footers themselves.
 *
 *    Default: UIEdgeInsetsZero
 */
@property (nonatomic, assign) UIEdgeInsets footerInset;

/**
 *  @brief The margins that are used to lay out content in each section.
 *  @discussion
 *    Section insets are margins applied only to the items in the section.
 *    They represent the distance between the header view and the rows and between the rows and the footer view.
 *    They also indicate the spacing on either side of rows. They do not affect the size of the headers or footers themselves.
 *
 *    Default: UIEdgeInsetsZero
 */
@property (nonatomic, assign) UIEdgeInsets sectionInset;

/**
 *  @brief The direction in which items will be rendered in subsequent rows.
 *  @discussion
 *    The direction in which each item is rendered. This could be left to right (PLCollectionViewWaterfallLayoutItemRenderDirectionLeftToRight), right to left (PLCollectionViewWaterfallLayoutItemRenderDirectionRightToLeft), or shortest row fills first (PLCollectionViewWaterfallLayoutItemRenderDirectionShortestFirst).
 *
 *    Default: PLCollectionViewWaterfallLayoutItemRenderDirectionShortestFirst
 */
@property (nonatomic, assign) PLCollectionViewWaterfallLayoutItemRenderDirection itemRenderDirection;

/**
 *  @brief The minimum height of the collection view's content.
 *  @discussion
 *    The minimum height of the collection view's content. This could be used to allow hidden headers with no content.
 *
 *    Default: 0.f
 */
@property (nonatomic, assign) CGFloat minimumContentHeight;

/**
 *  @brief The calculated width of an item in the specified section.
 *  @discussion
 *    The width of an item is calculated based on number of rows, the collection view width, and the horizontal insets for that section.
 */
- (CGFloat)itemWidthInSectionAtIndex:(NSInteger)section;

@end

