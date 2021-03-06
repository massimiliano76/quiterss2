/****************************************************************************
**
** QuiteRSS is a open-source cross-platform news feed reader
** Copyright (C) 2011-2017 QuiteRSS Team <quiterssteam@gmail.com>
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <https://www.gnu.org/licenses/>.
**
****************************************************************************/
#include "webengine.h"

#ifndef DISABLE_BROWSER
#ifdef MOBILE
#include <QtWebView>
#else
#include <QtWebEngine>
#endif
#endif

WebEngine::WebEngine(QObject *parent) : QObject(parent)
{

}

void WebEngine::initialize()
{
#ifndef DISABLE_BROWSER
#ifdef MOBILE
    QtWebView::initialize();
#else
    QtWebEngine::initialize();
#endif
#endif
}

QStringList WebEngine::getQmlSelectors()
{
    QStringList selectors;
#ifndef DISABLE_BROWSER
#ifdef MOBILE
    selectors.append("mobile");
#else
    selectors.append("webview");
#endif
#endif
    return selectors;
}
