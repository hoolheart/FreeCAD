/***************************************************************************
 *   Copyright (c) 2022 Wanderer Fan <wandererfan@gmail.com>               *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/

#include "PreCompiled.h"
#ifndef _PreComp_
#include <QApplication>
#include <QGuiApplication>
#include <QMouseEvent>
#include <QScrollBar>
#endif

#include <Mod/TechDraw/App/DrawPage.h>

#include "QGVPage.h"
#include "QGSPage.h"
#include "QGVNavStyleTinkerCAD.h"

using namespace TechDrawGui;

namespace TechDrawGui {

QGVNavStyleTinkerCAD::QGVNavStyleTinkerCAD()
{
}

QGVNavStyleTinkerCAD::~QGVNavStyleTinkerCAD()
{
}

void QGVNavStyleTinkerCAD::handleMousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton) {
        startPan(event->pos());
        event->accept();
    }
}

void QGVNavStyleTinkerCAD::handleMouseMoveEvent(QMouseEvent *event)
{
    if (getViewer()->isBalloonPlacing()) {
        getViewer()->setBalloonCursorPos(event->pos());
    }

    if (panningActive) {
        pan(event->pos());
        event->accept();
    }
}

void QGVNavStyleTinkerCAD::handleMouseReleaseEvent(QMouseEvent *event)
{
    if (getViewer()->isBalloonPlacing()) {
        placeBalloon(event->pos());
    }

    if (panningActive) {
        if (event->button() == Qt::MiddleButton) {
            stopPan();
            event->accept();
        }
    }
}

}  // namespace TechDrawGui
