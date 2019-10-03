


























typedef enum YGAlign{YGAlignAuto, YGAlignFlexStart, YGAlignCenter, YGAlignFlexEnd, YGAlignStretch, YGAlignBaseline, YGAlignSpaceBetween, YGAlignSpaceAround} YGAlign; const char* YGAlignToString(YGAlign);;
typedef enum YGDimension{YGDimensionWidth, YGDimensionHeight} YGDimension; const char* YGDimensionToString(YGDimension);

typedef enum YGDirection{YGDirectionInherit, YGDirectionLTR, YGDirectionRTL} YGDirection; const char* YGDirectionToString(YGDirection);





typedef enum YGDisplay{YGDisplayFlex, YGDisplayNone} YGDisplay; const char* YGDisplayToString(YGDisplay);

typedef enum YGEdge{YGEdgeLeft, YGEdgeTop, YGEdgeRight, YGEdgeBottom, YGEdgeStart, YGEdgeEnd, YGEdgeHorizontal, YGEdgeVertical, YGEdgeAll} YGEdge; const char* YGEdgeToString(YGEdge);
typedef enum YGExperimentalFeature{YGExperimentalFeatureWebFlexBasis} YGExperimentalFeature; const char* YGExperimentalFeatureToString(YGExperimentalFeature);

typedef enum YGFlexDirection{YGFlexDirectionColumn, YGFlexDirectionColumnReverse, YGFlexDirectionRow, YGFlexDirectionRowReverse} YGFlexDirection; const char* YGFlexDirectionToString(YGFlexDirection);






typedef enum YGJustify{YGJustifyFlexStart, YGJustifyCenter, YGJustifyFlexEnd, YGJustifySpaceBetween, YGJustifySpaceAround, YGJustifySpaceEvenly} YGJustify; const char* YGJustifyToString(YGJustify);
typedef enum YGLogLevel{YGLogLevelError, YGLogLevelWarn, YGLogLevelInfo, YGLogLevelDebug, YGLogLevelVerbose, YGLogLevelFatal} YGLogLevel; const char* YGLogLevelToString(YGLogLevel);
typedef enum YGMeasureMode{YGMeasureModeUndefined, YGMeasureModeExactly, YGMeasureModeAtMost} YGMeasureMode; const char* YGMeasureModeToString(YGMeasureMode);





typedef enum YGNodeType{YGNodeTypeDefault, YGNodeTypeText} YGNodeType; const char* YGNodeTypeToString(YGNodeType);

typedef enum YGOverflow{YGOverflowVisible, YGOverflowHidden, YGOverflowScroll} YGOverflow; const char* YGOverflowToString(YGOverflow);





typedef enum YGPositionType{YGPositionTypeRelative, YGPositionTypeAbsolute} YGPositionType; const char* YGPositionTypeToString(YGPositionType);

typedef enum YGPrintOptions{YGPrintOptionsLayout = 1, YGPrintOptionsStyle = 2, YGPrintOptionsChildren = 4} YGPrintOptions; const char* YGPrintOptionsToString(YGPrintOptions);





typedef enum YGUnit{YGUnitUndefined, YGUnitPoint, YGUnitPercent, YGUnitAuto} YGUnit; const char* YGUnitToString(YGUnit);






typedef enum YGWrap{YGWrapNoWrap, YGWrapWrap, YGWrapWrapReverse} YGWrap; const char* YGWrapToString(YGWrap);

















static const uint32_t __nan = 0x7fc00000;





typedef struct YGValue {
  float value;
  YGUnit unit;
} YGValue;

extern const YGValue YGValueAuto;
extern const YGValue YGValueUndefined;
extern const YGValue YGValueZero;



typedef struct YGSize {
  float width;
  float height;
} YGSize;

typedef struct YGConfig* YGConfigRef;

typedef struct YGNode* YGNodeRef;
typedef const struct YGNode* YGNodeConstRef;

typedef YGSize (*YGMeasureFunc)(
    YGNodeRef node,
    float width,
    YGMeasureMode widthMode,
    float height,
    YGMeasureMode heightMode);
typedef float (*YGBaselineFunc)(YGNodeRef node, float width, float height);
typedef void (*YGDirtiedFunc)(YGNodeRef node);
typedef void (*YGPrintFunc)(YGNodeRef node);
typedef void (*YGNodeCleanupFunc)(YGNodeRef node);
typedef int (*YGLogger)(
    YGConfigRef config,
    YGNodeRef node,
    YGLogLevel level,
    const char* format,
    va_list args);
typedef YGNodeRef (
    *YGCloneNodeFunc)(YGNodeRef oldNode, YGNodeRef owner, int childIndex);


           YGNodeRef YGNodeNew(void);
           YGNodeRef YGNodeNewWithConfig(YGConfigRef config);
           YGNodeRef YGNodeClone(YGNodeRef node);
           void YGNodeFree(YGNodeRef node);
           void YGNodeFreeRecursiveWithCleanupFunc(
    YGNodeRef node,
    YGNodeCleanupFunc cleanup);
           void YGNodeFreeRecursive(YGNodeRef node);
           void YGNodeReset(YGNodeRef node);

           void YGNodeInsertChild(
    YGNodeRef node,
    YGNodeRef child,
    uint32_t index);

           void YGNodeRemoveChild(YGNodeRef node, YGNodeRef child);
           void YGNodeRemoveAllChildren(YGNodeRef node);
           YGNodeRef YGNodeGetChild(YGNodeRef node, uint32_t index);
           YGNodeRef YGNodeGetOwner(YGNodeRef node);
           YGNodeRef YGNodeGetParent(YGNodeRef node);
           uint32_t YGNodeGetChildCount(YGNodeRef node);
           void YGNodeSetChildren(
    YGNodeRef owner,
    const YGNodeRef children[],
    uint32_t count);

           void YGNodeSetIsReferenceBaseline(
    YGNodeRef node,
    bool isReferenceBaseline);

           bool YGNodeIsReferenceBaseline(YGNodeRef node);

           void YGNodeCalculateLayout(
    YGNodeRef node,
    float availableWidth,
    float availableHeight,
    YGDirection ownerDirection);







           void YGNodeMarkDirty(YGNodeRef node);





           void YGNodeMarkDirtyAndPropogateToDescendants(YGNodeRef node);

           void YGNodePrint(YGNodeRef node, YGPrintOptions options);

           bool YGFloatIsUndefined(float value);

           bool YGNodeCanUseCachedMeasurement(
    YGMeasureMode widthMode,
    float width,
    YGMeasureMode heightMode,
    float height,
    YGMeasureMode lastWidthMode,
    float lastWidth,
    YGMeasureMode lastHeightMode,
    float lastHeight,
    float lastComputedWidth,
    float lastComputedHeight,
    float marginRow,
    float marginColumn,
    YGConfigRef config);

           void YGNodeCopyStyle(YGNodeRef dstNode, YGNodeRef srcNode);

           void* YGNodeGetContext(YGNodeRef node);
           void YGNodeSetContext(YGNodeRef node, void* context);
void YGConfigSetPrintTreeFlag(YGConfigRef config, bool enabled);
bool YGNodeHasMeasureFunc(YGNodeRef node);
           void YGNodeSetMeasureFunc(YGNodeRef node, YGMeasureFunc measureFunc);
bool YGNodeHasBaselineFunc(YGNodeRef node);
void YGNodeSetBaselineFunc(YGNodeRef node, YGBaselineFunc baselineFunc);
YGDirtiedFunc YGNodeGetDirtiedFunc(YGNodeRef node);
void YGNodeSetDirtiedFunc(YGNodeRef node, YGDirtiedFunc dirtiedFunc);
void YGNodeSetPrintFunc(YGNodeRef node, YGPrintFunc printFunc);
           bool YGNodeGetHasNewLayout(YGNodeRef node);
           void YGNodeSetHasNewLayout(YGNodeRef node, bool hasNewLayout);
YGNodeType YGNodeGetNodeType(YGNodeRef node);
void YGNodeSetNodeType(YGNodeRef node, YGNodeType nodeType);
           bool YGNodeIsDirty(YGNodeRef node);
bool YGNodeLayoutGetDidUseLegacyFlag(YGNodeRef node);

           void YGNodeStyleSetDirection(YGNodeRef node, YGDirection direction);
           YGDirection YGNodeStyleGetDirection(YGNodeConstRef node);

           void YGNodeStyleSetFlexDirection(
    YGNodeRef node,
    YGFlexDirection flexDirection);
           YGFlexDirection YGNodeStyleGetFlexDirection(YGNodeConstRef node);

           void YGNodeStyleSetJustifyContent(
    YGNodeRef node,
    YGJustify justifyContent);
           YGJustify YGNodeStyleGetJustifyContent(YGNodeConstRef node);

           void YGNodeStyleSetAlignContent(
    YGNodeRef node,
    YGAlign alignContent);
           YGAlign YGNodeStyleGetAlignContent(YGNodeConstRef node);

           void YGNodeStyleSetAlignItems(YGNodeRef node, YGAlign alignItems);
           YGAlign YGNodeStyleGetAlignItems(YGNodeConstRef node);

           void YGNodeStyleSetAlignSelf(YGNodeRef node, YGAlign alignSelf);
           YGAlign YGNodeStyleGetAlignSelf(YGNodeConstRef node);

           void YGNodeStyleSetPositionType(
    YGNodeRef node,
    YGPositionType positionType);
           YGPositionType YGNodeStyleGetPositionType(YGNodeConstRef node);

           void YGNodeStyleSetFlexWrap(YGNodeRef node, YGWrap flexWrap);
           YGWrap YGNodeStyleGetFlexWrap(YGNodeConstRef node);

           void YGNodeStyleSetOverflow(YGNodeRef node, YGOverflow overflow);
           YGOverflow YGNodeStyleGetOverflow(YGNodeConstRef node);

           void YGNodeStyleSetDisplay(YGNodeRef node, YGDisplay display);
           YGDisplay YGNodeStyleGetDisplay(YGNodeConstRef node);

           void YGNodeStyleSetFlex(YGNodeRef node, float flex);
           float YGNodeStyleGetFlex(YGNodeConstRef node);

           void YGNodeStyleSetFlexGrow(YGNodeRef node, float flexGrow);
           float YGNodeStyleGetFlexGrow(YGNodeConstRef node);

           void YGNodeStyleSetFlexShrink(YGNodeRef node, float flexShrink);
           float YGNodeStyleGetFlexShrink(YGNodeConstRef node);

           void YGNodeStyleSetFlexBasis(YGNodeRef node, float flexBasis);
           void YGNodeStyleSetFlexBasisPercent(YGNodeRef node, float flexBasis);
           void YGNodeStyleSetFlexBasisAuto(YGNodeRef node);
           YGValue YGNodeStyleGetFlexBasis(YGNodeConstRef node);

           void YGNodeStyleSetPosition(
    YGNodeRef node,
    YGEdge edge,
    float position);
           void YGNodeStyleSetPositionPercent(
    YGNodeRef node,
    YGEdge edge,
    float position);
           YGValue YGNodeStyleGetPosition(YGNodeConstRef node, YGEdge edge);

           void YGNodeStyleSetMargin(YGNodeRef node, YGEdge edge, float margin);
           void YGNodeStyleSetMarginPercent(
    YGNodeRef node,
    YGEdge edge,
    float margin);
           void YGNodeStyleSetMarginAuto(YGNodeRef node, YGEdge edge);
           YGValue YGNodeStyleGetMargin(YGNodeConstRef node, YGEdge edge);

           void YGNodeStyleSetPadding(
    YGNodeRef node,
    YGEdge edge,
    float padding);
           void YGNodeStyleSetPaddingPercent(
    YGNodeRef node,
    YGEdge edge,
    float padding);
           YGValue YGNodeStyleGetPadding(YGNodeConstRef node, YGEdge edge);

           void YGNodeStyleSetBorder(YGNodeRef node, YGEdge edge, float border);
           float YGNodeStyleGetBorder(YGNodeConstRef node, YGEdge edge);

           void YGNodeStyleSetWidth(YGNodeRef node, float width);
           void YGNodeStyleSetWidthPercent(YGNodeRef node, float width);
           void YGNodeStyleSetWidthAuto(YGNodeRef node);
           YGValue YGNodeStyleGetWidth(YGNodeConstRef node);

           void YGNodeStyleSetHeight(YGNodeRef node, float height);
           void YGNodeStyleSetHeightPercent(YGNodeRef node, float height);
           void YGNodeStyleSetHeightAuto(YGNodeRef node);
           YGValue YGNodeStyleGetHeight(YGNodeConstRef node);

           void YGNodeStyleSetMinWidth(YGNodeRef node, float minWidth);
           void YGNodeStyleSetMinWidthPercent(YGNodeRef node, float minWidth);
           YGValue YGNodeStyleGetMinWidth(YGNodeConstRef node);

           void YGNodeStyleSetMinHeight(YGNodeRef node, float minHeight);
           void YGNodeStyleSetMinHeightPercent(YGNodeRef node, float minHeight);
           YGValue YGNodeStyleGetMinHeight(YGNodeConstRef node);

           void YGNodeStyleSetMaxWidth(YGNodeRef node, float maxWidth);
           void YGNodeStyleSetMaxWidthPercent(YGNodeRef node, float maxWidth);
           YGValue YGNodeStyleGetMaxWidth(YGNodeConstRef node);

           void YGNodeStyleSetMaxHeight(YGNodeRef node, float maxHeight);
           void YGNodeStyleSetMaxHeightPercent(YGNodeRef node, float maxHeight);
           YGValue YGNodeStyleGetMaxHeight(YGNodeConstRef node);
           void YGNodeStyleSetAspectRatio(YGNodeRef node, float aspectRatio);
           float YGNodeStyleGetAspectRatio(YGNodeConstRef node);

           float YGNodeLayoutGetLeft(YGNodeRef node);
           float YGNodeLayoutGetTop(YGNodeRef node);
           float YGNodeLayoutGetRight(YGNodeRef node);
           float YGNodeLayoutGetBottom(YGNodeRef node);
           float YGNodeLayoutGetWidth(YGNodeRef node);
           float YGNodeLayoutGetHeight(YGNodeRef node);
           YGDirection YGNodeLayoutGetDirection(YGNodeRef node);
           bool YGNodeLayoutGetHadOverflow(YGNodeRef node);
bool YGNodeLayoutGetDidLegacyStretchFlagAffectLayout(YGNodeRef node);





           float YGNodeLayoutGetMargin(YGNodeRef node, YGEdge edge);
           float YGNodeLayoutGetBorder(YGNodeRef node, YGEdge edge);
           float YGNodeLayoutGetPadding(YGNodeRef node, YGEdge edge);

           void YGConfigSetLogger(YGConfigRef config, YGLogger logger);
           void YGAssert(bool condition, const char* message);
           void YGAssertWithNode(
    YGNodeRef node,
    bool condition,
    const char* message);
           void YGAssertWithConfig(
    YGConfigRef config,
    bool condition,
    const char* message);


           void YGConfigSetPointScaleFactor(
    YGConfigRef config,
    float pixelsInPoint);
void YGConfigSetShouldDiffLayoutWithoutLegacyStretchBehaviour(
    YGConfigRef config,
    bool shouldDiffLayout);






           void YGConfigSetUseLegacyStretchBehaviour(
    YGConfigRef config,
    bool useLegacyStretchBehaviour);


           YGConfigRef YGConfigNew(void);
           void YGConfigFree(YGConfigRef config);
           void YGConfigCopy(YGConfigRef dest, YGConfigRef src);
           int32_t YGConfigGetInstanceCount(void);

           void YGConfigSetExperimentalFeatureEnabled(
    YGConfigRef config,
    YGExperimentalFeature feature,
    bool enabled);
           bool YGConfigIsExperimentalFeatureEnabled(
    YGConfigRef config,
    YGExperimentalFeature feature);



           void YGConfigSetUseWebDefaults(YGConfigRef config, bool enabled);
           bool YGConfigGetUseWebDefaults(YGConfigRef config);

           void YGConfigSetCloneNodeFunc(
    YGConfigRef config,
    YGCloneNodeFunc callback);


           YGConfigRef YGConfigGetDefault(void);

           void YGConfigSetContext(YGConfigRef config, void* context);
           void* YGConfigGetContext(YGConfigRef config);

           float YGRoundValueToPixelGrid(
    float value,
    float pointScaleFactor,
    bool forceCeil,
    bool forceFloor);
