/**
 * @file pdraw_renderer_videocoreegl.hpp
 * @brief Parrot Drones Awesome Video Viewer Library - Broadcom VideoCore 4 EGL renderer
 * @date 17/12/2016
 * @author aurelien.barre@akaaba.net
 *
 * Copyright (c) 2016 Aurelien Barre <aurelien.barre@akaaba.net>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 * 
 *   * Neither the name of the copyright holder nor the names of the
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _PDRAW_RENDERER_VIDEOCOREEGL_HPP_
#define _PDRAW_RENDERER_VIDEOCOREEGL_HPP_

#ifdef USE_VIDEOCOREEGL

#include <pthread.h>
#include "GLES2/gl2.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>

#include "pdraw_renderer_gles2.hpp"
#include "pdraw_gles2_video.hpp"
#include "pdraw_gles2_hud.hpp"


namespace Pdraw
{


class VideoCoreEglRenderer : public Gles2Renderer
{
public:

    VideoCoreEglRenderer();

    ~VideoCoreEglRenderer();

    int setRendererParams
            (int windowWidth, int windowHeight,
             int renderX, int renderY,
             int renderWidth, int renderHeight,
             void *uiHandler);

    int setVideoDimensions(unsigned int videoWidth, unsigned int videoHeight);

    void* getVideoEglImage(int index);

    int swapDecoderEglImage();

    int render(int timeout);

private:

    int swapRendererEglImage();

    int mVideoWidth;
    int mVideoHeight;
    EGLDisplay mDisplay;
    EGLSurface mSurface;
    EGLContext mContext;
    void *mEglImage[3];
    int mEglImageIdxReady;
    int mEglImageIdxDecoderLocked;
    int mEglImageIdxRendererLocked;
    pthread_mutex_t mEglImageMutex;
};

}

#endif /* USE_VIDEOCOREEGL */

#endif /* !_PDRAW_RENDERER_VIDEOCOREEGL_HPP_ */
