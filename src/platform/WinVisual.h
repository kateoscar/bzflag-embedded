/* bzflag
 * Copyright 1993-1999, Chris Schoeneman
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named LICENSE that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/* WinVisual:
 *	Builders for Windows visuals suitable for OpenGL contexts and windows.
 */

#ifndef BZF_WINVISUAL_H
#define	BZF_WINVISUAL_H

#include "BzfVisual.h"
#include "WinDisplay.h"
#include <windows.h>

class WinVisual : public BzfVisual {
  public:
			WinVisual(const WinDisplay*);
			WinVisual(const WinVisual&);
			~WinVisual();

    void		setLevel(int level);
    void		setDoubleBuffer(boolean);
    void		setIndex(int minDepth);
    void		setRGBA(int minRed, int minGreen,
				int minBlue, int minAlpha);
    void		setDepth(int minDepth);
    void		setStencil(int minDepth);
    void		setAccum(int minRed, int minGreen,
				int minBlue, int minAlpha);
    void		setStereo(boolean);
    void		setMultisample(int minSamples);

    boolean		build();

    // for other Windows stuff
    void		reset();
    int			get(HDC, const PIXELFORMATDESCRIPTOR**);

  protected:
    int			findAttribute(int attribute) const;
    void		appendAttribute(int attribute, int value);
    void		removeAttribute(int index);
    void		editAttribute(int index, int value);

  private:
    WinDisplay::Rep*	display;
    PIXELFORMATDESCRIPTOR pfd;
    int			pixelFormat;
    HDC			hDC;
};

#endif // BZF_WINVISUAL_H
