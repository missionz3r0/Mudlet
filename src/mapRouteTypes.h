#ifndef MUDLET_MAPROUTETYPES_H
#define MUDLET_MAPROUTETYPES_H

/***************************************************************************
 *   Copyright (C) 2013-2016 by Stephen Lyons                              *
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

#include <QString>
#include <QtGlobal>

class TRoom;

// The plain description of a room and of an exit between two rooms, as the
// map's route finding sees them.

struct location
{
    int id;    // Typically 4 bytes
    TRoom* pR; // 4 or 8 bytes? - so may have reduced size from 20 to 8 or 12 plus padding...?
};

typedef float cost;

// Used to record edge details and to deduplicate parallel ones:
struct route
{
    float cost;              // Needed during establishing the best parallel edge
    quint8 direction;        // Use DIR_xxx values to code exit direction
    QString specialExitName; // If direction is DIR_OTHER then this is needed
};

#endif // MUDLET_MAPROUTETYPES_H
