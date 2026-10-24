#ifndef GAME_TITLE_MYLAYOUTT_HPP
#define GAME_TITLE_MYLAYOUTT_HPP

#include <revolution/types.h>

#include "Layout.hpp"

namespace Title {

class CMyLayoutT : public CLayout {
public:
    static const s32 ANIMATION_COUNT = 11;

    virtual ~CMyLayoutT(void);
    virtual void _10(void);

    CMyLayoutT(void) {
        setAnimationCount(ANIMATION_COUNT);
    }

    void playAnimFromBeginForward(s32 index);
    bool getAnimIsPlaying(s32 index);
    f32 getBackgroundLoopFrame(void);
};

} // namespace Title

#endif
