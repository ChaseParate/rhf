#include "Title/MyLayoutT.hpp"

#include "LayoutManager.hpp"

#include "MessageManager.hpp"

const char layoutFile_title[] = "title.brlyt";
DECL_SECTION(".sdata") static const char *layoutFileTable[] = { layoutFile_title };

const char *sAnimNames[Title::CMyLayoutT::ANIMATION_COUNT] = {"title_logo_open", "title_logo_open", "title_logo_open", "title_star_beat", "title_star_beat", "title_star_beat", "title_logo_open", "title_logo_beat", "title_message_open", "title_close", "title_bg_loop"};
const char *sPanelNames[Title::CMyLayoutT::ANIMATION_COUNT] = {"N_star_all_00", "N_star_all_01", "N_star_all_02", "N_star_all_00", "N_star_all_01", "N_star_all_02", "N_logo_all_00", "N_logo_all_00", "N_message_00", "N_all_00", "N_bg_all_00"};
const bool sRecurseBinds[Title::CMyLayoutT::ANIMATION_COUNT] = {true, true, true, true, true, true, true, true, true, true, true};

enum {
    anim_title_bg_loop = 10
};

void Title::CMyLayoutT::_10(void) {
    nw4r::lyt::MultiArcResourceAccessor *resAccessor = gLayoutManager->getResAccessor();

    u32 size;
    void *resource = resAccessor->GetResource(0, layoutFileTable[0], &size);

    buildLayout(resource, resAccessor);

    for (s32 i = 0; i < ANIMATION_COUNT; i++) {
        nw4r::lyt::Pane *pane = getLayout()->GetRootPane()->FindPaneByName(sPanelNames[i]);
        getAnimation(i)->fn_801D9E70(getLayout(), pane, sAnimNames[i], resAccessor, sRecurseBinds[i]);
    }

    gMessageManager->fn_80088474(getLayout()->GetRootPane());

    this->CLayout::_10();

    getAnimation(anim_title_bg_loop)->setLoop(true);
    playAnimFromBeginForward(anim_title_bg_loop);
}

void Title::CMyLayoutT::playAnimFromBeginForward(s32 index) {
    getAnimation(index)->playFromBeginForward();
}

bool Title::CMyLayoutT::getAnimIsPlaying(s32 index) {
    return getAnimation(index)->getIsPlaying();
}

f32 Title::CMyLayoutT::getBackgroundLoopFrame(void) {
    return getAnimation(anim_title_bg_loop)->fn_801DA650();
}

Title::CMyLayoutT::~CMyLayoutT(void) {
    _14();
}
