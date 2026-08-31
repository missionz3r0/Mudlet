#ifndef MUDLET_TFONTATTRIBUTES_H
#define MUDLET_TFONTATTRIBUTES_H

/***************************************************************************
 *   Copyright (C) 2008-2013 by Heiko Koehn - KoehnHeiko@googlemail.com    *
 *   Copyright (C) 2014-2023 by Stephen Lyons                              *
 *                                               - slysven@virginmedia.com *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "utils.h"

#include <QFont>
#include <QString>

// This contains the details of a font that we might want to maintain a record
// of, independently of a QFont instance:
struct TFontAttributes
{
    explicit TFontAttributes(const bool isAntiAliased = false)
    : mStyleStrategy(isAntiAliased ? static_cast<QFont::StyleStrategy>(QFont::PreferAntialias | QFont::PreferQuality) : static_cast<QFont::StyleStrategy>(QFont::NoAntialias | QFont::PreferQuality))
    {
    }

    explicit TFontAttributes(const QFont& font)
    {
        mName = font.family();
        mPointSize = font.pointSize();
        mStyleHint = font.styleHint();
        mStyleStrategy = font.styleStrategy();
        mFixedPitch = font.fixedPitch();
        mKerning = font.kerning();
        mWeight = font.weight();
        mUnderline = font.underline();
        mOverline = font.overline();
        mStrikeout = font.strikeOut();
        mItalic = font.italic();
        // Although we had a setter for this we never used it:
        // mLetterSpacing = font.letterSpacing();
        // mSpacingType = font.SpacingType();
    }

    // Since C++20 the comparison operators can also be default coded by the
    // compiler:
    bool operator==(const TFontAttributes& other) const = default;
    bool operator!=(const TFontAttributes& other) const = default;

    TFontAttributes(const TFontAttributes& other) = default;
    TFontAttributes& operator=(const TFontAttributes& other) = default;

    QFont makeFont() const
    {
        QFont font = QFont(mName, mPointSize, mWeight, mItalic);
        font.setFixedPitch(mFixedPitch);
        font.setStyleHint(mStyleHint, mStyleStrategy);
        font.setKerning(mKerning);
        font.setUnderline(mUnderline);
        font.setOverline(mOverline);
        font.setStrikeOut(mStrikeout);

        return font;
    }

    void setAntiAliasOption(const bool isAntiAliased)
    {
        mStyleStrategy =
                isAntiAliased ? static_cast<QFont::StyleStrategy>(QFont::PreferAntialias | QFont::PreferQuality) : static_cast<QFont::StyleStrategy>(QFont::NoAntialias | QFont::PreferQuality);
    }

    // enums to consider:
    // Not used: QFont::Capitalization mCapitalization; // { MixedCase, AllUppercase, AllLowercase, SmallCaps, Capitalize }
    // Not used: QFont::HintingPreference mHintingPreference; // { PreferDefaultHinting, PreferNoHinting, PreferVerticalHinting, PreferFullHinting }
    // Not used: QFont::SpacingType mSpacingType; // { PercentageSpacing, AbsoluteSpacing }
    // Not used: QFont::Stretch mStretch; // { AnyStretch, UltraCondensed, ExtraCondensed, Condensed, SemiCondensed, ..., UltraExpanded }
    // Not used: QFont::Style mStyle; // { StyleNormal, StyleItalic, StyleOblique }
    // Combined and used with next: QFont::StyleHint mStyleHint; // { AnyStyle, SansSerif, Helvetica, Serif, Times, ..., System }
    // Combined and used with prior: QFont::StyleStrategy mStyleStrategy; // { PreferDefault, PreferBitmap, PreferDevice, PreferOutline, ForceOutline, ..., PreferQuality }
    // Used: QFont::Weight mWeight; // { Thin, ExtraLight, Light, Normal, Medium, ..., Black }

    QString mName = qsl("Bitstream Vera Sans Mono");
    int mPointSize = 14;
    // Actually this is combined with the next one - but doesn't work on X11
    // anyway - and since we don't specify it in the TConsole case this means
    // the QFont::AnyStyle is used for other Desktop environments:
    QFont::StyleHint mStyleHint = QFont::AnyStyle;
    // We use either: (QFont::NoAntialias | QFont::PreferQuality) for all
    // TConsoles but the main one can be set to (QFont::PreferAntialias |
    // QFont::PreferQuality) instead - see constructor:
    QFont::StyleStrategy mStyleStrategy = static_cast<QFont::StyleStrategy>(QFont::NoAntialias | QFont::PreferQuality);
    // qreal mLetterSpacing = 0.0;
    // QFont::SpacingType mSpacingType = QFont::AbsoluteSpacing;
    // We use but don't set "Line Spacing" - so don't worry about it.
    QFont::Weight mWeight = QFont::Normal;
    bool mFixedPitch = true; // We always set this
    bool mKerning = false;   // We haven't been resetting this but we ought to
    // we don't set these on "base" fonts for TConsole's but we can set them for
    // bits of text:
    bool mUnderline = false;
    bool mOverline = false;
    bool mStrikeout = false;
    bool mItalic = false;
};

#endif // MUDLET_TFONTATTRIBUTES_H
