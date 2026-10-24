#ifndef GAME_TITLE_MYLAYOUTF_HPP
#define GAME_TITLE_MYLAYOUTF_HPP

#include <revolution/types.h>

#include "Layout.hpp"

#include "Title/SceneTitle.hpp"

#include "SaveData.hpp"

namespace Title {

enum ETitleState {
    TITLE_STATE_FILE_SELECT_IN = 0,
    TITLE_STATE_FILE_SELECT = 1,
    TITLE_STATE_FILE_SELECT_OUT = 2,
    TITLE_STATE_FILE_SELECT_RETURN = 3,
    TITLE_STATE_ACTION_MENU_IN = 4,
    TITLE_STATE_ACTION_MENU_OUT = 5,
    TITLE_STATE_ACTION_MENU = 6,
    TITLE_STATE_ICON_SELECT_IN = 7,
    TITLE_STATE_ICON_SELECT_OUT = 8,
    TITLE_STATE_ICON_SELECT = 9,
    TITLE_STATE_MII_SELECT_IN = 10,
    TITLE_STATE_MII_SELECT_OUT = 11,
    TITLE_STATE_MII_SELECT = 12,
    TITLE_STATE_DELETE_DIALOG_IN = 13,
    TITLE_STATE_DELETE_DIALOG = 14,
    TITLE_STATE_DELETE_DIALOG_OUT = 15,
    TITLE_STATE_CONFIRM_DIALOG_IN = 16,
    TITLE_STATE_CONFIRM_DIALOG = 17,
    TITLE_STATE_CONFIRM_DIALOG_OUT = 18,
    TITLE_STATE_MESSAGE_DIALOG_IN = 19,
    TITLE_STATE_MESSAGE_DIALOG = 20,
    TITLE_STATE_MESSAGE_DIALOG_OUT = 21,
    TITLE_STATE_START_GAME = 22,
};

enum EFileActionButtonIndex {
    TITLE_FILE_ACTION_BUTTON_START = 0,
    TITLE_FILE_ACTION_BUTTON_BACK = 1,
    TITLE_FILE_ACTION_BUTTON_DELETE = 2,
    TITLE_FILE_ACTION_BUTTON_CHANGE = 3,

    TITLE_FILE_ACTION_BUTTON_COUNT,
};

enum ENameButtonIndex {
    TITLE_NAME_BUTTON_BACK = 15,
    TITLE_NAME_BUTTON_MII = 16,

    TITLE_NAME_BUTTON_COUNT,
};

enum EMiiButtonIndex {
    TITLE_MII_BUTTON_PAGE_LEFT = 10,
    TITLE_MII_BUTTON_PAGE_RIGHT = 11,
    TITLE_MII_BUTTON_BACK = 12,

    TITLE_MII_BUTTON_COUNT,
};

class CMyLayoutF : public CLayout {
public:
    virtual ~CMyLayoutF(void);
    virtual void _10(void);
    virtual void _14(void);
    virtual void _18(nw4r::lyt::DrawInfo *drawInfo);

    CMyLayoutF(void);

    static void fileSelectManagerCallback(s32 arg1, s8 arg2);
    static void iconSelectManagerCallback(s32 arg1, s8 arg2);
    static void miiSelectManagerCallback(s32 arg1, s8 arg2);
    static void miscManagerCursorCallback(bool useCursor);
    static void unkCallback(s32 arg1, s32 arg2);

    void setBackgroundLoopFrame(f32 frame);
    void updateState(ETitleState state);
    void updateSaveDisplay(s32 saveIndex);
    void setupIconSelection(void);
    void updateMiiPage(s32 page);
    void updateSelectionSfx(void);

private:
    ETitleState mState;
    ETitleState mPrevState;
    s32 mUnk24;
    CSceneTitle *mScene;

    CExBtnPaneManager *mFileSelectManager;
    CExBtnPaneManager *mActionMenuManager;
    CExBtnPaneManager *mIconSelectManager;
    CExBtnPaneManager *mMiiSelectManager;
    CExBtnPaneManager *mDeleteDialogManager;
    CExBtnPaneManager *mConfirmDialogManager;
    CExBtnPaneManager *mMessageDialogManager;

    CExBtnPane mFileButtons[SAVE_COUNT];
    CExBtnPane mFileActionButtons[TITLE_FILE_ACTION_BUTTON_COUNT];
    CExBtnPane mNameButtons[TITLE_NAME_BUTTON_COUNT];
    CExBtnPane mMiiButtons[TITLE_MII_BUTTON_COUNT];

    CExBtnPane mDeleteBackButton;
    CExBtnPane mConfirmButton;
    CExBtnPane mCancelButton;
    CExBtnPane mMessageOkButton;

    nw4r::lyt::Pane *mCursorFramePane;
    nw4r::lyt::Pane *mCursorWindowPane;

    nw4r::lyt::TextBox *mMenuMessageTextBox;
    nw4r::lyt::TextBox *mDialogMessageTextBox;
    nw4r::lyt::TextBox *mCurrentPageTextBox;
    nw4r::lyt::TextBox *mTotalPagesTextBox;

    nw4r::lyt::TexMap mDefaultMiiTexture;

    s32 mSelectedSaveIndex;
    s32 mDeleteHoldFrames;
    s32 mMiiPage;
    bool mUnk9B8;
    s32 mStartGameFrames;
};

} // namespace Title

#endif
