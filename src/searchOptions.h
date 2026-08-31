#ifndef MUDLET_SEARCHOPTIONS_H
#define MUDLET_SEARCHOPTIONS_H

/***************************************************************************
 *   Copyright (C) 2008-2012 by Heiko Koehn - KoehnHeiko@googlemail.com    *
 *   Copyright (C) 2014 by Ahmed Charles - acharles@outlook.com            *
 *   Copyright (C) 2017-2020 by Ian Adkins - ieadkins@gmail.com            *
 *   Copyright (C) 2015-2018, 2020, 2022-2023 by Stephen Lyons             *
 *                                               - slysven@virginmedia.com *
 *   Copyright (C) 2023 by Lecker Kebap - Leris@mudlet.org                 *
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

#include <QFlags>

// The search settings that Host stores on behalf of the editor and of the
// main console's buffer.  dlgTriggerEditor and TConsole each adopt one set as
// their own nested names, so Host can hold the settings without a dependency
// on either class.

namespace editorSearch {
enum SearchOption {
    // Unset:
    SearchOptionNone = 0x0,
    SearchOptionCaseSensitive = 0x1,
    SearchOptionIncludeVariables = 0x2,
    SearchOptionWholeWord = 0x4 /*,
    SearchOptionRegExp = 0x8 */
};
Q_DECLARE_FLAGS(SearchOptions, SearchOption)
} // namespace editorSearch

namespace bufferSearch {
enum SearchOption {
    // Unset:
    SearchOptionNone = 0x0,
    SearchOptionCaseSensitive = 0x1
};
Q_DECLARE_FLAGS(SearchOptions, SearchOption)
} // namespace bufferSearch

Q_DECLARE_OPERATORS_FOR_FLAGS(editorSearch::SearchOptions)
Q_DECLARE_OPERATORS_FOR_FLAGS(bufferSearch::SearchOptions)

#endif // MUDLET_SEARCHOPTIONS_H
