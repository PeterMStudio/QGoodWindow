/*
The MIT License (MIT)

Copyright © 2018, Juergen Skrotzky (https://github.com/Jorgen-VikingGod, JorgenVikingGod@gmail.com)
Copyright © 2018-2024 Antonio Dias (https://github.com/antonypro)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "windowstylebase.h"
#include "stylecommon.h"

WindowStyleBase::WindowStyleBase() : WindowStyleBase(styleBase())
{
#ifdef Q_OS_WIN
    m_hash_pixmap_cache[SP_MessageBoxInformation] = StyleCommon::winStandardPixmap(SP_MessageBoxInformation);
    m_hash_pixmap_cache[SP_MessageBoxWarning] = StyleCommon::winStandardPixmap(SP_MessageBoxWarning);
    m_hash_pixmap_cache[SP_MessageBoxCritical] = StyleCommon::winStandardPixmap(SP_MessageBoxCritical);
    m_hash_pixmap_cache[SP_MessageBoxQuestion] = StyleCommon::winStandardPixmap(SP_MessageBoxQuestion);
#endif
}

WindowStyleBase::WindowStyleBase(QStyle *style) : QProxyStyle(style)
{

}

WindowStyleBase::~WindowStyleBase()
{

}

QStyle *WindowStyleBase::styleBase() const
{
    QStyle *base = QStyleFactory::create(QStringLiteral("Fusion"));
    return base;
}

QIcon WindowStyleBase::standardIcon(StandardPixmap standardPixmap, const QStyleOption *option, const QWidget *widget) const
{
#ifdef Q_OS_WIN
    switch (standardPixmap)
    {
        case SP_MessageBoxInformation:
        case SP_MessageBoxWarning:
        case SP_MessageBoxCritical:
        case SP_MessageBoxQuestion:
        {
            QPixmap pixmap = m_hash_pixmap_cache.value(standardPixmap, QPixmap());

            if (!pixmap.isNull())
                return QIcon(pixmap);

            break;
        }
        default:
            break;
    }
#endif

    return QProxyStyle::standardIcon(standardPixmap, option, widget);
}

void WindowStyleBase::polish(QPalette &palette)
{
   QProxyStyle::polish(palette);
}

void WindowStyleBase::polish(QApplication *app)
{
   QProxyStyle::polish(app);
}

void WindowStyleBase::unpolish(QApplication *app)
{
    QProxyStyle::unpolish(app);
}

QStyle *WindowStyleBase::baseStyle() const
{
    return styleBase();
}
